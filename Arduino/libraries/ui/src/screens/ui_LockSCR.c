// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_LockSCR_screen_init(void)
{
    ui_LockSCR = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LockSCR, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_LockSCR, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LockSCR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PassKey = lv_keyboard_create(ui_LockSCR);
    lv_keyboard_set_mode(ui_PassKey, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_PassKey, 320);
    lv_obj_set_height(ui_PassKey, 240);
    lv_obj_set_align(ui_PassKey, LV_ALIGN_CENTER);

    ui_PassTXT = lv_textarea_create(ui_LockSCR);
    lv_obj_set_width(ui_PassTXT, 124);
    lv_obj_set_height(ui_PassTXT, 56);
    lv_obj_set_x(ui_PassTXT, 96);
    lv_obj_set_y(ui_PassTXT, -90);
    lv_obj_set_align(ui_PassTXT, LV_ALIGN_CENTER);
    if("0123456789" == "") lv_textarea_set_accepted_chars(ui_PassTXT, NULL);
    else lv_textarea_set_accepted_chars(ui_PassTXT, "0123456789");
    lv_textarea_set_max_length(ui_PassTXT, 6);
    lv_textarea_set_placeholder_text(ui_PassTXT, "Passcode");
    lv_textarea_set_password_mode(ui_PassTXT, true);
    lv_obj_set_style_text_letter_space(ui_PassTXT, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_PassTXT, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PassTXT, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PassTXT, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PassTXT, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PassTXT, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PassTXT, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    lv_keyboard_set_textarea(ui_PassKey, ui_PassTXT);

}