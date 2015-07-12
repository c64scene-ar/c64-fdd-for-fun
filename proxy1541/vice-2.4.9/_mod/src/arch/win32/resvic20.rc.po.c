
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

#define FILE_DESCRIPTION  "Vice VIC20 Emulator"



IDR_MENUVIC MENU DISCARDABLE
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
            MENUITEM "", IDM_CART_VIC20_GENERIC
            MENUITEM "", IDM_CART_VIC20_MEGACART
            MENUITEM "", IDM_CART_VIC20_FINAL_EXPANSION
            MENUITEM "", IDM_CART_VIC20_FP
            MENUITEM SEPARATOR
            POPUP N_("Add to generic cartridge")
            BEGIN
                MENUITEM "", IDM_CART_SMART_ATTACH
                MENUITEM "", IDM_CART_VIC20_8KB_2000
                MENUITEM "", IDM_CART_VIC20_16KB_4000
                MENUITEM "", IDM_CART_VIC20_8KB_6000
                MENUITEM "", IDM_CART_VIC20_8KB_A000
                MENUITEM "", IDM_CART_VIC20_4KB_B000
            END
            MENUITEM SEPARATOR
            MENUITEM "", IDM_CART_SET_DEFAULT
        END
        MENUITEM "", IDM_CART_DETACH
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
            MENUITEM "", IDM_TOGGLE_MAINCPU_TRACE, CHECKED
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
        MENUITEM "", IDM_TOGGLE_WARP_MODE, CHECKED
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
            MENUITEM "", IDM_SWAP_EXTRA_JOYSTICK
            MENUITEM "", IDM_ALLOW_JOY_OPPOSITE_TOGGLE
            MENUITEM "", IDM_JOYKEYS_TOGGLE
        END
        MENUITEM "", IDM_PADDLES
        MENUITEM "", IDM_LIGHTPEN_SETTINGS
        MENUITEM SEPARATOR
        MENUITEM "", IDM_VIDEO_SETTINGS
        MENUITEM "", IDM_TOGGLE_FULLSCREEN
        MENUITEM "", IDM_TOGGLE_ALWAYSONTOP
        MENUITEM SEPARATOR
        MENUITEM "", IDM_VIC20MODEL_SETTINGS
        MENUITEM "", IDM_VIC20_SETTINGS
        POPUP N_("Video standard")
        BEGIN
            MENUITEM "", IDM_SYNC_FACTOR_PAL
            MENUITEM "", IDM_SYNC_FACTOR_NTSC
        END
        MENUITEM "", IDM_RAM_SETTINGS
        MENUITEM "", IDM_ROM_SETTINGS
        MENUITEM "", IDM_VIC_SETTINGS
        MENUITEM SEPARATOR
        POPUP N_("Cartridge/IO settings")
        BEGIN
            MENUITEM "", IDM_MEGACART_WRITEBACK
            MENUITEM "", IDM_MEGACART_WRITEBACK_FILE
            MENUITEM "", IDM_FINAL_EXPANSION_WRITEBACK
            MENUITEM "", IDM_VIC_FLASH_PLUGIN_WRITEBACK
            MENUITEM "", IDM_SIDCART_SETTINGS
            MENUITEM "", IDM_IEEE488
            MENUITEM SEPARATOR
            MENUITEM "", IDM_DIGIMAX_SETTINGS
            MENUITEM "", IDM_DS12C887RTC_SETTINGS
            MENUITEM "", IDM_GEORAM_SETTINGS
            MENUITEM "", IDM_SFX_SE_SETTINGS
            MENUITEM "", IDM_SFX_SS_SETTINGS
#ifdef HAVE_TFE
            MENUITEM "", IDM_TFE_SETTINGS
#endif
            MENUITEM "", IDM_MIDI_SETTINGS
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




IDD_VIC20ROM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 70
BEGIN
    LTEXT      "", IDC_KERNAL,
               9, 8, 40, 8
    EDITTEXT   IDC_VIC20ROM_KERNAL_FILE,
               55, 7, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_VIC20ROM_KERNAL_BROWSE,
               185, 7, 50, 14, 0

    LTEXT      "",  IDC_BASIC,
               9, 28, 40, 8
    EDITTEXT   IDC_VIC20ROM_BASIC_FILE,
               55, 27, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_VIC20ROM_BASIC_BROWSE,
               185, 27, 50, 14, 0

    LTEXT      "", IDC_CHARACTER,
               9, 48, 40, 8
    EDITTEXT   IDC_VIC20ROM_CHARGEN_FILE,
               55, 47, 125, 12, WS_TABSTOP | ES_AUTOHSCROLL
    PUSHBUTTON "", IDC_VIC20ROM_CHARGEN_BROWSE,
               185, 47, 50, 14, 0
END



IDD_VIC20DRIVEROM_SETTINGS_DIALOG DIALOG DISCARDABLE  0, 0, 240, 250
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
END




IDD_VIC20_SETTINGS_DIALOG DIALOG DISCARDABLE  0, 0, 215, 130
BEGIN
    DEFPUSHBUTTON   "", IDOK,
                    30, 110, 50, 14
    PUSHBUTTON      "", IDCANCEL,
                    90, 110, 50, 14
    GROUPBOX        "", IDC_VIC_MEMORY,
                    7, 7, 200, 95
    AUTORADIOBUTTON "", IDC_VIC_NOEXPANSION,
                    12, 23, 90, 10, BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP
    AUTORADIOBUTTON "", IDC_VIC_3KEXPANSION,
                    12, 36, 90, 10, BS_AUTORADIOBUTTON
    AUTORADIOBUTTON "", IDC_VIC_8KEXPANSION,
                    12, 49, 90, 10, BS_AUTORADIOBUTTON
    AUTORADIOBUTTON "", IDC_VIC_16KEXPANSION,
                    12, 62, 90, 10, BS_AUTORADIOBUTTON
    AUTORADIOBUTTON "", IDC_VIC_24KEXPANSION,
                    12, 75, 90, 10, BS_AUTORADIOBUTTON
    AUTORADIOBUTTON "", IDC_VIC_FULLEXPANSION,
                    12, 88, 90, 10, BS_AUTORADIOBUTTON
    AUTORADIOBUTTON "", IDC_VIC_CUSTOMEXPANSION,
                    120, 23, 50, 10, BS_AUTORADIOBUTTON
    AUTOCHECKBOX    "", IDC_VIC_MEMORY_BLOCK0,
                    132, 35, 50, 10, BS_AUTOCHECKBOX | WS_GROUP | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_VIC_MEMORY_BLOCK1,
                    132, 47, 50, 10, BS_AUTOCHECKBOX | WS_GROUP | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_VIC_MEMORY_BLOCK2,
                    132, 59, 50, 10, BS_AUTOCHECKBOX | WS_GROUP | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_VIC_MEMORY_BLOCK3,
                    132, 71, 50, 10, BS_AUTOCHECKBOX | WS_GROUP | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_VIC_MEMORY_BLOCK5,
                    132, 83, 50, 10, BS_AUTOCHECKBOX | WS_GROUP | WS_TABSTOP
