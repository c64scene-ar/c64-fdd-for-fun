
#include "vice.h"

#include "res.h"
#include "rescommon.h"

#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


IDD_GEORAM_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 180, 122
BEGIN
    AUTOCHECKBOX    "", IDC_GEORAM_ENABLE,
                    7, 7, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    LTEXT           "", IDC_GEORAM_SIZE_LABEL,
                    9, 24, 50, 8
    COMBOBOX        IDC_GEORAM_SIZE,
                    65, 22, 50, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_GEORAM_WRITE_ENABLE,
                    7, 44, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    LTEXT           "", IDC_GEORAM_FILE_LABEL,
                    9, 66, 46, 8
    PUSHBUTTON      "", IDC_GEORAM_BROWSE,
                    55, 64, 50, 14, 0
    EDITTEXT        IDC_GEORAM_FILE,
                    9, 82, 160, 12, WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK,
                    30, 102, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    90, 102, 50, 14, WS_TABSTOP
END


IDD_GEORAM_MASCUERADE_SETTINGS_DIALOG DIALOG DISCARDABLE 0, 0, 180, 136
BEGIN
    AUTOCHECKBOX    "", IDC_GEORAM_ENABLE,
                    7, 7, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_GEORAM_IO_SWAP,
                    7, 20, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    LTEXT           "", IDC_GEORAM_SIZE_LABEL,
                    9, 38, 50, 8
    COMBOBOX        IDC_GEORAM_SIZE,
                    65, 36, 50, 80, CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP
    AUTOCHECKBOX    "", IDC_GEORAM_WRITE_ENABLE,
                    7, 58, 99, 10, BS_AUTOCHECKBOX | WS_TABSTOP
    LTEXT           "", IDC_GEORAM_FILE_LABEL,
                    9, 80, 46, 8
    PUSHBUTTON      "", IDC_GEORAM_BROWSE,
                    55, 78, 50, 14, 0
    EDITTEXT        IDC_GEORAM_FILE,
                    9, 96, 160, 12, WS_TABSTOP

    DEFPUSHBUTTON   "", IDOK,
                    30, 116, 50, 14, WS_TABSTOP
    PUSHBUTTON      "", IDCANCEL,
                    90, 116, 50, 14, WS_TABSTOP
END



STRINGTABLE
BEGIN
  IDS_SELECT_FILE_GEORAM  N_("Select file for GEO-RAM")
  IDS_GEORAM_CAPTION      N_("GEO-RAM settings")
  IDS_GEORAM_ENABLE       N_("Enable the GEO-RAM expansion unit")
  IDS_GEORAM_SIZE_LABEL   N_("GEO-RAM size")
  IDS_GEORAM_WRITE_ENABLE N_("Save GEO-RAM image when changed")
  IDS_GEORAM_FILE_LABEL   N_("GEO-RAM file")
END



STRINGTABLE
LANGUAGE LANG_DANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "V�lg fil for GEO-RAM"
  IDS_GEORAM_CAPTION      "GEO-RAM-indstillinger"
  IDS_GEORAM_ENABLE       "Aktiv�r GEO-RAM-udviddelsesenheden"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM-st�rrelse"
  IDS_GEORAM_WRITE_ENABLE "Gem GEO-RAM image ved �ndringer"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM-fil"
END



STRINGTABLE
LANGUAGE LANG_GERMAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Datei f�r GEO-RAM ausw�hlen"
  IDS_GEORAM_CAPTION      "GEO-RAM Einstellungen"
  IDS_GEORAM_ENABLE       "GEO-RAM Erweiterung aktivieren"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM Gr��e"
  IDS_GEORAM_WRITE_ENABLE "GEO-RAM Imagedatei bei �nderung speichern"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM Datei"
END



STRINGTABLE
LANGUAGE LANG_SPANISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Seleccionar fichero para GEO-RAM"
  IDS_GEORAM_CAPTION      "Ajustes GEO-RAM"
  IDS_GEORAM_ENABLE       "Permitir unidad expansi�n GEO-RAM"
  IDS_GEORAM_SIZE_LABEL   "Tama�o GEO-RAM"
  IDS_GEORAM_WRITE_ENABLE "Grabar imagen GEO-RAM cuando cambie"
  IDS_GEORAM_FILE_LABEL   "Fihcero GEO-RAM"
END



