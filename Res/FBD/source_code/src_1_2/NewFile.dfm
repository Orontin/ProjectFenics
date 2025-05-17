object NewFileForm: TNewFileForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1072#1103' '#1089#1093#1077#1084#1072
  ClientHeight = 200
  ClientWidth = 211
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lbStreamsCount: TLabel
    Left = 16
    Top = 24
    Width = 93
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1085#1080#1090#1086#1082
  end
  object lbLinesCount: TLabel
    Left = 16
    Top = 56
    Width = 94
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1103#1076#1086#1074
  end
  object btOk: TButton
    Left = 26
    Top = 160
    Width = 75
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    ModalResult = 1
    TabOrder = 0
  end
  object btCancel: TButton
    Left = 115
    Top = 160
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 1
  end
  object edStreamsCount: TEdit
    Left = 128
    Top = 21
    Width = 57
    Height = 21
    Hint = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1086#1090' 2 '#1076#1086' 300'
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
    Text = '8'
    OnKeyPress = edStreamsCountKeyPress
  end
  object edLinesCount: TEdit
    Left = 128
    Top = 53
    Width = 57
    Height = 21
    Hint = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1086#1090' 2 '#1076#1086' 500'
    ParentShowHint = False
    ShowHint = False
    TabOrder = 3
    Text = '8'
    OnKeyPress = edLinesCountKeyPress
  end
  object UpDownStreams: TUpDown
    Left = 185
    Top = 21
    Width = 17
    Height = 21
    Associate = edStreamsCount
    Min = 2
    Max = 250
    Position = 8
    TabOrder = 4
    Thousands = False
  end
  object UpDownLines: TUpDown
    Left = 185
    Top = 53
    Width = 17
    Height = 21
    Associate = edLinesCount
    Min = 2
    Max = 250
    Increment = 2
    Position = 8
    TabOrder = 5
    Thousands = False
  end
  object rgFirstKnot: TRadioGroup
    Left = 16
    Top = 84
    Width = 185
    Height = 61
    Caption = #1055#1077#1088#1074#1099#1081' '#1091#1079#1077#1083#1086#1082
    ItemIndex = 0
    Items.Strings = (
      #1053#1080#1090#1080' 1 - 2'
      #1053#1080#1090#1080' 2 - 3')
    TabOrder = 6
  end
end
