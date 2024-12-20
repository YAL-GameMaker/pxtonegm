#define pxtone_load
/// (path)
// GMS >= 1:
var _buf = buffer_load(argument0);
var _result = pxtone_load_buffer(_buf);
buffer_delete(_buf);
return _result;
/*/
return pxtone_load_ns(argument0);
//*/

// GMS >= 1:
#define pxtonegm_prepare_buffer
/// (size:int)->buffer~
var _size = argument0;
gml_pragma("global", "global.__pxtonegm_buffer = undefined");
var _buf = global.__pxtonegm_buffer;
if (_buf == undefined) {
    _buf = buffer_create(_size, buffer_grow, 1);
    global.__pxtonegm_buffer = _buf;
} else if (buffer_get_size(_buf) < _size) {
    buffer_resize(_buf, _size);
}
buffer_seek(_buf, buffer_seek_start, 0);
return _buf;
//*/