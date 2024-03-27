// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_SplashSCR
void ui_SplashSCR_screen_init(void);
lv_obj_t * ui_SplashSCR;
lv_obj_t * ui_LoadingBAR;
lv_obj_t * ui_LoadinginfoLBL;
lv_obj_t * ui_VersionLBL;
lv_obj_t * ui_LogoIMG;


// SCREEN: ui_MainSCR
void ui_MainSCR_screen_init(void);
lv_obj_t * ui_MainSCR;
void ui_event_SettingBTN(lv_event_t * e);
lv_obj_t * ui_SettingBTN;
lv_obj_t * ui_SettingBTNLBL;
lv_obj_t * ui_DispenseBTN;
lv_obj_t * ui_DispenseBTNLBL;
void ui_event_TraycfgBTN(lv_event_t * e);
lv_obj_t * ui_TraycfgBTN;
lv_obj_t * ui_TraycfgBTNLBL;
lv_obj_t * ui_ClockLBL;
lv_obj_t * ui_WifiIconIMG;
lv_obj_t * ui_NoWifiIconIMG;
lv_obj_t * ui_PAGE1CON;
lv_obj_t * ui_BaseIMG;
lv_obj_t * ui_TrayIMG1;
lv_obj_t * ui_TrayNumLBL1;
lv_obj_t * ui_TrayCheckIMG1;
lv_obj_t * ui_TrayLBL1;
lv_obj_t * ui_TrayIMG2;
lv_obj_t * ui_TrayNumLBL2;
lv_obj_t * ui_TrayLBL2;
lv_obj_t * ui_TrayCheckIMG2;
lv_obj_t * ui_TrayIMG3;
lv_obj_t * ui_TrayNumLBL3;
lv_obj_t * ui_TrayLBL3;
lv_obj_t * ui_TrayCheckIMG3;
lv_obj_t * ui_TrayIMG4;
lv_obj_t * ui_TrayNumLBL4;
lv_obj_t * ui_TrayLBL4;
lv_obj_t * ui_TrayCheckIMG4;
lv_obj_t * ui_TrayIMG5;
lv_obj_t * ui_TrayNumLBL5;
lv_obj_t * ui_TrayLBL5;
lv_obj_t * ui_TrayCheckIMG5;
void ui_event_UpIMGBTN(lv_event_t * e);
lv_obj_t * ui_UpIMGBTN;
lv_obj_t * ui_PAGE2CON;
lv_obj_t * ui_TopCapIMG;
void ui_event_DownIMGBTN(lv_event_t * e);
lv_obj_t * ui_DownIMGBTN;
lv_obj_t * ui_TrayIMG6;
lv_obj_t * ui_TrayNumLBL6;
lv_obj_t * ui_TrayLBL6;
lv_obj_t * ui_TrayCheckIMG6;
lv_obj_t * ui_TrayIMG7;
lv_obj_t * ui_TrayNumLBL7;
lv_obj_t * ui_TrayLBL7;
lv_obj_t * ui_TrayCheckIMG7;
lv_obj_t * ui_TrayIMG8;
lv_obj_t * ui_TrayNumLBL8;
lv_obj_t * ui_TrayLBL8;
lv_obj_t * ui_TrayCheckIMG8;
lv_obj_t * ui_TrayIMG9;
lv_obj_t * ui_TrayNumLBL9;
lv_obj_t * ui_TrayLBL9;
lv_obj_t * ui_TrayCheckIMG9;
lv_obj_t * ui_TrayIMG10;
lv_obj_t * ui_TrayNumLBL10;
lv_obj_t * ui_TrayLBL10;
lv_obj_t * ui_TrayCheckIMG10;
void ui_event_DismissBTN(lv_event_t * e);
lv_obj_t * ui_DismissBTN;
lv_obj_t * ui_DissmissBTNLBL;
lv_obj_t * ui_DismissPAN;
void ui_event_TrueDismissBTN(lv_event_t * e);
lv_obj_t * ui_TrueDismissBTN;
lv_obj_t * ui_TrueDissmissBTNLBL;
void ui_event_DismissCancelBTN(lv_event_t * e);
lv_obj_t * ui_DismissCancelBTN;
lv_obj_t * ui_DismissCancelBTNLBL;
lv_obj_t * ui_DismissLBL;
lv_obj_t * ui_DoubletakePAN;
void ui_event_DispenseAgainBTN(lv_event_t * e);
lv_obj_t * ui_DispenseAgainBTN;
lv_obj_t * ui_DispenseAgainBTNLBL;
void ui_event_DoubleDispenseCancelBTN(lv_event_t * e);
lv_obj_t * ui_DoubleDispenseCancelBTN;
lv_obj_t * ui_DoubleDispenseCancelBTNLBL;
lv_obj_t * ui_DoubleDispenseLBL;


