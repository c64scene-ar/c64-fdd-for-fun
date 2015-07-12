
#include "vice.h"

#ifndef WINDOWS_RC_COMPILE
#define WINDOWS_RC_COMPILE
#endif

#ifdef IDE_COMPILE
#include <winuser.h>
#endif

#include "debug.h"
#include "res.h"
#include "rescommon.h"

#ifdef IDE_COMPILE
#include "videoarch.h"
#endif

#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


#define FILE_DESCRIPTION  "Vice C128 Emulator"


IDR_MENUC128 MENU DISCARDABLE
BEGIN
    POPUP N_("File")
    BEGIN
        MENUITEM "", IDM_AUTOSTART
        MENUITEM SEPARATOR
        POPUP N_("Attach disk image")
        BEGIN
            MENUITEM "", IDM_ATTACH_8
            MENUITEM "", IDM_ATTACH_9
            MENUITEM "", IDM_ATTACH_10
            MENUITEM "", IDM_ATTACH_11
        END
        POPUP N_("Detach disk image")
        BEGIN
            MENUITEM "", IDM_DETACH_8
            MENUITEM "", IDM_DETACH_9
            MENUITEM "", IDM_DETACH_10
            MENUITEM "", IDM_DETACH_11
            MENUITEM SEPARATOR
            MENUITEM "", IDM_DETACH_ALL
        END
        POPUP N_("Flip list")
        BEGIN
            MENUITEM "", IDM_FLIP_ADD
            MENUITEM "", IDM_FLIP_REMOVE
            MENUITEM "", IDM_FLIP_NEXT
            MENUITEM "", IDM_FLIP_PREVIOUS
            MENUITEM SEPARATOR
            MENUITEM "", IDM_FLIP_LOAD
            MENUITEM "", IDM_FLIP_SAVE
        END
        MENUITEM SEPARATOR
        MENUITEM "", IDM_ATTACH_TAPE
        MENUITEM "", IDM_DETACH_TAPE
        POPUP N_("Datassette control")
        BEGIN
            MENUITEM "", IDM_DATASETTE_CONTROL_STOP
            MENUITEM "", IDM_DATASETTE_CONTROL_START
            MENUITEM "", IDM_DATASETTE_CONTROL_FORWARD
            MENUITEM "", IDM_DATASETTE_CONTROL_REWIND
            MENUITEM "", IDM_DATASETTE_CONTROL_RECORD
            MENUITEM "", IDM_DATASETTE_CONTROL_RESET
            MENUITEM "", IDM_DATASETTE_RESET_COUNTER
        END
        MENUITEM SEPARATOR
        POPUP N_("Attach cartridge image")
        BEGIN
            MENUITEM "", IDM_CART_ATTACH_CRT
            MENUITEM SEPARATOR
            MENUITEM "", IDM_CART_ATTACH_8KB
            MENUITEM "", IDM_CART_ATTACH_16KB
            MENUITEM SEPARATOR
            MENUITEM "", IDM_CART_ATTACH_AR
            MENUITEM "", IDM_CART_ATTACH_AR3
            MENUITEM "", IDM_CART_ATTACH_AR4
            MENUITEM "", IDM_CART_ATTACH_AT
            MENUITEM "", IDM_CART_ATTACH_EPYX
            MENUITEM "", IDM_CART_ATTACH_IDE64
            MENUITEM "", IDM_CART_ATTACH_IEEE488
            MENUITEM "", IDM_CART_ATTACH_MMC_REPLAY
            MENUITEM "", IDM_CART_ATTACH_RR
            MENUITEM "", IDM_CART_ATTACH_STARDOS
            MENUITEM "", IDM_CART_ATTACH_STB
            MENUITEM "", IDM_CART_ATTACH_SS4
            MENUITEM "", IDM_CART_ATTACH_SS5
            MENUITEM SEPARATOR
            MENUITEM "", IDM_CART_SET_DEFAULT
        END
        MENUITEM "", IDM_CART_DETACH
        MENUITEM "", IDM_CART_FREEZE
        MENUITEM SEPARATOR
        MENUITEM "", IDM_MONITOR
        MENUITEM SEPARATOR
        MENUITEM "", IDM_NETWORK_SETTINGS
        MENUITEM SEPARATOR
        POPUP N_("Reset")
        BEGIN
            MENUITEM "", IDM_RESET_HARD
            MENUITEM "", IDM_RESET_SOFT
            MENUITEM SEPARATOR
            MENUITEM "", IDM_RESET_DRIVE8
            MENUITEM "", IDM_RESET_DRIVE9
            MENUITEM "", IDM_RESET_DRIVE10
            MENUITEM "", IDM_RESET_DRIVE11
        END
        POPUP N_("Default CPU JAM action")
        BEGIN
            MENUITEM "", IDM_JAM_ACTION_ASK
            MENUITEM "", IDM_JAM_ACTION_CONTINUE
            MENUITEM "", IDM_JAM_ACTION_START_MONITOR
            MENUITEM "", IDM_JAM_ACTION_RESET
            MENUITEM "", IDM_JAM_ACTION_HARD_RESET
            MENUITEM "", IDM_JAM_ACTION_QUIT_EMULATOR
        END
#ifdef DEBUG
        POPUP N_("Debug")
        BEGIN
            POPUP N_("Mode")
            BEGIN
                MENUITEM "", IDM_DEBUG_MODE_NORMAL
                MENUITEM "", IDM_DEBUG_MODE_SMALL
                MENUITEM "", IDM_DEBUG_MODE_HISTORY
                MENUITEM "", IDM_DEBUG_MODE_AUTOPLAY
            END
            MENUITEM "", IDM_TOGGLE_MAINCPU_TRACE,   CHECKED
            MENUITEM "", IDM_TOGGLE_DRIVE0CPU_TRACE, CHECKED
            MENUITEM "", IDM_TOGGLE_DRIVE1CPU_TRACE, CHECKED
        END