END



IDD_VIC20KBD_MAPPING_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 240, 120
BEGIN
    AUTORADIOBUTTON "", IDC_VIC20KBD_MAPPING_SELECT_SYM,
                    10, 10, 54, 10, BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP
    AUTORADIOBUTTON "", IDC_VIC20KBD_MAPPING_SELECT_POS,
                    10, 30, 54, 10, BS_AUTORADIOBUTTON

    EDITTEXT        IDC_VIC20KBD_MAPPING_SYM,
                    65, 9, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_VIC20KBD_MAPPING_SYM_BROWSE,
                    185, 9, 50, 14, 0
    EDITTEXT        IDC_VIC20KBD_MAPPING_POS,
                    65, 29, 110, 12, WS_TABSTOP
    PUSHBUTTON      "", IDC_VIC20KBD_MAPPING_POS_BROWSE,
                    185, 29, 50, 14, 0

    PUSHBUTTON      "", IDC_VIC20KBD_MAPPING_DUMP,
                    10, 54, 60, 14, 0
    PUSHBUTTON      "", IDC_KBD_SHORTCUT_DUMP,
                    80, 54, 60, 14, 0

    DEFPUSHBUTTON   "", IDOK,
                    20, 100, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    80, 100, 50, 14, WS_TABSTOP
END



IDD_VIC20MODEL_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 150, 80
CAPTION ""
BEGIN
    LTEXT         "", IDC_VIC20MODEL_LABEL,
                  4, 12, 60, 8
    COMBOBOX      IDC_VIC20MODEL_LIST,
                  45, 11, 90, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP


    DEFPUSHBUTTON   "", IDOK,
                    20, 60, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    80, 60, 50, 14, WS_TABSTOP
END



STRINGTABLE
BEGIN
    IDS_VIC20_CAPTION                        N_("VIC20 settings")
    IDS_VIC_NOEXPANSION                      N_("No expansion memory")
    IDS_VIC_3KEXPANSION                      N_("3K (block 0)")
    IDS_VIC_8KEXPANSION                      N_("8K (block 1)")
    IDS_VIC_16KEXPANSION                     N_("16K (blocks 1/2)")
    IDS_VIC_24KEXPANSION                     N_("24K (blocks 1/2/3)")
    IDS_VIC_FULLEXPANSION                    N_("Full (blocks 0/1/2/3/5)")
    IDS_VIC_CUSTOMEXPANSION                  N_("Custom")
    IDS_VIC_BLOCK0                           N_("Block 0 (3K at $0400-$0FFF)")
    IDS_VIC_BLOCK1                           N_("Block 1 (8K at $2000-$3FFF)")
    IDS_VIC_BLOCK2                           N_("Block 2 (8K at $4000-$5FFF)")
    IDS_VIC_BLOCK3                           N_("Block 3 (8K at $6000-$7FFF)")
    IDS_VIC_BLOCK5                           N_("Block 5 (8K at $A000-$BFFF)")
    IDS_SELECT_GENERIC                       N_("Select generic cartridge image")
    IDS_SELECT_MEGACART                      N_("Select Mega-Cart image")
    IDS_SELECT_FINAL_EXPANSION               N_("Select Final Expansion image")
    IDS_SELECT_FP                            N_("Select Vic Flash Plugin image")
    IDS_ATTACH_4_8_16_CART_2000              N_("Attach 4/8/16KB cartridge image at $2000")
    IDS_ATTACH_4_8_16_CART_4000              N_("Attach 4/8/16KB cartridge image at $4000")
    IDS_ATTACH_4_8_16_CART_6000              N_("Attach 4/8/16KB cartridge image at $6000")
    IDS_ATTACH_4_8_CART_A000                 N_("Attach 4/8KB cartridge image at $A000")
    IDS_ATTACH_4_CART_B000                   N_("Attach 4KB cartridge image at $B000")
    IDS_IO_SWAP                              N_("Enable MasC=uerade I/O swap")
    IDS_VIC20MODEL                           N_("VIC20 model")
    IDS_MI_IEEE488                           N_("VIC-1112 IEEE-488 module")
    IDS_MI_PADDLES                           N_("Enable paddles")
    IDS_MI_CART_VIC20_GENERIC                N_("Generic image")
    IDS_MI_CART_VIC20_MEGACART               N_("Mega-Cart image")
    IDS_MI_CART_VIC20_FINAL_EXPANSION        N_("Final Expansion image")
    IDS_MI_CART_VIC20_FP                     N_("Vic Flash Plugin image")
    IDS_MP_ADD_TO_GENERIC                    N_("Add to generic cartridge")
    IDS_MI_CART_VIC20_8KB_2000               N_("4/8/16KB image at $2000")
    IDS_MI_CART_VIC20_16KB_4000              N_("4/8/16KB image at $4000")
    IDS_MI_CART_VIC20_8KB_6000               N_("4/8/16KB image at $6000")
    IDS_MI_CART_VIC20_8KB_A000               N_("4/8KB image at $A000")
    IDS_MI_CART_VIC20_4KB_B000               N_("4KB image at $B000")
    IDS_MI_VIC20_SETTINGS                    N_("VIC20 settings")
    IDS_MI_FINAL_EXPANSION_WRITEBACK         N_("Enable Final Expansion write back to ROM file")
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        N_("Enable Vic Flash Plugin write back to ROM file")
    IDS_MI_MEGACART_WRITEBACK                N_("Enable Mega-Cart NvRAM writeback")
    IDS_MI_MEGACART_WRITEBACK_FILE           N_("Select Mega-Cart non-volatile RAM file")
    IDS_MI_ACIA_SETTINGS_MASCUERADE          N_("ACIA settings")
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        N_("GEO-RAM settings")
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       N_("DigiMAX settings")
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   N_("DS12C887 RTC settings")
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           N_("Ethernet settings")
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        N_("SFX Sound Expander settings")
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        N_("SFX Sound Sampler settings")
    IDS_MI_VIC_SETTINGS                      N_("VIC settings")
    IDS_MI_VIC20MODEL_SETTINGS               N_("VIC20 model settings")
