
#include "vice.h"

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

#define FILE_DESCRIPTION  "Vice SCPU64 Emulator"



IDR_MENUSCPU64 MENU DISCARDABLE
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
        MENUITEM "", IDM_TOGGLE_WARP_MODE,            CHECKED
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
            MENUITEM "", IDM_MOUSE
            MENUITEM "", IDM_MOUSE_SETTINGS
        END
        MENUITEM "", IDM_LIGHTPEN_SETTINGS
        MENUITEM SEPARATOR
        MENUITEM "", IDM_VIDEO_SETTINGS
        MENUITEM "", IDM_TOGGLE_FULLSCREEN
        MENUITEM "", IDM_TOGGLE_ALWAYSONTOP
        MENUITEM SEPARATOR
        MENUITEM "", IDM_C64MODEL_SETTINGS
        MENUITEM "", IDM_SCPU64_SETTINGS
        MENUITEM "", IDM_TOGGLE_RESET_IEC_WITH_CPU
        MENUITEM "", IDM_RAM_SETTINGS
        MENUITEM "", IDM_ROM_SETTINGS
        MENUITEM "", IDM_VICII_SETTINGS
        MENUITEM "", IDM_SID_SETTINGS
        MENUITEM "", IDM_CIA_SETTINGS
        MENUITEM SEPARATOR
        POPUP N_("Cartridge/IO settings")
        BEGIN
            MENUITEM "", IDM_REU_SETTINGS
            MENUITEM "", IDM_GEORAM_SETTINGS
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
            MENUITEM "", IDM_C64BURSTMOD_SETTINGS
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



IDD_SCPU64_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 180, 110
BEGIN
    LTEXT           "", IDC_SCPU64_SIMM_SIZE_LABEL,
                    9, 9, 30, 8
    COMBOBOX        IDC_SCPU64_SIMM_SIZE,
                    45, 7, 100, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP

    AUTOCHECKBOX    "", IDC_SCPU64_JIFFY_SWITCH_ENABLE,
                    7, 24, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_SCPU64_SPEED_SWITCH_ENABLE,
                    7, 39, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK,
                    30, 90, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    90, 90, 50, 14, WS_TABSTOP
END



IDD_SCPU64ROM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 50
BEGIN
    LTEXT      "", IDC_SCPU64,
               9, 8, 40, 8
    EDITTEXT   IDC_SCPU64ROM_SCPU64_FILE,
               55, 7, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_SCPU64ROM_SCPU64_BROWSE,
               185, 7, 50, 14, 0
    LTEXT      "", IDC_CHARACTER,
               9, 28, 40, 8
    EDITTEXT   IDC_C64ROM_CHARGEN_FILE,
               55, 27, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_C64ROM_CHARGEN_BROWSE,
               185, 27, 50, 14, 0
END



IDD_C64DRIVEROM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 290
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

    LTEXT      "", IDC_1581,
               9, 88, 40, 8
    EDITTEXT   IDC_DRIVEROM_1581_FILE,
               55, 87, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1581_BROWSE,
               185, 87, 50, 14, 0

    LTEXT      "", IDC_2000,
               9, 108, 40, 8
    EDITTEXT   IDC_DRIVEROM_2000_FILE,
               55, 107, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_2000_BROWSE,
               185, 107, 50, 14, 0

    LTEXT      "", IDC_4000,
               9, 128, 40, 8
    EDITTEXT   IDC_DRIVEROM_4000_FILE,
               55, 127, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_4000_BROWSE,
               185, 127, 50, 14, 0

    LTEXT      "", IDC_2031,
               9, 148, 40, 8
    EDITTEXT   IDC_DRIVEROM_2031_FILE,
               55, 147, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_2031_BROWSE,
               185, 147, 50, 14, 0

    LTEXT      "", IDC_2040,
               9, 168, 40, 8
    EDITTEXT   IDC_DRIVEROM_2040_FILE,
               55, 167, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_2040_BROWSE,
               185, 167, 50, 14, 0

    LTEXT      "", IDC_3040,
               9, 188, 40, 8
    EDITTEXT   IDC_DRIVEROM_3040_FILE,
               55, 187, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_3040_BROWSE,
               185, 187, 50, 14, 0

    LTEXT      "", IDC_4040,
               9, 208, 40, 8
    EDITTEXT   IDC_DRIVEROM_4040_FILE,
               55, 207, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_4040_BROWSE,
               185, 207, 50, 14, 0

    LTEXT      "", IDC_1001,
               9, 228, 40, 8
    EDITTEXT   IDC_DRIVEROM_1001_FILE,
               55, 227, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_1001_BROWSE,
               185, 227, 50, 14, 0

    LTEXT      "", IDC_PROFDOS,
               9, 248, 40, 8
    EDITTEXT   IDC_DRIVEROM_PROFDOS_FILE,
               55, 247, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_PROFDOS_BROWSE,
               185, 247, 50, 14, 0

    LTEXT      "", IDC_SUPERCARD,
               9, 268, 40, 8
    EDITTEXT   IDC_DRIVEROM_SUPERCARD_FILE,
               55, 267, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_DRIVEROM_SUPERCARD_BROWSE,
               185, 267, 50, 14, 0