#endif
        MENUITEM SEPARATOR
        MENUITEM "", IDM_EXIT
    END
    POPUP N_("Edit")
    BEGIN
        MENUITEM "", IDM_EDIT_COPY
        MENUITEM "", IDM_EDIT_PASTE
    END
    POPUP N_("Snapshot")
    BEGIN
        MENUITEM "", IDM_SNAPSHOT_LOAD
        MENUITEM "", IDM_SNAPSHOT_SAVE
        MENUITEM "", IDM_LOADQUICK
        MENUITEM "", IDM_SAVEQUICK
        MENUITEM SEPARATOR
        MENUITEM "", IDM_EVENT_TOGGLE_RECORD
        MENUITEM "", IDM_EVENT_TOGGLE_PLAYBACK
        MENUITEM "", IDM_EVENT_SETMILESTONE
        MENUITEM "", IDM_EVENT_RESETMILESTONE
        POPUP N_("Recording start mode")
        BEGIN
            MENUITEM "", IDM_EVENT_START_MODE_SAVE
            MENUITEM "", IDM_EVENT_START_MODE_LOAD
            MENUITEM "", IDM_EVENT_START_MODE_RESET
            MENUITEM "", IDM_EVENT_START_MODE_PLAYBACK
        END
        MENUITEM "", IDM_EVENT_DIRECTORY
        MENUITEM SEPARATOR
        MENUITEM "", IDM_MEDIAFILE
        MENUITEM SEPARATOR
        MENUITEM "", IDM_SOUND_RECORD_START
        MENUITEM "", IDM_SOUND_RECORD_STOP
    END
    POPUP N_("Settings")
    BEGIN
        POPUP N_("Refresh rate")
        BEGIN
            MENUITEM "", IDM_REFRESH_RATE_AUTO
            MENUITEM "", IDM_REFRESH_RATE_1
            MENUITEM "", IDM_REFRESH_RATE_2
            MENUITEM "", IDM_REFRESH_RATE_3
            MENUITEM "", IDM_REFRESH_RATE_4
            MENUITEM "", IDM_REFRESH_RATE_5
            MENUITEM "", IDM_REFRESH_RATE_6
            MENUITEM "", IDM_REFRESH_RATE_7
            MENUITEM "", IDM_REFRESH_RATE_8
            MENUITEM "", IDM_REFRESH_RATE_9
            MENUITEM "", IDM_REFRESH_RATE_10
        END
        POPUP N_("Maximum speed")
        BEGIN
            MENUITEM "", IDM_MAXIMUM_SPEED_200
            MENUITEM "", IDM_MAXIMUM_SPEED_100
            MENUITEM "", IDM_MAXIMUM_SPEED_50
            MENUITEM "", IDM_MAXIMUM_SPEED_20
            MENUITEM "", IDM_MAXIMUM_SPEED_10
            MENUITEM "", IDM_MAXIMUM_SPEED_NO_LIMIT
            MENUITEM SEPARATOR
            MENUITEM "", IDM_MAXIMUM_SPEED_CUSTOM
        END
        MENUITEM "", IDM_PAUSE, CHECKED
        MENUITEM "", IDM_TOGGLE_WARP_MODE,  CHECKED
        MENUITEM SEPARATOR
        MENUITEM "", IDM_KEYBOARD_SETTINGS
        POPUP N_("Sound settings")
        BEGIN
            MENUITEM "", IDM_TOGGLE_SOUND,                CHECKED
            MENUITEM SEPARATOR
            MENUITEM "", IDM_SOUND_SETTINGS
        END
        MENUITEM SEPARATOR
        MENUITEM "", IDM_AUTOSTART_SETTINGS
        MENUITEM "", IDM_DATASETTE_SETTINGS
        POPUP N_("Drive settings")
        BEGIN
            MENUITEM "", IDM_TOGGLE_DRIVE_TRUE_EMULATION, CHECKED
            MENUITEM "", IDM_TOGGLE_DRIVE_SOUND_EMULATION, CHECKED
            MENUITEM SEPARATOR
            MENUITEM "", IDM_DRIVE_SETTINGS
        END
        MENUITEM "", IDM_DEVICEMANAGER
        MENUITEM "", IDM_TOGGLE_VIRTUAL_DEVICES
        MENUITEM SEPARATOR
        POPUP N_("Joystick settings")
        BEGIN
            MENUITEM "", IDM_JOY_SETTINGS
            MENUITEM "", IDM_EXTRA_JOY_SETTINGS
            MENUITEM SEPARATOR
            MENUITEM "", IDM_SWAP_JOYSTICK
            MENUITEM "", IDM_SWAP_EXTRA_JOYSTICK
            MENUITEM "", IDM_ALLOW_JOY_OPPOSITE_TOGGLE
            MENUITEM "", IDM_JOYKEYS_TOGGLE
        END
        POPUP N_("Mouse settings")
        BEGIN
            MENUITEM "", IDM_MOUSE_SETTINGS
            MENUITEM "", IDM_MOUSE
        END
        MENUITEM "", IDM_LIGHTPEN_SETTINGS
        MENUITEM SEPARATOR
        MENUITEM "", IDM_VIDEO_SETTINGS
        MENUITEM "", IDM_TOGGLE_FULLSCREEN
        MENUITEM "", IDM_TOGGLE_ALWAYSONTOP
        MENUITEM SEPARATOR
        MENUITEM "", IDM_C128MODEL_SETTINGS
        MENUITEM "", IDM_C128_SETTINGS
        MENUITEM "", IDM_RAM_SETTINGS
        MENUITEM "", IDM_ROM_SETTINGS
        MENUITEM "", IDM_VICII_SETTINGS
        POPUP N_("VDC settings")
        BEGIN
            MENUITEM "", IDM_TOGGLE_VDC64KB
            MENUITEM SEPARATOR
            POPUP N_("VDC revision")
            BEGIN
                MENUITEM N_("Rev 0"), IDM_VDC_REV_0
                MENUITEM N_("Rev 1"), IDM_VDC_REV_1
                MENUITEM N_("Rev 2"), IDM_VDC_REV_2
            END
        END
        MENUITEM "", IDM_SID_SETTINGS
        MENUITEM "", IDM_CIA_SETTINGS
        MENUITEM SEPARATOR
        POPUP N_("Cartridge/IO settings")
        BEGIN
            MENUITEM "", IDM_GEORAM_SETTINGS
            MENUITEM "", IDM_REU_SETTINGS
            MENUITEM "", IDM_RAMCART_SETTINGS
            MENUITEM SEPARATOR
            MENUITEM "", IDM_DQBB_SETTINGS
            MENUITEM "", IDM_EXPERT_SETTINGS
            MENUITEM "", IDM_ISEPIC_SETTINGS
            MENUITEM SEPARATOR
            MENUITEM "", IDM_EASYFLASH_SETTINGS
            MENUITEM "", IDM_IDE64_SETTINGS
            MENUITEM "", IDM_MMC64_SETTINGS
            MENUITEM "", IDM_MMCREPLAY_SETTINGS
            MENUITEM "", IDM_RR_SETTINGS
            MENUITEM SEPARATOR
#ifdef HAVE_TFE
            MENUITEM "", IDM_TFE_SETTINGS
