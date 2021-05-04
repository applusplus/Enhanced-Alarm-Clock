//---------------------------------------------------------------------------

#include <vcl.h>
#include <tchar.h>
#include <windows.h>
#include <mmsystem.h>
#include <DBXJSON.hpp>
#include <IniFiles.hpp>

#pragma comment(lib,"winmm.lib")
#pragma hdrstop

#include "enhanced_alarm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	dtpTime->Time = Time();
    dtpDate->Date = Date();

	oJson = new TJSONObject();
	oIni = new TIniFile((ExtractFilePath(Application->ExeName))+"\EAlarm.ini");
	eSoundPath->Text = oIni->ReadString("Settings", "SoundPath", "");
	TBytes StringBytes = TEncoding::UTF8->GetBytes(oIni->ReadString("Settings", "AlarmList", ""));
	oJson->Parse(StringBytes, 0);
	for(int i = 0;i < oJson->Size() ;i++){
		vleAlarmList->Strings->Add(oJson->Get(i)->JsonValue->Value());
	}
	delete oJson;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	//settings als JSON
	oJson = new TJSONObject();

	for(int i = 1; i < vleAlarmList->RowCount; i++){
		oJson->AddPair(IntToStr(i),(vleAlarmList->Keys[i])+"="+(vleAlarmList->Values[i]) );
	}
	oIni->WriteString("Settings", "SoundPath", eSoundPath->Text);
	oIni->WriteString("Settings", "AlarmList", oJson->ToString());

	mciSendString(L"close all", NULL, 0, NULL);
	delete oJson;
	delete oIni;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::butAddClick(TObject *Sender)
{
	String time = (TimeToStr(dtpTime->Time)).SubString(1,5);
	if(cbDate->Checked){
		time += " "+(DateToStr(dtpDate->Date)).SubString(1, 5);
	}
	vleAlarmList->InsertRow(time, "", true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::butDeleteClick(TObject *Sender)
{
	if(vleAlarmList->Strings->Count > 0){
		vleAlarmList->DeleteRow(vleAlarmList->Row);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::butLockClick(TObject *Sender)
{
	if(butLock->Caption == "Unlock"){
		ChangeStatus(true);
		butLock->Caption = "Lock";
	}else{
		ChangeStatus(false);
		butLock->Caption = "Unlock";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tAlarmTimer(TObject *Sender)
{
	String sTime;
	String sDate;
	for(int i=1; i < vleAlarmList->RowCount; i++){
		if((Trim(vleAlarmList->Keys[i])).Length() > 5){
			sDate = (Trim(vleAlarmList->Keys[i])).SubString(7, 11);
			if( sDate != (DateToStr(Date()).SubString(1,5))){
				continue;
			}
		}
		sTime = (vleAlarmList->Keys[i]).SubString(1,5);
		if( sTime == (TimeToStr(Time())).SubString(1,5)){
			mciSendString(L"play fsound repeat", NULL, 0, NULL);
			tAlarm->Enabled=false;
			Form1->WindowState=wsNormal;
			break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butStartClick(TObject *Sender)
{
	if(Trim(vleAlarmList->Keys[1]) == ""){
		Application->MessageBox(L"No Time was added!", L"Error", MB_OK);
	}else if(Trim(eSoundPath->Text) == ""){
		Application->MessageBox(L"No Sound file was chosen!", L"Error", MB_OK);
	}else{
		tAlarm->Enabled=true;
		ChangeStatus(false);
		butCancel->Enabled=true;
		butLock->Enabled=false;
		UnicodeString SoundPath = StringReplace(eSoundPath->Text,"\\", "\\\\", TReplaceFlags() << rfReplaceAll);
		mciSendString(("open \""+SoundPath+"\" alias fsound").w_str(), NULL, 0, NULL);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butCancelClick(TObject *Sender)
{
	mciSendString(L"stop fsound", NULL, 0, NULL);
	mciSendString(L"close fsound", NULL, 0, NULL);
	tAlarm->Enabled=false;
	ChangeStatus(true);
	butCancel->Enabled=false;
	butLock->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChangeStatus(bool status)
{
	butAdd->Enabled = status;
	butDelete->Enabled = status;
	dtpTime->Enabled = status;
	vleAlarmList->Enabled = status;
	butStart->Enabled = status;
	butOpenDialog->Enabled = status;
	eSoundPath->Enabled = status;
	cbDate->Enabled = status;
	dtpDate->Enabled = status;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::butOpenDialogClick(TObject *Sender)
{
	odSound->Execute();
	eSoundPath->Text = odSound->FileName;
}
//---------------------------------------------------------------------------