END



STRINGTABLE
LANGUAGE LANG_DANISH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20-indstillinger"
    IDS_VIC_NOEXPANSION                      "Ingen hukommelsesudviddelse"
    IDS_VIC_3KEXPANSION                      "3k (block 0)"
    IDS_VIC_8KEXPANSION                      "8k (block 1)"
    IDS_VIC_16KEXPANSION                     "16k (block 1/2)"
    IDS_VIC_24KEXPANSION                     "24k (block 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Alle (block 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Egen"
    IDS_VIC_BLOCK0                           "Block 0 (3k p� $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Block 1 (8k p� $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Block 2 (8k p� $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Block 3 (8k p� $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Block 5 (8k p� $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "V�lg standardcartridgeimage"
    IDS_SELECT_MEGACART                      "V�lg MegaCart-imagefil"
    IDS_SELECT_FINAL_EXPANSION               "V�lg Final Expansion-imagefil"
    IDS_SELECT_FP                            "V�lg Vic Flash Plugin-image"
    IDS_ATTACH_4_8_16_CART_2000              "Tilslut 4/8/16kB-cartridge image p� $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Tilslut 4/8/16kB-cartridge image p� $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Tilslut 4/8/16kB-cartridge image p� $6000"
    IDS_ATTACH_4_8_CART_A000                 "Tilslut 4/8kB-cartridge image p� $A000"
    IDS_ATTACH_4_CART_B000                   "Tilslut 4kB-cartridge image p� $B000"
    IDS_IO_SWAP                              "Aktiv�r MasC=uerade I/O-ombytning"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488-modul"
    IDS_MI_PADDLES                           "Aktiv�r paddles"
    IDS_MI_CART_VIC20_GENERIC                "Standard-image..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart image..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion-image..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin-image..."
    IDS_MP_ADD_TO_GENERIC                    "Tilf�j til standardcartridge..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB-image p� $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB-image p� $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB-image p� $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB-image p� $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB-image p� $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20-indstillinger..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Aktiv�r Final Expansion tilbageskrivning til ROM-fil"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Aktiv�r Vic Flash Plugin tilbageskrivning til ROM-fil"
    IDS_MI_MEGACART_WRITEBACK                "Aktiv�r Mega-Cart NvRAM tilbageskrivning"
    IDS_MI_MEGACART_WRITEBACK_FILE           "V�lg Mega-Cart NVRAM-fil"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA-indstillinger (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM-indstillinger (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX-indstillinger (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC-indstillinger (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernetindstillinger (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander-indstillinger (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler-indstillinger (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC-indstillinger..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model settings..."
END



STRINGTABLE
LANGUAGE LANG_GERMAN, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20 Einstellungen"
    IDS_VIC_NOEXPANSION                      "Keine Speichererweiterung"
    IDS_VIC_3KEXPANSION                      "3K (Block 0)"
    IDS_VIC_8KEXPANSION                      "8K (Block 1)"
    IDS_VIC_16KEXPANSION                     "16K (Bl�cke 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (Bl�cke 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Alle (Bl�cke 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Benutzerdefiniert"
    IDS_VIC_BLOCK0                           "Block 0 (3K bei $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Block 1 (8K bei $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Block 2 (8K bei $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Block 3 (8K bei $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Block 5 (8K bei $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Unverselles Erweiterungsmodul Image Datei w�hlen"
    IDS_SELECT_MEGACART                      "Mega-Cart Image Date w�hlen"
    IDS_SELECT_FINAL_EXPANSION               "Final Expansion Image Datei ausw�hlen"
    IDS_SELECT_FP                            "Vic Flash Plugin Image ausw�hlen"
    IDS_ATTACH_4_8_16_CART_2000              "4/8/16KB Modul Image bei $2000 einlegen"
    IDS_ATTACH_4_8_16_CART_4000              "4/8/16KB Modul Image bei $4000 einlegen"
    IDS_ATTACH_4_8_16_CART_6000              "4/8/16KB Modul Image bei $6000 einlegen"
    IDS_ATTACH_4_8_CART_A000                 "4/8KB Modul Image bei $A000 einlegen"
    IDS_ATTACH_4_CART_B000                   "4KB Modul Image bei $B000 einlegen"
    IDS_IO_SWAP                              "MasC=uerade I/O swap aktivieren"
    IDS_VIC20MODEL                           "VIC20 Modell"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488 Modul"
    IDS_MI_PADDLES                           "Paddles aktivieren"
    IDS_MI_CART_VIC20_GENERIC                "Generisches Image..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart Image..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion Image..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin Image..."
    IDS_MP_ADD_TO_GENERIC                    "Zu universellem Erweiterungsmodul hinzuf�gen..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB Image bei $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB Image bei $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB Image bei $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB Image bei $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB Image bei $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20 Einstellungen..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Final Expansion ROM Schreibzugriff aktivieren"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Vic Flash Plugin R�ckschreiben auf ROM Datei aktivieren"
    IDS_MI_MEGACART_WRITEBACK                "Mega-Cart NvRAM R�ckschreiben aktivieren"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Mega-Cart nicht-fl�chtiges RAM Datei w�hlen"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA Einstellungen (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM Einstellungen (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX Einstellungen (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC Einstellungen (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernet Einstellungen (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander Einstellungen (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler Einstellungen (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC Einstellungen..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 Modell Einstellungen..."
END



STRINGTABLE
LANGUAGE LANG_SPANISH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "Ajustes VIC20"
    IDS_VIC_NOEXPANSION                      "Sin expansi�n de memoria"
    IDS_VIC_3KEXPANSION                      "3K (bloque 0)"
    IDS_VIC_8KEXPANSION                      "8K (bloque 1)"
    IDS_VIC_16KEXPANSION                     "16K (bloques 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (bloques 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Completo (bloques 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Personalizado"
    IDS_VIC_BLOCK0                           "Bloque 0 (3K at $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Bloque 1 (8K at $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Bloque 2 (8K at $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Bloque 3 (8K at $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Bloque 5 (8K at $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Seleccionar imagen cartucho generico"
    IDS_SELECT_MEGACART                      "Seleccionar imagen Mega-Cart"
    IDS_SELECT_FINAL_EXPANSION               "Seleccionar imagen Final Expansion"
    IDS_SELECT_FP                            "Seleccionar imagen Vic Flash Plugin"
    IDS_ATTACH_4_8_16_CART_2000              "Insertar 4/8/16KB imagen cartucho en $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Insertar 4/8/16KB imagen cartucho en $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Insertar 4/8/16KB imagen cartucho en $6000"
    IDS_ATTACH_4_8_CART_A000                 "Insertar 4/8KB imagen cartucho en $A000"
    IDS_ATTACH_4_CART_B000                   "Insertar 4KB imagen cartucho en $B000"
    IDS_IO_SWAP                              "Permitir intercambio MasC=uerade Entrada/Salida"
    IDS_VIC20MODEL                           "Modelo VIC20"
    IDS_MI_IEEE488                           "M�dulo VIC-1112 IEEE-488"
    IDS_MI_PADDLES                           "Permitir paddles"
    IDS_MI_CART_VIC20_GENERIC                "Imagen generica..."
    IDS_MI_CART_VIC20_MEGACART               "Imagen Mega-Cart..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Imagen Final Expansion..."
    IDS_MI_CART_VIC20_FP                     "Imagen Vic Flash Plugin..."
    IDS_MP_ADD_TO_GENERIC                    "A�adir al cartucho generico..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB imagen en $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB imagen en $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB imagen en $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB imagen en $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB imagen en $B000..."
    IDS_MI_VIC20_SETTINGS                    "Ajustes VIC20..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Permitir grabaci�n en fichero ROM Final Expansion"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Permitir grabacion en ROM Vic Flash Plugin"
    IDS_MI_MEGACART_WRITEBACK                "Permitir respuesta Mega-Cart NvRAM"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Seleccionar fichero RAM Mega-Cart no volatil"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "Ajustes ACIA (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "Ajustes GEO-RAM (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "Ajustes DigiMAX (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "Ajustes DS12C887 RTC (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ajustes Ethernet (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "Ajustes SFX Sound Expander (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "Ajustes SFX Sound Sampler (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "Ajustes VIC..."
    IDS_MI_VIC20MODEL_SETTINGS               "Ajustes modelo VIC20..."
END



STRINGTABLE
LANGUAGE LANG_FRENCH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "Param�tres VIC20"
    IDS_VIC_NOEXPANSION                      "Aucune expansion de m�moire"
    IDS_VIC_3KEXPANSION                      "3 ko (block 0)"
    IDS_VIC_8KEXPANSION                      "8 ko (block 1)"
    IDS_VIC_16KEXPANSION                     "16 ko (block 1/2)"
    IDS_VIC_24KEXPANSION                     "24 ko (block 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Tous (blocks 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Personnalis�"
    IDS_VIC_BLOCK0                           "Bloc 0 (3 ko � $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Bloc 1 (8 ko � $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Bloc 2 (8 ko � $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Bloc 3 (8 ko � $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Bloc 5 (8 ko � $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "S�lectionner l'image de cartouche g�n�rique"
    IDS_SELECT_MEGACART                      "S�lectionner l'image Mega-Cart"
    IDS_SELECT_FINAL_EXPANSION               "S�lectionner l'image ROM Final Expansion"
    IDS_SELECT_FP                            "S�lectionner l'image Vic Flash Plugin"
    IDS_ATTACH_4_8_16_CART_2000              "Insertion d'une image 4/8/16 ko � $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Insertion d'une image 4/8/16 ko � $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Insertion d'une image 4/8/16 ko � $6000"
    IDS_ATTACH_4_8_CART_A000                 "Insertion d'une image 4/8 ko � $A000"
    IDS_ATTACH_4_CART_B000                   "Insertion d'une image 4 ko � $B000"
    IDS_IO_SWAP                              "Activer la permutation E/S MasC=uerade"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "Module VIC-1112 IEEE 488"
    IDS_MI_PADDLES                           "Activer paddles"
    IDS_MI_CART_VIC20_GENERIC                "Image g�n�rique..."
    IDS_MI_CART_VIC20_MEGACART               "Image Mega-Cart..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Image Final Expansion..."
    IDS_MI_CART_VIC20_FP                     "Image Vic Flash Plugin..."
    IDS_MP_ADD_TO_GENERIC                    "Ajouter � une cartouche g�n�rique..."
    IDS_MI_CART_VIC20_8KB_2000               "image 4/8/16 ko � $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "image 4/8/16 ko � $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "image 4/8/16 ko � $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "image 4/8 ko � $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "image 4 ko � $B000..."
    IDS_MI_VIC20_SETTINGS                    "Param�tres VIC20..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Activer la r��criture du fichier ROM Final Expansion"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Activer la r��criture du fichier ROM Vic Flash Plugin"
    IDS_MI_MEGACART_WRITEBACK                "Permettre la r��criture de l'image Mega-Cart"
    IDS_MI_MEGACART_WRITEBACK_FILE           "S�lectionner le fichier de RAM non-volatile Mega-Cart"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "Param�tres ACIA (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "Param�tres GEO-RAM (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "Param�tres DigiMAX (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "Param�tres DS12C887 RTC (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Param�tres Ethernet (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "Param�tres du SFX Sound Expander (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "Param�tres du SFX Sound Sampler (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "Param�tres VIC..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model settings..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_HUNGARIAN, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20 settings"
    IDS_VIC_NOEXPANSION                      "Nincs mem�ria b�v�t�s"
    IDS_VIC_3KEXPANSION                      "3K (blokk 0)"
    IDS_VIC_8KEXPANSION                      "8K (blokk 1)"
    IDS_VIC_16KEXPANSION                     "16K (blokk 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (blokk 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Full (blocks 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Egy�ni"
    IDS_VIC_BLOCK0                           "Block 0 (3K at $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Block 1 (8K at $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Block 2 (8K at $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Block 3 (8K at $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Block 5 (8K at $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Select generic cartridge image"
    IDS_SELECT_MEGACART                      "V�lassza ki a Mega-Cart k�pm�st"
    IDS_SELECT_FINAL_EXPANSION               "V�lassza ki a Final Expansion k�pm�st"
    IDS_SELECT_FP                            "Select Vic Flash Plugin image"
    IDS_ATTACH_4_8_16_CART_2000              "4/8/16KB k�pm�s csatol�sa $2000 c�mre"
    IDS_ATTACH_4_8_16_CART_4000              "4/8/16KB k�pm�s csatol�sa $4000 c�mre"
    IDS_ATTACH_4_8_16_CART_6000              "4/8/16KB k�pm�s csatol�sa $6000 c�mre"
    IDS_ATTACH_4_8_CART_A000                 "4/8KB k�pm�s csatol�sa $A000 c�mre"
    IDS_ATTACH_4_CART_B000                   "4KB k�pm�s csatol�sa $B000 c�mre"
    IDS_IO_SWAP                              "Enable MasC=uerade I/O swap"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488 module"
    IDS_MI_PADDLES                           "Enable paddles"
    IDS_MI_CART_VIC20_GENERIC                "Generic image..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart image..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion image..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin image..."
    IDS_MP_ADD_TO_GENERIC                    "Hozz�ad�s �ltal�nos cartridge-hoz..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB image at $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB image at $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB image at $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB image at $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB image at $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20 settings..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Final Expansion ROM f�jlba vissza�r�s enged�lyez�se"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Enable Vic Flash Plugin write back to ROM file"
    IDS_MI_MEGACART_WRITEBACK                "Enable Mega-Cart NvRAM writeback"
    IDS_MI_MEGACART_WRITEBACK_FILE           "V�lassza ki az NvRAM k�pf�jlt"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA settings (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM settings (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX settings (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC settings (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernet settings (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander settings (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler settings (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC be�ll�t�sai..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_ITALIAN, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "Impostazioni VIC20"
    IDS_VIC_NOEXPANSION                      "Nessuna espansione di memoria"
    IDS_VIC_3KEXPANSION                      "3K (blocco 0)"
    IDS_VIC_8KEXPANSION                      "8K (blocco 1)"
    IDS_VIC_16KEXPANSION                     "16K (blocchi 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (blocchi 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Tutti (Blocchi 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Personalizzato"
    IDS_VIC_BLOCK0                           "Blocco 0 (3K a $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Blocco 1 (8K a $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Blocco 2 (8K a $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Blocco 3 (8K a $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Blocco 5 (8K a $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Seleziona immagine cartuccia generica"
    IDS_SELECT_MEGACART                      "Seleziona immagine Mega-Cart"
    IDS_SELECT_FINAL_EXPANSION               "Seleziona immagine Final Expansion"
    IDS_SELECT_FP                            "Seleziona immagine Vic Flash Plugin "
    IDS_ATTACH_4_8_16_CART_2000              "Seleziona immagine cartuccia di 4/8/16KB a $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Seleziona immagine cartuccia di 4/8/16KB a $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Seleziona immagine cartuccia di 4/8/16KB a $6000"
    IDS_ATTACH_4_8_CART_A000                 "Seleziona immagine cartuccia di 4/8KB a $A000"
    IDS_ATTACH_4_CART_B000                   "Seleziona immagine cartuccia di 4KB a $B000"
    IDS_IO_SWAP                              "Attiva I/O swap MasC=uerade"
    IDS_VIC20MODEL                           "Modello VIC20"
    IDS_MI_IEEE488                           "Modulo VIC-1112 IEEE-488"
    IDS_MI_PADDLES                           "Attiva paddle"
    IDS_MI_CART_VIC20_GENERIC                "Immagine generica..."
    IDS_MI_CART_VIC20_MEGACART               "Immagine Mega-Cart..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Immagine Final Expansion..."
    IDS_MI_CART_VIC20_FP                     "Immagine Vic Flash Plugin..."
    IDS_MP_ADD_TO_GENERIC                    "Aggiungi a cartuccia generica..."
    IDS_MI_CART_VIC20_8KB_2000               "Immagine di 4/8/16KB a $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "Immagine di 4/8/16KB a $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "Immagine di 4/8/16KB a $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "Immagine di 4/8KB a $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "Immagine di 4KB a $B000..."
    IDS_MI_VIC20_SETTINGS                    "Impostazioni VIC20..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Attiva write back per Final Expansion su file ROM"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Attiva write back per Vic Flash Plugin su file ROM"
    IDS_MI_MEGACART_WRITEBACK                "Write back NvRAM Mega-Cart"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Seleziona file non-volatile RAM Mega-Cart"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "Impostazioni ACIA (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "Impostazioni GEO-RAM (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "Impostazioni DigiMAX (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "Impostazioni DS12C887 RTC (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Impostazioni Ethernet (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "Impostazioni SFX Sound Expander (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "Impostazioni SFX Sound Sampler (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "Impostazioni VIC..."
    IDS_MI_VIC20MODEL_SETTINGS               "Impostazioni modello VIC20..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(949)
#endif
STRINGTABLE
LANGUAGE LANG_KOREAN, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20 settings"
    IDS_VIC_NOEXPANSION                      "Ȯ�� �޸� ����"
    IDS_VIC_3KEXPANSION                      "3k (block 0)"
    IDS_VIC_8KEXPANSION                      "8k (block 1)"
    IDS_VIC_16KEXPANSION                     "16k (block 1/2)"
    IDS_VIC_24KEXPANSION                     "24k (block 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Full (blocks 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Ŀ����"
    IDS_VIC_BLOCK0                           "block 0 (3k $0400-$0FFF ����)"
    IDS_VIC_BLOCK1                           "block 1 (8k $2000-$3FFF ����)"
    IDS_VIC_BLOCK2                           "block 2 (8k $4000-$5FFF ����)"
    IDS_VIC_BLOCK3                           "block 3 (8k $6000-$7FFF ����)"
    IDS_VIC_BLOCK5                           "block 5 (8k $A000-$BFFF ����)"
    IDS_SELECT_GENERIC                       "Select generic cartridge image"
    IDS_SELECT_MEGACART                      "Select Mega-Cart image"
    IDS_SELECT_FINAL_EXPANSION               "Select Final Expansion image"
    IDS_SELECT_FP                            "Select Vic Flash Plugin image"
    IDS_ATTACH_4_8_16_CART_2000              "4/8/16KB īƮ���� �̹��� ��  $2000 �� ���̱�"
    IDS_ATTACH_4_8_16_CART_4000              "4/8/16KB īƮ���� �̹��� ��  $4000 �� ���̱�"
    IDS_ATTACH_4_8_16_CART_6000              "4/8/16KB īƮ���� �̹��� ��  $6000 �� ���̱�"
    IDS_ATTACH_4_8_CART_A000                 "4/8KB īƮ���� �̹��� ��  $A000 �� ���̱�"
    IDS_ATTACH_4_CART_B000                   "4KB īƮ���� �̹��� ��  $B000 �� ���̱�"
    IDS_IO_SWAP                              "Enable MasC=uerade I/O swap"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488 module"
    IDS_MI_PADDLES                           "�е� ��밡���ϰ� �ϱ�"
    IDS_MI_CART_VIC20_GENERIC                "Generic image..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart image..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion image..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin image..."
    IDS_MP_ADD_TO_GENERIC                    "���ʸ� īƮ������ ���ϱ�..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB image at $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB image at $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB image at $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB image at $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB image at $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20 settings..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Enable Final Expansion write back to ROM file"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Enable Vic Flash Plugin write back to ROM file"
    IDS_MI_MEGACART_WRITEBACK                "Enable Mega-Cart NvRAM writeback"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Select Mega-Cart non-volatile RAM file"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA ���� (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM ���� (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX ���� (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC settings (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "�̴��� ���� (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander ���� (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler settings (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC ����..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_DUTCH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20 instellingen"
    IDS_VIC_NOEXPANSION                      "Geen geheugenuitbreiding"
    IDS_VIC_3KEXPANSION                      "3K (blok 0)"
    IDS_VIC_8KEXPANSION                      "8K (blok 1)"
    IDS_VIC_16KEXPANSION                     "16K (blokken 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (blokken 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Alles (blokken 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Aangepast"
    IDS_VIC_BLOCK0                           "Blok 0 (3K in $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Blok 1 (8K in $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Blok 2 (8K in $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Blok 3 (8K in $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Blok 5 (8K in $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Selecteer algemeen cartridge bestand"
    IDS_SELECT_MEGACART                      "Selecteer Mega-Cart bestand"
    IDS_SELECT_FINAL_EXPANSION               "Selecteer Final Expansion bestand"
    IDS_SELECT_FP                            "Selecteer Vic Flash Plugin bestand"
    IDS_ATTACH_4_8_16_CART_2000              "Koppel 4/8/16KB bestand op $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Koppel 4/8/16KB bestand op $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Koppel 4/8/16KB bestand op $6000"
    IDS_ATTACH_4_8_CART_A000                 "Koppel 4/8KB bestand op $A000"
    IDS_ATTACH_4_CART_B000                   "Koppel 4KB bestand op $B000"
    IDS_IO_SWAP                              "Activeer MasC=uerade I/O verwisseling"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488 module"
    IDS_MI_PADDLES                           "Activeer paddles"
    IDS_MI_CART_VIC20_GENERIC                "Algemeen bestand..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart bestand..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion bestand..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin bestand..."
    IDS_MP_ADD_TO_GENERIC                    "Voeg toe aan algemeen cartridge..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB bestand in $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB bestand in $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB bestand in $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB bestand in $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB bestand in $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20 instellingen..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Activeer terug schrijven naar ROM bestand voor Final Expansion"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Activeer terug schrijven naar ROM bestand voor Vic Flash Plugin"
    IDS_MI_MEGACART_WRITEBACK                "Activeer Mega-Cart NvRAM terug schrijven"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Selecteer Mega-Cart non-volatile RAM bestand"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA instellingen (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM instellingen (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX instellingen (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC instellingen (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernet instellingen (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander instellingen (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler instellingen (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC instellingen..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model instellingen..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_POLISH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "Ustawienia VIC20"
    IDS_VIC_NOEXPANSION                      "Bez rozszerzenia pami�ci"
    IDS_VIC_3KEXPANSION                      "3K (blok 0)"
    IDS_VIC_8KEXPANSION                      "8K (blok 1)"
    IDS_VIC_16KEXPANSION                     "16K (bloki 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (bloki 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Wszystkie (bloki 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "W�asna"
    IDS_VIC_BLOCK0                           "Blok 0 (3K w $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Blok 1 (8K w $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Blok 2 (8K w $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Blok 3 (8K w $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Blok 5 (8K w $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Wybierz typowy obraz kartrid�a"
    IDS_SELECT_MEGACART                      "Wybierz obraz Mega-Cart"
    IDS_SELECT_FINAL_EXPANSION               "Wybierz obraz Final Expansion"
    IDS_SELECT_FP                            "Wybierz obraz Vic Flash Plugin"
    IDS_ATTACH_4_8_16_CART_2000              "Wsu� 4/8/16KB obraz w $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Wsu� 4/8/16KB obraz w $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Wsu� 4/8/16KB obraz w $6000"
    IDS_ATTACH_4_8_CART_A000                 "Wsu� 4/8KB obraz w $A000"
    IDS_ATTACH_4_CART_B000                   "Wsu� 4KB obraz w $B000"
    IDS_IO_SWAP                              "W��cz zamian� we/wy MasC=uerade"
    IDS_VIC20MODEL                           "Model VIC20"
    IDS_MI_IEEE488                           "Modu� IEEE-488 VIC-1112"
    IDS_MI_PADDLES                           "W��cz pokr�t�a steruj�ce"
    IDS_MI_CART_VIC20_GENERIC                "Standardowy obraz..."
    IDS_MI_CART_VIC20_MEGACART               "Obraz Mega-Cart..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Obraz Final Expansion..."
    IDS_MI_CART_VIC20_FP                     "Obraz Vic Flash Plugin..."
    IDS_MP_ADD_TO_GENERIC                    "Dodaj do standardowego kartrid�a..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB obraz w $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB obraz w $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB obraz w $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB obraz w $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB obraz w $B000..."
    IDS_MI_VIC20_SETTINGS                    "Ustawienia VIC20..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "W��cz zapis do pliku ROM Final Expansion"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "W��cz zapis do pliku ROM Vic Flash Plugin"
    IDS_MI_MEGACART_WRITEBACK                "W��cz zapis do NvRAM Mega-Cart"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Wybierz sta�y plik RAM Mega-Cart"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "Ustawienia ACIA (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "Ustawienia GEO-RAM (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "Ustawienia DigiMAX (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "Ustawienia DS12C887 RTC (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ustawienia Ethernet (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "Ustawienia SFX Sound Expander (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "Ustawienia samplera d�wi�ku SFX (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "Ustawienia VIC..."
    IDS_MI_VIC20MODEL_SETTINGS               "Ustawienia modelu VIC20..."
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
    IDS_VIC20_CAPTION                        "VIC20 settings"
    IDS_VIC_NOEXPANSION                      "No expansion memory"
    IDS_VIC_3KEXPANSION                      "3K (block 0)"
    IDS_VIC_8KEXPANSION                      "8K (block 1)"
    IDS_VIC_16KEXPANSION                     "16K (blocks 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (blocks 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Full (blocks 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Custom"
    IDS_VIC_BLOCK0                           "Block 0 (3K at $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Block 1 (8K at $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Block 2 (8K at $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Block 3 (8K at $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Block 5 (8K at $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "Select generic cartridge image"
    IDS_SELECT_MEGACART                      "Select Mega-Cart image"
    IDS_SELECT_FINAL_EXPANSION               "Select Final Expansion image"
    IDS_SELECT_FP                            "Select Vic Flash Plugin image"
    IDS_ATTACH_4_8_16_CART_2000              "Attach 4/8/16KB cartridge image at $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Attach 4/8/16KB cartridge image at $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Attach 4/8/16KB cartridge image at $6000"
    IDS_ATTACH_4_8_CART_A000                 "Attach 4/8KB cartridge image at $A000"
    IDS_ATTACH_4_CART_B000                   "Attach 4KB cartridge image at $B000"
    IDS_IO_SWAP                              "Enable MasC=uerade I/O swap"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488 module"
    IDS_MI_PADDLES                           "Enable paddles"
    IDS_MI_CART_VIC20_GENERIC                "Generic image..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart image..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion image..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin image..."
    IDS_MP_ADD_TO_GENERIC                    "Add to generic cartridge..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB image at $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB image at $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB image at $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB image at $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB image at $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20 settings..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Enable Final Expansion write back to ROM file"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Enable Vic Flash Plugin write back to ROM file"
    IDS_MI_MEGACART_WRITEBACK                "Enable Mega-Cart NvRAM writeback"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Select Mega-Cart non-volatile RAM file"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA settings (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM settings (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX settings (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC settings (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernet settings (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander settings (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler settings (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC settings..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_SWEDISH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20-inst�llningar"
    IDS_VIC_NOEXPANSION                      "Ingen minnesut�kning"
    IDS_VIC_3KEXPANSION                      "3K (block 0)"
    IDS_VIC_8KEXPANSION                      "8K (block 1)"
    IDS_VIC_16KEXPANSION                     "16K (block 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (block 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Alla (block 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "Egen"
    IDS_VIC_BLOCK0                           "Block 0 (3K p� $0400-$0FFF)"
    IDS_VIC_BLOCK1                           "Block 1 (8K p� $2000-$3FFF)"
    IDS_VIC_BLOCK2                           "Block 2 (8K p� $4000-$5FFF)"
    IDS_VIC_BLOCK3                           "Block 3 (8K p� $6000-$7FFF)"
    IDS_VIC_BLOCK5                           "Block 5 (8K p� $A000-$BFFF)"
    IDS_SELECT_GENERIC                       "V�lj generisk insticksmodulavbildning"
    IDS_SELECT_MEGACART                      "V�lj Mega-Cart-modulfil"
    IDS_SELECT_FINAL_EXPANSION               "V�lj avbildning f�r Final Expansion"
    IDS_SELECT_FP                            "V�lj avbildning f�r Vic Flash-insticksmodul"
    IDS_ATTACH_4_8_16_CART_2000              "Anslut 4/8/16KB-modulfil vid $2000"
    IDS_ATTACH_4_8_16_CART_4000              "Anslut 4/8/16KB-modulfil vid $4000"
    IDS_ATTACH_4_8_16_CART_6000              "Anslut 4/8/16KB-modulfil vid $6000"
    IDS_ATTACH_4_8_CART_A000                 "Anslut 4/8KB-modulfil vid $A000"
    IDS_ATTACH_4_CART_B000                   "Anslut 4KB-modulfil vid $B000"
    IDS_IO_SWAP                              "Aktivera MasC=uerade I/O-v�xling"
    IDS_VIC20MODEL                           "VIC20-modell"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488-modul"
    IDS_MI_PADDLES                           "Aktivera paddlar"
    IDS_MI_CART_VIC20_GENERIC                "Generisk avbild..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart-avbildning..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion-fil..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash insticksmodul-fil..."
    IDS_MP_ADD_TO_GENERIC                    "L�gg till generisk insticksmodul..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB-fil vid $2000..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB-fil vid $4000..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB-fil vid $6000..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB-fil vid $A000..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB-fil vid $B000..."
    IDS_MI_VIC20_SETTINGS                    "VIC20-inst�llningar..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Aktivera �terskrivning till ROM-fil f�r Final Expansion"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Aktivera �terskrivning till ROM-fil f�r Vic Flash-insticksmodul"
    IDS_MI_MEGACART_WRITEBACK                "Aktivera Mega-Cart NvRAM-�terskrivning"
    IDS_MI_MEGACART_WRITEBACK_FILE           "V�lj NvRAM-fil f�r Mega-Cart"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA-inst�llningar (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM-inst�llningar (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX-inst�llningar (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC-inst�llningar (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernetinst�llningar (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "Inst�llningar f�r SFX Sound Expander (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "Inst�llningar f�r SFX Sound Sampler (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC-inst�llningar..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20-modellinst�llningar..."
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28599)
#endif
STRINGTABLE
LANGUAGE LANG_TURKISH, SUBLANG_NEUTRAL
BEGIN
    IDS_VIC20_CAPTION                        "VIC20 ayarlar�"
    IDS_VIC_NOEXPANSION                      "Geni�leti�mi� bellek yok"
    IDS_VIC_3KEXPANSION                      "3K (blok 0)"
    IDS_VIC_8KEXPANSION                      "8K (blok 1)"
    IDS_VIC_16KEXPANSION                     "16K (bloklar 1/2)"
    IDS_VIC_24KEXPANSION                     "24K (bloklar 1/2/3)"
    IDS_VIC_FULLEXPANSION                    "Tam (bloklar 0/1/2/3/5)"
    IDS_VIC_CUSTOMEXPANSION                  "�zel"
    IDS_VIC_BLOCK0                           "Blok 0 ($0400-$0FFF aras�nda 3K)"
    IDS_VIC_BLOCK1                           "Blok 1 ($2000-$3FFF aras�nda 8K)"
    IDS_VIC_BLOCK2                           "Blok 2 ($4000-$5FFF aras�nda 8K)"
    IDS_VIC_BLOCK3                           "Blok 3 ($6000-$7FFF aras�nda 8K)"
    IDS_VIC_BLOCK5                           "Blok 5 ($A000-$BFFF aras�nda 8K)"
    IDS_SELECT_GENERIC                       "Jenerik kartu� imaj� se�"
    IDS_SELECT_MEGACART                      "Mega-Cart imaj� se�"
    IDS_SELECT_FINAL_EXPANSION               "Final Expansion imaj� se�"
    IDS_SELECT_FP                            "Vic Flash Plugin imaj� se�"
    IDS_ATTACH_4_8_16_CART_2000              "$2000 adresine 4/8/16KB kartu� imaj� yerle�tir"
    IDS_ATTACH_4_8_16_CART_4000              "$4000 adresine 4/8/16KB kartu� imaj� yerle�tir"
    IDS_ATTACH_4_8_16_CART_6000              "$6000 adresine 4/8/16KB kartu� imaj� yerle�tir"
    IDS_ATTACH_4_8_CART_A000                 "$A000 adresine 4/8KB kartu� imaj� yerle�tir"
    IDS_ATTACH_4_CART_B000                   "$B000 adresine 4KB kartu� imaj� yerle�tir"
    IDS_IO_SWAP                              "MasC=uerade G/� de�i�imini aktif et"
    IDS_VIC20MODEL                           "VIC20 model"
    IDS_MI_IEEE488                           "VIC-1112 IEEE-488 mod�l�"
    IDS_MI_PADDLES                           "Paddlelar� aktif et"
    IDS_MI_CART_VIC20_GENERIC                "Jenerik imaj..."
    IDS_MI_CART_VIC20_MEGACART               "Mega-Cart imaj�..."
    IDS_MI_CART_VIC20_FINAL_EXPANSION        "Final Expansion imaj�..."
    IDS_MI_CART_VIC20_FP                     "Vic Flash Plugin imaj�..."
    IDS_MP_ADD_TO_GENERIC                    "Jenerik kartu�a ekle..."
    IDS_MI_CART_VIC20_8KB_2000               "4/8/16KB imaj� $2000 adresinde..."
    IDS_MI_CART_VIC20_16KB_4000              "4/8/16KB imaj� $4000 adresinde..."
    IDS_MI_CART_VIC20_8KB_6000               "4/8/16KB imaj� $6000 adresinde..."
    IDS_MI_CART_VIC20_8KB_A000               "4/8KB imaj� $A000 adresinde..."
    IDS_MI_CART_VIC20_4KB_B000               "4KB imaj� $B000 adresinde..."
    IDS_MI_VIC20_SETTINGS                    "VIC20 ayarlar�..."
    IDS_MI_FINAL_EXPANSION_WRITEBACK         "Final Expansion ROM dosyas�na geri yazmay� aktif et"
    IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK        "Flash Plugin ROM dosyas�na geri yazmay� aktif et"
    IDS_MI_MEGACART_WRITEBACK                "Mega-Cart NvRAM geri yazmay� aktif et"
    IDS_MI_MEGACART_WRITEBACK_FILE           "Mega-Cart non-volatile RAM dosyas�n� se�"
    IDS_MI_ACIA_SETTINGS_MASCUERADE          "ACIA Ayarlar� (MasC=uerade)..."
    IDS_MI_GEORAM_SETTINGS_MASCUERADE        "GEO-RAM ayarlar� (MasC=uerade)..."
    IDS_MI_DIGIMAX_SETTINGS_MASCUERADE       "DigiMAX ayarlar� (MasC=uerade)..."
    IDS_MI_DS12C887RTC_SETTINGS_MASCUERADE   "DS12C887 RTC ayarlar� (MasC=uerade)..."
#ifdef HAVE_TFE
    IDS_MI_TFE_SETTINGS_MASCUERADE           "Ethernet Ayarlar� (MasC=uerade)..."
#endif
    IDS_MI_SFX_SE_SETTINGS_MASCUERADE        "SFX Sound Expander Ayarlar� (MasC=uerade)..."
    IDS_MI_SFX_SS_SETTINGS_MASCUERADE        "SFX Sound Sampler ayarlar� (MasC=uerade)..."
    IDS_MI_VIC_SETTINGS                      "VIC ayarlar�..."
    IDS_MI_VIC20MODEL_SETTINGS               "VIC20 model settings..."
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


