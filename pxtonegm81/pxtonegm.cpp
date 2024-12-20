#pragma once
#include "stdafx.h"

#include <vector>
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#include <optional>
#endif
#include <stdint.h>
#include <cstring>
#include <tuple>

#define dllg /* tag */
#define dllgm /* tag;mangled */

#if defined(_WINDOWS)
#define dllx extern "C" __declspec(dllexport)
#define dllm __declspec(dllexport)
#elif defined(GNUC)
#define dllx extern "C" __attribute__ ((visibility("default"))) 
#define dllm __attribute__ ((visibility("default"))) 
#else
#define dllx extern "C"
#define dllm /* */
#endif

#ifdef _WINDEF_
/// auto-generates a window_handle() on GML side
typedef HWND GAME_HWND;
#endif

/// auto-generates an asset_get_index("argument_name") on GML side
typedef int gml_asset_index_of;
/// Wraps a C++ pointer for GML.
template <typename T> using gml_ptr = T*;
/// Passes a modified struct back to GML
template <typename T> using gml_inout = T&;
/// Modifies an array of values that GML passed in
template <typename T> using gml_inout_vector = std::vector<T>&;

/// Same as gml_ptr, but replaces the GML-side pointer by a nullptr after passing it to C++
template <typename T> using gml_ptr_destroy = T*;
/// Wraps any ID (or anything that casts to int64, really) for GML.
template <typename T> using gml_id = T;
/// Same as gml_id, but replaces the GML-side ID by a 0 after passing it to C++
template <typename T> using gml_id_destroy = T;

class gml_buffer {
private:
	uint8_t* _data;
	int32_t _size;
	int32_t _tell;
public:
	gml_buffer() : _data(nullptr), _tell(0), _size(0) {}
	gml_buffer(uint8_t* data, int32_t size, int32_t tell) : _data(data), _size(size), _tell(tell) {}

	inline uint8_t* data() { return _data; }
	inline int32_t tell() { return _tell; }
	inline int32_t size() { return _size; }
};

class gml_istream {
	uint8_t* pos;
	uint8_t* start;
public:
	gml_istream(void* origin) : pos((uint8_t*)origin), start((uint8_t*)origin) {}

	template<class T> T read() {
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable to be read");
		T result{};
		std::memcpy(&result, pos, sizeof(T));
		pos += sizeof(T);
		return result;
	}

	char* read_string() {
		char* r = (char*)pos;
		while (*pos != 0) pos++;
		pos++;
		return r;
	}

	gml_buffer read_gml_buffer() {
		auto _data = (uint8_t*)read<int64_t>();
		auto _size = read<int32_t>();
		auto _tell = read<int32_t>();
		return gml_buffer(_data, _size, _tell);
	}
};

class gml_ostream {
	uint8_t* pos;
	uint8_t* start;
public:
	gml_ostream(void* origin) : pos((uint8_t*)origin), start((uint8_t*)origin) {}

	template<class T> void write(T val) {
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable to be write");
		memcpy(pos, &val, sizeof(T));
		pos += sizeof(T);
	}

	void write_string(const char* s) {
		for (int i = 0; s[i] != 0; i++) write<char>(s[i]);
		write<char>(0);
	}
};

class gmk_buffer {
	uint8_t* buf = 0;
	int pos = 0;
	int len = 0;
public:
	gmk_buffer() {}
	uint8_t* prepare(int size) {
		if (len < size) {
			auto nb = (uint8_t*)realloc(buf, size);
			if (nb == nullptr) {
				trace("Failed to reallocate %u bytes in gmk_buffer::prepare", size);
				return nullptr;
			}
			len = size;
			buf = nb;
		}
		pos = 0;
		return buf;
	}
	void init() {
		buf = 0;
		pos = 0;
		len = 0;
	}
	void rewind() { pos = 0; }
	inline uint8_t* data() { return buf; }
	//
	template<class T> void write(T val) {
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable to be write");
		int next = pos + sizeof(T);
		if (next > len) {
			auto nl = len;
			while (nl < next) nl *= 2;
			auto nb = (uint8_t*)realloc(buf, nl);
			if (nb == nullptr) {
				trace("Failed to reallocate %u bytes in gmk_buffer::write", nl);
				return;
			}
			len = nl;
			buf = nb;
		}
		memcpy(buf + pos, &val, sizeof(T));
		pos = next;
	}
	template<class T> T read() {
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable to be read");
		int next = pos + sizeof(T);
		T result{};
		if (next > len) return result;
		memcpy(&result, buf + pos, sizeof(T));
		pos = next;
		return result;
	}
	void write_string(const char* str) {
		int n = (int)strlen(str) + 1;
		int next = pos + n;
		if (next > len) {
			auto nl = len;
			while (nl < next) nl *= 2;
			auto nb = (uint8_t*)realloc(buf, nl);
			if (nb == nullptr) {
				trace("Failed to reallocate %u bytes in gmk_buffer::write", nl);
				return;
			}
			len = nl;
			buf = nb;
		}
		memcpy(buf + pos, str, n);
		pos = next;
	}
	const char* read_string() {
		if (pos >= len) return "";
		auto str = (const char*)(buf + pos);
		pos += (int)strlen(str) + 1;
		return str;
	}
};
//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by pxtonegm.rc

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        101
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WINDOWS
	#include "targetver.h"
	
	#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
	#include <windows.h>
