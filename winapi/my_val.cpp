#include <iostream>

#include <map>
#include <vector>
#include <vcl.h>

#define mapa make_pair
#define ff first
#define ss second
#define puba push_back

using namespace std;

const int MOD = 751;

vector<AnsiString>logs;
bool loging = 0;

void add_log(AnsiString s) {
	if (!loging)
		return;
	vector<AnsiString>log = logs;
	log.push_back(s);
	logs = log;
}

// old
int d[MOD][MOD], nb = 45, k = 3;
// new
map<pair<int, int>, int>mapDiv; // a / b = c;
pair<int, int> dataMns[724];

pair<int, int>G, Pm, Pb, Cm, E;

void make_Pb();

int get_nb() {
	return nb;
}

int get_k() {
	return k;
}

void set_nb(int a) {
	nb = a;
}

void set_k(int a) {
	k = a;
}

void set_E(pair<int, int>a) {
	E = a;
}

void set_G(pair<int, int>a) {
	G = a;
}

pair<int, int>get_E() {
	return E;
}

pair<int, int>get_G() {
	return G;
}

pair<int, int>get_Pb() {
	make_Pb();
	return Pb;
}

// optimistic DO NOT dell comment
int divv(int a, int b) {
	a %= MOD, b %= MOD;
	while (a < 0 || b < 0) {
		a < 0 ? a = a + MOD : a;
		b < 0 ? b = b + MOD : b;
	}

	/* work, but not speed;
	int t = 0;
	while (d[b][t] != a && t < MOD)
	t++;

	return t;
	 */
	// new
	return mapDiv.find(mapa(a, b))->ss;
}

pair<int, int>sum(pair<int, int>a, pair<int, int>b) {
	AnsiString ts = " lam: ";

	long long lam = 0, x1 = a.ff, x2 = b.ff, y1 = a.ss, y2 = b.ss, x3 = -1, y3 = -1;
	if (a != b)
		lam = divv(y2 - y1, x2 - x1);
	else
		lam = divv(3 * x1 * x1 + E.ff, 2 * y1);

	ts += lam;
	add_log(ts);
	ts = " ";

	x3 = (lam * lam - x1 - x2);

	ts += "x3=";
	ts += x3;
	x3 %= MOD;

	y3 = (lam * (x1 - x3) - y1);
	ts += " y3=";
	ts += y3;
	add_log(ts);

	y3 %= MOD;

	while (x3 < 0 || y3 < 0) {
		x3 < 0 ? x3 = x3 + MOD : x3;
		y3 < 0 ? y3 = y3 + MOD : y3;
	}

	return mapa(x3, y3);
}

void make_Pb() {
	pair<int, int>m_pb = G;
	for (int i = 1; i < nb; ++i) {
		m_pb = sum(m_pb, G);
	}
	Pb = m_pb;
}

void set_def() {
	E = mapa(-1, 1);
	G = mapa(0, 1);
	Pm = mapa(66, 552);
	nb = 45;
	k = 3;

	//new divv
	mapDiv.clear();
	for (int i = 0; i < MOD; ++i) {
		for (int j = 0; j < MOD; ++j) {
			// old, work, but not speed;
			// d[i][j] = (i * j) % MOD;
			// new
			// mapDiv.emplace(mapa((i * j) % MOD, i), j);
			mapDiv[mapa((i * j) % MOD, i)] = j;
		}
	}
	//new mns
	for (int i = 1, tlen = 0; i < MOD; ++i) {
		int t = i * i * i - i + 1;
		t %= MOD;
		for (int j = 1; j < MOD; ++j) {
			if ((j * j) % MOD == t) {
				//cout << i << "," << j << endl;
				dataMns[tlen++]= mapa(i, j);
			}
		}
	}


	make_Pb(); // mapa(406, 397);
}

// get Cm
pair<pair<int, int>, pair<int, int> >g_cm(pair<int, int>data) {
	pair<int, int>a = G, b = Pb;

	AnsiString ts = " ��������� kG ";
	add_log(ts);
	for (int i = 1; i < k; ++i) {
		a = sum(a, G);
	}
	ts = " ��������� Pm +kPb ";
	add_log(ts);
	for (int i = 1; i < k; ++i)
		b = sum(b, Pb);

	b = sum(data, b);

	return mapa(a, b);
}

