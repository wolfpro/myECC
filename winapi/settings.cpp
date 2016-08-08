// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "settings.h"
#include "my_val.cpp"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

String make_name(pair<int, int>p) {
	String s;
	s = p.ff;
	s += " ";
	s += p.ss;
	return s;
}

void sync_const() {
	String s;
	Form2->Edit1->Text = get_nb();
	Form2->Edit2->Text = get_k();
	Form2->Edit3->Text = make_name(get_Pb());
	Form2->Edit4->Text = make_name(get_E());
	Form2->Edit5->Text = make_name(get_G());
}

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
	set_def();

	sync_const();
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) {
	set_def();
	sync_const();
}

// ---------------------------------------------------------------------------

int gv(String s) {
	int t = 0, mn = 1;
	for (int i = 1; i <= s.Length(); ++i) {
		if (s[i] == '-') {
			mn = -1;
			continue;
		}
		t *= 10;
		t += s[i] - '0';
	}
	return t*mn;
}

pair<int, int>doub_gv(String st) {
	String at = "", bt = "";
	bool fl = 0;
	for (int i = 1; i <= st.Length(); ++i) {
		if (st[i] == ' ') {
			fl = 1;
			continue;
		}
		if (fl)
			bt += st[i];
		else
			at += st[i];
	}

	return mapa(gv(at), gv(bt));
}

void update() {
	set_nb(gv(Form2->Edit1->Text));
	// nb = gv(Form2->Edit1->Text);
	// k = gv(Form2->Edit2->Text);
	set_k(gv(Form2->Edit2->Text));
	set_E(doub_gv(Form2->Edit4->Text));
	set_G(doub_gv(Form2->Edit5->Text));
	// E = doub_gv(Form2->Edit4->Text);
	// G = doub_gv(Form2->Edit5->Text);
}

void __fastcall TForm2::Button4Click(TObject *Sender) {
	update();
	sync_const();
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender) {
	sync_const();
	Form2->Hide();
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender) {
	update();
	sync_const();
	Form2->Hide();
}

// ---------------------------------------------------------------------------