#endif

#if defined(WIN32)
#define dllx extern "C" __declspec(dllexport)
#elif defined(GNUC)
#define dllx extern "C" __attribute__ ((visibility("default"))) 
#else
#define dllx extern "C"
#endif

#define trace(...) { printf("[pxtonegm:%d] ", __LINE__); printf(__VA_ARGS__); printf("\n"); fflush(stdout); }

#include "gml_ext.h"

// TODO: reference additional headers your program requires here#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>
#include "gml_ext.h"
gmk_buffer gmk_buffer_args;
// Struct forward declarations:
// from pxtonegm.cpp:30:
struct pxtone_quality {
	long channel_num, samples_per_sec, bits_per_sample, sample_per_buf;
};
// from pxtonegm.cpp:110:
struct pxtone_tune_info {
	long beat_num;
	float beat_tempo;
	long beat_clock;
	long meas_num;
};
extern bool pxtone_init(GAME_HWND hwnd, long channel_num, long samples_per_sec, long bits_per_sample, float buffer_length_sec, bool directSound);
dllx double pxtone_init_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	GAME_HWND _arg_hwnd = (GAME_HWND)_in.read<uint64_t>();
	long _arg_channel_num = _in.read<long>();
	long _arg_samples_per_sec = _in.read<long>();
	long _arg_bits_per_sample = _in.read<long>();
	float _arg_buffer_length_sec = _in.read<float>();
	bool _arg_directSound;
	if (_in.read<bool>()) {
		_arg_directSound = _in.read<bool>();
	} else _arg_directSound = false;
	return pxtone_init(_arg_hwnd, _arg_channel_num, _arg_samples_per_sec, _arg_bits_per_sample, _arg_buffer_length_sec, _arg_directSound);
}

extern bool pxtone_reset(GAME_HWND hwnd, long channel_num, long samples_per_sec, long bits_per_sample, float buffer_length_sec, bool directSound);
dllx double pxtone_reset_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	GAME_HWND _arg_hwnd = (GAME_HWND)_in.read<uint64_t>();
	long _arg_channel_num = _in.read<long>();
	long _arg_samples_per_sec = _in.read<long>();
	long _arg_bits_per_sample = _in.read<long>();
	float _arg_buffer_length_sec = _in.read<float>();
	bool _arg_directSound;
	if (_in.read<bool>()) {
		_arg_directSound = _in.read<bool>();
	} else _arg_directSound = false;
	return pxtone_reset(_arg_hwnd, _arg_channel_num, _arg_samples_per_sec, _arg_bits_per_sample, _arg_buffer_length_sec, _arg_directSound);
}

extern pxtone_quality pxtone_get_quality();
dllx double pxtone_get_quality_raw(void* _inout_ptr, double _inout_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _inout_ptr = _gmkb;
	gml_istream _in(_inout_ptr);
	pxtone_quality _result = pxtone_get_quality();
	gml_ostream _out(_inout_ptr);
	auto& _r = _result;
	_out.write<long>(_r.channel_num);
	_out.write<long>(_r.samples_per_sec);
	_out.write<long>(_r.bits_per_sample);
	_out.write<long>(_r.sample_per_buf);
	return 1;
}

extern bool pxtone_load_ns(const char* full_path);
dllx double pxtone_load_ns_raw(void* _in_ptr, double _in_ptr_size, const char* _arg_full_path) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	return pxtone_load_ns(_arg_full_path);
}

