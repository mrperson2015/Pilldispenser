// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_TrayConfigSCR_screen_init(void)
{
    ui_TrayConfigSCR = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_TrayConfigSCR, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_TrayConfigSCR, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TrayConfigSCR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrayCfgBackBTN = lv_btn_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayCfgBackBTN, 68);
    lv_obj_set_height(ui_TrayCfgBackBTN, 36);
    lv_obj_set_x(ui_TrayCfgBackBTN, 3);
    lv_obj_set_y(ui_TrayCfgBackBTN, 3);
    lv_obj_clear_flag(ui_TrayCfgBackBTN,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_TrayCfgBackBTN, lv_color_hex(0x941818), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TrayCfgBackBTN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrayCfgBackLBL = lv_label_create(ui_TrayCfgBackBTN);
    lv_obj_set_width(ui_TrayCfgBackLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayCfgBackLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayCfgBackLBL, 0);
    lv_obj_set_y(ui_TrayCfgBackLBL, 1);
    lv_obj_set_align(ui_TrayCfgBackLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TrayCfgBackLBL, "Cancel");

    ui_TraydescTXT = lv_textarea_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TraydescTXT, 163);
    lv_obj_set_height(ui_TraydescTXT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TraydescTXT, 78);
    lv_obj_set_y(ui_TraydescTXT, 3);
    lv_textarea_set_max_length(ui_TraydescTXT, 15);
    lv_textarea_set_placeholder_text(ui_TraydescTXT, "Description...");
    lv_textarea_set_one_line(ui_TraydescTXT, true);
    lv_obj_set_style_border_color(ui_TraydescTXT, lv_color_hex(0x3175DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TraydescTXT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_TrayCfgSaveBTN = lv_btn_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayCfgSaveBTN, 68);
    lv_obj_set_height(ui_TrayCfgSaveBTN, 36);
    lv_obj_set_x(ui_TrayCfgSaveBTN, 247);
    lv_obj_set_y(ui_TrayCfgSaveBTN, 3);
    lv_obj_clear_flag(ui_TrayCfgSaveBTN,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_TrayCfgSaveBTN, lv_color_hex(0x3175DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TrayCfgSaveBTN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrayCfgSaveLBL = lv_label_create(ui_TrayCfgSaveBTN);
    lv_obj_set_width(ui_TrayCfgSaveLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayCfgSaveLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayCfgSaveLBL, 0);
    lv_obj_set_y(ui_TrayCfgSaveLBL, 1);
    lv_obj_set_align(ui_TrayCfgSaveLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TrayCfgSaveLBL, "Save");

    ui_TrayHourDROP = lv_dropdown_create(ui_TrayConfigSCR);
    lv_dropdown_set_options(ui_TrayHourDROP,
                            "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23");
    lv_obj_set_width(ui_TrayHourDROP, 60);
    lv_obj_set_height(ui_TrayHourDROP, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayHourDROP, 3);
    lv_obj_set_y(ui_TrayHourDROP, 45);
    lv_obj_add_flag(ui_TrayHourDROP, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_border_color(ui_TrayHourDROP, lv_color_hex(0x3175DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TrayHourDROP, 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_TrayMinutesDROP = lv_dropdown_create(ui_TrayConfigSCR);
    lv_dropdown_set_options(ui_TrayMinutesDROP, "00\n05\n10\n15\n20\n25\n30\n35\n40\n45\n50\n55\n");
    lv_obj_set_width(ui_TrayMinutesDROP, 60);
    lv_obj_set_height(ui_TrayMinutesDROP, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayMinutesDROP, 70);
    lv_obj_set_y(ui_TrayMinutesDROP, 45);
    lv_obj_add_flag(ui_TrayMinutesDROP, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_border_color(ui_TrayMinutesDROP, lv_color_hex(0x3175DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TrayMinutesDROP, 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_TrayAlertCHK = lv_checkbox_create(ui_TrayConfigSCR);
    lv_checkbox_set_text(ui_TrayAlertCHK, "Automatic Alert");
    lv_obj_set_width(ui_TrayAlertCHK, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayAlertCHK, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayAlertCHK, 139);
    lv_obj_set_y(ui_TrayAlertCHK, 53);
    lv_obj_add_flag(ui_TrayAlertCHK, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    lv_obj_set_style_border_color(ui_TrayAlertCHK, lv_color_hex(0x3175DE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TrayAlertCHK, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TrayAlertCHK, lv_color_hex(0x3175DE), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_TrayAlertCHK, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_TrayRGBLBL = lv_label_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayRGBLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayRGBLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayRGBLBL, 3);
    lv_obj_set_y(ui_TrayRGBLBL, 88);
    lv_label_set_text(ui_TrayRGBLBL, "User Color:");
    lv_obj_set_style_text_align(ui_TrayRGBLBL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ColorRoller = lv_roller_create(ui_TrayConfigSCR);
    lv_roller_set_options(ui_ColorRoller, "RED\nMAGENTA\nVIOLET\nBLUE\nCYAN\nGREEN\nYELLOW\nORANGE", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(ui_ColorRoller, 119);
    lv_obj_set_width(ui_ColorRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_ColorRoller, 3);
    lv_obj_set_y(ui_ColorRoller, 116);
    lv_obj_set_style_border_color(ui_ColorRoller, lv_color_hex(0x3175DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ColorRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ColorRoller, lv_color_hex(0x3971BD), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ColorRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_TrayCfgClearBTN = lv_btn_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayCfgClearBTN, 193);
    lv_obj_set_height(ui_TrayCfgClearBTN, 36);
    lv_obj_set_x(ui_TrayCfgClearBTN, 122);
    lv_obj_set_y(ui_TrayCfgClearBTN, 202);
    lv_obj_clear_flag(ui_TrayCfgClearBTN,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_TrayCfgClearBTN, lv_color_hex(0x941818), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TrayCfgClearBTN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrayCfgClearLBL = lv_label_create(ui_TrayCfgClearBTN);
    lv_obj_set_width(ui_TrayCfgClearLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayCfgClearLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayCfgClearLBL, 0);
    lv_obj_set_y(ui_TrayCfgClearLBL, 1);
    lv_obj_set_align(ui_TrayCfgClearLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TrayCfgClearLBL, "Clear Tray Config.");

    ui_ColorPanel = lv_obj_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_ColorPanel, 102);
    lv_obj_set_height(ui_ColorPanel, 21);
    lv_obj_set_x(ui_ColorPanel, -106);
    lv_obj_set_y(ui_ColorPanel, -3);
    lv_obj_set_align(ui_ColorPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ColorPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ColorPanel, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ColorPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ColorPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TrayDisplLBL = lv_label_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayDisplLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayDisplLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayDisplLBL, 122);
    lv_obj_set_y(ui_TrayDisplLBL, 99);
    lv_label_set_text(ui_TrayDisplLBL, "Tray Pos. Adjustement:");
    lv_obj_set_style_text_align(ui_TrayDisplLBL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DisplaceTrayDROP = lv_dropdown_create(ui_TrayConfigSCR);
    lv_dropdown_set_options(ui_DisplaceTrayDROP,
                            "E\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29");
    lv_obj_set_width(ui_DisplaceTrayDROP, 60);
    lv_obj_set_height(ui_DisplaceTrayDROP, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DisplaceTrayDROP, 122);
    lv_obj_set_y(ui_DisplaceTrayDROP, 119);
    lv_obj_add_flag(ui_DisplaceTrayDROP, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_border_color(ui_DisplaceTrayDROP, lv_color_hex(0x3175DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DisplaceTrayDROP, 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_TrayDisplLBL1 = lv_label_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayDisplLBL1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayDisplLBL1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayDisplLBL1, 191);
    lv_obj_set_y(ui_TrayDisplLBL1, 129);
    lv_label_set_text(ui_TrayDisplLBL1, "to 30");
    lv_obj_set_style_text_align(ui_TrayDisplLBL1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DisplaceBTN = lv_btn_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_DisplaceBTN, 79);
    lv_obj_set_height(ui_DisplaceBTN, 36);
    lv_obj_set_x(ui_DisplaceBTN, 236);
    lv_obj_set_y(ui_DisplaceBTN, 119);
    lv_obj_clear_flag(ui_DisplaceBTN, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_DisplaceBTN, lv_color_hex(0x3175DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DisplaceBTN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DisplaceBTNLBL = lv_label_create(ui_DisplaceBTN);
    lv_obj_set_width(ui_DisplaceBTNLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DisplaceBTNLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DisplaceBTNLBL, 0);
    lv_obj_set_y(ui_DisplaceBTNLBL, 1);
    lv_obj_set_align(ui_DisplaceBTNLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DisplaceBTNLBL, "Go");

    ui_TrayHalfStepLBL = lv_label_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TrayHalfStepLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TrayHalfStepLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TrayHalfStepLBL, 122);
    lv_obj_set_y(ui_TrayHalfStepLBL, 164);
    lv_label_set_text(ui_TrayHalfStepLBL, "Tray Aligment:\n(Half step)");
    lv_obj_set_style_text_align(ui_TrayHalfStepLBL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HalfDisplaceBTN = lv_btn_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_HalfDisplaceBTN, 79);
    lv_obj_set_height(ui_HalfDisplaceBTN, 36);
    lv_obj_set_x(ui_HalfDisplaceBTN, 236);
    lv_obj_set_y(ui_HalfDisplaceBTN, 161);
    lv_obj_clear_flag(ui_HalfDisplaceBTN,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_HalfDisplaceBTN, lv_color_hex(0x3175DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HalfDisplaceBTN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HalfDisplaceBTNLBL = lv_label_create(ui_HalfDisplaceBTN);
    lv_obj_set_width(ui_HalfDisplaceBTNLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HalfDisplaceBTNLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HalfDisplaceBTNLBL, 0);
    lv_obj_set_y(ui_HalfDisplaceBTNLBL, 1);
    lv_obj_set_align(ui_HalfDisplaceBTNLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HalfDisplaceBTNLBL, "Fix");

    ui_TraynotinstalledLBL = lv_label_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_TraynotinstalledLBL, 202);
    lv_obj_set_height(ui_TraynotinstalledLBL, 104);
    lv_obj_set_x(ui_TraynotinstalledLBL, 54);
    lv_obj_set_y(ui_TraynotinstalledLBL, 25);
    lv_obj_set_align(ui_TraynotinstalledLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TraynotinstalledLBL,
                      "Tray currently not \ninstalled, please change\ninstalled trays in settings.");
    lv_obj_add_flag(ui_TraynotinstalledLBL, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_TraynotinstalledLBL, lv_color_hex(0xDA1B1B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TraynotinstalledLBL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TraynotinstalledLBL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TraynotinstalledLBL, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TraynotinstalledLBL, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraynotinstalledLBL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Keyboard2 = lv_keyboard_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_Keyboard2, 320);
    lv_obj_set_height(ui_Keyboard2, 196);
    lv_obj_set_x(ui_Keyboard2, 2);
    lv_obj_set_y(ui_Keyboard2, 0);
    lv_obj_set_align(ui_Keyboard2, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_bg_color(ui_Keyboard2, lv_color_hex(0x292831), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Keyboard2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Keyboard2, lv_color_hex(0x3175DE), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Keyboard2, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);

    ui_InprogressPAN = lv_obj_create(ui_TrayConfigSCR);
    lv_obj_set_width(ui_InprogressPAN, 312);
    lv_obj_set_height(ui_InprogressPAN, 235);
    lv_obj_set_x(ui_InprogressPAN, -1);
    lv_obj_set_y(ui_InprogressPAN, -1);
    lv_obj_set_align(ui_InprogressPAN, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_InprogressPAN, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_InprogressPAN, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_InprogressPANLBL = lv_label_create(ui_InprogressPAN);
    lv_obj_set_width(ui_InprogressPANLBL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_InprogressPANLBL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_InprogressPANLBL, LV_ALIGN_CENTER);
    lv_label_set_text(ui_InprogressPANLBL, "Please wait...\n\nAdjustement in progress");
    lv_obj_set_style_text_align(ui_InprogressPANLBL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_TrayCfgBackBTN, ui_event_TrayCfgBackBTN, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TraydescTXT, ui_event_TraydescTXT, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TrayCfgSaveBTN, ui_event_TrayCfgSaveBTN, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TrayCfgClearBTN, ui_event_TrayCfgClearBTN, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DisplaceBTN, ui_event_DisplaceBTN, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard2, ui_TraydescTXT);
    lv_obj_add_event_cb(ui_Keyboard2, ui_event_Keyboard2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TrayConfigSCR, ui_event_TrayConfigSCR, LV_EVENT_ALL, NULL);

}