#endif
            MENUITEM "", IDM_IEEE488
            MENUITEM SEPARATOR
            MENUITEM "", IDM_DIGIMAX_SETTINGS
            MENUITEM "", IDM_MAGICVOICE_SETTINGS
            MENUITEM "", IDM_MIDI_SETTINGS
            MENUITEM "", IDM_SFX_SE_SETTINGS
            MENUITEM "", IDM_TOGGLE_SFX_SS
            MENUITEM SEPARATOR
            MENUITEM "", IDM_DS12C887RTC_SETTINGS
            MENUITEM "", IDM_TOGGLE_USERPORT_RTC
            MENUITEM SEPARATOR
            MENUITEM "", IDM_TOGGLE_CART_RESET
        END
        POPUP N_("RS232 settings")
        BEGIN
            MENUITEM "", IDM_ACIA_SETTINGS
            MENUITEM "", IDM_RS232USER_SETTINGS
            MENUITEM "", IDM_RS232_SETTINGS
        END
        MENUITEM SEPARATOR
        MENUITEM "", IDM_SETTINGS_SAVE_FILE
        MENUITEM "", IDM_SETTINGS_LOAD_FILE
        MENUITEM "", IDM_SETTINGS_SAVE
        MENUITEM "", IDM_SETTINGS_LOAD
        MENUITEM "", IDM_SETTINGS_DEFAULT
        MENUITEM SEPARATOR
        MENUITEM "", IDM_TOGGLE_SAVE_SETTINGS_ON_EXIT
        MENUITEM "", IDM_TOGGLE_CONFIRM_ON_EXIT
    END
    POPUP N_("Language")
    BEGIN
        MENUITEM "", IDM_LANG_EN
        MENUITEM "", IDM_LANG_DA
        MENUITEM "", IDM_LANG_DE
        MENUITEM "", IDM_LANG_ES
        MENUITEM "", IDM_LANG_FR
        MENUITEM "", IDM_LANG_HU
        MENUITEM "", IDM_LANG_IT
        MENUITEM "", IDM_LANG_KO
        MENUITEM "", IDM_LANG_NL
        MENUITEM "", IDM_LANG_PL
        MENUITEM "", IDM_LANG_RU
        MENUITEM "", IDM_LANG_SV
        MENUITEM "", IDM_LANG_TR
    END
    POPUP N_("Help"), HELP
    BEGIN
        MENUITEM "", IDM_HELP
        MENUITEM SEPARATOR
        MENUITEM "", IDM_ABOUT
        MENUITEM SEPARATOR
        MENUITEM "", IDM_CMDLINE
        MENUITEM SEPARATOR
        MENUITEM "", IDM_CONTRIBUTORS
        MENUITEM "", IDM_LICENSE
        MENUITEM "", IDM_WARRANTY
    END
END



IDD_C128MODEL_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 150, 80
CAPTION ""
BEGIN
    LTEXT         "", IDC_C128MODEL_LABEL,
                  4, 12, 60, 8
    COMBOBOX      IDC_C128MODEL_LIST,
                  45, 11, 90, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK,
                    20, 60, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    80, 60, 50, 14, WS_TABSTOP
END



IDD_C128ROM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 350
BEGIN
    LTEXT      "", IDC_KERNAL_INT,
               9, 8, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALINT_FILE,
               55, 7, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALINT_BROWSE,
               185, 7, 50, 14, 0

    LTEXT      "", IDC_KERNAL_DE,
               9, 28, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALDE_FILE,
               55, 27, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALDE_BROWSE,
               185, 27, 50, 14, 0

    LTEXT      "", IDC_KERNAL_FI,
               9, 48, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALFI_FILE,
               55, 47, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALFI_BROWSE,
               185, 47, 50, 14, 0

    LTEXT      "", IDC_KERNAL_FR,
               9, 68, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALFR_FILE,
               55, 67, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALFR_BROWSE,
               185, 67, 50, 14, 0

    LTEXT      "", IDC_KERNAL_IT,
               9, 88, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALIT_FILE,
               55, 87, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALIT_BROWSE,
               185, 87, 50, 14, 0

    LTEXT      "", IDC_KERNAL_NO,
               9, 108, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALNO_FILE,
               55, 107, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALNO_BROWSE,
               185, 107, 50, 14, 0

    LTEXT      "", IDC_KERNAL_SE,
               9, 128, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALSE_FILE,
               55, 127, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALSE_BROWSE,
               185, 127, 50, 14, 0

    LTEXT      "", IDC_KERNAL_CH,
               9, 148, 40, 8
    EDITTEXT   IDC_C128ROM_KERNALCH_FILE,
               55, 147, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNALCH_BROWSE,
               185, 147, 50, 14, 0

    LTEXT      "", IDC_BASIC_LO,
               9, 168, 40, 8
    EDITTEXT   IDC_C128ROM_BASICLO_FILE,
               55, 167, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_BASICLO_BROWSE,
               185, 167, 50, 14, 0

    LTEXT      "", IDC_BASIC_HI,
               9, 188, 40, 8
    EDITTEXT   IDC_C128ROM_BASICHI_FILE,
               55, 187, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_BASICHI_BROWSE,
               185, 187, 50, 14, 0

    LTEXT      "", IDC_CHAR_INT,
               9, 208, 40, 8
    EDITTEXT   IDC_C128ROM_CHARGENINT_FILE,
               55, 207, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_CHARGENINT_BROWSE,
               185, 207, 50, 14, 0

    LTEXT      "", IDC_CHAR_DE,
               9, 228, 40, 8
    EDITTEXT   IDC_C128ROM_CHARGENDE_FILE,
               55, 227, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_CHARGENDE_BROWSE,
               185, 227, 50, 14, 0

    LTEXT      "", IDC_CHAR_FR,
               9, 248, 40, 8
    EDITTEXT   IDC_C128ROM_CHARGENFR_FILE,
               55, 247, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_CHARGENFR_BROWSE,
               185, 247, 50, 14, 0

    LTEXT      "", IDC_CHAR_SE,
               9, 268, 40, 8
    EDITTEXT   IDC_C128ROM_CHARGENSE_FILE,
               55, 267, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_CHARGENSE_BROWSE,
               185, 267, 50, 14, 0

    LTEXT      "", IDC_CHAR_CH,
               9, 288, 40, 8
    EDITTEXT   IDC_C128ROM_CHARGENCH_FILE,
               55, 287, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_CHARGENCH_BROWSE,
               185, 287, 50, 14, 0

    LTEXT      "", IDC_KERNAL_C64,
               9, 308, 40, 8
    EDITTEXT   IDC_C128ROM_KERNAL64_FILE,
               55, 307, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_KERNAL64_BROWSE,
               185, 307, 50, 14, 0

    LTEXT      "", IDC_BASIC_C64,
               9, 328, 40, 8
    EDITTEXT   IDC_C128ROM_BASIC64_FILE,
               55, 327, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C128ROM_BASIC64_BROWSE,
               185, 327, 50, 14, 0
