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
dllg bool pxtone_load_ns(const char* full_path) {
	return pxtone_Tune_Load(hmPxToneGM, NULL, full_path);
}
dllg bool pxtone_load_buffer(gml_buffer buf, std::optional<int> length = {}) {
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

// what do the noise functions do, anyway