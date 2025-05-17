object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Friendship Bracelets Designer'
  ClientHeight = 529
  ClientWidth = 587
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 510
    Width = 587
    Height = 19
    AutoHint = True
    Panels = <>
    ParentShowHint = False
    ShowHint = False
  end
  object gbScheme: TGroupBox
    Left = 0
    Top = 0
    Width = 532
    Height = 510
    Align = alClient
    Caption = #1060#1088#1072#1075#1084#1077#1085#1090' '#1089#1093#1077#1084#1099
    Color = clWhite
    Constraints.MinHeight = 200
    Constraints.MinWidth = 200
    ParentColor = False
    TabOrder = 1
    object sbScheme: TScrollBox
      Left = 2
      Top = 15
      Width = 528
      Height = 493
      Align = alClient
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clWhite
      ParentColor = False
      TabOrder = 0
      OnResize = sbSchemeResize
      object pbScheme: TPaintBox
        Left = 0
        Top = 0
        Width = 105
        Height = 105
        ParentShowHint = False
        ShowHint = False
        OnMouseMove = pbSchemeMouseMove
        OnMouseUp = pbSchemeMouseUp
        OnPaint = pbSchemePaint
      end
    end
  end
  object gbPreview: TGroupBox
    Left = 532
    Top = 0
    Width = 55
    Height = 510
    Align = alRight
    Caption = #1060#1077#1085#1100#1082#1072
    Color = clWhite
    ParentColor = False
    TabOrder = 2
    object pbPreview: TPaintBox
      Left = 10
      Top = 15
      Width = 181
      Height = 369
      Hint = #1055#1088#1080#1073#1083#1080#1079#1080#1090#1100' / '#1054#1090#1076#1072#1083#1080#1090#1100
      Color = clWhite
      ParentColor = False
      OnMouseUp = pbPreviewMouseUp
      OnPaint = pbPreviewPaint
    end
  end
  object MainMenu: TMainMenu
    Left = 544
    Top = 400
    object miFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object miNew: TMenuItem
        Caption = #1053#1086#1074#1099#1081
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1089#1093#1077#1084#1091
        OnClick = miNewClick
      end
      object miOpen: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1089#1091#1097#1077#1089#1090#1074#1091#1102#1097#1091#1102' '#1089#1093#1077#1084#1091
        OnClick = miOpenClick
      end
      object miSave: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1089#1093#1077#1084#1091' '#1074' '#1092#1072#1081#1083
        OnClick = miSaveClick
      end
      object miExport: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1089#1093#1077#1084#1091' '#1082#1072#1082' '#1088#1080#1089#1091#1085#1086#1082
        OnClick = miExportClick
      end
      object miClose: TMenuItem
        Caption = #1047#1072#1082#1088#1099#1090#1100
        Hint = #1047#1072#1082#1086#1085#1095#1080#1090#1100' '#1088#1072#1073#1086#1090#1099' '#1089' '#1090#1077#1082#1091#1097#1077#1081' '#1089#1093#1077#1084#1086#1081
        OnClick = miCloseClick
      end
      object miLine: TMenuItem
        Caption = '-'
      end
      object miExit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Hint = #1042#1099#1081#1090#1080' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        OnClick = miExitClick
      end
    end
    object miScheme: TMenuItem
      Caption = #1057#1093#1077#1084#1072
      object miAddLines: TMenuItem
        Caption = #1055#1088#1086#1076#1083#1080#1090#1100
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1082#1086#1085#1077#1094' '#1076#1074#1072' '#1088#1103#1076#1072' '#1091#1079#1077#1083#1082#1086#1074
        OnClick = miAddLinesClick
      end
      object miDelLines: TMenuItem
        Caption = #1057#1086#1082#1088#1072#1090#1080#1090#1100
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1076#1074#1072' '#1087#1086#1089#1083#1077#1076#1085#1080#1093' '#1088#1103#1076#1072' '#1091#1079#1077#1083#1082#1086#1074
        OnClick = miDelLinesClick
      end
      object miOptimize: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1087#1086#1074#1090#1086#1088#1099
        OnClick = miOptimizeClick
      end
    end
    object miOptions: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      object miShowPreview: TMenuItem
        AutoCheck = True
        Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1092#1077#1085#1100#1082#1091
        Checked = True
        OnClick = miShowPreviewClick
      end
      object miLanguage: TMenuItem
        Caption = #1071#1079#1099#1082
        object miEnglish: TMenuItem
          Caption = 'English'
          Checked = True
          OnClick = miEnglishClick
        end
        object miRussian: TMenuItem
          Caption = #1056#1091#1089#1089#1082#1080#1081
          OnClick = miRussianClick
        end
      end
    end
    object miHelp: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object miAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        Hint = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = miAboutClick
      end
    end
  end
  object ColorDialog: TColorDialog
    Color = clWhite
    Options = [cdFullOpen]
    Left = 432
    Top = 400
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'fbd'
    Filter = 'All supported (*.fbd, *.rnx)|*.fbd;*.rnx'
    Left = 464
    Top = 400
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'fbd'
    Filter = 'FBD files (*.fbd)|*.fbd'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 504
    Top = 400
  end
  object SaveDialogExport: TSaveDialog
    DefaultExt = 'jpg'
    Filter = 'JPEG files (*.jpg)|*.jpg|Bitmap files (*.bmp)|*.bmp'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 400
    Top = 400
  end
end
