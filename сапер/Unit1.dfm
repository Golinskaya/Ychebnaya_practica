object Form1: TForm1
  Left = 192
  Top = 125
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 415
  ClientWidth = 538
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object display: TLabel
    Left = 240
    Top = 40
    Width = 36
    Height = 26
    Caption = '000'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Playingfield: TImage
    Left = 88
    Top = 96
    Width = 377
    Height = 329
    OnClick = PlayingfieldClick
  end
  object Button1: TButton
    Left = 72
    Top = 48
    Width = 121
    Height = 25
    Caption = 'normal'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 352
    Top = 48
    Width = 121
    Height = 25
    Caption = 'Start'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 16
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object GameRules1: TMenuItem
        Caption = 'Game Rules'
        OnClick = GameRules1Click
      end
      object About1: TMenuItem
        Caption = 'About'
        OnClick = About1Click
      end
    end
  end
end
