SET(SOURCES screens/ui_SplashSCR.c
    screens/ui_MainSCR.c
    screens/ui_WifiSCR.c
    screens/ui_TrayConfigSCR.c
    screens/ui_ClockSCR.c
    screens/ui_PickPillsSCR.c
    screens/ui_BlankSCR.c
    screens/ui_SettingSCR.c
    screens/ui_LockSCR.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_apdlogo_png.c
    images/ui_img_231307730.c
    images/ui_img_2117515183.c
    images/ui_img_base_png.c
    images/ui_img_tray_png.c
    images/ui_img_red_cross_png.c
    images/ui_img_green_check_png.c
    images/ui_img_arrowupdown_png.c
    images/ui_img_topcap_png.c
    images/ui_img_arrowupdown2_png.c
    images/ui_img_apd_takepills_png.c
    fonts/ui_font_Datefont.c
    fonts/ui_font_Timefont.c)

add_library(ui ${SOURCES})
