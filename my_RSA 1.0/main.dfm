object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Demo_ECC'
  ClientHeight = 450
  ClientWidth = 600
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 383
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
  end
  object Label2: TLabel
    Left = 450
    Top = 8
    Width = 133
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1085#1085#1099#1081' '#1090#1077#1082#1089#1090
  end
  object Button1: TButton
    Left = 402
    Top = 75
    Width = 37
    Height = 36
    Caption = '->'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 402
    Top = 130
    Width = 37
    Height = 36
    Caption = '<-'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit2: TMemo
    Left = 450
    Top = 27
    Width = 133
    Height = 364
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 2
    WantTabs = True
  end
  object ProgressBar1: TProgressBar
    Left = 8
    Top = 405
    Width = 575
    Height = 31
    Position = 100
    TabOrder = 3
  end
  object Edit1: TMemo
    Left = 8
    Top = 27
    Width = 383
    Height = 364
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 4
    WantTabs = True
  end
  object Button3: TButton
    Left = 402
    Top = 355
    Width = 37
    Height = 36
    Caption = 'set'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 402
    Top = 313
    Width = 37
    Height = 36
    Caption = 'log'
    TabOrder = 6
    OnClick = Button4Click
  end
end