// SCREEN: ui_WifiSCR
void ui_WifiSCR_screen_init(void);
lv_obj_t * ui_WifiSCR;
lv_obj_t * ui_SSIDDropDown;
lv_obj_t * ui_Keyboard;
lv_obj_t * ui_PassTxtBox;
lv_obj_t * ui_SSIDLBL;
lv_obj_t * ui_PassLBL;
lv_obj_t * ui_WIFILBL;
void ui_event_SkipWifiBTN(lv_event_t * e);
lv_obj_t * ui_SkipWifiBTN;
lv_obj_t * ui_SkipWifiBTNLBL;
lv_obj_t * ui_ScanWifiBTN;
lv_obj_t * ui_ScanWifiBTNLBL;
lv_obj_t * ui_WifiScanPAN;
lv_obj_t * ui_WifiScanPANLBL;


// SCREEN: ui_SettingSCR
void ui_SettingSCR_screen_init(void);
lv_obj_t * ui_SettingSCR;
void ui_event_WifiBTN(lv_event_t * e);
lv_obj_t * ui_WifiBTN;
lv_obj_t * ui_WifiBTNLBL;
lv_obj_t * ui_WifiClearBTN;
lv_obj_t * ui_WifiClearBTNLBL;
void ui_event_UTCSlider(lv_event_t * e);
lv_obj_t * ui_UTCSlider;
lv_obj_t * ui_VolSlider;
lv_obj_t * ui_UTCLBL;
lv_obj_t * ui_VolLBL;
lv_obj_t * ui_MuteCHK;
lv_obj_t * ui_DSTCHK;
lv_obj_t * ui_SettingBackBTN;
lv_obj_t * ui_SettingBackBTNLBL;
lv_obj_t * ui_HowManyTrayDROP;
lv_obj_t * ui_InstalledTrayLBL;
lv_obj_t * ui_ScreensaverCHK1;
void ui_event_SettingBackBTN1(lv_event_t * e);
lv_obj_t * ui_SettingBackBTN1;
lv_obj_t * ui_SettingBackBTNLBL1;
lv_obj_t * ui_VolTestBTN;
lv_obj_t * ui_VolTestBTNLBL;
lv_obj_t * ui_DayHourDROP;
lv_obj_t * ui_DayMinutesDROP;
lv_obj_t * ui_StartofthedayLBL;
lv_obj_t * ui_WifiInfoLBL;


// SCREEN: ui_TrayConfigSCR
void ui_TrayConfigSCR_screen_init(void);
void ui_event_TrayConfigSCR(lv_event_t * e);
lv_obj_t * ui_TrayConfigSCR;
void ui_event_TrayCfgBackBTN(lv_event_t * e);
lv_obj_t * ui_TrayCfgBackBTN;
lv_obj_t * ui_TrayCfgBackLBL;
void ui_event_TraydescTXT(lv_event_t * e);
lv_obj_t * ui_TraydescTXT;
void ui_event_TrayCfgSaveBTN(lv_event_t * e);
lv_obj_t * ui_TrayCfgSaveBTN;
lv_obj_t * ui_TrayCfgSaveLBL;
lv_obj_t * ui_TrayHourDROP;
lv_obj_t * ui_TrayMinutesDROP;
lv_obj_t * ui_TraynotinstalledLBL;
lv_obj_t * ui_TrayAlertCHK;
lv_obj_t * ui_TrayRGBLBL;
lv_obj_t * ui_ColorRoller;
void ui_event_TrayCfgClearBTN(lv_event_t * e);
lv_obj_t * ui_TrayCfgClearBTN;
lv_obj_t * ui_TrayCfgClearLBL;
lv_obj_t * ui_ColorPanel;
lv_obj_t * ui_DisplaceTrayDROP;
lv_obj_t * ui_TrayDisplLBL;
lv_obj_t * ui_TrayDisplLBL1;
void ui_event_DisplaceBTN(lv_event_t * e);
lv_obj_t * ui_DisplaceBTN;
lv_obj_t * ui_DisplaceBTNLBL;
void ui_event_Keyboard2(lv_event_t * e);
lv_obj_t * ui_Keyboard2;
lv_obj_t * ui_InprogressPAN;
lv_obj_t * ui_InprogressPANLBL;


