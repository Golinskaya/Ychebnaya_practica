//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Fieldlatitude 18
#define Max_Latitude 30

byte Degreeofdifficulty=2;
boolean Mines_plased=false;
boolean Game_isrunning=false;
int Numberofreplenishment[4]={0,40,80,150};
byte Latitude[4]={0,15,20,30};

int temp;
byte X, Y;
int Restmines=0;
int i;

boolean Mine[Max_Latitude+1] [Max_Latitude+1];
boolean Flag[Max_Latitude+1] [Max_Latitude+1];
boolean Open[Max_Latitude+1] [Max_Latitude+1];
byte Content[Max_Latitude+1] [Max_Latitude+1];

int Field_X1[Max_Latitude+1] [Max_Latitude+1];
int Field_X2[Max_Latitude+1] [Max_Latitude+1];
int Field_Y1[Max_Latitude+1] [Max_Latitude+1];
int Field_Y2[Max_Latitude+1] [Max_Latitude+1];

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
       Degreeofdifficulty++;
    if (Degreeofdifficulty>3)
      {
       Degreeofdifficulty=1;
      }
           switch (Degreeofdifficulty)
         {
          case 1: Button1->Caption="easy";break;
          case 2: Button1->Caption="normal";break;
          case 3: Button1->Caption="complicated";break;
         } 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
      Game_start();
      i = 1;
       Timer1->Interval = 1000;
       Timer1->Enabled = true;

       
}
//---------------------------------------------------------------------------


TForm1:: Game_start()
{
     Mines_plased=false;
    Coordinate_calculation();
    Playingfield->Width=(Latitude[Degreeofdifficulty]*Fieldlatitude)+1;
    Playingfield->Height=Playingfield->Width;
    Playingfield->Refresh();
    for (byte a=1;a<(Max_Latitude+1);a++)
         {
           for (byte b=1;b<(Max_Latitude+1);b++)
               {
                 Mine[a][b]=false;
                 Flag[a][b]=false;
                 Open[a][b]=false;
                 Content[a][b]=0;
               }
         }

         for (byte a=1;a<(Max_Latitude+1);a++)
         {
           for (byte b=1;b<(Max_Latitude+1);b++)
               {
                 Flag_set(b, a, 0);
                }
         }

    Playingfield->Left=Form1->Width/2-Playingfield->Width/2;
    Playingfield->Visible=true;
    Game_isrunning=true;
    display->Caption=IntToStr(Numberofreplenishment[Degreeofdifficulty]);
    return 0;   
}

TForm1::Coordinate_calculation()
{
   for (byte a=1;a<(Max_Latitude+1);a++)
               {
                  for (byte b=1;b<(Max_Latitude+1);b++)
                       {
                          Field_X1[a][b]=((b-1)* Fieldlatitude)+1;
                          Field_X2[a][b]=((b-1)*  Fieldlatitude+ Fieldlatitude);
                          Field_Y1[a][b]=((a-1)* Fieldlatitude)+1;
                          Field_Y2[a][b]=((a-1)*  Fieldlatitude+ Fieldlatitude);
                       }
               }
       return 0;    
}


TForm1::Field_read()
{
        POINT Mausposition;
       GetCursorPos(&Mausposition);
       int MausX=Mausposition.x-Form1->Left-Playingfield->Left;
       int MausY=Mausposition.y-Form1->Top-Playingfield->Top;
       X=((MausX-8)/Fieldlatitude)+1;
       Y=((MausY-30)/Fieldlatitude)+1;
       if (X>Latitude[Degreeofdifficulty])
                       {
                         X=Latitude[Degreeofdifficulty];
                       }

       if (Y>Latitude[Degreeofdifficulty])
                      {
                         Y=Latitude[Degreeofdifficulty];
                      }
            return 0;
}
void __fastcall TForm1::PlayingfieldClick(TObject *Sender)
{
     if (Game_isrunning==true)
        {
      Field_read();
     GetAsyncKeyState(VK_CONTROL);
     if (GetAsyncKeyState(VK_CONTROL)&& Open[Y][X]==false)
         {
           if (Flag[Y][X]==false)
                   {
                     if(Restmines>0)
                             {
                               Flag_set(X, Y, 1);
                               Flag[Y][X]=true;
                             }

                   }
              else
                    {
                       Flag_set(X, Y, 0);
                       Flag[Y][X]=false;

                    }
           Kontrol();

         }
  else
         {
           if(Mines_plased==false)
              {
                Mine_distribution();
                Mines_plased=true;
              }
            if (Mine[Y][X]==true)
                    {
                     Mines_reveal();
                    }
               else
                    {
                       if (Open[Y][X]==false)
                            {
                               Uncover_field(X, Y);
                               Kontrol();
                            }

                    }
               }
         }

}
//---------------------------------------------------------------------------


TForm1::Draw_field(byte x, byte y,byte Nummer)
{
        Playingfield->Canvas->Pen->Color=clBlack;
       Playingfield->Canvas->Brush->Color=clSilver;
       Playingfield->Canvas->Rectangle(Field_X1[y][x]-1,Field_Y1[y][x]-1,Field_X2[y][x]+1,Field_Y2[y][x]+1);
       Playingfield->Canvas->Pen->Color=clSilver;
       Playingfield->Canvas->Rectangle(Field_X1[y][x],Field_Y1[y][x],Field_X2[y][x],Field_Y2[y][x]);
       if (Nummer>0)
           {
             Playingfield->Canvas->Pen->Color=clBlack;
             TRect Number=Rect(Field_X1[y][x],Field_Y1[y][x],Field_X2[y][x],Field_Y2[y][x]);
             Playingfield->Canvas->TextRect(Number,Field_X1[y][x]+4,Field_Y1[y][x],Nummer);
           }
       return 0;
}


TForm1::Flag_set(byte x, byte y, boolean set)
{
     Playingfield->Canvas->Pen->Color=clBlack;
       Playingfield->Canvas->Rectangle(Field_X1[y][x]-1,Field_Y1[y][x]-1,Field_X2[y][x]+1,Field_Y2[y][x]+1);
       if (set==true)
            {
              Restmines--;
              Playingfield->Canvas->Brush->Color=clLime;
              Playingfield->Canvas->Pen->Color=clLime;
              Playingfield->Canvas->Rectangle(Field_X1[y][x],Field_Y1[y][x],Field_X2[y][x],Field_Y2[y][x]);
            }
       else
             {
               Restmines++;
              Playingfield->Canvas->Brush->Color=clGray;
              Playingfield->Canvas->Pen->Color=clGray;
              Playingfield->Canvas->Rectangle(Field_X1[y][x],Field_Y1[y][x],Field_X2[y][x],Field_Y2[y][x]);
             }
             return 0;
}


TForm1::Mine_distribution()
{
         Restmines=0;
        while (Restmines<(Numberofreplenishment[Degreeofdifficulty]))
                {
                   byte x=(rand()%Latitude[Degreeofdifficulty])+1;
                   byte y=(rand()%Latitude[Degreeofdifficulty])+1;

                   if(x<(X+2) && x>(X-2) && y<(Y+2) && y>(Y-2)){} else
                   {

                      if (Mine[y][x]==false)
                        {
                          for (byte a=(y-1);a<(y+2);a++)
                             {
                                for (byte b=(x-1);b<(x+2);b++)
                                    {
                                       Content[a][b]++;

                                    }


                            }


                       Mine[y][x]=true;
                       Restmines++;
                      }

                   }

                }
         return 0;
}



TForm1::Mines_reveal()
{
      Playingfield->Canvas->Brush->Color=clRed;
      Playingfield->Canvas->Pen->Color=clRed;
      Playingfield->Canvas->Rectangle(Field_X1[Y][X],Field_Y1[Y][X],Field_X2[Y][X],Field_Y2[Y][X]);
      for (byte a=1;a<(Latitude[Degreeofdifficulty]+1);a++)
          {
             for (byte b=1;b<(Latitude[Degreeofdifficulty]+1);b++)
                  {
                    if (Mine[a][b]==true)
                       {
                         Playingfield->Canvas->Brush->Color=clBlack;
                         Playingfield->Canvas->Pen->Color=clBlack;
                         Playingfield->Canvas->Ellipse(Field_X1[a][b]+2,Field_Y1[a][b]+2,Field_X2[a][b]-2,Field_Y2[a][b]-2);

                       }


                  }

           }


    Game_isrunning=false;
    return 0;
}


TForm1::Uncover_field(byte x, byte y)
{
       Open[y][x]=true;
       if (Content[y][x]>0)
          {
            Draw_field(x, y, Content[y][x]);
            if(Flag[y][x]==true)
               {
                 Flag[y][x]=false;
               }
          }
    else
          {
            Draw_field(x, y, 0);
             int x1=x-1;  if (x1<1) {x1=1;}
             int x2=x+2;   if(x2>(Latitude[Degreeofdifficulty]+1)) {x2=Latitude[Degreeofdifficulty]+1;}
             int y1=y-1;   if (y1<1) {y1=1;}
             int y2=y+2;   if(y2>(Latitude[Degreeofdifficulty]+1)) {y2=Latitude[Degreeofdifficulty]+1;}
             for (byte a=y1;a<y2;a++)
                 {
                    for (byte b=x1;b<x2;b++)
                        {
                          if (Open[a][b]==false && Flag[a][b]==false)
                                 {
                                   Uncover_field(b, a);
                                 }
                         }
                 }
          }
    return 0;
}

TForm1::Kontrol()
{
       byte Counter=0;
       Restmines= Numberofreplenishment[Degreeofdifficulty];
      for (byte a=1;a<Latitude[Degreeofdifficulty]+1;a++)
          {
               for (byte b=1;b<Latitude[Degreeofdifficulty]+1;b++)
                    {
                      if(Flag[a][b]==true)
                         {
                            Restmines--;
                           if(Mine[a][b]==true)
                             {
                               Counter++;
                              }
                         }
                    }
          }

         display->Caption=IntToStr(Restmines);
         display->Left=Form1->Width/2-display->Width/2;
         if (Counter==Numberofreplenishment[Degreeofdifficulty])
            {
               Game_isrunning=false;
               ShowMessage("Минное поле обезврежено");
            }
      return 0;
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Button2->Left=Form1->Width/2+50;
    Button1->Left=Form1->Left/2+10;
    Timer1->Enabled=false;
  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GameRules1Click(TObject *Sender)
{
  ShowMessage(" Цель игры является нахождения всех спрятанных бомб на минном поле.Задача пользователя открыть все ячейки поля, не содержащие бомб на мином поле.");



}
//---------------------------------------------------------------------------
void __fastcall TForm1::About1Click(TObject *Sender)
{
    ShowMessage("Игра Сапёр реализованная на Borland Builder C++ 6.Проект создан Голинской Лилией.");    
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Exit2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Memo1->Lines->Clear();
  Memo1->Lines->Add(Name->Text);
  Memo1->Lines->Add(display->Caption);
  Memo1->Lines->Add(Button1->Caption);
  Memo1->Lines->Add(Label2->Caption);
  Memo1->Lines->SaveToFile("result.txt");
  ShowMessage("Игра сохранена");
}
//---------------------------------------------------------------------------











void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
      Label2->Caption = i;
      if (!i)
      Timer1->Enabled = 0;
       i++;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
      Memo1->Lines->Clear();
      Memo1->Lines->LoadFromFile("result.txt");
      Name->Text=Memo1->Lines->Strings[0];
      Button1->Caption=Memo1->Lines->Strings[1];
      display->Caption=Memo1->Lines->Strings[2];
      Label2->Caption=Memo1->Lines->Strings[3];
}
//---------------------------------------------------------------------------

