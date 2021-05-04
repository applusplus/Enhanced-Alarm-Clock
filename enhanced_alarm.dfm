object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Enhanced Alarm Clock v1.0 :: by applusplus'
  ClientHeight = 227
  ClientWidth = 501
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object vleAlarmList: TValueListEditor
    Left = 0
    Top = 0
    Width = 265
    Height = 230
    Enabled = False
    Strings.Strings = (
      '=')
    TabOrder = 0
    TitleCaptions.Strings = (
      'Time'
      'Hint')
    ColWidths = (
      99
      160)
  end
  object dtpTime: TDateTimePicker
    Left = 280
    Top = 8
    Width = 53
    Height = 23
    Date = 40830.000000000000000000
    Format = 'HH:mm'
    Time = 0.984722222223354000
    Enabled = False
    Kind = dtkTime
    TabOrder = 1
  end
  object butLock: TButton
    Left = 271
    Top = 194
    Width = 75
    Height = 25
    Caption = 'Unlock'
    TabOrder = 2
    OnClick = butLockClick
  end
  object butAdd: TButton
    Left = 280
    Top = 56
    Width = 40
    Height = 25
    Caption = 'Add'
    Enabled = False
    TabOrder = 3
    OnClick = butAddClick
  end
  object butDelete: TButton
    Left = 360
    Top = 56
    Width = 57
    Height = 25
    Caption = 'Delete'
    Enabled = False
    TabOrder = 4
    OnClick = butDeleteClick
  end
  object butStart: TButton
    Left = 271
    Top = 152
    Width = 82
    Height = 25
    Caption = 'Start'
    Enabled = False
    TabOrder = 5
    OnClick = butStartClick
  end
  object butCancel: TButton
    Left = 400
    Top = 152
    Width = 83
    Height = 25
    Caption = 'Cancel'
    Enabled = False
    TabOrder = 6
    OnClick = butCancelClick
  end
  object eSoundPath: TEdit
    Left = 271
    Top = 120
    Width = 194
    Height = 21
    Enabled = False
    ReadOnly = True
    TabOrder = 7
  end
  object butOpenDialog: TButton
    Left = 471
    Top = 116
    Width = 25
    Height = 25
    Caption = '...'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = butOpenDialogClick
  end
  object dtpDate: TDateTimePicker
    Left = 368
    Top = 8
    Width = 57
    Height = 21
    Date = 40833.000000000000000000
    Format = 'dd.MM'
    Time = 0.820248900461592700
    Enabled = False
    TabOrder = 9
  end
  object cbDate: TCheckBox
    Left = 352
    Top = 10
    Width = 15
    Height = 17
    Enabled = False
    TabOrder = 10
  end
  object tAlarm: TTimer
    Enabled = False
    Interval = 200
    OnTimer = tAlarmTimer
    Left = 456
    Top = 8
  end
  object odSound: TOpenDialog
    Filter = 'Sound Files (*.mp3 *.wav)|*.mp3;*.wav'
    Options = [ofReadOnly, ofHideReadOnly, ofEnableSizing]
    Left = 456
    Top = 56
  end
end
