#include <iostream>
#include <vector>

#define mapa make_pair
#define ff first
#define ss second

using namespace std;

const int MOD = 751;

const int CLEN = 94;
pair<char, pair<int, int> >val_c[CLEN];
pair<pair<int, int>, char>c_val[CLEN];
int x = 1, y = 1, an = 1;

// main()
void set_df_val() {

	for (; x < 186; ++x) {
		int t = x * x * x - x + 1;
		y = -1;
		// cout << t << ":";
		t %= MOD; ;
		for (int i = 1; i < 751; ++i) {
			// cout << i*i;
			if ((i * i) % MOD == t)
				y = i;
		}
		if (y > -1) {
			// cout << (char)(an + 32) << ":(" << x << "," << y << ")" << endl;
			// /cout << an << endl;
			val_c[an - 1] = mapa((char)(an + 32), mapa(x, y));
			c_val[an - 1] = mapa(mapa(x, y), (char)(an + 32));
			an++;
		}
	}

	for (int i = 0; i < an; ++i) {
		pair<char, pair<int, int> >p = val_c[i];
		// cout << p.ff << "=" << p.ss.ff << "," << p.ss.ss << endl;
	}
	an--;

	set_def();
}

string gi(int a) {
	string s = "";
	while (a > 0) {
		char c = a % 10 + '0';
		s += c;
		a /= 10;
	}
	return s;
}

string get_Cm(string s) {
	string ans = "";
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < an; ++j) {
			if (s[i] == val_c[j].ff) {
				// cout << val_c[j].ss.ff << " " << val_c[j].ss.ss << endl;

				// shifr
				pair<pair<int, int>, pair<int, int> >cm = g_cm(val_c[j].ss);

				ans = gi(cm.ff.ff) + " " + gi(cm.ff.ss) + " " + gi(cm.ss.ff) + " " + gi
				      (cm.ss.ss);
				// cout << "Cm{(" << cm.ff.ff << ", " << cm.ff.ss << "), (" << cm.ss.ff << ", " << cm.ss.ss << ")} = ";

				// deshifr
				/* pair <int, int> rp = rev(cm);
				for (int i = 0; i < CLEN; ++i) {
				if (rp == c_val[i].ff) {
				cout << c_val[i].ss << ": " << val_c[i].ss.ff << " " << val_c[i].ss.ss << endl ;
				break;
				}
				} */
				// << rev(cm) << endl;

				break;
			}
		}
	}
	return ans;
}

string get_sym(string s) {
	string ans = "";
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < an; ++j) {
			if (s[i] == val_c[j].ff) {
				// cout << val_c[j].ss.ff << " " << val_c[j].ss.ss << endl;

				// shifr
				pair<pair<int, int>, pair<int, int> >cm = g_cm(val_c[j].ss);
				// cout << "Cm{(" << cm.ff.ff << ", " << cm.ff.ss << "), (" << cm.ss.ff << ", " << cm.ss.ss << ")} = ";

				// deshifr
				pair<int, int>rp = rev(cm);
				for (int i = 0; i < CLEN; ++i) {
					if (rp == c_val[i].ff) {
						// cout << c_val[i].ss << ": " << val_c[i].ss.ff << " " << val_c[i].ss.ss << endl ;
						ans += c_val[i].ss;
						break;
					}
				}
				// << rev(cm) << endl;

				break;
			}
		}
	}
	return ans;
}

/*
int main() {

string s;
//cin >> s;

//getline(cin, s);
// s = "sd";
for (int i = 0; i < s.size(); ++i) {
for (int j = 0; j < an; ++j) {
if (s[i] == val_c[j].ff) {
//cout << val_c[j].ss.ff << " " << val_c[j].ss.ss << endl;

//shifr
pair <pair <int, int>, pair <int, int> >  cm = g_cm(val_c[j].ss);
cout << "Cm{(" << cm.ff.ff << ", " << cm.ff.ss << "), (" << cm.ss.ff << ", " << cm.ss.ss << ")} = ";

//deshifr
pair <int, int> rp = rev(cm);
for (int i = 0; i < CLEN; ++i) {
if (rp == c_val[i].ff) {
cout << c_val[i].ss << ": " << val_c[i].ss.ff << " " << val_c[i].ss.ss << endl ;
break;
}
}
// << rev(cm) << endl;

break;
}
}
}

return 0;
}
 */
