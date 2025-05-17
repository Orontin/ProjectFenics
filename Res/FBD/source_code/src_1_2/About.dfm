object AboutForm: TAboutForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  ClientHeight = 140
  ClientWidth = 212
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
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 170
    Height = 13
    Caption = 'Friendship Bracelets Designer v.1.2'
  end
  object Label2: TLabel
    Left = 24
    Top = 35
    Width = 170
    Height = 13
    Caption = 'Copyright (c) by Anton Savin, 2010'
  end
  object lbEMail: TLabel
    Left = 32
    Top = 54
    Width = 145
    Height = 13
    Cursor = crHandPoint
    Caption = 'braceletsdesigner@rambler.ru'
    OnClick = lbEMailClick
  end
  object lbLink: TLabel
    Left = 26
    Top = 73
    Width = 164
    Height = 13
    Cursor = crHandPoint
    Caption = #1055#1088#1080' '#1087#1086#1076#1076#1077#1088#1078#1082#1077' http://fene4ki.ru'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentColor = False
    ParentFont = False
    OnClick = lbLinkClick
  end
  object btOk: TButton
    Left = 71
    Top = 98
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
  end
end
