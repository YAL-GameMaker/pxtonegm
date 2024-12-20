#define pxtone_init
/// pxtone_init(channel_num:int, samples_per_sec:int, bits_per_sample:int, buffer_length_sec:number, directSound:bool = false)->bool
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 26);
external_call(global.f_pxtonegm_gmkb_write_ptr, window_handle());
external_call(global.f_pxtonegm_gmkb_write_s32, argument[0]);
external_call(global.f_pxtonegm_gmkb_write_s32, argument[1]);
external_call(global.f_pxtonegm_gmkb_write_s32, argument[2]);
external_call(global.f_pxtonegm_gmkb_write_f32, argument[3]);
if (argument_count >= 5) {
    external_call(global.f_pxtonegm_gmkb_write_bool, true);
    external_call(global.f_pxtonegm_gmkb_write_bool, argument[4]);
} else external_call(global.f_pxtonegm_gmkb_write_bool, false);
//*/
return external_call(global.f_pxtone_init_raw, "", 26);

#define pxtone_reset
/// pxtone_reset(channel_num:int, samples_per_sec:int, bits_per_sample:int, buffer_length_sec:number, directSound:bool = false)->bool
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 26);
external_call(global.f_pxtonegm_gmkb_write_ptr, window_handle());
external_call(global.f_pxtonegm_gmkb_write_s32, argument[0]);
external_call(global.f_pxtonegm_gmkb_write_s32, argument[1]);
external_call(global.f_pxtonegm_gmkb_write_s32, argument[2]);
external_call(global.f_pxtonegm_gmkb_write_f32, argument[3]);
if (argument_count >= 5) {
    external_call(global.f_pxtonegm_gmkb_write_bool, true);
    external_call(global.f_pxtonegm_gmkb_write_bool, argument[4]);
} else external_call(global.f_pxtonegm_gmkb_write_bool, false);
//*/
return external_call(global.f_pxtone_reset_raw, "", 26);

#define pxtone_get_quality
/// pxtone_get_quality()->
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 16);
if (external_call(global.f_pxtone_get_quality_raw, "", 16)) {
    var _struct_0; _struct_0 = ds_list_create(); // pxtone_quality
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // channel_num
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // samples_per_sec
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // bits_per_sample
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // sample_per_buf
    return _struct_0;
    //*/
} else {
    return -1;
    //*/
}

#define pxtone_load_ns
/// pxtone_load_ns(full_path:string)->bool
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 1);
return external_call(global.f_pxtone_load_ns_raw, "", 1, argument0);

#define pxtone_load_buffer
/// pxtone_load_buffer(buf:buffer, ?length:int?)->bool
show_error("pxtone_load_buffer is unavailable because the following aren't present in this GameMaker version:
buffer_exists
buffer_get_address
buffer_get_size
buffer_tell
", true);
/*var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 22);
var _val_0; _val_0 = argument[0];
if (buffer_exists(_val_0)) {
    external_call(global.f_pxtonegm_gmkb_write_u64, int64(buffer_get_address(_val_0)));
    external_call(global.f_pxtonegm_gmkb_write_s32, buffer_get_size(_val_0));
    external_call(global.f_pxtonegm_gmkb_write_s32, buffer_tell(_val_0));
} else {
    external_call(global.f_pxtonegm_gmkb_write_u64, 0);
    external_call(global.f_pxtonegm_gmkb_write_s32, 0);
    external_call(global.f_pxtonegm_gmkb_write_s32, 0);
}
if (argument_count >= 2) {
    external_call(global.f_pxtonegm_gmkb_write_bool, true);
    var _val_0; _val_0 = argument[1];
    var _flag_0; _flag_0 = is_real(_val_0);
    external_call(global.f_pxtonegm_gmkb_write_bool, _flag_0);
    if (_flag_0) {
        external_call(global.f_pxtonegm_gmkb_write_s32, _val_0);
    }
} else external_call(global.f_pxtonegm_gmkb_write_bool, false);
//*\/
return external_call(global.f_pxtone_load_buffer_raw, "", 22);*/

#define pxtone_start
/// pxtone_start(start_sample:int = 0, fadein_msec:int = 0)->bool
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 10);
if (argument_count >= 1) {
    external_call(global.f_pxtonegm_gmkb_write_bool, true);
    external_call(global.f_pxtonegm_gmkb_write_s32, argument[0]);
} else external_call(global.f_pxtonegm_gmkb_write_bool, false);
if (argument_count >= 2) {
    external_call(global.f_pxtonegm_gmkb_write_bool, true);
    external_call(global.f_pxtonegm_gmkb_write_s32, argument[1]);
} else external_call(global.f_pxtonegm_gmkb_write_bool, false);
return external_call(global.f_pxtone_start_raw, "", 10);

#define pxtone_fadeout
/// pxtone_fadeout(msec:int)->bool
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 4);
external_call(global.f_pxtonegm_gmkb_write_s32, argument0);
return external_call(global.f_pxtone_fadeout_raw, "", 4);

#define pxtone_set_loop
/// pxtone_set_loop(loop:bool)->bool
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 1);
external_call(global.f_pxtonegm_gmkb_write_bool, argument0);
return external_call(global.f_pxtone_set_loop_raw, "", 1);

#define pxtone_tune_get_info
/// pxtone_tune_get_info()->
var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 16);
if (external_call(global.f_pxtone_tune_get_info_raw, "", 16)) {
    var _struct_0; _struct_0 = ds_list_create(); // pxtone_tune_info
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // beat_num
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_f32)); // beat_tempo
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // beat_clock
    ds_list_add(_struct_0, external_call(global.f_pxtonegm_gmkb_read_s32)); // meas_num
    return _struct_0;
    //*/
} else {
    return -1;
    //*/
}

#define pxtone_tune_vomit
/// pxtone_tune_vomit(buf:buffer, sample_num:int)->bool 
show_error("pxtone_tune_vomit is unavailable because the following aren't present in this GameMaker version:
buffer_exists
buffer_get_address
buffer_get_size
buffer_tell
", true);
/*var _buf; _buf = external_call(global.f_pxtonegm_gmkb_prepare, 20);
var _val_0; _val_0 = argument0;
if (buffer_exists(_val_0)) {
    external_call(global.f_pxtonegm_gmkb_write_u64, int64(buffer_get_address(_val_0)));
    external_call(global.f_pxtonegm_gmkb_write_s32, buffer_get_size(_val_0));
    external_call(global.f_pxtonegm_gmkb_write_s32, buffer_tell(_val_0));
} else {
    external_call(global.f_pxtonegm_gmkb_write_u64, 0);
    external_call(global.f_pxtonegm_gmkb_write_s32, 0);
    external_call(global.f_pxtonegm_gmkb_write_s32, 0);
}
external_call(global.f_pxtonegm_gmkb_write_s32, argument1);
return external_call(global.f_pxtone_tune_vomit_raw, "", 20);*/

