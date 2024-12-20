#include "gml_ext.h"
gmk_buffer gmk_buffer_args;
// Struct forward declarations:
// from pxtonegm.cpp:30:
struct pxtone_quality {
	long channel_num, samples_per_sec, bits_per_sample, sample_per_buf;
};
// from pxtonegm.cpp:105:
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
