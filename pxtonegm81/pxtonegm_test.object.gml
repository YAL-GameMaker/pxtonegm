#event create
pxtone_init_wrapper();
pxtone_init(2, 44100, 16, 0.2);
trace(pxtone_get_spb());
file_list = ds_list_create();
file_folder = "tunes";
var name = file_find_first(file_folder + "/*.ptcop", 0);
while (name != "") {
	trace("+", name);
	ds_list_add(file_list, name);
	name = file_find_next();
}
file_find_close();
file_index = 0;
file_count = ds_list_size(file_list);
alarm[0] = 1

#event alarm0
//pxtone_load("test/opening.ptcop");
if (file_count == 0) exit;
if (file_index >= file_count) {
	//exit;
	file_index = 0;
}
var rel = ds_list_find_value(file_list, file_index);
trace("rel", rel);
var path = file_folder + "/" + rel;
file_index += 1;
var ok = pxtone_load(path);
pxtone_start(0, 0);
room_speed = 60;
playing = true;
start_at = 0;
//alarm[1] = room_speed;
trace("path", path, file_exists(path));
if (!ok) {
	trace("error", pxtone_last_error());
	exit;
}
trace("ok", ok);
trace("name", pxtone_get_name());
trace("comment", pxtone_get_comment());
trace("pxtone_get_repeat_measure", pxtone_get_repeat_measure());
trace("pxtone_get_play_measure", pxtone_get_play_measure());
trace("pxtone_get_sps", pxtone_get_sps());
trace("pxtone_get_bps", pxtone_get_bps());
trace("pxtone_get_spb", pxtone_get_spb());
trace("pxtone_get_beat_number", pxtone_get_beat_number());
trace("pxtone_get_beat_tempo", pxtone_get_beat_tempo());
trace("pxtone_get_beat_clock", pxtone_get_beat_clock());

#event alarm1
start_at = pxtone_stop();
trace("sample", start_at);
trace("clock", pxtone_get_clock());
trace("ratio", start_at / pxtone_get_clock());
alarm[0] = 60;

#event other_user0

#event step
if (keyboard_check_pressed(vk_space)) {
    if (playing) {
        playing = false;
        start_at = pxtone_stop();
        trace(start_at);
    } else {
        playing = true;
        pxtone_start(start_at, 0);
    }
}

#event keypress:vk_enter
alarm[1] = 1;
