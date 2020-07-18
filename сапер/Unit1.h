//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TLabel *display;
        TButton *Button1;
        TButton *Button2;
        TImage *Playingfield;
        TMenuItem *File1;
        TMenuItem *Help1;
        TMenuItem *GameRules1;
        TMenuItem *About1;
        TMenuItem *Exit2;
        TLabel *Label1;
        TTimer *Timer1;
        TButton *Button3;
        TLabel *Label2;
        TMemo *Memo1;
        TEdit *Name;
        TLabel *Label3;
        TButton *Button4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall PlayingfieldClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall GameRules1Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Exit2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
         Game_start();
        Coordinate_calculation();
        Field_read();
        Draw_field(byte x, byte y,byte Nummer);
        Flag_set(byte x, byte y, boolean set);
        Mine_distribution();
        Mines_reveal();
        Uncover_field(byte x, byte y);
        Kontrol();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