extern bool pxtone_load_buffer(gml_buffer buf, std::optional<int> length);
dllx double pxtone_load_buffer_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	gml_buffer _arg_buf = _in.read_gml_buffer();
	std::optional<int> _arg_length;
	if (_in.read<bool>()) {
		std::optional<int> _a_length;
		if (_in.read<bool>()) {
			_a_length = _in.read<int>();
		} else _a_length = {};
		_arg_length = _a_length;
	} else _arg_length = {};
	return pxtone_load_buffer(_arg_buf, _arg_length);
}

extern bool pxtone_start(long start_sample, long fadein_msec);
dllx double pxtone_start_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	long _arg_start_sample;
	if (_in.read<bool>()) {
		_arg_start_sample = _in.read<long>();
	} else _arg_start_sample = 0;
	long _arg_fadein_msec;
	if (_in.read<bool>()) {
		_arg_fadein_msec = _in.read<long>();
	} else _arg_fadein_msec = 0;
	return pxtone_start(_arg_start_sample, _arg_fadein_msec);
}

extern bool pxtone_fadeout(long msec);
dllx double pxtone_fadeout_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	long _arg_msec = _in.read<long>();
	return pxtone_fadeout(_arg_msec);
}

extern bool pxtone_set_loop(bool loop);
dllx double pxtone_set_loop_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	bool _arg_loop = _in.read<bool>();
	return pxtone_set_loop(_arg_loop);
}

extern pxtone_tune_info pxtone_tune_get_info();
dllx double pxtone_tune_get_info_raw(void* _inout_ptr, double _inout_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _inout_ptr = _gmkb;
	gml_istream _in(_inout_ptr);
	pxtone_tune_info _result = pxtone_tune_get_info();
	gml_ostream _out(_inout_ptr);
	auto& _r = _result;
	_out.write<long>(_r.beat_num);
	_out.write<float>(_r.beat_tempo);
	_out.write<long>(_r.beat_clock);
	_out.write<long>(_r.meas_num);
	return 1;
}

extern bool pxtone_tune_vomit(gml_buffer buf, long sample_num);
dllx double pxtone_tune_vomit_raw(void* _in_ptr, double _in_ptr_size) {
	auto _gmkb = gmk_buffer_args.data();
	if (_gmkb) _in_ptr = _gmkb;
	gml_istream _in(_in_ptr);
	gml_buffer _arg_buf = _in.read_gml_buffer();
	long _arg_sample_num = _in.read<long>();
	return pxtone_tune_vomit(_arg_buf, _arg_sample_num);
}

// GM8.1 and earlier:
/// #gmki
dllx double pxtonegm_gmkb_prepare(double _size) {
	gmk_buffer_args.prepare((int)_size);
	return 1;
}
// reads:
/// #gmki
dllx double pxtonegm_gmkb_read_s32() {
	return (double)gmk_buffer_args.read<int32_t>();
}
/// #gmki
dllx double pxtonegm_gmkb_read_f32() {
	return (double)gmk_buffer_args.read<float>();
}
// writes:
/// #gmki
dllx double pxtonegm_gmkb_write_ptr(double val) {
	gmk_buffer_args.write((int64_t)(int32_t)val);
	return 1;
}
/// #gmki
dllx double pxtonegm_gmkb_write_bool(double val) {
	gmk_buffer_args.write((bool)val);
	return 1;
}
/// #gmki
dllx double pxtonegm_gmkb_write_s32(double val) {
	gmk_buffer_args.write((int32_t)val);
	return 1;
}
/// #gmki
dllx double pxtonegm_gmkb_write_f32(double val) {
	gmk_buffer_args.write((float)val);
	return 1;
}
/// #gmki
dllx double pxtonegm_gmkb_write_u64(double val) {
	#if defined(TINY) && (INTPTR_MAX == INT32_MAX)
	int64_t result;
	__asm {
		fld val
		fistp result
	}
	gmk_buffer_args.write(result);
	#else
	gmk_buffer_args.write((int64_t)val);
	#endif
	return 1;
}
// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

HMODULE hmPxToneGM = 0;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		hmPxToneGM = hModule;
	}
	return TRUE;
}

/// @author YellowAfterlife

#include "stdafx.h"
#include "pxtone.h"
#pragma comment(lib, "../pxtone/pxtone.lib")

///
dllx double pxtone_is_available() {
	return 1;
}

long pxtone_clock = 0;
BOOL pxtone_callback(long clock) {
	pxtone_clock = clock;
	return TRUE;
}