END



IDD_C128DRIVEROM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 310
BEGIN
    LTEXT      "", IDC_1541,
               9, 8, 40, 8
    EDITTEXT   IDC_DRIVEROM_1541_FILE,
               55, 7, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1541_BROWSE,
               185, 7, 50, 14, 0

    LTEXT      "", IDC_1541_II,
               9, 28, 40, 8
    EDITTEXT   IDC_DRIVEROM_1541II_FILE,
               55, 27, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1541II_BROWSE,
               185, 27, 50, 14, 0

    LTEXT      "", IDC_1570,
               9, 48, 40, 8
    EDITTEXT   IDC_DRIVEROM_1570_FILE,
               55, 47, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1570_BROWSE,
               185, 47, 50, 14, 0

    LTEXT      "", IDC_1571,
               9, 68, 40, 8
    EDITTEXT   IDC_DRIVEROM_1571_FILE,
               55, 67, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1571_BROWSE,
               185, 67, 50, 14, 0

    LTEXT      "", IDC_1571CR,
               9, 88, 40, 8
    EDITTEXT   IDC_DRIVEROM_1571CR_FILE,
               55, 87, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1571CR_BROWSE,
               185, 87, 50, 14, 0

    LTEXT      "", IDC_1581,
               9, 108, 40, 8
    EDITTEXT   IDC_DRIVEROM_1581_FILE,
               55, 107, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1581_BROWSE,
               185, 107, 50, 14, 0

    LTEXT      "", IDC_2000,
               9, 128, 40, 8
    EDITTEXT   IDC_DRIVEROM_2000_FILE,
               55, 127, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_2000_BROWSE,
               185, 127, 50, 14, 0

    LTEXT      "", IDC_4000,
               9, 148, 40, 8
    EDITTEXT   IDC_DRIVEROM_4000_FILE,
               55, 147, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_4000_BROWSE,
               185, 147, 50, 14, 0

    LTEXT      "", IDC_2031,
               9, 168, 40, 8
    EDITTEXT   IDC_DRIVEROM_2031_FILE,
               55, 167, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_2031_BROWSE,
               185, 167, 50, 14, 0

    LTEXT      "", IDC_2040,
               9, 188, 40, 8
    EDITTEXT   IDC_DRIVEROM_2040_FILE,
               55, 187, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_2040_BROWSE,
               185, 187, 50, 14, 0

    LTEXT      "", IDC_3040,
               9, 208, 40, 8
    EDITTEXT   IDC_DRIVEROM_3040_FILE,
               55, 207, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_3040_BROWSE,
               185, 207, 50, 14, 0

    LTEXT      "", IDC_4040,
               9, 228, 40, 8
    EDITTEXT   IDC_DRIVEROM_4040_FILE,
               55, 227, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_4040_BROWSE,
               185, 227, 50, 14, 0

    LTEXT      "", IDC_1001,
               9, 248, 40, 8
    EDITTEXT   IDC_DRIVEROM_1001_FILE,
               55, 247, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1001_BROWSE,
               185, 247, 50, 14, 0

    LTEXT      "", IDC_PROFDOS,
               9, 268, 40, 8
    EDITTEXT   IDC_DRIVEROM_PROFDOS_FILE,
               55, 267, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_PROFDOS_BROWSE,
               185, 267, 50, 14, 0

    LTEXT      "", IDC_SUPERCARD,
               9, 288, 40, 8
    EDITTEXT   IDC_DRIVEROM_SUPERCARD_FILE,
               55, 287, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_SUPERCARD_BROWSE,
               185, 287, 50, 14, 0
END



IDD_C128_MACHINE_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 220, 110
BEGIN
    LTEXT    "", IDC_MACHINE_TYPE,
             10, 9, 50, 8
    COMBOBOX IDC_C128_MACHINE_TYPE,
             60, 7, 60, 50, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
END



IDD_C128_FUNCTIONROM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 110
BEGIN
    GROUPBOX     "", IDC_INTERNAL_FUNCTION_ROM,
                 5, 5, 225, 45
    LTEXT        "", IDC_C128_FUNCTIONROM_INTERNAL_TYPE_LABEL,
                 15, 15, 30, 8
    COMBOBOX     IDC_C128_FUNCTIONROM_INTERNAL_TYPE,
                 45, 13, 50, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    LTEXT        "", IDC_FILE_NAME_1,
                 11, 33, 50, 8
    EDITTEXT     IDC_C128_FUNCTIONROM_INTERNAL_NAME,
                 50, 30, 115, 15, WS_TABSTOP
    PUSHBUTTON   "", IDC_C128_FUNCTIONROM_INTERNAL_BROWSE,
                 175, 30, 50, 14, 0
    GROUPBOX     "", IDC_EXTERNAL_FUNCTION_ROM,
                 5, 55, 225, 45
    LTEXT        "", IDC_C128_FUNCTIONROM_EXTERNAL_TYPE_LABEL,
                 15, 65, 30, 8
    COMBOBOX     IDC_C128_FUNCTIONROM_EXTERNAL_TYPE,
                 45, 63, 50, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    LTEXT        "", IDC_FILE_NAME_2,
                 11, 83, 50, 8
    EDITTEXT     IDC_C128_FUNCTIONROM_EXTERNAL_NAME,
                 50, 80, 115, 15, WS_TABSTOP
    PUSHBUTTON   "", IDC_C128_FUNCTIONROM_EXTERNAL_BROWSE,
                 175, 80, 50, 14, 0
END



IDD_C128_RAM_BANKS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 110
BEGIN
    AUTOCHECKBOX "", IDC_C128_FULL_BANKS,
                 15, 15, 120, 10, BS_AUTOCHECKBOX | WS_TABSTOP
END