// SCREEN: ui_ClockSCR
void ui_ClockSCR_screen_init(void);
void ui_event_ClockSCR(lv_event_t * e);
lv_obj_t * ui_ClockSCR;
lv_obj_t * ui_ClockSCRLBL;
lv_obj_t * ui_DateSCRLBL;


// SCREEN: ui_PickPillsSCR
void ui_PickPillsSCR_screen_init(void);
void ui_event_PickPillsSCR(lv_event_t * e);
lv_obj_t * ui_PickPillsSCR;
lv_obj_t * ui_TakepillsIMG;


// SCREEN: ui_BlankSCR
void ui_BlankSCR_screen_init(void);
void ui_event_BlankSCR(lv_event_t * e);
lv_obj_t * ui_BlankSCR;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_arrowupdown[1] = {&ui_img_arrowupdown2_png};
const lv_img_dsc_t * ui_imgset_870338999[1] = {&ui_img_2117515183};
const lv_img_dsc_t * ui_imgset_1675751314[1] = {&ui_img_231307730};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_SettingBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_SettingSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_SettingSCR_screen_init);
    }
}
void ui_event_TraycfgBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_TrayConfigSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_TrayConfigSCR_screen_init);
    }
}
void ui_event_UpIMGBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_PAGE2CON, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_PAGE1CON, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_TrayIMG1, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG2, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG3, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG4, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG5, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
void ui_event_DownIMGBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_PAGE1CON, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_PAGE2CON, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_TrayIMG10, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG9, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG8, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG7, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_TrayIMG6, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}
void ui_event_DismissBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_DismissPAN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_TrueDismissBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_DismissPAN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_DismissBTN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_DismissCancelBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_DismissPAN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_DispenseAgainBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_DoubletakePAN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_DoubleDispenseCancelBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_DoubletakePAN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_SkipWifiBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_SettingSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_SettingSCR_screen_init);
    }
}
void ui_event_WifiBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_WifiSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_WifiSCR_screen_init);
    }
}
void ui_event_UTCSlider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_UTCLBL, target, "UTC Offset: ", "");
    }
}
void ui_event_SettingBackBTN1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
    }
}
void ui_event_TrayConfigSCR(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_TrayCfgBackBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_TraydescTXT(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_keyboard_set_target(ui_Keyboard2,  ui_TraydescTXT);
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_TrayCfgSaveBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_TrayCfgClearBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
    }
}
void ui_event_DisplaceBTN(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_InprogressPAN, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Keyboard2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_KEY &&  lv_event_get_key(e) == LV_KEY_ENTER) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    if(event_code == LV_EVENT_READY) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    if(event_code == LV_EVENT_CANCEL) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_ClockSCR(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
    }
}
void ui_event_PickPillsSCR(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
    }
}
void ui_event_BlankSCR(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_MainSCR, LV_SCR_LOAD_ANIM_NONE, 100, 0, &ui_MainSCR_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_SplashSCR_screen_init();
    ui_MainSCR_screen_init();
    ui_WifiSCR_screen_init();
    ui_SettingSCR_screen_init();
    ui_TrayConfigSCR_screen_init();
    ui_ClockSCR_screen_init();
    ui_PickPillsSCR_screen_init();
    ui_BlankSCR_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_SplashSCR);
}
