/*
 * scpu64ui.c - SCPU64-specific user interface.
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "debug.h"
#include "res.h"
#include "scpu64ui.h"
#include "translate.h"
#include "ui.h"
#include "uiacia.h"
#include "uic64burstmod.h"
#include "uic64cart.h"
#include "uicia.h"
#include "uidigimax.h"
#include "uidqbb.h"
#include "uidrivec64.h"
#include "uids12c887rtc.h"
#include "uieasyflash.h"
#include "uiexpert.h"
#include "uigeoram.h"
#include "uiide64.h"
#include "uiisepic.h"
#include "uijoystick.h"
#include "uikeyboard.h"
#include "uilib.h"
#include "uilightpen.h"
#include "uimagicvoice.h"
#include "uimidi.h"
#include "uimmc64.h"
#include "uimmcreplay.h"
#include "uimouse.h"
#include "uiramcart.h"
#include "uiretroreplay.h"
#include "uireu.h"
#include "uirom.h"
#include "uirs232user.h"
#include "uiscpu64.h"
#include "uiscpu64model.h"
#include "uisid.h"
#include "uisoundexpander.h"
#include "uitfe.h"
#include "uivicii.h"
#include "uivideo.h"

static const ui_menu_toggle_t scpu64_ui_menu_toggles[] = {
    { "Mouse", IDM_MOUSE },
    { "CartridgeReset", IDM_TOGGLE_CART_RESET },
    { "SFXSoundSampler", IDM_TOGGLE_SFX_SS },
    { "UserportRTC", IDM_TOGGLE_USERPORT_RTC },
    { "IECReset", IDM_TOGGLE_RESET_IEC_WITH_CPU },
    { NULL, 0 }
};

static const uirom_settings_t uirom_settings[] = {
    { UIROM_TYPE_MAIN, TEXT("SCPU64"), "SCPU64Name",
      IDC_SCPU64ROM_SCPU64_FILE, IDC_SCPU64ROM_SCPU64_BROWSE },
    { UIROM_TYPE_MAIN, TEXT("Character"), "ChargenName",
      IDC_C64ROM_CHARGEN_FILE, IDC_C64ROM_CHARGEN_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("1541"), "DosName1541",
      IDC_DRIVEROM_1541_FILE, IDC_DRIVEROM_1541_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("1541-II"), "DosName1541ii",
      IDC_DRIVEROM_1541II_FILE, IDC_DRIVEROM_1541II_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("1570"), "DosName1570",
      IDC_DRIVEROM_1570_FILE, IDC_DRIVEROM_1570_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("1571"), "DosName1571",
      IDC_DRIVEROM_1571_FILE, IDC_DRIVEROM_1571_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("1581"), "DosName1581",
      IDC_DRIVEROM_1581_FILE, IDC_DRIVEROM_1581_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("2000"), "DosName2000",
      IDC_DRIVEROM_2000_FILE, IDC_DRIVEROM_2000_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("4000"), "DosName4000",
      IDC_DRIVEROM_4000_FILE, IDC_DRIVEROM_4000_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("2031"), "DosName2031",
      IDC_DRIVEROM_2031_FILE, IDC_DRIVEROM_2031_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("2040"), "DosName2040",
      IDC_DRIVEROM_2040_FILE, IDC_DRIVEROM_2040_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("3040"), "DosName3040",
      IDC_DRIVEROM_3040_FILE, IDC_DRIVEROM_3040_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("4040"), "DosName4040",
      IDC_DRIVEROM_4040_FILE, IDC_DRIVEROM_4040_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("1001"), "DosName1001",
      IDC_DRIVEROM_1001_FILE, IDC_DRIVEROM_1001_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("Professional DOS"), "DriveProfDOS1571Name",
      IDC_DRIVEROM_PROFDOS_FILE, IDC_DRIVEROM_PROFDOS_BROWSE },
    { UIROM_TYPE_DRIVE, TEXT("SuperCard+"), "DriveSuperCardName",
      IDC_DRIVEROM_SUPERCARD_FILE, IDC_DRIVEROM_SUPERCARD_BROWSE },
    { 0, NULL, NULL, 0, 0 }
};

#define SCPU64UI_KBD_NUM_MAP 3

static const uikeyboard_mapping_entry_t mapping_entry[SCPU64UI_KBD_NUM_MAP] = {
    { IDC_C64KBD_MAPPING_SELECT_SYM, IDC_C64KBD_MAPPING_SYM,
      IDC_C64KBD_MAPPING_SYM_BROWSE, "KeymapSymFile" },
    { IDC_C64KBD_MAPPING_SELECT_POS, IDC_C64KBD_MAPPING_POS,
      IDC_C64KBD_MAPPING_POS_BROWSE, "KeymapPosFile" },
    { IDC_C64KBD_MAPPING_SELECT_SYMDE, IDC_C64KBD_MAPPING_SYMDE,
      IDC_C64KBD_MAPPING_SYMDE_BROWSE, "KeymapSymDeFile" }
};

static uilib_localize_dialog_param scpu64_kbd_trans[] = {
    { IDC_C64KBD_MAPPING_SELECT_SYM, IDS_SYMBOLIC_US, 0 },
    { IDC_C64KBD_MAPPING_SELECT_SYMDE, IDS_SYMBOLIC_DE, 0 },
    { IDC_C64KBD_MAPPING_SELECT_POS, IDS_POSITIONAL, 0 },
    { IDC_C64KBD_MAPPING_SYM_BROWSE, IDS_BROWSE, 0 },
    { IDC_C64KBD_MAPPING_SYMDE_BROWSE, IDS_BROWSE, 0 },
    { IDC_C64KBD_MAPPING_POS_BROWSE, IDS_BROWSE, 0 },
    { IDC_C64KBD_MAPPING_DUMP, IDS_DUMP_KEYSET, 0 },
    { IDC_KBD_SHORTCUT_DUMP, IDS_DUMP_SHORTCUTS, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group scpu64_kbd_left_group[] = {
    { IDC_C64KBD_MAPPING_SELECT_SYM, 1 },
    { IDC_C64KBD_MAPPING_SELECT_SYMDE, 1 },
    { IDC_C64KBD_MAPPING_SELECT_POS, 1 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_kbd_middle_group[] = {
    { IDC_C64KBD_MAPPING_SYM, 0 },
    { IDC_C64KBD_MAPPING_SYMDE, 0 },
    { IDC_C64KBD_MAPPING_POS, 0 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_kbd_right_group[] = {
    { IDC_C64KBD_MAPPING_SYM_BROWSE, 0 },
    { IDC_C64KBD_MAPPING_SYMDE_BROWSE, 0 },
    { IDC_C64KBD_MAPPING_POS_BROWSE, 0 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_kbd_buttons_group[] = {
    { IDC_C64KBD_MAPPING_DUMP, 1 },
    { IDC_KBD_SHORTCUT_DUMP, 1 },
    { 0, 0 }
};

static int scpu64_kbd_move_buttons_group[] = {
    IDC_C64KBD_MAPPING_DUMP,
    IDC_KBD_SHORTCUT_DUMP,
    0
};

static uikeyboard_config_t uikeyboard_config = {
    IDD_C64KBD_MAPPING_SETTINGS_DIALOG,
    SCPU64UI_KBD_NUM_MAP,
    mapping_entry,
    IDC_C64KBD_MAPPING_DUMP,
    scpu64_kbd_trans,
    scpu64_kbd_left_group,
    scpu64_kbd_middle_group,
    scpu64_kbd_right_group,
    scpu64_kbd_buttons_group,
    scpu64_kbd_move_buttons_group
};

ui_menu_translation_table_t scpu64ui_menu_translation_table[] = {
    { IDM_EXIT, IDS_MI_EXIT },
    { IDM_ABOUT, IDS_MI_ABOUT },
    { IDM_HELP, IDS_MP_HELP },
    { IDM_PAUSE, IDS_MI_PAUSE },
    { IDM_EDIT_COPY, IDS_MI_EDIT_COPY },
    { IDM_EDIT_PASTE, IDS_MI_EDIT_PASTE },
    { IDM_AUTOSTART, IDS_MI_AUTOSTART },
    { IDM_RESET_HARD, IDS_MI_RESET_HARD },
    { IDM_RESET_SOFT, IDS_MI_RESET_SOFT },
    { IDM_RESET_DRIVE8, IDS_MI_DRIVE8 },
    { IDM_RESET_DRIVE9, IDS_MI_DRIVE9 },
    { IDM_RESET_DRIVE10, IDS_MI_DRIVE10 },
    { IDM_RESET_DRIVE11, IDS_MI_DRIVE11 },
    { IDM_ATTACH_8, IDS_MI_DRIVE8 },
    { IDM_ATTACH_9, IDS_MI_DRIVE9 },
    { IDM_ATTACH_10, IDS_MI_DRIVE10 },
    { IDM_ATTACH_11, IDS_MI_DRIVE11 },
    { IDM_DETACH_8, IDS_MI_DRIVE8 },
    { IDM_DETACH_9, IDS_MI_DRIVE9 },
    { IDM_DETACH_10, IDS_MI_DRIVE10 },
    { IDM_DETACH_11, IDS_MI_DRIVE11 },
    { IDM_DETACH_ALL, IDS_MI_DETACH_ALL },
    { IDM_TOGGLE_SOUND, IDS_MI_TOGGLE_SOUND },
    { IDM_TOGGLE_DOUBLESIZE, IDS_MI_TOGGLE_DOUBLESIZE },
    { IDM_TOGGLE_DOUBLESCAN, IDS_MI_TOGGLE_DOUBLESCAN },
    { IDM_TOGGLE_DRIVE_TRUE_EMULATION, IDS_MI_DRIVE_TRUE_EMULATION },
    { IDM_TOGGLE_DRIVE_SOUND_EMULATION, IDS_MI_DRIVE_SOUND_EMULATION },
    { IDM_TOGGLE_VIDEOCACHE, IDS_MI_TOGGLE_VIDEOCACHE },
    { IDM_DRIVE_SETTINGS, IDS_MI_DRIVE_SETTINGS },
    { IDM_CART_ATTACH_CRT, IDS_MI_CART_ATTACH_CRT },
    { IDM_CART_ATTACH_8KB, IDS_MI_CART_ATTACH_8KB },
    { IDM_CART_ATTACH_16KB, IDS_MI_CART_ATTACH_16KB },
    { IDM_CART_ATTACH_AR, IDS_MI_CART_ATTACH_AR },
    { IDM_CART_ATTACH_AR3, IDS_MI_CART_ATTACH_AR3 },
    { IDM_CART_ATTACH_AR4, IDS_MI_CART_ATTACH_AR4 },
    { IDM_CART_ATTACH_STARDOS, IDS_MI_CART_ATTACH_STARDOS },
    { IDM_CART_ATTACH_AT, IDS_MI_CART_ATTACH_AT },
    { IDM_CART_ATTACH_EPYX, IDS_MI_CART_ATTACH_EPYX },
    { IDM_CART_ATTACH_IEEE488, IDS_MI_CART_ATTACH_IEEE488 },
    { IDM_CART_ATTACH_RR, IDS_MI_CART_ATTACH_RR },
    { IDM_CART_ATTACH_MMC_REPLAY, IDS_MI_CART_ATTACH_MMC_REPLAY },
    { IDM_CART_ATTACH_IDE64, IDS_MI_CART_ATTACH_IDE64 },
    { IDM_CART_ATTACH_SS4, IDS_MI_CART_ATTACH_SS4 },
    { IDM_CART_ATTACH_SS5, IDS_MI_CART_ATTACH_SS5 },
    { IDM_CART_ATTACH_STB, IDS_MI_CART_ATTACH_STB },
    { IDM_FLIP_ADD, IDS_MI_FLIP_ADD },
    { IDM_FLIP_REMOVE, IDS_MI_FLIP_REMOVE },
    { IDM_FLIP_NEXT, IDS_MI_FLIP_NEXT },
    { IDM_FLIP_PREVIOUS, IDS_MI_FLIP_PREVIOUS },
    { IDM_FLIP_LOAD, IDS_MI_FLIP_LOAD },
    { IDM_FLIP_SAVE, IDS_MI_FLIP_SAVE },
    { IDM_CART_SET_DEFAULT, IDS_MI_CART_SET_DEFAULT },
    { IDM_TOGGLE_CART_RESET, IDS_MI_TOGGLE_CART_RESET },
    { IDM_CART_DETACH, IDS_MI_CART_DETACH },
    { IDM_CART_FREEZE, IDS_MI_CART_FREEZE },
    { IDM_MONITOR, IDS_MI_MONITOR },
#ifdef DEBUG
    { IDM_DEBUG_MODE_NORMAL, IDS_MI_DEBUG_MODE_NORMAL },
    { IDM_DEBUG_MODE_SMALL, IDS_MI_DEBUG_MODE_SMALL },
    { IDM_DEBUG_MODE_HISTORY, IDS_MI_DEBUG_MODE_HISTORY },
    { IDM_DEBUG_MODE_AUTOPLAY, IDS_MI_DEBUG_MODE_AUTOPLAY },
    { IDM_TOGGLE_MAINCPU_TRACE, IDS_MI_TOGGLE_MAINCPU_TRACE },
    { IDM_TOGGLE_DRIVE0CPU_TRACE, IDS_MI_TOGGLE_DRIVE0CPU_TRACE },
    { IDM_TOGGLE_DRIVE1CPU_TRACE, IDS_MI_TOGGLE_DRIVE1CPU_TRACE },
#endif
    { IDM_SNAPSHOT_LOAD, IDS_MI_SNAPSHOT_LOAD },
    { IDM_SNAPSHOT_SAVE, IDS_MI_SNAPSHOT_SAVE },
    { IDM_LOADQUICK, IDS_MI_LOADQUICK },
    { IDM_SAVEQUICK, IDS_MI_SAVEQUICK },
    { IDM_EVENT_TOGGLE_RECORD, IDS_MI_EVENT_TOGGLE_RECORD },
    { IDM_EVENT_TOGGLE_PLAYBACK, IDS_MI_EVENT_TOGGLE_PLAYBACK },
    { IDM_EVENT_SETMILESTONE, IDS_MI_EVENT_SETMILESTONE },
    { IDM_EVENT_RESETMILESTONE, IDS_MI_EVENT_RESETMILESTONE },
    { IDM_EVENT_START_MODE_SAVE, IDS_MI_EVENT_START_MODE_SAVE },
    { IDM_EVENT_START_MODE_LOAD, IDS_MI_EVENT_START_MODE_LOAD },
    { IDM_EVENT_START_MODE_RESET, IDS_MI_EVENT_START_MODE_RESET },
    { IDM_EVENT_START_MODE_PLAYBACK, IDS_MI_EVENT_START_MODE_PLAYBCK },
    { IDM_EVENT_DIRECTORY, IDS_MI_EVENT_DIRECTORY },
    { IDM_JAM_ACTION_ASK, IDS_MI_JAM_ACTION_ASK },
    { IDM_JAM_ACTION_CONTINUE, IDS_MI_JAM_ACTION_CONTINUE },
    { IDM_JAM_ACTION_START_MONITOR, IDS_MI_JAM_ACTION_START_MONITOR },
    { IDM_JAM_ACTION_RESET, IDS_MI_JAM_ACTION_RESET },
    { IDM_JAM_ACTION_HARD_RESET, IDS_MI_JAM_ACTION_HARD_RESET },
    { IDM_JAM_ACTION_QUIT_EMULATOR, IDS_MI_JAM_ACTION_QUIT_EMULATOR },
    { IDM_MEDIAFILE, IDS_MI_MEDIAFILE },
    { IDM_SOUND_RECORD_START, IDS_MI_SOUND_RECORD_START },
    { IDM_SOUND_RECORD_STOP, IDS_MI_SOUND_RECORD_STOP },
    { IDM_REFRESH_RATE_AUTO, IDS_MI_REFRESH_RATE_AUTO },
    { IDM_MAXIMUM_SPEED_NO_LIMIT, IDS_MI_MAXIMUM_SPEED_NO_LIMIT },
    { IDM_MAXIMUM_SPEED_CUSTOM, IDS_MI_MAXIMUM_SPEED_CUSTOM },
    { IDM_TOGGLE_WARP_MODE, IDS_MI_TOGGLE_WARP_MODE },
    { IDM_TOGGLE_ALWAYSONTOP, IDS_MI_TOGGLE_ALWAYSONTOP },
    { IDM_TOGGLE_RESET_IEC_WITH_CPU, IDS_MI_TOGGLE_RESET_IEC_WITH_CPU },
    { IDM_SWAP_JOYSTICK, IDS_MI_SWAP_JOYSTICK },
    { IDM_SWAP_EXTRA_JOYSTICK, IDS_MI_SWAP_EXTRA_JOYSTICK },
    { IDM_ALLOW_JOY_OPPOSITE_TOGGLE, IDS_MI_ALLOW_JOY_OPPOSITE },
    { IDM_JOYKEYS_TOGGLE, IDS_MI_JOYKEYS_TOGGLE },
    { IDM_TOGGLE_VIRTUAL_DEVICES, IDS_MI_TOGGLE_VIRTUAL_DEVICES },
    { IDM_MOUSE, IDS_MI_MOUSE },
    { IDM_AUTOSTART_SETTINGS, IDS_MI_AUTOSTART_SETTINGS },
    { IDM_C64MODEL_SETTINGS, IDS_MI_C64MODEL_SETTINGS },
    { IDM_VIDEO_SETTINGS, IDS_MI_VIDEO_SETTINGS },
    { IDM_DEVICEMANAGER, IDS_MI_DEVICEMANAGER },
    { IDM_JOY_SETTINGS, IDS_MI_JOY_SETTINGS },
    { IDM_EXTRA_JOY_SETTINGS, IDS_MI_USERPORT_JOY_SETTINGS },
    { IDM_KEYBOARD_SETTINGS, IDS_MI_KEYBOARD_SETTINGS },
    { IDM_SOUND_SETTINGS, IDS_MI_SOUND_SETTINGS },
    { IDM_ROM_SETTINGS, IDS_MI_ROM_SETTINGS },
    { IDM_RAM_SETTINGS, IDS_MI_RAM_SETTINGS },
    { IDM_VICII_SETTINGS, IDS_MI_VICII_SETTINGS },
    { IDM_SCPU64_SETTINGS, IDS_MI_SCPU64_SETTINGS },
    { IDM_MOUSE_SETTINGS, IDS_MI_MOUSE_SETTINGS },
    { IDM_LIGHTPEN_SETTINGS, IDS_MI_LIGHTPEN_SETTINGS },
    { IDM_SID_SETTINGS, IDS_MI_SID_SETTINGS },
    { IDM_CIA_SETTINGS, IDS_MI_CIA_SETTINGS },
    { IDM_RS232_SETTINGS, IDS_MI_RS232_SETTINGS },
    { IDM_REU_SETTINGS, IDS_MI_REU_SETTINGS },
    { IDM_GEORAM_SETTINGS, IDS_MI_GEORAM_SETTINGS },
    { IDM_RAMCART_SETTINGS, IDS_MI_RAMCART_SETTINGS },
    { IDM_DQBB_SETTINGS, IDS_MI_DQBB_SETTINGS },
    { IDM_EXPERT_SETTINGS, IDS_MI_EXPERT_SETTINGS },
    { IDM_ISEPIC_SETTINGS, IDS_MI_ISEPIC_SETTINGS },
    { IDM_MIDI_SETTINGS, IDS_MI_MIDI_SETTINGS },
    { IDM_MMC64_SETTINGS, IDS_MI_MMC64_SETTINGS },
    { IDM_MMCREPLAY_SETTINGS, IDS_MI_MMCREPLAY_SETTINGS },
    { IDM_RR_SETTINGS, IDS_MI_RR_SETTINGS },
    { IDM_MAGICVOICE_SETTINGS, IDS_MI_MAGICVOICE_SETTINGS },
    { IDM_DIGIMAX_SETTINGS, IDS_MI_DIGIMAX_SETTINGS },
    { IDM_DS12C887RTC_SETTINGS, IDS_MI_DS12C887RTC_SETTINGS },
    { IDM_C64BURSTMOD_SETTINGS, IDS_MI_C64BURSTMOD_SETTINGS },
    { IDM_IDE64_SETTINGS, IDS_MI_IDE64_SETTINGS },
#ifdef HAVE_TFE
    { IDM_TFE_SETTINGS, IDS_MI_TFE_SETTINGS },
#endif
    { IDM_ACIA_SETTINGS, IDS_MI_ACIA_SETTINGS },
    { IDM_RS232USER_SETTINGS, IDS_MI_RS232USER_SETTINGS },
    { IDM_EASYFLASH_SETTINGS, IDS_MI_EASYFLASH_SETTINGS },
    { IDM_SFX_SE_SETTINGS, IDS_MI_SFX_SE_SETTINGS },
    { IDM_TOGGLE_SFX_SS, IDS_MI_TOGGLE_SFX_SS },
    { IDM_TOGGLE_USERPORT_RTC, IDS_MI_TOGGLE_USERPORT_RTC },
    { IDM_SETTINGS_SAVE_FILE, IDS_MI_SETTINGS_SAVE_FILE },
    { IDM_SETTINGS_LOAD_FILE, IDS_MI_SETTINGS_LOAD_FILE },
    { IDM_SETTINGS_SAVE, IDS_MI_SETTINGS_SAVE },
    { IDM_SETTINGS_LOAD, IDS_MI_SETTINGS_LOAD },
    { IDM_SETTINGS_DEFAULT, IDS_MI_SETTINGS_DEFAULT },
    { IDM_TOGGLE_SAVE_SETTINGS_ON_EXIT, IDS_MI_SAVE_SETTINGS_ON_EXIT },
    { IDM_TOGGLE_CONFIRM_ON_EXIT, IDS_MI_CONFIRM_ON_EXIT },
    { IDM_LANG_EN, IDS_MI_LANG_EN },
    { IDM_LANG_DA, IDS_MI_LANG_DA },
    { IDM_LANG_DE, IDS_MI_LANG_DE },
    { IDM_LANG_ES, IDS_MI_LANG_ES },
    { IDM_LANG_FR, IDS_MI_LANG_FR },
    { IDM_LANG_HU, IDS_MI_LANG_HU },
    { IDM_LANG_IT, IDS_MI_LANG_IT },
    { IDM_LANG_KO, IDS_MI_LANG_KO },
    { IDM_LANG_NL, IDS_MI_LANG_NL },
    { IDM_LANG_PL, IDS_MI_LANG_PL },
    { IDM_LANG_RU, IDS_MI_LANG_RU },
    { IDM_LANG_SV, IDS_MI_LANG_SV },
    { IDM_LANG_TR, IDS_MI_LANG_TR },
    { IDM_CMDLINE, IDS_MI_CMDLINE },
    { IDM_CONTRIBUTORS, IDS_MI_CONTRIBUTORS },
    { IDM_LICENSE, IDS_MI_LICENSE },
    { IDM_WARRANTY, IDS_MI_WARRANTY },
    { IDM_NETWORK_SETTINGS, IDS_MI_NETWORK_SETTINGS },
    { IDM_TOGGLE_FULLSCREEN, IDS_MI_TOGGLE_FULLSCREEN },
    { 0, 0 }
};

ui_popup_translation_table_t scpu64ui_popup_translation_table[] = {
    { 1, IDS_MP_FILE },
    { 2, IDS_MP_ATTACH_DISK_IMAGE },
    { 2, IDS_MP_DETACH_DISK_IMAGE },
    { 2, IDS_MP_FLIP_LIST },
    { 2, IDS_MP_ATTACH_CARTRIDGE_IMAGE },
    { 2, IDS_MP_RESET },
    { 2, IDS_MP_DEFAULT_CPU_JAM_ACTION },
#ifdef DEBUG
    { 2, IDS_MP_DEBUG },
    { 3, IDS_MP_MODE },
#endif
    { 1, IDS_MP_EDIT },
    { 1, IDS_MP_SNAPSHOT },
    { 2, IDS_MP_RECORDING_START_MODE },
/*    { 1, IDS_MP_OPTIONS }, */
    { 1, IDS_MP_SETTINGS },
    { 2, IDS_MP_REFRESH_RATE },
    { 2, IDS_MP_MAXIMUM_SPEED },
    { 2, IDS_MP_SOUND_SETTINGS },
    { 2, IDS_MP_DRIVE_SETTINGS },
    { 2, IDS_MP_JOYSTICK_SETTINGS },
    { 2, IDS_MP_MOUSE_SETTINGS },
    { 2, IDS_MP_CARTRIDGE_IO_SETTINGS },
    { 2, IDS_MP_RS232_SETTINGS },
    { 1, IDS_MP_LANGUAGE },
    { 1, IDS_MP_HELP },
    { 0, 0 }
};

