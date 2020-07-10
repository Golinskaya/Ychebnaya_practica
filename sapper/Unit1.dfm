object Form1: TForm1
  Left = 192
  Top = 125
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 568
  ClientWidth = 886
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object display: TLabel
    Left = 440
    Top = 48
    Width = 43
    Height = 29
    Caption = '000'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Playingfield: TImage
    Left = 168
    Top = 96
    Width = 553
    Height = 441
    OnClick = PlayingfieldClick
  end
  object Button1: TButton
    Left = 88
    Top = 40
    Width = 177
    Height = 25
    Caption = 'normal'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 600
    Top = 40
    Width = 177
    Height = 25
    Caption = 'Start'
    TabOrder = 1
    OnClick = Button2Click
  end
end
