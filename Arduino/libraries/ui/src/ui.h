// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_SplashSCR
void ui_SplashSCR_screen_init(void);
extern lv_obj_t * ui_SplashSCR;
extern lv_obj_t * ui_LoadingBAR;
extern lv_obj_t * ui_LoadinginfoLBL;
extern lv_obj_t * ui_VersionLBL;
extern lv_obj_t * ui_LogoIMG;
// SCREEN: ui_MainSCR
void ui_MainSCR_screen_init(void);
extern lv_obj_t * ui_MainSCR;
void ui_event_SettingBTN(lv_event_t * e);
extern lv_obj_t * ui_SettingBTN;
extern lv_obj_t * ui_SettingBTNLBL;
extern lv_obj_t * ui_DispenseBTN;
extern lv_obj_t * ui_DispenseBTNLBL;
void ui_event_TraycfgBTN(lv_event_t * e);
extern lv_obj_t * ui_TraycfgBTN;
extern lv_obj_t * ui_TraycfgBTNLBL;
extern lv_obj_t * ui_ClockLBL;
extern lv_obj_t * ui_WifiIconIMG;
extern lv_obj_t * ui_NoWifiIconIMG;
extern lv_obj_t * ui_PAGE1CON;
extern lv_obj_t * ui_BaseIMG;
extern lv_obj_t * ui_LCDLBL;
extern lv_obj_t * ui_TrayIMG1;
extern lv_obj_t * ui_TrayNumLBL1;
extern lv_obj_t * ui_TrayCheckIMG1;
extern lv_obj_t * ui_TrayLBL1;
extern lv_obj_t * ui_TrayIMG2;
extern lv_obj_t * ui_TrayNumLBL2;
extern lv_obj_t * ui_TrayLBL2;
extern lv_obj_t * ui_TrayCheckIMG2;
extern lv_obj_t * ui_TrayIMG3;
extern lv_obj_t * ui_TrayNumLBL3;
extern lv_obj_t * ui_TrayLBL3;
extern lv_obj_t * ui_TrayCheckIMG3;
extern lv_obj_t * ui_TrayIMG4;
extern lv_obj_t * ui_TrayNumLBL4;
extern lv_obj_t * ui_TrayLBL4;
extern lv_obj_t * ui_TrayCheckIMG4;
extern lv_obj_t * ui_TrayIMG5;
extern lv_obj_t * ui_TrayNumLBL5;
extern lv_obj_t * ui_TrayLBL5;
extern lv_obj_t * ui_TrayCheckIMG5;
void ui_event_UpIMGBTN(lv_event_t * e);
extern lv_obj_t * ui_UpIMGBTN;
extern lv_obj_t * ui_PAGE2CON;
extern lv_obj_t * ui_TopCapIMG;
void ui_event_DownIMGBTN(lv_event_t * e);
extern lv_obj_t * ui_DownIMGBTN;
extern lv_obj_t * ui_TrayIMG6;
extern lv_obj_t * ui_TrayNumLBL6;
extern lv_obj_t * ui_TrayLBL6;
extern lv_obj_t * ui_TrayCheckIMG6;
extern lv_obj_t * ui_TrayIMG7;
extern lv_obj_t * ui_TrayNumLBL7;
extern lv_obj_t * ui_TrayLBL7;
extern lv_obj_t * ui_TrayCheckIMG7;
extern lv_obj_t * ui_TrayIMG8;
extern lv_obj_t * ui_TrayNumLBL8;
extern lv_obj_t * ui_TrayLBL8;
extern lv_obj_t * ui_TrayCheckIMG8;
extern lv_obj_t * ui_TrayIMG9;
extern lv_obj_t * ui_TrayNumLBL9;
extern lv_obj_t * ui_TrayLBL9;
extern lv_obj_t * ui_TrayCheckIMG9;
extern lv_obj_t * ui_TrayIMG10;
extern lv_obj_t * ui_TrayNumLBL10;
extern lv_obj_t * ui_TrayLBL10;
extern lv_obj_t * ui_TrayCheckIMG10;
void ui_event_DismissBTN(lv_event_t * e);
extern lv_obj_t * ui_DismissBTN;
extern lv_obj_t * ui_DissmissBTNLBL;
extern lv_obj_t * ui_DismissPAN;
void ui_event_TrueDismissBTN(lv_event_t * e);
extern lv_obj_t * ui_TrueDismissBTN;
extern lv_obj_t * ui_TrueDissmissBTNLBL;
void ui_event_DismissCancelBTN(lv_event_t * e);
extern lv_obj_t * ui_DismissCancelBTN;
extern lv_obj_t * ui_DismissCancelBTNLBL;
extern lv_obj_t * ui_DismissLBL;
extern lv_obj_t * ui_DoubletakePAN;
void ui_event_DispenseAgainBTN(lv_event_t * e);
extern lv_obj_t * ui_DispenseAgainBTN;
extern lv_obj_t * ui_DispenseAgainBTNLBL;
void ui_event_DoubleDispenseCancelBTN(lv_event_t * e);
extern lv_obj_t * ui_DoubleDispenseCancelBTN;
extern lv_obj_t * ui_DoubleDispenseCancelBTNLBL;
extern lv_obj_t * ui_DoubleDispenseLBL;
// SCREEN: ui_WifiSCR
void ui_WifiSCR_screen_init(void);
extern lv_obj_t * ui_WifiSCR;
extern lv_obj_t * ui_SSIDDropDown;
extern lv_obj_t * ui_Keyboard;
extern lv_obj_t * ui_PassTxtBox;
extern lv_obj_t * ui_SSIDLBL;
extern lv_obj_t * ui_PassLBL;
extern lv_obj_t * ui_WIFILBL;
void ui_event_SkipWifiBTN(lv_event_t * e);
extern lv_obj_t * ui_SkipWifiBTN;
extern lv_obj_t * ui_SkipWifiBTNLBL;
extern lv_obj_t * ui_ScanWifiBTN;
extern lv_obj_t * ui_ScanWifiBTNLBL;
extern lv_obj_t * ui_WifiScanPAN;
extern lv_obj_t * ui_WifiScanPANLBL;
// SCREEN: ui_TrayConfigSCR
void ui_TrayConfigSCR_screen_init(void);
void ui_event_TrayConfigSCR(lv_event_t * e);
extern lv_obj_t * ui_TrayConfigSCR;
void ui_event_TrayCfgBackBTN(lv_event_t * e);
extern lv_obj_t * ui_TrayCfgBackBTN;
extern lv_obj_t * ui_TrayCfgBackLBL;
void ui_event_TraydescTXT(lv_event_t * e);
extern lv_obj_t * ui_TraydescTXT;
void ui_event_TrayCfgSaveBTN(lv_event_t * e);
extern lv_obj_t * ui_TrayCfgSaveBTN;
extern lv_obj_t * ui_TrayCfgSaveLBL;
extern lv_obj_t * ui_TrayHourDROP;
extern lv_obj_t * ui_TrayMinutesDROP;
extern lv_obj_t * ui_TrayAlertCHK;
extern lv_obj_t * ui_TrayRGBLBL;
extern lv_obj_t * ui_ColorRoller;
void ui_event_TrayCfgClearBTN(lv_event_t * e);
extern lv_obj_t * ui_TrayCfgClearBTN;
extern lv_obj_t * ui_TrayCfgClearLBL;
extern lv_obj_t * ui_ColorPanel;
extern lv_obj_t * ui_TrayDisplLBL;
extern lv_obj_t * ui_DisplaceTrayDROP;
extern lv_obj_t * ui_TrayDisplLBL1;
void ui_event_DisplaceBTN(lv_event_t * e);
extern lv_obj_t * ui_DisplaceBTN;
extern lv_obj_t * ui_DisplaceBTNLBL;
extern lv_obj_t * ui_TrayHalfStepLBL;
extern lv_obj_t * ui_HalfDisplaceBTN;
extern lv_obj_t * ui_HalfDisplaceBTNLBL;
extern lv_obj_t * ui_TraynotinstalledLBL;
void ui_event_Keyboard2(lv_event_t * e);
extern lv_obj_t * ui_Keyboard2;
extern lv_obj_t * ui_InprogressPAN;
extern lv_obj_t * ui_InprogressPANLBL;
// SCREEN: ui_ClockSCR
void ui_ClockSCR_screen_init(void);
void ui_event_ClockSCR(lv_event_t * e);
extern lv_obj_t * ui_ClockSCR;
extern lv_obj_t * ui_ClockSCRLBL;
extern lv_obj_t * ui_DateSCRLBL;
// SCREEN: ui_PickPillsSCR
void ui_PickPillsSCR_screen_init(void);
void ui_event_PickPillsSCR(lv_event_t * e);
extern lv_obj_t * ui_PickPillsSCR;
extern lv_obj_t * ui_TakepillsIMG;
// SCREEN: ui_BlankSCR
void ui_BlankSCR_screen_init(void);
void ui_event_BlankSCR(lv_event_t * e);
extern lv_obj_t * ui_BlankSCR;
// SCREEN: ui_SettingSCR
void ui_SettingSCR_screen_init(void);
extern lv_obj_t * ui_SettingSCR;
void ui_event_WifiBTN(lv_event_t * e);
extern lv_obj_t * ui_WifiBTN;
extern lv_obj_t * ui_WifiBTNLBL;
extern lv_obj_t * ui_WifiClearBTN;
extern lv_obj_t * ui_WifiClearBTNLBL;
void ui_event_UTCSlider(lv_event_t * e);
extern lv_obj_t * ui_UTCSlider;
extern lv_obj_t * ui_VolSlider;
extern lv_obj_t * ui_UTCLBL;
extern lv_obj_t * ui_VolLBL;
extern lv_obj_t * ui_MuteCHK;
extern lv_obj_t * ui_DSTCHK;
extern lv_obj_t * ui_SettingBackBTN;
extern lv_obj_t * ui_SettingBackBTNLBL;
extern lv_obj_t * ui_HowManyTrayDROP;
extern lv_obj_t * ui_InstalledTrayLBL;
extern lv_obj_t * ui_ScreensaverCHK1;
void ui_event_SettingBackBTN1(lv_event_t * e);
extern lv_obj_t * ui_SettingBackBTN1;
extern lv_obj_t * ui_SettingBackBTNLBL1;
extern lv_obj_t * ui_VolTestBTN;
extern lv_obj_t * ui_VolTestBTNLBL;
extern lv_obj_t * ui_DayHourDROP;
extern lv_obj_t * ui_DayMinutesDROP;
extern lv_obj_t * ui_StartofthedayLBL;
extern lv_obj_t * ui_WifiInfoLBL;
// SCREEN: ui_Setting2SCR
void ui_Setting2SCR_screen_init(void);
extern lv_obj_t * ui_Setting2SCR;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_apdlogo_png);    // assets/APDLogo.png
LV_IMG_DECLARE(ui_img_231307730);    // assets/Wifi-16.png
LV_IMG_DECLARE(ui_img_2117515183);    // assets/Nowifi-16.png
LV_IMG_DECLARE(ui_img_base_png);    // assets/Base.png
LV_IMG_DECLARE(ui_img_tray_png);    // assets/Tray.png
LV_IMG_DECLARE(ui_img_red_cross_png);    // assets/Red_Cross.png
LV_IMG_DECLARE(ui_img_green_check_png);    // assets/Green_Check.png
LV_IMG_DECLARE(ui_img_arrowupdown_png);    // assets/ArrowUpDown.png
LV_IMG_DECLARE(ui_img_topcap_png);    // assets/TopCap.png
LV_IMG_DECLARE(ui_img_arrowupdown2_png);    // assets/ArrowUpDown2.png
LV_IMG_DECLARE(ui_img_apd_takepills_png);    // assets/APD_Takepills.png



LV_FONT_DECLARE(ui_font_Datefont);
LV_FONT_DECLARE(ui_font_Timefont);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