static uilib_localize_dialog_param scpu64_main_trans[] = {
    { IDC_SCPU64, IDS_SCPU64, 0 },
    { IDC_SCPU64ROM_SCPU64_BROWSE, IDS_BROWSE, 0 },
    { IDC_CHARACTER, IDS_CHARACTER, 0 },
    { IDC_C64ROM_CHARGEN_BROWSE, IDS_BROWSE, 0 },
    { 0, 0, 0 }
};

static uilib_localize_dialog_param scpu64_drive_trans[] = {
    { IDC_DRIVEROM_1541_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1541II_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1570_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1571_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1581_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_2000_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_4000_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_2031_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_2040_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_3040_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_4040_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1001_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_PROFDOS_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_SUPERCARD_BROWSE, IDS_BROWSE, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group scpu64_main_left_group[] = {
    { IDC_SCPU64, 0 },
    { IDC_CHARACTER, 0 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_main_middle_group[] = {
    { IDC_SCPU64ROM_SCPU64_FILE, 0 },
    { IDC_C64ROM_CHARGEN_FILE, 0 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_main_right_group[] = {
    { IDC_SCPU64ROM_SCPU64_BROWSE, 0 },
    { IDC_C64ROM_CHARGEN_BROWSE, 0 },
    { 0, 0}
};

static uilib_dialog_group scpu64_drive_left_group[] = {
    { IDC_1541, 0 },
    { IDC_1541_II, 0 },
    { IDC_1570, 0 },
    { IDC_1571, 0 },
    { IDC_1581, 0 },
    { IDC_2000, 0 },
    { IDC_4000, 0 },
    { IDC_2031, 0 },
    { IDC_2040, 0 },
    { IDC_3040, 0 },
    { IDC_4040, 0 },
    { IDC_1001, 0 },
    { IDC_PROFDOS, 0 },
    { IDC_SUPERCARD, 0 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_drive_middle_group[] = {
    { IDC_DRIVEROM_1541_FILE, 0 },
    { IDC_DRIVEROM_1541II_FILE, 0 },
    { IDC_DRIVEROM_1570_FILE, 0 },
    { IDC_DRIVEROM_1571_FILE, 0 },
    { IDC_DRIVEROM_1581_FILE, 0 },
    { IDC_DRIVEROM_2000_FILE, 0 },
    { IDC_DRIVEROM_4000_FILE, 0 },
    { IDC_DRIVEROM_2031_FILE, 0 },
    { IDC_DRIVEROM_2040_FILE, 0 },
    { IDC_DRIVEROM_3040_FILE, 0 },
    { IDC_DRIVEROM_4040_FILE, 0 },
    { IDC_DRIVEROM_1001_FILE, 0 },
    { IDC_DRIVEROM_PROFDOS_FILE, 0 },
    { IDC_DRIVEROM_SUPERCARD_FILE, 0 },
    { 0, 0 }
};

static uilib_dialog_group scpu64_drive_right_group[] = {
    { IDC_DRIVEROM_1541_BROWSE, 0 },
    { IDC_DRIVEROM_1541II_BROWSE, 0 },
    { IDC_DRIVEROM_1570_BROWSE, 0 },
    { IDC_DRIVEROM_1571_BROWSE, 0 },
    { IDC_DRIVEROM_1581_BROWSE, 0 },
    { IDC_DRIVEROM_2000_BROWSE, 0 },
    { IDC_DRIVEROM_4000_BROWSE, 0 },
    { IDC_DRIVEROM_2031_BROWSE, 0 },
    { IDC_DRIVEROM_2040_BROWSE, 0 },
    { IDC_DRIVEROM_3040_BROWSE, 0 },
    { IDC_DRIVEROM_4040_BROWSE, 0 },
    { IDC_DRIVEROM_1001_BROWSE, 0 },
    { IDC_DRIVEROM_PROFDOS_BROWSE, 0 },
    { IDC_DRIVEROM_SUPERCARD_BROWSE, 0 },
    { 0, 0 }
};

static generic_trans_table_t scpu64_generic_trans[] = {
    { IDC_1541, "1541" },
    { IDC_1541_II, "1541-II" },
    { IDC_1570, "1570" },
    { IDC_1571, "1571" },
    { IDC_1581, "1581" },
    { IDC_2000, "2000" },
    { IDC_4000, "4000" },
    { IDC_2031, "2031" },
    { IDC_2040, "2040" },
    { IDC_3040, "3040" },
    { IDC_4040, "4040" },
    { IDC_1001, "1001" },
    { IDC_PROFDOS, "Professional DOS" },
    { IDC_SUPERCARD, "SuperCard+" },
    { 0, NULL }
};

static const int scpu64_sid_baseaddress[] = { 0xd4, 0xd5, 0xd6, 0xd7, 0xde, 0xdf, -1 };

static void scpu64_ui_specific(WPARAM wparam, HWND hwnd)
{
    uic64cart_proc(wparam, hwnd);

    switch (wparam) {
        case IDM_C64BURSTMOD_SETTINGS:
            ui_c64burstmod_settings_dialog(hwnd);
            break;
        case IDM_C64MODEL_SETTINGS:
            ui_scpu64model_settings_dialog(hwnd);
            break;
        case IDM_VICII_SETTINGS:
            ui_vicii_settings_dialog(hwnd);
            break;
        case IDM_SCPU64_SETTINGS:
            ui_scpu64_settings_dialog(hwnd);
            break;
        case IDM_SID_SETTINGS:
            ui_sid_settings_dialog(hwnd, scpu64_sid_baseaddress);
            break;
        case IDM_REU_SETTINGS:
            ui_reu_settings_dialog(hwnd);
            break;
        case IDM_GEORAM_SETTINGS:
            ui_georam_settings_dialog(hwnd);
            break;
        case IDM_CIA_SETTINGS:
            ui_cia_settings_dialog(hwnd, 2);
            break;
        case IDM_RAMCART_SETTINGS:
            ui_ramcart_settings_dialog(hwnd);
            break;
        case IDM_DQBB_SETTINGS:
            ui_dqbb_settings_dialog(hwnd);
            break;
        case IDM_EXPERT_SETTINGS:
            ui_expert_settings_dialog(hwnd);
            break;
        case IDM_ISEPIC_SETTINGS:
            ui_isepic_settings_dialog(hwnd);
            break;
        case IDM_MIDI_SETTINGS:
            ui_midi_settings_dialog(hwnd);
            break;
        case IDM_MMC64_SETTINGS:
            ui_mmc64_settings_dialog(hwnd);
            break;
        case IDM_MMCREPLAY_SETTINGS:
            ui_mmcreplay_settings_dialog(hwnd);
            break;
        case IDM_RR_SETTINGS:
            ui_rr_settings_dialog(hwnd);
            break;
        case IDM_MAGICVOICE_SETTINGS:
            ui_magicvoice_settings_dialog(hwnd);
            break;
        case IDM_DIGIMAX_SETTINGS:
            ui_digimax_settings_dialog(hwnd);
            break;
        case IDM_DS12C887RTC_SETTINGS:
            ui_ds12c887rtc_settings_dialog(hwnd);
            break;
        case IDM_LIGHTPEN_SETTINGS:
            ui_lightpen_settings_dialog(hwnd);
            break;
        case IDM_EASYFLASH_SETTINGS:
            ui_easyflash_settings_dialog(hwnd);
            break;
        case IDM_SFX_SE_SETTINGS:
            ui_soundexpander_settings_dialog(hwnd);
            break;
        case IDM_IDE64_SETTINGS:
            uiide64_settings_dialog(hwnd);
            break;
        case IDM_JOY_SETTINGS:
            ui_joystick_settings_dialog(hwnd);
            break;
        case IDM_EXTRA_JOY_SETTINGS:
            ui_extra_joystick_settings_dialog(hwnd);
            break;
        case IDM_ROM_SETTINGS:
            uirom_settings_dialog(hwnd, IDD_SCPU64ROM_SETTINGS_DIALOG, IDD_C64DRIVEROM_SETTINGS_DIALOG,
                                  uirom_settings,
                                  scpu64_main_trans, scpu64_drive_trans, scpu64_generic_trans,
                                  scpu64_main_left_group, scpu64_main_middle_group, scpu64_main_right_group,
                                  scpu64_drive_left_group, scpu64_drive_middle_group, scpu64_drive_right_group);
            break;
#ifdef HAVE_TFE
        case IDM_TFE_SETTINGS:
           ui_tfe_settings_dialog(hwnd);
           break;
#endif
        case IDM_VIDEO_SETTINGS:
            ui_video_settings_dialog(hwnd, UI_VIDEO_CHIP_VICII, UI_VIDEO_CHIP_NONE);
            break;
        case IDM_DRIVE_SETTINGS:
            uidrivec64_settings_dialog(hwnd);
            break;
        case IDM_ACIA_SETTINGS:
            ui_acia_settings_dialog(hwnd);
            break;
        case IDM_RS232USER_SETTINGS:
            ui_rs232user_settings_dialog(hwnd);
            break;
        case IDM_KEYBOARD_SETTINGS:
            uikeyboard_settings_dialog(hwnd, &uikeyboard_config);
            break;
        case IDM_MOUSE_SETTINGS:
            ui_mouse_settings_dialog(hwnd);
            break;
    }
}

int scpu64ui_init(void)
{
    uic64cart_init();

    ui_register_machine_specific(scpu64_ui_specific);
    ui_register_menu_toggles(scpu64_ui_menu_toggles);
    ui_register_translation_tables(scpu64ui_menu_translation_table, scpu64ui_popup_translation_table);

    return 0;
}

void scpu64ui_shutdown(void)
{
}
