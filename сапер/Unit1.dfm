object Form1: TForm1
  Left = 332
  Top = 127
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 643
  ClientWidth = 840
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
    Left = 320
    Top = 96
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
    Left = 56
    Top = 144
    Width = 441
    Height = 409
    OnClick = PlayingfieldClick
  end
  object Label1: TLabel
    Left = 296
    Top = 64
    Width = 137
    Height = 22
    Caption = 'Number of mines'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 608
    Top = 152
    Width = 72
    Height = 24
    Caption = 'Time 00'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 488
    Top = 32
    Width = 142
    Height = 23
    Caption = 'Enter your name'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Button1: TButton
    Left = 72
    Top = 88
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
    Left = 552
    Top = 88
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
  object Button3: TButton
    Left = 624
    Top = 520
    Width = 153
    Height = 41
    Caption = 'Save as'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = 552
    Top = 184
    Width = 225
    Height = 241
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
    Visible = False
  end
  object Name: TEdit
    Left = 640
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Name'
  end
  object Button4: TButton
    Left = 624
    Top = 568
    Width = 161
    Height = 41
    Caption = 'Loading'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 5
    OnClick = Button4Click
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 16
    object File1: TMenuItem
      Caption = 'File'
      object Exit2: TMenuItem
        Caption = 'Exit'
        OnClick = Exit2Click
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
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 64
    Top = 16
  end
end