END



IDD_C64KBD_MAPPING_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 140
BEGIN
    AUTORADIOBUTTON "", IDC_C64KBD_MAPPING_SELECT_SYM,
                    10, 10, 54, 10, BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP
    AUTORADIOBUTTON "", IDC_C64KBD_MAPPING_SELECT_SYMDE,
                    10, 30, 54, 10, BS_AUTORADIOBUTTON
    AUTORADIOBUTTON "", IDC_C64KBD_MAPPING_SELECT_POS,
                    10, 50, 54, 10, BS_AUTORADIOBUTTON

    EDITTEXT        IDC_C64KBD_MAPPING_SYM,
                    65, 9, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_C64KBD_MAPPING_SYM_BROWSE,
                    185, 9, 50, 14, 0
    EDITTEXT        IDC_C64KBD_MAPPING_SYMDE,
                    65, 29, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_C64KBD_MAPPING_SYMDE_BROWSE,
                    185, 29, 50, 14, 0
    EDITTEXT        IDC_C64KBD_MAPPING_POS,
                    65, 49, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_C64KBD_MAPPING_POS_BROWSE,
                    185, 49, 50, 14, 0

    PUSHBUTTON      "", IDC_C64KBD_MAPPING_DUMP,
                    10, 74, 60, 14, 0
    PUSHBUTTON      "", IDC_KBD_SHORTCUT_DUMP,
                    80, 74, 60, 14, 0

    DEFPUSHBUTTON   "", IDOK,
                    20, 120, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    80, 120, 50, 14, WS_TABSTOP
END



IDD_C64MODEL_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 150, 80
CAPTION ""
BEGIN
    LTEXT         "", IDC_C64MODEL_LABEL,
                  4, 12, 60, 8
    COMBOBOX      IDC_C64MODEL_LIST,
                  45, 11, 90, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK,
                    20, 60, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    80, 60, 50, 14, WS_TABSTOP
END



IDD_C64BURSTMOD_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 180, 110
BEGIN
    AUTOCHECKBOX    "", IDC_C64BURSTMOD_ENABLE,
                    7, 7, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    LTEXT           "", IDC_C64BURSTMOD_CIA_LABEL,
                    9, 24, 30, 8
    COMBOBOX        IDC_C64BURSTMOD_CIA,
                    45, 22, 50, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK,
                    30, 90, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    90, 90, 50, 14, WS_TABSTOP
END