IDD_C128KBD_MAPPING_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 120
BEGIN
    AUTORADIOBUTTON "",IDC_C128KBD_MAPPING_SELECT_SYM,
                    10, 10, 54, 10, BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP
    AUTORADIOBUTTON "", IDC_C128KBD_MAPPING_SELECT_POS,
                    10, 30, 54, 10, BS_AUTORADIOBUTTON

    EDITTEXT        IDC_C128KBD_MAPPING_SYM,
                    65, 9, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_C128KBD_MAPPING_SYM_BROWSE,
                    185, 9, 50, 14, 0
    EDITTEXT        IDC_C128KBD_MAPPING_POS,
                    65, 29, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_C128KBD_MAPPING_POS_BROWSE,
                    185, 29, 50, 14, 0

    PUSHBUTTON      "", IDC_C128KBD_MAPPING_DUMP,
                    10, 54, 60, 14, 0
    PUSHBUTTON      "", IDC_KBD_SHORTCUT_DUMP,
                    80, 54, 60, 14, 0

    DEFPUSHBUTTON   "", IDOK,
                    20, 100, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    80, 100, 50, 14, WS_TABSTOP
END



STRINGTABLE
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   N_("Select Internal Function ROM file")
  IDS_SELECT_EXT_FUNCTION_ROM   N_("Select External Function ROM file")
  IDS_MACHINE_TYPE              N_("Machine type")
  IDS_FUNCTION_ROM              N_("Function ROM")
  IDS_RAM_BANKS                 N_("RAM banks")
  IDS_C128_SETTINGS             N_("C128 settings")
  IDS_KERNAL_INT                N_("Kernal Int.")
  IDS_KERNAL_DE                 N_("Kernal DE")
  IDS_KERNAL_FI                 N_("Kernal FI")
  IDS_KERNAL_FR                 N_("Kernal FR")
  IDS_KERNAL_IT                 N_("Kernal IT")
  IDS_KERNAL_NO                 N_("Kernal NO")
  IDS_KERNAL_SE                 N_("Kernal SE")
  IDS_KERNAL_CH                 N_("Kernal CH")
  IDS_BASIC_LO                  N_("Basic LO")
  IDS_BASIC_HI                  N_("Basic HI")
  IDS_CHAR_INT                  N_("Char. Int.")
  IDS_CHAR_DE                   N_("Char. DE")
  IDS_CHAR_FR                   N_("Char. FR")
  IDS_CHAR_SE                   N_("Char. SE")
  IDS_CHAR_CH                   N_("Char. CH")
  IDS_KERNAL_C64                N_("Kernal C64")
  IDS_BASIC_C64                 N_("Basic C64")
  IDS_INTERNATIONAL             N_("International")
  IDS_FINNISH                   N_("Finnish")
  IDS_FRENCH                    N_("French")
  IDS_GERMAN                    N_("German")
  IDS_ITALIAN                   N_("Italian")
  IDS_NORWEGIAN                 N_("Norwegian")
  IDS_SWEDISH                   N_("Swedish")
  IDS_SWISS                     N_("Swiss")
  IDS_INT_FUNCTION_ROM          N_("Internal Function ROM")
  IDS_INT_FUNCTION_ROM_TYPE     N_("Internal Function ROM type")
  IDS_FILE_NAME                 N_("File name")
  IDS_EXT_FUNCTION_ROM          N_("External Function ROM")
  IDS_EXT_FUNCTION_ROM_TYPE     N_("External Function ROM type")
  IDS_C128_FULL_BANKS           N_("Enable RAM banks 2 and 3")
  IDS_C128MODEL                 N_("C128 model")
  IDS_MP_VDC_SETTINGS           N_("VDC settings")
  IDS_MP_VDC_REVISION           N_("VDC revision")
  IDS_MI_TOGGLE_VDC64KB         N_("64KB video memory")
  IDS_MI_IEEE488                N_("IEEE488 Interface emulation")
  IDS_MI_C128_SETTINGS          N_("C128 settings")
  IDS_MI_C128MODEL_SETTINGS     N_("C128 model settings")
END



STRINGTABLE
LANGUAGE LANG_DANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "V�lg image for intern funktions-ROM"
  IDS_SELECT_EXT_FUNCTION_ROM   "V�lg image for ekstern funktions-ROM"
  IDS_MACHINE_TYPE              "Maskintype"
  IDS_FUNCTION_ROM              "Funktions-ROM"
  IDS_RAM_BANKS                 "RAM-banke"
  IDS_C128_SETTINGS             "C128-indstillinger"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LAV"
  IDS_BASIC_HI                  "Basic H�J"
  IDS_CHAR_INT                  "Tegn Int."
  IDS_CHAR_DE                   "Tegn DE"
  IDS_CHAR_FR                   "Tegn FR"
  IDS_CHAR_SE                   "Tegn SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "BASIC C64"
  IDS_INTERNATIONAL             "International"
  IDS_FINNISH                   "Finsk"
  IDS_FRENCH                    "Fransk"
  IDS_GERMAN                    "Tysk"
  IDS_ITALIAN                   "Italiensk"
  IDS_NORWEGIAN                 "Norsk"
  IDS_SWEDISH                   "Svensk"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Intern funktions-ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Intern funktions-ROM-type"
  IDS_FILE_NAME                 "Filnavn"
  IDS_EXT_FUNCTION_ROM          "Extern funktions-ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "External Function ROM type"
  IDS_C128_FULL_BANKS           "Aktiv�r RAM-bank 2 og 3"
  IDS_C128MODEL                 "C128 model"
  IDS_MP_VDC_SETTINGS           "VDC-indstillinger"
  IDS_MP_VDC_REVISION           "VDC-revision"
  IDS_MI_TOGGLE_VDC64KB         "64KB grafikhukommelse"
  IDS_MI_IEEE488                "Emulering af IEEE488-interface"
  IDS_MI_C128_SETTINGS          "C128-indstillinger..."
  IDS_MI_C128MODEL_SETTINGS     "C128-modelindstillinger..."
END



STRINGTABLE
LANGUAGE LANG_GERMAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Internes Funktions ROM Image Datei ausw�hlen"
  IDS_SELECT_EXT_FUNCTION_ROM   "Externes Funktions ROM Image Datei ausw�hlen"
  IDS_MACHINE_TYPE              "Maschinen Typ"
  IDS_FUNCTION_ROM              "Function ROM"
  IDS_RAM_BANKS                 "RAM B�nke"
  IDS_C128_SETTINGS             "C128 Einstellungen"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "International"
  IDS_FINNISH                   "Finnisch"
  IDS_FRENCH                    "Franz�sisch"
  IDS_GERMAN                    "Deutsch"
  IDS_ITALIAN                   "Italienisch"
  IDS_NORWEGIAN                 "Norwegisch"
  IDS_SWEDISH                   "Schwedisch"
  IDS_SWISS                     "Schweiz"
  IDS_INT_FUNCTION_ROM          "Internes Funktions ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Internes Funktions ROM Typ"
  IDS_FILE_NAME                 "Dateiname"
  IDS_EXT_FUNCTION_ROM          "Externes Funktions ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "Externes Funktions ROM Typ"
  IDS_C128_FULL_BANKS           "RAM B�nke 2 und 3 aktivieren"
  IDS_C128MODEL                 "C128 Modell"
  IDS_MP_VDC_SETTINGS           "VDC Einstellungen"
  IDS_MP_VDC_REVISION           "VDC Revision"
  IDS_MI_TOGGLE_VDC64KB         "64KB Bildschirm Speicher"
  IDS_MI_IEEE488                "IEEE488 Schnittstellen-Emulation"
  IDS_MI_C128_SETTINGS          "C128 Einstellungen..."
  IDS_MI_C128MODEL_SETTINGS     "C128 Modell Einstellungen..."