dllg bool pxtone_init(GAME_HWND hwnd, long channel_num, long samples_per_sec, long bits_per_sample, float buffer_length_sec, bool directSound = false) {
	return pxtone_Ready(hwnd, channel_num, samples_per_sec, bits_per_sample, buffer_length_sec, directSound, pxtone_callback);
}
dllg bool pxtone_reset(GAME_HWND hwnd, long channel_num, long samples_per_sec, long bits_per_sample, float buffer_length_sec, bool directSound = false) {
	return pxtone_Reset(hwnd, channel_num, samples_per_sec, bits_per_sample, buffer_length_sec, directSound, pxtone_callback);
}

///
dllx const char* pxtone_last_error() {
	return pxtone_GetLastError();
}

struct pxtone_quality {
	long channel_num, samples_per_sec, bits_per_sample, sample_per_buf;
};
dllg pxtone_quality pxtone_get_quality() {
	static_assert(sizeof(int32_t) == sizeof(long), "long is i32");
	pxtone_quality qty{};
	pxtone_GetQuality(&qty.channel_num, &qty.samples_per_sec, &qty.bits_per_sample, &qty.sample_per_buf);
	return qty;
}
// aside: these have nothing to do with tune, named so for backwards compat
///
dllx double pxtone_get_channels() {
	return pxtone_get_quality().channel_num;
}
///
dllx double pxtone_get_sps() {
	return pxtone_get_quality().samples_per_sec;
}
///
dllx double pxtone_get_bps() {
	return pxtone_get_quality().bits_per_sample;
}
///
dllx double pxtone_get_spb() {
	return pxtone_get_quality().sample_per_buf;
}

///
dllx double pxtone_release() {
	return pxtone_Release();
}

extern HMODULE hmPxToneGM;
inline void pxtone_before_load() {
	if (pxtone_Tune_IsStreaming()) pxtone_Tune_Stop();
}
dllg bool pxtone_load_ns(const char* full_path) {
	pxtone_before_load();
	return pxtone_Tune_Load(hmPxToneGM, NULL, full_path);
}
dllg bool pxtone_load_buffer(gml_buffer buf, std::optional<int> length = {}) {
	pxtone_before_load();
	return pxtone_Tune_Read(buf.data(), length ? *length : buf.size());
}

///
dllx double pxtone_tune_release() {
	return pxtone_Tune_Release();
}

dllg bool pxtone_start(long start_sample = 0, long fadein_msec = 0) {
	return pxtone_Tune_Start(start_sample, fadein_msec);
}

dllg bool pxtone_fadeout(long msec) {
	return pxtone_Tune_Fadeout(msec);
}
///
dllx double pxtone_set_volume(double volume) {
	pxtone_Tune_SetVolume((float)volume);
	return 1;
}
///
dllx double pxtone_stop() {
	return pxtone_Tune_Stop();
}
///
dllx double pxtone_isplaying() {
	return pxtone_Tune_IsStreaming();
}
///
dllx double pxtone_get_clock() {
	return pxtone_clock;
}

dllg bool pxtone_set_loop(bool loop) {
	pxtone_Tune_SetLoop(loop);
	return true;
}

struct pxtone_tune_info {
	long beat_num;
	float beat_tempo;
	long beat_clock;
	long meas_num;
};
dllg pxtone_tune_info pxtone_tune_get_info() {
	pxtone_tune_info inf{};
	pxtone_Tune_GetInformation(&inf.beat_num, &inf.beat_tempo, &inf.beat_clock, &inf.meas_num);
	return inf;
}
///
dllx double pxtone_get_beat_number() {
	return pxtone_tune_get_info().beat_num;
}
///
dllx double pxtone_get_beat_tempo() {
	return pxtone_tune_get_info().beat_tempo;
}
///
dllx double pxtone_get_beat_clock() {
	return pxtone_tune_get_info().beat_clock;
}
///
dllx double pxtone_get_measure_number() {
	return pxtone_tune_get_info().meas_num;
}

///
dllx double pxtone_get_repeat_measure() {
	return pxtone_Tune_GetRepeatMeas();
}
///
dllx double pxtone_get_play_measure() {
	return pxtone_Tune_GetPlayMeas();
}

///
dllx const char* pxtone_get_name() {
	return pxtone_Tune_GetName();
}
///
dllx const char* pxtone_get_comment() {
	return pxtone_Tune_GetComment();
}

///
dllg bool pxtone_tune_vomit(gml_buffer buf, long sample_num) {
	return pxtone_Tune_Vomit(buf.data(), sample_num);
}

// what do the noise functions do, anyway// stdafx.cpp : source file that includes just the standard includes
// pxtonegm.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
