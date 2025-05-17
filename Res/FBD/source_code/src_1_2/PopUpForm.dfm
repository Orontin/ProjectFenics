object fmPopup: TfmPopup
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #1043#1088#1091#1087#1087#1099' '#1094#1074#1090#1086#1074
  ClientHeight = 192
  ClientWidth = 173
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lbGroups: TListBox
    Left = 8
    Top = 8
    Width = 156
    Height = 105
    Style = lbOwnerDrawFixed
    AutoComplete = False
    BorderStyle = bsNone
    ItemHeight = 20
    Items.Strings = (
      #1043#1088#1091#1087#1087#1072' 1'
      #1043#1088#1091#1087#1087#1072' 2'
      #1043#1088#1091#1087#1087#1072' 3'
      #1043#1088#1091#1087#1087#1072' 4'
      #1043#1088#1091#1087#1087#1072' 5')
    TabOrder = 0
    OnDrawItem = lbGroupsDrawItem
  end
  object btDelete: TButton
    Left = 89
    Top = 129
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 1
    OnClick = btDeleteClick
  end
  object btOK: TButton
    Left = 89
    Top = 159
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = btOKClick
  end
  object btAdd: TButton
    Left = 8
    Top = 129
    Width = 75
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 3
    OnClick = btAddClick
  end
end