END



STRINGTABLE
LANGUAGE LANG_SPANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Seleccionar fichero ROM funci�n interno"
  IDS_SELECT_EXT_FUNCTION_ROM   "Seleccionar fichero ROM funci�n externo"
  IDS_MACHINE_TYPE              "Tipo de m�quina"
  IDS_FUNCTION_ROM              "ROM funci�n"
  IDS_RAM_BANKS                 "Bancos de RAM"
  IDS_C128_SETTINGS             "Ajustes C128"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal  DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic bajo"
  IDS_BASIC_HI                  "Basic alto"
  IDS_CHAR_INT                  "Char.Int."
  IDS_CHAR_DE                   "Char.DE"
  IDS_CHAR_FR                   "Char.FR"
  IDS_CHAR_SE                   "Char.SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Internacional"
  IDS_FINNISH                   "Finland�s"
  IDS_FRENCH                    "Franc�s"
  IDS_GERMAN                    "Alem�n"
  IDS_ITALIAN                   "Italiano"
  IDS_NORWEGIAN                 "Noruego"
  IDS_SWEDISH                   "Sueco"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "ROM de funci�n interna"
  IDS_INT_FUNCTION_ROM_TYPE     "Tipo  Function ROM interna"
  IDS_FILE_NAME                 "nombre de fichero"
  IDS_EXT_FUNCTION_ROM          "ROM de funci�n externa"
  IDS_EXT_FUNCTION_ROM_TYPE     "Tipo  Function ROM externa"
  IDS_C128_FULL_BANKS           "Permitir bancos 2 y 3"
  IDS_C128MODEL                 "Modelo C128"
  IDS_MP_VDC_SETTINGS           "Ajustes VDC"
  IDS_MP_VDC_REVISION           "Revisi�n VDC"
  IDS_MI_TOGGLE_VDC64KB         "Memoria de video 64KB"
  IDS_MI_IEEE488                "Emulaci�n de interface IEEE488"
  IDS_MI_C128_SETTINGS          "Ajustes C128..."
  IDS_MI_C128MODEL_SETTINGS     "Ajustes modelo C128..."
END



STRINGTABLE
LANGUAGE LANG_FRENCH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "S�lectionner le fichier image ROM Fonction interne"
  IDS_SELECT_EXT_FUNCTION_ROM   "S�lectionner le fichier image ROM Fonction externe"
  IDS_MACHINE_TYPE              "Type de machine"
  IDS_FUNCTION_ROM              "ROM Fonction"
  IDS_RAM_BANKS                 "Banques de RAM"
  IDS_C128_SETTINGS             "Param�tres C128"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "International"
  IDS_FINNISH                   "Finlandais"
  IDS_FRENCH                    "Fran�ais"
  IDS_GERMAN                    "Allemand"
  IDS_ITALIAN                   "Italien"
  IDS_NORWEGIAN                 "Norv�gien"
  IDS_SWEDISH                   "Su�dois"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Image ROM Fonction interne"
  IDS_INT_FUNCTION_ROM_TYPE     "Type ROM Fonction interne"
  IDS_FILE_NAME                 "Nom de fichier"
  IDS_EXT_FUNCTION_ROM          "Image ROM Fonction externe"
  IDS_EXT_FUNCTION_ROM_TYPE     "External Function ROM type"
  IDS_C128_FULL_BANKS           "Activer les banques RAM 2 et 3"
  IDS_C128MODEL                 "Mod�le C128"
  IDS_MP_VDC_SETTINGS           "Param�tres VDC"
  IDS_MP_VDC_REVISION           "R�vision VDC"
  IDS_MI_TOGGLE_VDC64KB         "M�moire vid�o de 64Ko"
  IDS_MI_IEEE488                "Interface d'�mulation IEEE488"
  IDS_MI_C128_SETTINGS          "Param�tres C128..."
  IDS_MI_C128MODEL_SETTINGS     "Param�tres du mod�le C128..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_HUNGARIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Adja meg a bels� Function ROM k�pm�s nev�t"
  IDS_SELECT_EXT_FUNCTION_ROM   "Adja meg a k�ls� Function ROM k�pm�s nev�t"
  IDS_MACHINE_TYPE              "G�p t�pus"
  IDS_FUNCTION_ROM              "Function ROM"
  IDS_RAM_BANKS                 "RAM bankok"
  IDS_C128_SETTINGS             "C128 be�ll�t�sai"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Nemzetk�zi"
  IDS_FINNISH                   "Finn"
  IDS_FRENCH                    "Francia"
  IDS_GERMAN                    "N�met"
  IDS_ITALIAN                   "Olasz"
  IDS_NORWEGIAN                 "Norv�g"
  IDS_SWEDISH                   "Sv�d"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Bels� Function ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Internal Function ROM type"
  IDS_FILE_NAME                 "F�jln�v"
  IDS_EXT_FUNCTION_ROM          "K�ls� Function ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "External Function ROM type"
  IDS_C128_FULL_BANKS           "2-es �s 3-as RAM bankok enged�lyez�se"
  IDS_C128MODEL                 "C128 model"
  IDS_MP_VDC_SETTINGS           "VDC be�ll�t�sai"
  IDS_MP_VDC_REVISION           "VDC v�ltozat"
  IDS_MI_TOGGLE_VDC64KB         "64KB k�perny� mem�ria"
  IDS_MI_IEEE488                "IEEE488 Interface emulation"
  IDS_MI_C128_SETTINGS          "C128 be�ll�t�sai..."
  IDS_MI_C128MODEL_SETTINGS     "C128 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_ITALIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Seleziona file Function ROM interna"
  IDS_SELECT_EXT_FUNCTION_ROM   "Seleziona file Function ROM esterna"
  IDS_MACHINE_TYPE              "Tipo computer"
  IDS_FUNCTION_ROM              "Function ROM"
  IDS_RAM_BANKS                 "Banchi di Ram"
  IDS_C128_SETTINGS             "Impostazioni C128"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Internazionale"
  IDS_FINNISH                   "Finlandese"
  IDS_FRENCH                    "Francese"
  IDS_GERMAN                    "Tedesco"
  IDS_ITALIAN                   "Italiano"
  IDS_NORWEGIAN                 "Norvegese"
  IDS_SWEDISH                   "Svedese"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Function ROM interna"
  IDS_INT_FUNCTION_ROM_TYPE     "Tipo function ROM interna"
  IDS_FILE_NAME                 "Nome file"
  IDS_EXT_FUNCTION_ROM          "Function ROM esterna"
  IDS_EXT_FUNCTION_ROM_TYPE     "Tipo Function ROM esterna"
  IDS_C128_FULL_BANKS           "Attiva banchi RAM 2 e 3"
  IDS_C128MODEL                 "Modello C128"
  IDS_MP_VDC_SETTINGS           "Impostazioni VDC"
  IDS_MP_VDC_REVISION           "Revisione VDC"
  IDS_MI_TOGGLE_VDC64KB         "Memoria video di 64KB"
  IDS_MI_IEEE488                "Emulazione interfaccia IEEE488"
  IDS_MI_C128_SETTINGS          "Impostazioni C128..."
  IDS_MI_C128MODEL_SETTINGS     "Impostazioni modello C128..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(949)
