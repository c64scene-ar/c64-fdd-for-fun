/*
 * petui.cc - PET-specific user interface.
 *
 * Written by
 *  Andreas Matthies <andreas.matthies@gmx.net>
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

#include <FilePanel.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Window.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__BEOS__) && defined(WORDS_BIGENDIAN)
#include <string.h>
#endif

#include "ui_file.h"

extern "C" {
#include "archdep.h"
#include "constants.h"
#include "petmodel.h"
#include "petui.h"
#include "resources.h"
#include "types.h"
#include "ui.h"
#include "ui_drive.h"
#include "ui_pet.h"
#include "ui_sidcart.h"
#include "ui_video.h"
#include "util.h"
#include "video.h"
}

static ui_drive_type_t pet_drive_types[] = {
    { "2031", DRIVE_TYPE_2031 },
    { "2040", DRIVE_TYPE_2040 },
    { "3040", DRIVE_TYPE_3040 },
    { "4040", DRIVE_TYPE_4040 },
    { "1001", DRIVE_TYPE_1001 },
    { "8050", DRIVE_TYPE_8050 },
    { "8250", DRIVE_TYPE_8250 },
    { "None", DRIVE_TYPE_NONE },
    { NULL, 0 }
};

ui_menu_toggle  pet_ui_menu_toggles[] = {
    { "CRTCDoubleSize", MENU_TOGGLE_DOUBLESIZE },
    { "CRTCStretchVertical", MENU_TOGGLE_STRETCHVERTICAL },
    { "CRTCDoubleScan", MENU_TOGGLE_DOUBLESCAN },
    { "CRTCVideoCache", MENU_TOGGLE_VIDEOCACHE },
    { "PETREU", MENU_TOGGLE_PETREU },
    { "PETDWW", MENU_TOGGLE_PETDWW },
    { "PETHRE", MENU_TOGGLE_PETHRE },
    { "UserportDAC", MENU_TOGGLE_PET_USERPORT_DAC },
    { NULL, 0 }
};

ui_res_possible_values petAciaDevice[] = {
    { 1, MENU_ACIA_RS323_DEVICE_1 },
    { 2, MENU_ACIA_RS323_DEVICE_2 },
    { 3, MENU_ACIA_RS323_DEVICE_3 },
    { 4, MENU_ACIA_RS323_DEVICE_4 },
    { -1, 0 }
};

ui_res_possible_values PETREUSize[] = {
    { 128, MENU_PETREU_SIZE_128 },
    { 512, MENU_PETREU_SIZE_512 },
    { 1024, MENU_PETREU_SIZE_1024 },
    { 2048, MENU_PETREU_SIZE_2048 },
    { -1, 0 }
};

ui_res_possible_values pet_RenderFilters[] = {
    { VIDEO_FILTER_NONE, MENU_RENDER_FILTER_NONE },
    { VIDEO_FILTER_CRT, MENU_RENDER_FILTER_CRT_EMULATION },
    { -1, 0 }
};

ui_res_value_list pet_ui_res_values[] = {
    { "Acia1Dev", petAciaDevice },
    { "PETREUsize", PETREUSize},
    { "CRTCFilter", pet_RenderFilters },
    { NULL, NULL }
};

static const char *pet_sidcart_address_text_pair[] = { "$8F00", "$E900" };
static const char *pet_sidcart_clock_pair[] = { "C64", "PET" };
static const int pet_sidcart_address_int_pair[] = { 0x8f00, 0xe900 };

void pet_ui_specific(void *msg, void *window)
{
    switch (((BMessage*)msg)->what) {
        case MENU_PET_MODEL_2001:
            petmodel_set(PETMODEL_2001);
            break;
        case MENU_PET_MODEL_3008:
            petmodel_set(PETMODEL_3008);
            break;
        case MENU_PET_MODEL_3016:
            petmodel_set(PETMODEL_3016);
            break;
        case MENU_PET_MODEL_3032:
            petmodel_set(PETMODEL_3032);
            break;
        case MENU_PET_MODEL_3032B:
            petmodel_set(PETMODEL_3032B);
            break;
        case MENU_PET_MODEL_4016:
            petmodel_set(PETMODEL_4016);
            break;
        case MENU_PET_MODEL_4032:
            petmodel_set(PETMODEL_4032);
            break;
        case MENU_PET_MODEL_4032B:
            petmodel_set(PETMODEL_4032B);
            break;
        case MENU_PET_MODEL_8032:
            petmodel_set(PETMODEL_8032);
            break;
        case MENU_PET_MODEL_8096:
            petmodel_set(PETMODEL_8096);
            break;
        case MENU_PET_MODEL_8296:
            petmodel_set(PETMODEL_8296);
            break;
        case MENU_PET_MODEL_SUPERPET:
            petmodel_set(PETMODEL_SUPERPET);
            break;
        case MENU_PET_SETTINGS:
            ui_pet();
            break;
        case MENU_VIDEO_SETTINGS:
            ui_video(UI_VIDEO_CHIP_CRTC);
            break;
        case MENU_DRIVE_SETTINGS:
            ui_drive(pet_drive_types, HAS_NO_CAPS);
            break;
        case MENU_SIDCART_SETTINGS:
            ui_sidcart(pet_sidcart_address_text_pair, pet_sidcart_clock_pair, pet_sidcart_address_int_pair);
            break;
        case MENU_PETREU_FILE:
            ui_select_file(B_SAVE_PANEL, PETREU_FILE, (void*)0);
            break;
        case MENU_PETDWW_FILE:
            ui_select_file(B_SAVE_PANEL, PETDWW_FILE, (void*)0);
            break;
        case MENU_COMPUTER_KERNAL_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_KERNAL_ROM_FILE, (void*)0);
            break;
        case MENU_COMPUTER_BASIC_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_BASIC_ROM_FILE, (void*)0);
            break;
        case MENU_COMPUTER_CHARGEN_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_CHARGEN_ROM_FILE, (void*)0);
            break;
        case MENU_COMPUTER_EDITOR_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_EDITOR_ROM_FILE, (void*)0);
            break;
        case MENU_COMPUTER_ROM_9_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_ROM_9_FILE, (void*)0);
            break;
        case MENU_COMPUTER_ROM_A_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_ROM_A_FILE, (void*)0);
            break;
        case MENU_COMPUTER_ROM_B_FILE:
            ui_select_file(B_SAVE_PANEL, COMPUTER_ROM_B_FILE, (void*)0);
            break;
        case MENU_DRIVE_2031_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, DRIVE_2031_ROM_FILE, (void*)0);
            break;
        case MENU_DRIVE_2040_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, DRIVE_2040_ROM_FILE, (void*)0);
            break;
        case MENU_DRIVE_3040_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, DRIVE_3040_ROM_FILE, (void*)0);
            break;
        case MENU_DRIVE_4040_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, DRIVE_4040_ROM_FILE, (void*)0);
            break;
        case MENU_DRIVE_1001_ROM_FILE:
            ui_select_file(B_SAVE_PANEL, DRIVE_1001_ROM_FILE, (void*)0);
            break;
        default:
            break;
    }
}

int petui_init(void)
{
    ui_register_machine_specific(pet_ui_specific);
    ui_register_menu_toggles(pet_ui_menu_toggles);
    ui_register_res_values(pet_ui_res_values);
    ui_update_menus();
    return 0;
}

void petui_shutdown(void)
{
}