STRINGTABLE
BEGIN
  IDS_C64_MODEL                  N_("C64 model")
  IDS_C64_PAL                    N_("C64 PAL")
  IDS_C64C_PAL                   N_("C64C PAL")
  IDS_C64_OLD_PAL                N_("C64 old PAL")
  IDS_C64_NTSC                   N_("C64 NTSC")
  IDS_C64C_NTSC                  N_("C64C NTSC")
  IDS_C64_OLD_NTSC               N_("C64 old NTSC")
  IDS_DREAN                      N_("Drean")
  IDS_C64_SX_PAL                 N_("C64 SX PAL")
  IDS_C64_SX_NTSC                N_("C64 SX NTSC")
  IDS_JAPANESE                   N_("Japanese")
  IDS_C64_GS                     N_("C64 GS")
  IDS_PET64_PAL                  N_("PET64 PAL")
  IDS_PET64_NTSC                 N_("PET64 NTSC")
  IDS_MAX_MACHINE                N_("MAX Machine")
  IDS_6569_PAL                   N_("6569 (PAL)")
  IDS_8565_PAL                   N_("8565 (PAL)")
  IDS_6569R1_OLD_PAL             N_("6569R1 (old PAL)")
  IDS_6567_NTSC                  N_("6567 (NTSC)")
  IDS_8562_NTSC                  N_("8562 (NTSC)")
  IDS_6567R56A_OLD_NTSC          N_("6567R56A (old NTSC)")
  IDS_6572_PAL_N                 N_("6572 (PAL-N)")
  IDS_C64_MODEL_CAPTION          N_("C64 model settings")
  IDS_C64BURSTMOD_CAPTION        N_("C64 drive burst modification settings")
  IDS_C64BURSTMOD_ENABLE         N_("Enable the C64 drive burst modification")
  IDS_C64BURSTMOD_CIA            N_("C64 drive burst modification CIA")
  IDS_SCPU64_CAPTION             N_("SuperCPU64 settings")
  IDS_SCPU64_SIMM_SIZE           N_("SIMM size")
  IDS_SCPU64_JIFFY_SWITCH_ENABLE N_("Enable the jiffy switch")
  IDS_SCPU64_SPEED_SWITCH_ENABLE N_("Enable the speed switch")
  IDS_MI_C64BURSTMOD_SETTINGS    N_("C64 drive burst modification settings")
  IDS_MI_SCPU64_SETTINGS         N_("SuperCPU64 settings")
END



STRINGTABLE
LANGUAGE LANG_DANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64-model"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 gammel PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 gammel NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (gammel PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (gammel NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64-model indstillinger"
  IDS_C64BURSTMOD_CAPTION        "C64-drev burst-modifikationsindstillinger"
  IDS_C64BURSTMOD_ENABLE         "Aktiv�r C64-drev burst-modifikation"
  IDS_C64BURSTMOD_CIA            "C64-drev burst-modifikation CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64 settings"
  IDS_SCPU64_SIMM_SIZE           "SIMM size"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Enable the jiffy switch"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Enable the speed switch"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64-drev burst-modifikationsindstillinger..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 settings..."
END