STRINGTABLE
LANGUAGE LANG_FRENCH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "S�lectionner le fichier GEO-RAM"
  IDS_GEORAM_CAPTION      "Param�tres GEO-RAM"
  IDS_GEORAM_ENABLE       "Activer l'unit� d'expansion GEO-RAM"
  IDS_GEORAM_SIZE_LABEL   "Taille du GEO-RAM"
  IDS_GEORAM_WRITE_ENABLE "Enregistrer l'image GEO-RAM lorsque modifi�e"
  IDS_GEORAM_FILE_LABEL   "Fichier GEO-RAM"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_HUNGARIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Select file for GEO-RAM"
  IDS_GEORAM_CAPTION      "GEO-RAM settings"
  IDS_GEORAM_ENABLE       "Enable the GEO-RAM expansion unit"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM size"
  IDS_GEORAM_WRITE_ENABLE "Save GEO-RAM image when changed"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM file"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_ITALIAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Seleziona file per GEO-RAM"
  IDS_GEORAM_CAPTION      "Impostazioni GEO-RAM"
  IDS_GEORAM_ENABLE       "Attiva l'espansione GEO-RAM"
  IDS_GEORAM_SIZE_LABEL   "Dimensione GEO-RAM"
  IDS_GEORAM_WRITE_ENABLE "Salva immagine GEO-RAM al cambio"
  IDS_GEORAM_FILE_LABEL   "File GEO-RAM"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(949)
#endif
STRINGTABLE
LANGUAGE LANG_KOREAN, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Select file for GEO-RAM"
  IDS_GEORAM_CAPTION      "GEO-RAM ����"
  IDS_GEORAM_ENABLE       "Enable the GEO-RAM expansion unit"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM size"
  IDS_GEORAM_WRITE_ENABLE "Save GEO-RAM image when changed"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM ����"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_DUTCH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Selecteer bestand voor GEO-RAM"
  IDS_GEORAM_CAPTION      "GEO-RAM instellingen"
  IDS_GEORAM_ENABLE       "Activeer de GEO-RAM uitbreidingseenheid"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM grootte"
  IDS_GEORAM_WRITE_ENABLE "GEO-RAM bestand opslaan indien gewijzigd"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM bestand"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28592)
#endif
STRINGTABLE
LANGUAGE LANG_POLISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "Wybierz plik GEO-RAM"
  IDS_GEORAM_CAPTION      "Ustawienia GEO-RAM"
  IDS_GEORAM_ENABLE       "W��cz jednostk� rozszerzenia GEO-RAM"
  IDS_GEORAM_SIZE_LABEL   "Rozmiar GEO-RAM"
  IDS_GEORAM_WRITE_ENABLE "Zapisuj obraz GEO-RAM przy zmianie"
  IDS_GEORAM_FILE_LABEL   "Plik GEO-RAM"
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
  IDS_SELECT_FILE_GEORAM  "Select file for GEO-RAM"
  IDS_GEORAM_CAPTION      "GEO-RAM settings"
  IDS_GEORAM_ENABLE       "Enable the GEO-RAM expansion unit"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM size"
  IDS_GEORAM_WRITE_ENABLE "Save GEO-RAM image when changed"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM file"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif



STRINGTABLE
LANGUAGE LANG_SWEDISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "V�lj fil f�r GEO-RAM"
  IDS_GEORAM_CAPTION      "GEO-RAM-inst�llningar"
  IDS_GEORAM_ENABLE       "Aktivera GEORAM-expansionsenhet"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM-storlek"
  IDS_GEORAM_WRITE_ENABLE "Spara GEO-RAM-avbildning vid �ndringar"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM-fil"
END



#ifndef WINDRES_CP_IGNORE
#pragma code_page(28599)
#endif
STRINGTABLE
LANGUAGE LANG_TURKISH, SUBLANG_NEUTRAL
BEGIN
  IDS_SELECT_FILE_GEORAM  "GEO-RAM i�in dosya se�in"
  IDS_GEORAM_CAPTION      "GEO-RAM ayarlar�"
  IDS_GEORAM_ENABLE       "GEO-RAM geni�letme birimini aktif et"
  IDS_GEORAM_SIZE_LABEL   "GEO-RAM boyutu"
  IDS_GEORAM_WRITE_ENABLE "GEO-RAM imaj� de�i�ti�inde kaydet"
  IDS_GEORAM_FILE_LABEL   "GEO-RAM dosyas�"
END
#ifndef WINDRES_CP_IGNORE
#pragma code_page(28591)
#endif


