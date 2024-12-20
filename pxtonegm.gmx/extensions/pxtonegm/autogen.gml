#define pxtone_init
/// pxtone_init(channel_num:int, samples_per_sec:int, bits_per_sample:int, buffer_length_sec:number, directSound:bool = false)->bool
var _buf; _buf = pxtonegm_prepare_buffer(26);
// GMS >= 1:
buffer_write(_buf, buffer_u64, int64(window_handle()));
buffer_write(_buf, buffer_s32, argument[0]);
buffer_write(_buf, buffer_s32, argument[1]);
buffer_write(_buf, buffer_s32, argument[2]);
buffer_write(_buf, buffer_f32, argument[3]);
if (argument_count >= 5) {
    buffer_write(_buf, buffer_bool, true);
    buffer_write(_buf, buffer_bool, argument[4]);
} else buffer_write(_buf, buffer_bool, false);
/*/
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
return pxtone_init_raw(buffer_get_address(_buf), 26);

#define pxtone_reset
/// pxtone_reset(channel_num:int, samples_per_sec:int, bits_per_sample:int, buffer_length_sec:number, directSound:bool = false)->bool
var _buf; _buf = pxtonegm_prepare_buffer(26);
// GMS >= 1:
buffer_write(_buf, buffer_u64, int64(window_handle()));
buffer_write(_buf, buffer_s32, argument[0]);
buffer_write(_buf, buffer_s32, argument[1]);
buffer_write(_buf, buffer_s32, argument[2]);
buffer_write(_buf, buffer_f32, argument[3]);
if (argument_count >= 5) {
    buffer_write(_buf, buffer_bool, true);
    buffer_write(_buf, buffer_bool, argument[4]);
} else buffer_write(_buf, buffer_bool, false);
/*/
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
return pxtone_reset_raw(buffer_get_address(_buf), 26);

#define pxtone_get_quality
/// pxtone_get_quality()->
var _buf; _buf = pxtonegm_prepare_buffer(16);
if (pxtone_get_quality_raw(buffer_get_address(_buf), 16)) {
    // GMS >= 1:
    var _struct_0 = array_create(4); // pxtone_quality
    _struct_0[0] = buffer_read(_buf, buffer_s32); // channel_num
    _struct_0[1] = buffer_read(_buf, buffer_s32); // samples_per_sec
    _struct_0[2] = buffer_read(_buf, buffer_s32); // bits_per_sample
    _struct_0[3] = buffer_read(_buf, buffer_s32); // sample_per_buf
    return _struct_0;
    /*/
    var _struct_0; _struct_0 = ds_list_create(); // pxtone_quality
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // channel_num
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // samples_per_sec
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // bits_per_sample
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // sample_per_buf
    return _struct_0;
    //*/
} else {
    // GMS >= 1:
    return undefined;
    /*/
    return -1;
    //*/
}

#define pxtone_load_ns
/// pxtone_load_ns(full_path:string)->bool
var _buf; _buf = pxtonegm_prepare_buffer(1);
return pxtone_load_ns_raw(buffer_get_address(_buf), 1, argument0);

#define pxtone_load_buffer
/// pxtone_load_buffer(buf:buffer, ?length:int?)->bool
var _buf; _buf = pxtonegm_prepare_buffer(22);
// GMS >= 1:
var _val_0 = argument[0];
if (buffer_exists(_val_0)) {
    buffer_write(_buf, buffer_u64, int64(buffer_get_address(_val_0)));
    buffer_write(_buf, buffer_s32, buffer_get_size(_val_0));
    buffer_write(_buf, buffer_s32, buffer_tell(_val_0));
} else {
    buffer_write(_buf, buffer_u64, 0);
    buffer_write(_buf, buffer_s32, 0);
    buffer_write(_buf, buffer_s32, 0);
}
if (argument_count >= 2) {
    buffer_write(_buf, buffer_bool, true);
    var _val_0 = argument[1];
    var _flag_0 = _val_0 != undefined;
    buffer_write(_buf, buffer_bool, _flag_0);
    if (_flag_0) {
        buffer_write(_buf, buffer_s32, _val_0);
    }
} else buffer_write(_buf, buffer_bool, false);
/*/
var _val_0 = argument[0];
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
//*/
return pxtone_load_buffer_raw(buffer_get_address(_buf), 22);

#define pxtone_start
/// pxtone_start(start_sample:int = 0, fadein_msec:int = 0)->bool
var _buf; _buf = pxtonegm_prepare_buffer(10);
if (argument_count >= 1) {
    buffer_write(_buf, buffer_bool, true);
    buffer_write(_buf, buffer_s32, argument[0]);
} else buffer_write(_buf, buffer_bool, false);
if (argument_count >= 2) {
    buffer_write(_buf, buffer_bool, true);
    buffer_write(_buf, buffer_s32, argument[1]);
} else buffer_write(_buf, buffer_bool, false);
return pxtone_start_raw(buffer_get_address(_buf), 10);

#define pxtone_fadeout
/// pxtone_fadeout(msec:int)->bool
var _buf; _buf = pxtonegm_prepare_buffer(4);
buffer_write(_buf, buffer_s32, argument0);
return pxtone_fadeout_raw(buffer_get_address(_buf), 4);

#define pxtone_set_loop
/// pxtone_set_loop(loop:bool)->bool
var _buf; _buf = pxtonegm_prepare_buffer(1);
buffer_write(_buf, buffer_bool, argument0);
return pxtone_set_loop_raw(buffer_get_address(_buf), 1);

#define pxtone_tune_get_info
/// pxtone_tune_get_info()->
var _buf; _buf = pxtonegm_prepare_buffer(16);
if (pxtone_tune_get_info_raw(buffer_get_address(_buf), 16)) {
    // GMS >= 1:
    var _struct_0 = array_create(4); // pxtone_tune_info
    _struct_0[0] = buffer_read(_buf, buffer_s32); // beat_num
    _struct_0[1] = buffer_read(_buf, buffer_f32); // beat_tempo
    _struct_0[2] = buffer_read(_buf, buffer_s32); // beat_clock
    _struct_0[3] = buffer_read(_buf, buffer_s32); // meas_num
    return _struct_0;
    /*/
    var _struct_0; _struct_0 = ds_list_create(); // pxtone_tune_info
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // beat_num
    ds_list_add(_struct_0, buffer_read(_buf, buffer_f32)); // beat_tempo
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // beat_clock
    ds_list_add(_struct_0, buffer_read(_buf, buffer_s32)); // meas_num
    return _struct_0;
    //*/
} else {
    // GMS >= 1:
    return undefined;
    /*/
    return -1;
    //*/
}

#define pxtone_tune_vomit
/// pxtone_tune_vomit(buf:buffer, sample_num:int)->bool 
var _buf; _buf = pxtonegm_prepare_buffer(20);
var _val_0 = argument0;
if (buffer_exists(_val_0)) {
    buffer_write(_buf, buffer_u64, int64(buffer_get_address(_val_0)));
    buffer_write(_buf, buffer_s32, buffer_get_size(_val_0));
    buffer_write(_buf, buffer_s32, buffer_tell(_val_0));
} else {
    buffer_write(_buf, buffer_u64, 0);
    buffer_write(_buf, buffer_s32, 0);
    buffer_write(_buf, buffer_s32, 0);
}
buffer_write(_buf, buffer_s32, argument1);
return pxtone_tune_vomit_raw(buffer_get_address(_buf), 20);