#endif
STRINGTABLE
LANGUAGE LANG_KOREAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Select Internal Function ROM file"
  IDS_SELECT_EXT_FUNCTION_ROM   "Select External Function ROM file"
  IDS_MACHINE_TYPE              "�ӽ� ����"
  IDS_FUNCTION_ROM              "Function ROM"
  IDS_RAM_BANKS                 "RAM banks"
  IDS_C128_SETTINGS             "C128 settings"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "����"
  IDS_FINNISH                   "�ɶ����"
  IDS_FRENCH                    "��������"
  IDS_GERMAN                    "���Ͼ�"
  IDS_ITALIAN                   "��Ż���ƾ�"
  IDS_NORWEGIAN                 "�븣���̾�"
  IDS_SWEDISH                   "��������"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Internal Function ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Internal Function ROM type"
  IDS_FILE_NAME                 "���� �̸�"
  IDS_EXT_FUNCTION_ROM          "External Function ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "External Function ROM type"
  IDS_C128_FULL_BANKS           "Enable RAM banks 2 and 3"
  IDS_C128MODEL                 "C128 model"
  IDS_MP_VDC_SETTINGS           "VDC ����"
  IDS_MP_VDC_REVISION           "VDC revision"
  IDS_MI_TOGGLE_VDC64KB         "64KB ���� �޸�"
  IDS_MI_IEEE488                "IEEE488 Interface emulation"
  IDS_MI_C128_SETTINGS          "C128 settings..."
  IDS_MI_C128MODEL_SETTINGS     "C128 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_DUTCH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Selecteer intern functie ROM bestand"
  IDS_SELECT_EXT_FUNCTION_ROM   "Selecteer extern functie ROM bestand"
  IDS_MACHINE_TYPE              "Machinesoort"
  IDS_FUNCTION_ROM              "Functie ROM"
  IDS_RAM_BANKS                 "Ram banken"
  IDS_C128_SETTINGS             "C128 instellingen"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Internationaal"
  IDS_FINNISH                   "Fins"
  IDS_FRENCH                    "Frans"
  IDS_GERMAN                    "Duits"
  IDS_ITALIAN                   "Italiaans"
  IDS_NORWEGIAN                 "Noors"
  IDS_SWEDISH                   "Zweeds"
  IDS_SWISS                     "Zwitser"
  IDS_INT_FUNCTION_ROM          "Interne functie ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Interne functie ROM soort"
  IDS_FILE_NAME                 "Bestandsnaam"
  IDS_EXT_FUNCTION_ROM          "Externe functie ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "Externe functie ROM soort"
  IDS_C128_FULL_BANKS           "Aktiveer RAM bank 2 en 3"
  IDS_C128MODEL                 "C128 model"
  IDS_MP_VDC_SETTINGS           "VDC instellingen"
  IDS_MP_VDC_REVISION           "VDC revisie"
  IDS_MI_TOGGLE_VDC64KB         "64KB videogeheugen"
  IDS_MI_IEEE488                "IEEE488 Interface emulatie"
  IDS_MI_C128_SETTINGS          "C128 instellingen..."
  IDS_MI_C128MODEL_SETTINGS     "C128 model instellingen..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_POLISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Wybierz plik wewn�trznego Function ROM-u"
  IDS_SELECT_EXT_FUNCTION_ROM   "Wybierz plik zewn�trznego Function ROM-u"
  IDS_MACHINE_TYPE              "Typ maszyny"
  IDS_FUNCTION_ROM              "Function ROM"
  IDS_RAM_BANKS                 "Banki RAM"
  IDS_C128_SETTINGS             "Ustawienia C128"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Znak Int."
  IDS_CHAR_DE                   "Znak DE"
  IDS_CHAR_FR                   "Znak FR"
  IDS_CHAR_SE                   "Znak SE"
  IDS_CHAR_CH                   "Znak CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Mi�dzynarodowy"
  IDS_FINNISH                   "Fi�ski"
  IDS_FRENCH                    "Francuski"
  IDS_GERMAN                    "Niemiecki"
  IDS_ITALIAN                   "W�oski"
  IDS_NORWEGIAN                 "Norweski"
  IDS_SWEDISH                   "Szwedzki"
  IDS_SWISS                     "Szwajcarski"
  IDS_INT_FUNCTION_ROM          "Wewn�trzny Function ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Typ wewn�trznego Function ROM-u"
  IDS_FILE_NAME                 "Nazwa pliku"
  IDS_EXT_FUNCTION_ROM          "Zewn�trzny Function ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "Typ zewn�trznego Function ROM-u"
  IDS_C128_FULL_BANKS           "W��cz banki RAM 2 i 3"
  IDS_C128MODEL                 "Model C128"
  IDS_MP_VDC_SETTINGS           "Ustawienia VDC"
  IDS_MP_VDC_REVISION           "Wersja VDC"
  IDS_MI_TOGGLE_VDC64KB         "Pami�� wideo 64KB"
  IDS_MI_IEEE488                "Emulacja interfejsu IEEE488"
  IDS_MI_C128_SETTINGS          "Ustawienia C128..."
  IDS_MI_C128MODEL_SETTINGS     "Ustawienia modelu C128..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28595)
