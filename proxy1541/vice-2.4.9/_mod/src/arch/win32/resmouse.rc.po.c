
#include "vice.h"

#include "res.h"
#include "rescommon.h"

#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


IDD_MOUSE_SETTINGS_DIALOG DIALOG DISCARDABLE  0, 0, 180, 93
BEGIN
    LTEXT           "", IDC_MOUSE_TYPE_LABEL,
                    9, 6, 53, 8
    COMBOBOX        IDC_MOUSE_TYPE,
                    70, 5, 80, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    LTEXT           "", IDC_MOUSE_PORT_LABEL,
                    9, 24, 53, 8
    COMBOBOX        IDC_MOUSE_PORT,
                    70, 23, 80, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    LTEXT           "", IDC_MOUSE_SENSITIVITY_LABEL,
                    9, 42, 53, 8
    COMBOBOX        IDC_MOUSE_SENSITIVITY,
                    70, 41, 80, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK, 30, 68, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL, 90, 68, 50, 14, WS_TABSTOP
END



STRINGTABLE
BEGIN
  IDS_MOUSE_TYPE_LABEL        N_("Mouse type")
  IDS_MOUSE_PORT_LABEL        N_("Mouse port")
  IDS_P_SENSITIVITY           N_("sensitivity")
  IDS_DESC_MOUSE_SENSITIVITY  N_("Sensitivity of the mouse. [40]")
  IDS_MOUSE_SENSITIVITY_LABEL N_("Mouse sensitivity")
END



STRINGTABLE
LANGUAGE LANG_DANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Mussetype"
  IDS_MOUSE_PORT_LABEL        "Musseport"
  IDS_P_SENSITIVITY           "<sensitivity>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensitivity of the mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Mouse sensitivity"
END



STRINGTABLE
LANGUAGE LANG_GERMAN, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Maustyp"
  IDS_MOUSE_PORT_LABEL        "Maus Port"
  IDS_P_SENSITIVITY           "<Sensibilit�t>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensibilit�t der Maus [40]."
  IDS_MOUSE_SENSITIVITY_LABEL "Maus Sensibilit�t"
END



STRINGTABLE
LANGUAGE LANG_SPANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Tipo rat�n"
  IDS_MOUSE_PORT_LABEL        "Puerto del rat�n"
  IDS_P_SENSITIVITY           "<sensibilidad>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensibilidad del rat�n. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Sensibilidad del rat�n"
END



STRINGTABLE
LANGUAGE LANG_FRENCH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Type de souris"
  IDS_MOUSE_PORT_LABEL        "Port de la souris"
  IDS_P_SENSITIVITY           "<sensitivity>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensitivity of the mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Mouse sensitivity"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_HUNGARIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Eg�r t�pusa"
  IDS_MOUSE_PORT_LABEL        "Eg�r port"
  IDS_P_SENSITIVITY           "<sensitivity>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensitivity of the mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Mouse sensitivity"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_ITALIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Tipo di mouse"
  IDS_MOUSE_PORT_LABEL        "Porta del mouse"
  IDS_P_SENSITIVITY           "<sensibilit�>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensibilit� del mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Sensibilit� mouse"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(949)
#endif
STRINGTABLE
LANGUAGE LANG_KOREAN, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "���콺 Ÿ��"
  IDS_MOUSE_PORT_LABEL        "���콺 ��Ʈ"
  IDS_P_SENSITIVITY           "<sensitivity>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensitivity of the mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Mouse sensitivity"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_DUTCH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Muis soort"
  IDS_MOUSE_PORT_LABEL        "Muis poort"
  IDS_P_SENSITIVITY           "<gevoeligheid>"
  IDS_DESC_MOUSE_SENSITIVITY  "Gevoeligheid van de muis. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Muis gevoeligheid"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_POLISH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Typ myszy"
  IDS_MOUSE_PORT_LABEL        "Port myszy"
  IDS_P_SENSITIVITY           "<czu�o��>"
  IDS_DESC_MOUSE_SENSITIVITY  "czu�o�� myszy. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Czu�o�� myszy"
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
  IDS_MOUSE_TYPE_LABEL        "��� ����"
  IDS_MOUSE_PORT_LABEL        "���� ����"
  IDS_P_SENSITIVITY           "<sensitivity>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensitivity of the mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Mouse sensitivity"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_SWEDISH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Mustyp"
  IDS_MOUSE_PORT_LABEL        "Musport"
  IDS_P_SENSITIVITY           "<k�nslighet>"
  IDS_DESC_MOUSE_SENSITIVITY  "Musk�nslighet. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Musk�nslighet"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28599)
#endif
STRINGTABLE
LANGUAGE LANG_TURKISH, SUBLANG_NEUTRAL
BEGIN
  IDS_MOUSE_TYPE_LABEL        "Mouse tipi"
  IDS_MOUSE_PORT_LABEL        "Mouse portu"
  IDS_P_SENSITIVITY           "<sensitivity>"
  IDS_DESC_MOUSE_SENSITIVITY  "Sensitivity of the mouse. [40]"
  IDS_MOUSE_SENSITIVITY_LABEL "Mouse sensitivity"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


