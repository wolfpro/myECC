// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "my_val.cpp"

#include <string>
#include "log.h"
#include "settings.h"

#define mapa make_pair
#define ff first
#define ss second
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "acProgressBar"
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	setlocale(LC_ALL, "Russian");
	set_df_val();

	Form1->Edit1->Text = "������ World!";
	AnsiString s = Form1->Edit1->Text;
	// , a, b, ss = ""; // String s = Form1->Edit1->Text;
	// s = get_Cm(s);

	/* for (int i = 32; i < CLEN; ++i) {
	// AnsiChar c = get_vlc(i);
	// s = c;

	ss.Insert(get_vlc(13), ss.Length());
	ss.Insert(get_vlc(10), ss.Length());

	// ss.Insert("\'", ss.Length());
	// ss.Insert(val_c[i].ss, ss.Length());
	a = val_c[i].ss.ff;
	b = val_c[i].ss.ss;
	ss.Insert("(" + a + ", " + b + ")", ss.Length());
	// ss.Insert("\'", ss.Length());
	// ss.Insert('\r', 0);
	// ss.Insert("\r\n", 0);

	} */
	/*
	vector<AnsiString>log;
	log.Insert(get_vlc(13), log.Length());
	log.Insert(get_vlc(10), log.Length());
	 */

	loging = 1;
	s = get_Cm(s);
	loging = 0;

	Form1->Edit2->Text = s;

}

void set_prog(int i) {
	Form1->ProgressBar1->Position = i;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	loging = Form2->CheckBox1->Checked;

	Form1->ProgressBar1->Position = 0;
	AnsiString s = Form1->Edit1->Text;
	s = get_Cm(s);
	Form1->Edit2->Text = s;
	Form1->ProgressBar1->Position = 100;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	loging = 0;
	Form1->ProgressBar1->Position = 0;

	String s = Form1->Edit2->Text;

	pair<pair<int, int>, pair<int, int> >cm;
	AnsiString ss = "";
	for (int i = 1; i <= s.Length(); ++i) {
		if (s[i] == '\r') { // || s[i] == '\r')
			s.Delete(i, 1);
			s[i] = ' ';
			i -= 1;
		}
	}

	for (int i = 1, t = 0, v = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0; i <= s.Length() + 1;
		++i) {
		if (i > 0)
			Form1->ProgressBar1->Position = i * 100 / s.Length();
		if (i <= s.Length() && ('0' <= s[i] && s[i] <= '9')) {
			t *= 10;
			t += (s[i] - '0');
		}
		else {
			switch(v) {
			case 0:
				a1 = t;
				break;
			case 1:
				a2 = t;
				break;
			case 2:
				a3 = t;
				break;
			case 3:
				a4 = t;
				break;
			}
			v++;
			if (v >= 4) {
				cm = mapa(mapa(a1, a2), mapa(a3, a4));
				ss += get_sym(cm);
				v = 0;
			}
			t = 0;
		}
	}

	Form1->Edit1->Text = ss;

	Form1->ProgressBar1->Position = 100;

	loging = Form2->CheckBox1->Checked;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	Form2->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	Form3->Position = Form1->Position;
	Form3->Top = Form1->Top;
	Form3->Left = Form1->Left;

	Form3->Show();

	AnsiString ss;

	for (int i = 0; i < logs.size(); ++i) {
		ss.Insert(get_vlc(13), ss.Length());
		ss.Insert(get_vlc(10), ss.Length());
		ss.Insert(logs[i], ss.Length());
	}
	Form3->Memo1->Text = ss;
}
// ---------------------------------------------------------------------------