STRINGTABLE
LANGUAGE LANG_GERMAN, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64 Modell"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 alt PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 alt NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanisch"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (alt PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (alt NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64 Modell Einstellungen"
  IDS_C64BURSTMOD_CAPTION        "C64 Laufwerk Burstmodifkation Einstellungen"
  IDS_C64BURSTMOD_ENABLE         "C64 Laufwerk Burstmodifikation aktivieren"
  IDS_C64BURSTMOD_CIA            "C64 Laufwerk Burstmodifikation CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64 Einstellungen"
  IDS_SCPU64_SIMM_SIZE           "SIMM Gr��e"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Jiffy Schalter aktivieren"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Speed Schalter aktivieren"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64 Laufwerk Burstmodifkation Einstellungen..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 Einstellungen..."
END



STRINGTABLE
LANGUAGE LANG_SPANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "Modelo C64"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 PAL antiguo"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 NTSC antiguo"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japon�s"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "M�quina MAX"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (PAL antiguo)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (NTSC antiguo)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "Ajustes modelo C64"
  IDS_C64BURSTMOD_CAPTION        "Ajuste modificaci�n Burst en controlador C64"
  IDS_C64BURSTMOD_ENABLE         "Habilitar modificaci�n Burst en Controlador C64"
  IDS_C64BURSTMOD_CIA            "Modificaci�n Burst en CIA de controlador C64"
  IDS_SCPU64_CAPTION             "Ajustes SuperCPU64"
  IDS_SCPU64_SIMM_SIZE           "Tama�o SIMM"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Permitir conmutaci�n Jiffy"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Permitir conmutaci�n de velocidad"
  IDS_MI_C64BURSTMOD_SETTINGS    "Ajuste modificaci�n Burst en controlador C64..."
  IDS_MI_SCPU64_SETTINGS         "Ajustes SuperCPU64..."
END



STRINGTABLE
LANGUAGE LANG_FRENCH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "Mod�le C64"
  IDS_C64_PAL                    "RTC baseC64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "Ancien PAL C64"
  IDS_C64_NTSC                   "NTSC C64"
  IDS_C64C_NTSC                  "NTSC C64C"
  IDS_C64_OLD_NTSC               "Ancien NTSC C64"
  IDS_DREAN                      "R�ve"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (ancien PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (ancien NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "Param�tres du mod�le C64"
  IDS_C64BURSTMOD_CAPTION        "Param�tres de l'�mulation de Burst Lecteur C64"
  IDS_C64BURSTMOD_ENABLE         "Activer l'�mulation de Burst Lecteur C64"
  IDS_C64BURSTMOD_CIA            "Modification CIA Burst Lecteur C64"
  IDS_SCPU64_CAPTION             "Param�tres SuperCPU64"
  IDS_SCPU64_SIMM_SIZE           "Taille de la SIMM"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Activer 'Jiffy Switch'"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Activer l'interrupteur Vitesse"
  IDS_MI_C64BURSTMOD_SETTINGS    "Param�tres de l'�mulation de Burst Lecteur C64..."
  IDS_MI_SCPU64_SETTINGS         "Param�tres SuperCPU64..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_HUNGARIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64 model"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 old PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 old NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (old PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (old NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64 model settings"
  IDS_C64BURSTMOD_CAPTION        "C64 drive burst modification settings"
  IDS_C64BURSTMOD_ENABLE         "Enable the C64 drive burst modification"
  IDS_C64BURSTMOD_CIA            "C64 drive burst modification CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64 settings"
  IDS_SCPU64_SIMM_SIZE           "SIMM size"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Enable the jiffy switch"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Enable the speed switch"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64 drive burst modification settings..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_ITALIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "Modello C64"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 PAL vecchio"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 NTSC vecchio"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Giapponese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (PAL vecchio)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (NTSC vecchio)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "Impostazioni modello C64"
  IDS_C64BURSTMOD_CAPTION        "Impostazioni modifica burst del drive C64"
  IDS_C64BURSTMOD_ENABLE         "Attiva modifica burst del drive C64"
  IDS_C64BURSTMOD_CIA            "Modifica CIA burst del drive C64 "
  IDS_SCPU64_CAPTION             "Impostazioni SuperCPU64"
  IDS_SCPU64_SIMM_SIZE           "Dimensione SIMM"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Attiva pulsante jiffy"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Attiva il pulsante di velocit�"
  IDS_MI_C64BURSTMOD_SETTINGS    "Impostazioni modifica burst del drive C64..."
  IDS_MI_SCPU64_SETTINGS         "Impostazioni SuperCPU64..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(949)
#endif
STRINGTABLE
LANGUAGE LANG_KOREAN, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64 ��"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 �õ� PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 �õ� NTSC"
  IDS_DREAN                      "�帰"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (�õ� PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (�õ� NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64 �� ����"
  IDS_C64BURSTMOD_CAPTION        "C64 drive burst modification settings"
  IDS_C64BURSTMOD_ENABLE         "Enable the C64 drive burst modification"
  IDS_C64BURSTMOD_CIA            "C64 drive burst modification CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64 settings"
  IDS_SCPU64_SIMM_SIZE           "SIMM size"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Enable the jiffy switch"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Enable the speed switch"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64 drive burst modification settings..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_DUTCH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64 model"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 oud PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 oud NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japans"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (oud PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (oud NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64 model instellingen"
  IDS_C64BURSTMOD_CAPTION        "C64 drive burst modificatie instellingen"
  IDS_C64BURSTMOD_ENABLE         "Activeer de C64 drive burst modificatie"
  IDS_C64BURSTMOD_CIA            "C64 drive burst modificatie CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64 instellingen"
  IDS_SCPU64_SIMM_SIZE           "SIMM grootte"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Activeer de jiffy schakelaar"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Activeer de snelheid schakelaar"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64 drive burst modificatie instellingen..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 instellingen..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_POLISH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "Model C64"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 stary PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 stary NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japo�ski"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (stary PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (stary NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "Ustawienia modelu C64"
  IDS_C64BURSTMOD_CAPTION        "Ustawienia trybu synchronicznego nap�du C64"
  IDS_C64BURSTMOD_ENABLE         "W��cz modyfikacj� trybu synchronicznego nap�du C64"
  IDS_C64BURSTMOD_CIA            "CIA trybu synchronicznego nap�du C64"
  IDS_SCPU64_CAPTION             "Ustawienia SuperCPU64"
  IDS_SCPU64_SIMM_SIZE           "Ilo�� SIMM"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Ustaw prze��cznik jiffy"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "W��cz prze��cznik speed"
  IDS_MI_C64BURSTMOD_SETTINGS    "Ustawienia trybu synchronicznego nap�du C64..."
  IDS_MI_SCPU64_SETTINGS         "Ustawienia SuperCPU64..."
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
  IDS_C64_MODEL                  "������ C64"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 old PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 old NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (old PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (old NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64 model settings"
  IDS_C64BURSTMOD_CAPTION        "C64 drive burst modification settings"
  IDS_C64BURSTMOD_ENABLE         "Enable the C64 drive burst modification"
  IDS_C64BURSTMOD_CIA            "C64 drive burst modification CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64 settings"
  IDS_SCPU64_SIMM_SIZE           "SIMM size"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Enable the jiffy switch"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Enable the speed switch"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64 drive burst modification settings..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_SWEDISH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64-modell"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 gammal PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 gammal NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "japansk"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX-maskin"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (gammal PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (gammal NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64-modellinst�llningar"
  IDS_C64BURSTMOD_CAPTION        "Inst�llningar f�r C64 diskettburstmodifiering"
  IDS_C64BURSTMOD_ENABLE         "Aktivera C64 diskettburstmodifiering"
  IDS_C64BURSTMOD_CIA            "C64 diskettburstmodifiering CIA"
  IDS_SCPU64_CAPTION             "SuperCPU64-inst�llningar"
  IDS_SCPU64_SIMM_SIZE           "SIMM-storlek"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Aktivera jiffy-omkopplaren"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Aktivera hastighetsomkopplaren"
  IDS_MI_C64BURSTMOD_SETTINGS    "Inst�llningar f�r C64 diskettburstmodifiering..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64-inst�llningar..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28599)
#endif
STRINGTABLE
LANGUAGE LANG_TURKISH, SUBLANG_NEUTRAL
BEGIN
  IDS_C64_MODEL                  "C64 modeli"
  IDS_C64_PAL                    "C64 PAL"
  IDS_C64C_PAL                   "C64C PAL"
  IDS_C64_OLD_PAL                "C64 eski PAL"
  IDS_C64_NTSC                   "C64 NTSC"
  IDS_C64C_NTSC                  "C64C NTSC"
  IDS_C64_OLD_NTSC               "C64 eski NTSC"
  IDS_DREAN                      "Drean"
  IDS_C64_SX_PAL                 "C64 SX PAL"
  IDS_C64_SX_NTSC                "C64 SX NTSC"
  IDS_JAPANESE                   "Japanese"
  IDS_C64_GS                     "C64 GS"
  IDS_PET64_PAL                  "PET64 PAL"
  IDS_PET64_NTSC                 "PET64 NTSC"
  IDS_MAX_MACHINE                "MAX Machine"
  IDS_6569_PAL                   "6569 (PAL)"
  IDS_8565_PAL                   "8565 (PAL)"
  IDS_6569R1_OLD_PAL             "6569R1 (eski PAL)"
  IDS_6567_NTSC                  "6567 (NTSC)"
  IDS_8562_NTSC                  "8562 (NTSC)"
  IDS_6567R56A_OLD_NTSC          "6567R56A (eski NTSC)"
  IDS_6572_PAL_N                 "6572 (PAL-N)"
  IDS_C64_MODEL_CAPTION          "C64 model ayarlar�"
  IDS_C64BURSTMOD_CAPTION        "C64 s�r�c�s� atlama modifikasyon ayarlar�"
  IDS_C64BURSTMOD_ENABLE         "C64 s�r�c�s� atlama modifikasyonunu aktif et"
  IDS_C64BURSTMOD_CIA            "C64 s�r�c�s� atlama modifikasyon CIA's�"
  IDS_SCPU64_CAPTION             "SuperCPU64 settings"
  IDS_SCPU64_SIMM_SIZE           "SIMM size"
  IDS_SCPU64_JIFFY_SWITCH_ENABLE "Enable the jiffy switch"
  IDS_SCPU64_SPEED_SWITCH_ENABLE "Enable the speed switch"
  IDS_MI_C64BURSTMOD_SETTINGS    "C64 s�r�c�s� atlama modifikasyon ayarlar�..."
  IDS_MI_SCPU64_SETTINGS         "SuperCPU64 settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif

