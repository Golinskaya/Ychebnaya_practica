//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Fieldlatitude 20
#define Max_Latitude 30

byte Degreeofdifficulty=2;
boolean Mines_plased=false;
boolean Game_isrunning=false;
int Numberofreplenishment[4]={0,40,80,150};
byte Latitude[4]={0,15,20,30};

byte X, Y;
int Restmines=0;

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
}
//---------------------------------------------------------------------------


TForm1::Game_start()
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

TForm1::Draw_field(byte x, byte y)
{
       Playingfield->Canvas->Pen->Color=clBlack;
       Playingfield->Canvas->Brush->Color=clSilver;
       Playingfield->Canvas->Rectangle(Field_X1[y][x]-1,Field_Y1[y][x]-1,Field_X2[y][x]+1,Field_Y2[y][x]+1);
       Playingfield->Canvas->Pen->Color=clSilver;
       Playingfield->Canvas->Rectangle(Field_X1[y][x],Field_Y1[y][x],Field_X2[y][x],Field_Y2[y][x]);
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

                    }
               else
                    {
                       if (Open[Y][X]==false)
                            {

                            }

                    }

         }





}
//---------------------------------------------------------------------------


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

                   if(x<(X+2) && x<(X-2) && y<(Y+2) && y<(Y-2)){} else
                   {

                      if (Mine[y][x]==false)
                        {
                          for (byte a=(y-1);a<(y+2);a++)
                             {
                                for (byte b=(y-1);b<(y+2);b++)
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

TForm1::Mines_open()
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
                         Playingfield->Canvas->Ellipse(Field_X1[a][b]+2,Field_Y1[a][b]+2,Field_X2[a][b]+2,Field_Y2[a][b]+2);

                       }


                  }

          }

    Game_isrunning=false;
    return 0;
}