//DO NOT DELLET comment, otimasing
pair<int, int>mns(pair<int, int>a, pair<int, int>b) {
	//old
	//for (int i = 1; i < MOD; ++i) {
	//	for (int j = 1; j < MOD; ++j) {
	for (int k = 0; k < 724; ++k) {
		int i = dataMns[k].ff, j = dataMns[k].ss;
		if (sum(b, mapa(i, j)) == a) {
			return mapa(i, j);
		}
	}
	//}
	return mapa(-1, -1);
}

pair<int, int>rev(pair<pair<int, int>, pair<int, int> >cm) {
	// cm.ss - nb*cm.ff
	pair<int, int>kg = cm.ff;
	for (int i = 1; i < nb; ++i) {
		kg = sum(kg, cm.ff);
	}

	return mns(cm.ss, kg);
}

const int CLEN = 256;
pair<AnsiChar, pair<int, int> >val_c[CLEN];
pair<pair<int, int>, AnsiChar>c_val[CLEN];
int x = 1, y = 1, an = 0;

AnsiChar get_vlc(int i) {
	return val_c[i].ff;
}

// main()
void set_df_val() {
	// 531

	x = 1, y = 1, an = 0;
	for (; x < MOD && an < CLEN; ++x) {
		int t = x * x * x - x + 1;
		y = -1;
		t %= MOD; ;
		for (int i = 1; i < MOD; ++i) {
			if ((i * i) % MOD == t)
				y = i;
			else
				y = -1;
			if (y > -1) {
				int popr = 0; // first good symbol;
				val_c[an] = mapa((AnsiChar)(an + popr), mapa(x, y));
				c_val[an] = mapa(mapa(x, y), (AnsiChar)(an + popr));
				an++;
			}
		}
	}

	for (int i = 0; i < an; ++i) {
		pair<AnsiChar, pair<int, int> >p = val_c[i];
	}

	set_def();
}

AnsiString get_Cm(AnsiString s) {
	AnsiString ans = "";
	bool tlt = loging;
	for (int i = 1; i <= s.Length(); ++i) {
		if (s[i] == '\0')
			loging = 0;
		else
			loging = tlt;

		for (int j = 0; j < an; ++j) {
			AnsiChar ctr;
			if (j >= 207)
				ctr = s[i];
			AnsiString c = val_c[j].ff;
			AnsiString cc = s[i];
			if (cc == c) {
				int ask = 0; // shifr

				AnsiString ts = "��������� ��� '";
				ts += val_c[j].ff;
				ts += "'";

				add_log(ts);

				ts = " ������������� ����� ";
				ts += val_c[j].ss.ff;
				ts += " ";
				ts += val_c[j].ss.ss;
				add_log(ts);
				ts = " ";

				pair<pair<int, int>, pair<int, int> >cm = g_cm(val_c[j].ss);
				ts = "���������: Cm = {(";
				ts += cm.ff.ff;
				ts += ", ";
				ts += cm.ff.ss;
				ts += "), (";
				ts += cm.ss.ff;
				ts += ", ";
				ts += cm.ss.ss;
				ts += ")};";
				add_log(ts);

				ts = cm.ff.ff;
				ts += " ";
				ts += cm.ff.ss;
				ts += " ";
				ts += cm.ss.ff;
				ts += " ";
				ts += cm.ss.ss;

				ans += ts;
				ans += "\r\n";

				break;
			}
		}
	}
	return ans;
}

AnsiString get_sym(pair<pair<int, int>, pair<int, int> >cm) {
	AnsiString ans = "";
	// deshifr
	pair<int, int>rp = rev(cm);

	if (rp.ff < 0) {
		int trt = 0;
	}
	for (int i = 0; i < CLEN; ++i) {
		if (rp == c_val[i].ff) {
			ans += val_c[i].ff;
			break;
		}
	}
	return ans;
}
