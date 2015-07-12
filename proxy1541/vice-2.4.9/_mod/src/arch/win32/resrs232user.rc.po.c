
#include "vice.h"

#include "res.h"
#include "rescommon.h"

#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


IDD_RS232USER_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 170, 90
BEGIN
    AUTOCHECKBOX  "", IDC_RS232USER_ENABLE,
                  7, 7, 120, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    LTEXT         "", IDC_RS232USER_DEVICE_LABEL,
                  9, 24, 55, 8
    COMBOBOX      IDC_RS232USER_DEVICE, 75, 22, 75, 80,
                  CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    LTEXT         "", IDC_RS232USER_BAUDRATE_LABEL,
                  9, 44, 60, 8
    COMBOBOX      IDC_RS232USER_BAUDRATE,
                  75, 42, 75, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    DEFPUSHBUTTON "", IDOK,
                  25, 70, 50, 14, WS_TABSTOP
    PUSHBUTTON    "", IDCANCEL,
                  85, 70, 50, 14, WS_TABSTOP
END



STRINGTABLE
BEGIN
  IDS_RS232USER_CAPTION N_("RS232 userport settings")
  IDS_RS232USER_ENABLE  N_("Enable RS232 userport emulation")
  IDS_RS232USER_DEVICE  N_("Userport device")
  IDS_RS232USER_BAUD    N_("Userport baud rate")
END



STRINGTABLE
LANGUAGE LANG_DANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232-brugerportindstillinger"
  IDS_RS232USER_ENABLE  "Aktiv�r RS232-emulering p� brugerporten"
  IDS_RS232USER_DEVICE  "Brugerport enhed"
  IDS_RS232USER_BAUD    "Brugerportens baudhastighet"
END



STRINGTABLE
LANGUAGE LANG_GERMAN, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232 Userport Einstellungen"
  IDS_RS232USER_ENABLE  "RS232 Userport Emulation aktivieren"
  IDS_RS232USER_DEVICE  "Userport Ger�t"
  IDS_RS232USER_BAUD    "Userport Baud Rate"
END



STRINGTABLE
LANGUAGE LANG_SPANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "Ajustes puerto RS232"
  IDS_RS232USER_ENABLE  "Permitir emulacion puerto RS232"
  IDS_RS232USER_DEVICE  "Perif�rico puerto usuario"
  IDS_RS232USER_BAUD    "Velocidad (baudios) puerto usuario"
END



STRINGTABLE
LANGUAGE LANG_FRENCH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "Param�tres port utilisateur RS232"
  IDS_RS232USER_ENABLE  "Activer l'�mulation de p�riph�rique RS232 userport"
  IDS_RS232USER_DEVICE  "P�riph�rique Userport"
  IDS_RS232USER_BAUD    "Vitesse du Userport"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_HUNGARIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232 userport settings"
  IDS_RS232USER_ENABLE  "RS232 userport emul�ci� enged�lyez�se"
  IDS_RS232USER_DEVICE  "Userport eszk�z"
  IDS_RS232USER_BAUD    "Userport �tviteli r�ta"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_ITALIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "Impostazioni RS232 su userport"
  IDS_RS232USER_ENABLE  "Attiva l'emulazione della RS232 su userport"
  IDS_RS232USER_DEVICE  "Dispositivo su userport"
  IDS_RS232USER_BAUD    "Velocit� Userport"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(949)
#endif
STRINGTABLE
LANGUAGE LANG_KOREAN, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232 ������Ʈ ����"
  IDS_RS232USER_ENABLE  "Enable RS232 userport emulation"
  IDS_RS232USER_DEVICE  "Userport device"
  IDS_RS232USER_BAUD    "Userport baud rate"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_DUTCH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232 userport instellingen"
  IDS_RS232USER_ENABLE  "Activeer RS232 userportemulatie"
  IDS_RS232USER_DEVICE  "Userport apparaat"
  IDS_RS232USER_BAUD    "Userport baudrate"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_POLISH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "Ustawienia userportu RS232"
  IDS_RS232USER_ENABLE  "W��cz emulacj� userportu RS232"
  IDS_RS232USER_DEVICE  "Urz�dzenie userportu"
  IDS_RS232USER_BAUD    "Pr�dko�� transmisji userportu"
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
  IDS_RS232USER_CAPTION "RS232 userport settings"
  IDS_RS232USER_ENABLE  "Enable RS232 userport emulation"
  IDS_RS232USER_DEVICE  "Userport device"
  IDS_RS232USER_BAUD    "Userport baud rate"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_SWEDISH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232-anv�ndarportinst�llningar"
  IDS_RS232USER_ENABLE  "Aktivera RS232-emulering p� anv�ndarporten"
  IDS_RS232USER_DEVICE  "Anv�ndarportensenhet"
  IDS_RS232USER_BAUD    "Anv�ndarportens baudhastighet"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28599)
#endif
STRINGTABLE
LANGUAGE LANG_TURKISH, SUBLANG_NEUTRAL
BEGIN
  IDS_RS232USER_CAPTION "RS232 userport ayarlar�"
  IDS_RS232USER_ENABLE  "RS232 userport em�lasyonunu aktif et"
  IDS_RS232USER_DEVICE  "Userport ayg�t�"
  IDS_RS232USER_BAUD    "Userport baud rate"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


