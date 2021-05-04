//---------------------------------------------------------------------------

#ifndef enhanced_alarmH
#define enhanced_alarmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TValueListEditor *vleAlarmList;
	TDateTimePicker *dtpTime;
	TButton *butLock;
	TButton *butAdd;
	TButton *butDelete;
	TButton *butStart;
	TButton *butCancel;
	TTimer *tAlarm;
	TOpenDialog *odSound;
	TEdit *eSoundPath;
	TButton *butOpenDialog;
	TDateTimePicker *dtpDate;
	TCheckBox *cbDate;
	void __fastcall butAddClick(TObject *Sender);
	void __fastcall butLockClick(TObject *Sender);
	void __fastcall butDeleteClick(TObject *Sender);
	void __fastcall tAlarmTimer(TObject *Sender);
	void __fastcall butStartClick(TObject *Sender);
	void __fastcall butCancelClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall butOpenDialogClick(TObject *Sender);
private:	// Anwender-Deklarationen
public:		// Anwender-Deklarationen
	__fastcall TForm1(TComponent* Owner);

	// Variablen
	TJSONObject *oJson;
	TIniFile *oIni;
	// Funktionen
	void __fastcall ChangeStatus(bool status);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