#endif
STRINGTABLE
LANGUAGE LANG_RUSSIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Select Internal Function ROM file"
  IDS_SELECT_EXT_FUNCTION_ROM   "Select External Function ROM file"
  IDS_MACHINE_TYPE              "��� ����������"
  IDS_FUNCTION_ROM              "�������������� ���"
  IDS_RAM_BANKS                 "RAM banks"
  IDS_C128_SETTINGS             "��������� C128"
  IDS_KERNAL_INT                "Kernal Int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Char. Int."
  IDS_CHAR_DE                   "Char. DE"
  IDS_CHAR_FR                   "Char. FR"
  IDS_CHAR_SE                   "Char. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "�������������"
  IDS_FINNISH                   "�������"
  IDS_FRENCH                    "�����������"
  IDS_GERMAN                    "��������"
  IDS_ITALIAN                   "�����������"
  IDS_NORWEGIAN                 "����������"
  IDS_SWEDISH                   "��������"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Internal Function ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Internal Function ROM type"
  IDS_FILE_NAME                 "��� �����"
  IDS_EXT_FUNCTION_ROM          "External Function ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "External Function ROM type"
  IDS_C128_FULL_BANKS           "Enable RAM banks 2 and 3"
  IDS_C128MODEL                 "C128 model"
  IDS_MP_VDC_SETTINGS           "��������� VDC"
  IDS_MP_VDC_REVISION           "VDC revision"
  IDS_MI_TOGGLE_VDC64KB         "64KB video memory"
  IDS_MI_IEEE488                "IEEE488 Interface emulation"
  IDS_MI_C128_SETTINGS          "��������� C128..."
  IDS_MI_C128MODEL_SETTINGS     "C128 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_SWEDISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "V�lj avbildning f�r internt funktions-ROM"
  IDS_SELECT_EXT_FUNCTION_ROM   "V�lj avbildning f�r externt funktions-ROM"
  IDS_MACHINE_TYPE              "Maskintyp"
  IDS_FUNCTION_ROM              "Funktions-ROM"
  IDS_RAM_BANKS                 "RAM-bankar"
  IDS_C128_SETTINGS             "C128-inst�llningar"
  IDS_KERNAL_INT                "Kernal int."
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic L�"
  IDS_BASIC_HI                  "Basic H�"
  IDS_CHAR_INT                  "Teck. Int."
  IDS_CHAR_DE                   "Teck. DE"
  IDS_CHAR_FR                   "Teck. FR"
  IDS_CHAR_SE                   "Teck. SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Internationell"
  IDS_FINNISH                   "Finska"
  IDS_FRENCH                    "Franska"
  IDS_GERMAN                    "Tyska"
  IDS_ITALIAN                   "Italienska"
  IDS_NORWEGIAN                 "Norska"
  IDS_SWEDISH                   "Svenska"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Internt funktions-ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Internt funktions-ROM-typ"
  IDS_FILE_NAME                 "Filnamn"
  IDS_EXT_FUNCTION_ROM          "Externt funktions-ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "Externt funktions-ROM-typ"
  IDS_C128_FULL_BANKS           "Aktivera RAM-bank 2 och 3"
  IDS_C128MODEL                 "C128-modell"
  IDS_MP_VDC_SETTINGS           "VDC-inst�llningar"
  IDS_MP_VDC_REVISION           "VDC-revision"
  IDS_MI_TOGGLE_VDC64KB         "64KB grafikminne"
  IDS_MI_IEEE488                "Emulering av IEEE488-gr�nssnitt"
  IDS_MI_C128_SETTINGS          "C128-inst�llningar..."
  IDS_MI_C128MODEL_SETTINGS     "C128-modellinst�llningar..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28599)
#endif
STRINGTABLE
LANGUAGE LANG_TURKISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_INT_FUNCTION_ROM   "Dahili Function ROM dosyas� se�in"
  IDS_SELECT_EXT_FUNCTION_ROM   "Harici Function ROM dosyas� se�in"
  IDS_MACHINE_TYPE              "Makine tipi"
  IDS_FUNCTION_ROM              "Function ROM"
  IDS_RAM_BANKS                 "RAM banklar�"
  IDS_C128_SETTINGS             "C128 ayarlar�"
  IDS_KERNAL_INT                "Uluslararas� Kernal"
  IDS_KERNAL_DE                 "Kernal DE"
  IDS_KERNAL_FI                 "Kernal FI"
  IDS_KERNAL_FR                 "Kernal FR"
  IDS_KERNAL_IT                 "Kernal IT"
  IDS_KERNAL_NO                 "Kernal NO"
  IDS_KERNAL_SE                 "Kernal SE"
  IDS_KERNAL_CH                 "Kernal CH"
  IDS_BASIC_LO                  "Basic LO"
  IDS_BASIC_HI                  "Basic HI"
  IDS_CHAR_INT                  "Uluslararas� Karakter"
  IDS_CHAR_DE                   "Karakter DE"
  IDS_CHAR_FR                   "Karakter FR"
  IDS_CHAR_SE                   "Karakter SE"
  IDS_CHAR_CH                   "Char. CH"
  IDS_KERNAL_C64                "Kernal C64"
  IDS_BASIC_C64                 "Basic C64"
  IDS_INTERNATIONAL             "Uluslararas�"
  IDS_FINNISH                   "Fince"
  IDS_FRENCH                    "Frans�zca"
  IDS_GERMAN                    "Almanca"
  IDS_ITALIAN                   "�talyanca"
  IDS_NORWEGIAN                 "Norve��e"
  IDS_SWEDISH                   "�sve��e"
  IDS_SWISS                     "Swiss"
  IDS_INT_FUNCTION_ROM          "Uluslararas� Function ROM"
  IDS_INT_FUNCTION_ROM_TYPE     "Dahili Function ROM tipi"
  IDS_FILE_NAME                 "Dosya ismi"
  IDS_EXT_FUNCTION_ROM          "Harici Function ROM"
  IDS_EXT_FUNCTION_ROM_TYPE     "External Function ROM type"
  IDS_C128_FULL_BANKS           "RAM banklar� 2 ve 3'� aktif et"
  IDS_C128MODEL                 "C128 modeli"
  IDS_MP_VDC_SETTINGS           "VDC ayarlar�"
  IDS_MP_VDC_REVISION           "VDC revizyonu"
  IDS_MI_TOGGLE_VDC64KB         "64KB g�r�nt� belle�i"
  IDS_MI_IEEE488                "IEEE488 Arabirimi em�lasyonu"
  IDS_MI_C128_SETTINGS          "C128 ayarlar�..."
  IDS_MI_C128MODEL_SETTINGS     "C128 model ayarlar�..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


