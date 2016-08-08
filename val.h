#include <iostream>
#include <vector>

#define mapa make_pair
#define ff first
#define ss second

using namespace std;

const int MOD = 751;
int d[MOD][MOD], nb = 45, k = 3;
pair<int, int>G, Pm, Pb, Cm, E;

//<start> ������� ��� �����
void make_Pb();

int get_nb() {
   return nb;
}

int get_k() {
   return k;
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
//<end> ������� ��� �����

//������� � �������� ����;
int divv(int a, int b) {
   //��������� �� ������������ �����
   a %= MOD, b %= MOD;
   while (a < 0 || b < 0) {
      a < 0 ? a = a + MOD : a;
      b < 0 ? b = b + MOD : b;
   }
   int t = 0;
   //���� ������� ��������� �� ������ MOD, ��������� ����� t, ��� a = b * t mod(MOD);
   while (d[b][t] != a && t < MOD)
      t++;

   return t;
}

//�����
pair<int, int>sum(pair<int, int>a, pair<int, int>b) {
   //���������� ������� ����� ���� ����� �� ������������� ������;
   long long lam = 0, x1 = a.ff, x2 = b.ff, y1 = a.ss, y2 = b.ss, x3 = -1, y3 = -1;
   if (a != b)
      lam = divv(y2 - y1, x2 - x1);
   else
      lam = divv(3 * x1 * x1 + E.ff, 2 * y1);

   x3 = (lam * lam - x1 - x2) % MOD;
   y3 = (lam * (x1 - x3) - y1) % MOD;

   //��������� �� ������������ �����
   while (x3 < 0 || y3 < 0) {
      x3 < 0 ? x3 = x3 + MOD : x3;
      y3 < 0 ? y3 = y3 + MOD : y3;
   }

   return mapa(x3, y3);
}

//��������� ���������� �����
void make_Pb() {
   pair<int, int>m_pb = G;
   for (int i = 1; i < nb; ++i) {
      m_pb = sum(m_pb, G);
   }
   Pb = m_pb;
}

//����� ��������;
void set_def() {
   E = mapa(-1, 1);
   G = mapa(0, 1);
   Pm = mapa(66, 552);
   nb = 45;
   k = 3;

   for (int i = 0; i < MOD; ++i) {
      for (int j = 0; j < MOD; ++j) {
         d[i][j] = (i * j) % MOD;
      }
   }
   make_Pb(); // mapa(406, 397);
}

//���������, ���� ������� ��������, ��������� ����� ����� t, ��� a = b + t mod(MOD);
pair<int, int>mns(pair<int, int>a, pair<int, int>b) {
   for (int i = 1; i < MOD; ++i) {
      for (int j = 1; j < MOD; ++j) {
         if (sum(b, mapa(i, j)) == a) {
            return mapa(i, j);
         }
      }
   }

   return mapa(-1, -1);
}

// get Cm
//�� ������� ������� ������ Cm = {k*G, k*Pb + Data}, Data - ���������� ��������� �����
pair<pair<int, int>, pair<int, int> >g_cm(pair<int, int>data) {
   pair<int, int>a = G, b = Pb;
   for (int i = 1; i < k; ++i) {
      a = sum(a, G);
      b = sum(b, Pb);
   }
   b = sum(data, b);

   return mapa(a, b);
}

//����������, ���� �� �������;
pair<int, int>rev(pair<pair<int, int>, pair<int, int> >cm) {
   // cm.ss - nb*cm.ff
   pair<int, int>kg = cm.ff;
   for (int i = 1; i < nb; ++i) {
      kg = sum(kg, cm.ff);
   }

   kg = mns(cm.ss, kg);
   return kg;
}

//��������� ��� ������ � ���������;
const int CLEN = 256;
pair<char, pair<int, int> >val_c[CLEN];
pair<pair<int, int>, char>c_val[CLEN];
int x = 1, y = 1, an = 0;

//��� �����
char get_vlc(int i) {
   return val_c[i].ff;
}

// main() - ����� ��������;
void set_df_val() {
   // 531
   //������ ��������� y = x^3 - x + 1,
   //� ���� E751(���� � �������, �.�.
   //�� ������ 751, � ������� ���������� ���� ������ 751 ��� ����� (x, y) - ����� ����� ����� ���������)
   //������ ���������� x � y �� 0 �� 751;
   for (; x < MOD && an < CLEN; ++x) {
      int t = x * x * x - x + 1;
      y = -1;
      t %= MOD; ;
      for (int i = 1; i < MOD; ++i) {
         if ((i * i) % MOD == t)
            y = i;
      }
      //���� ������, �� ��������� ��� ����� � ����������� �� ��������� ������;
      if (y > -1) {
         int popr = 0; // first good symbol;
         val_c[an] = mapa((char)(an + popr), mapa(x, y));
         c_val[an] = mapa(mapa(x, y), (char)(an + popr));
         an++;
      }
   }

   for (int i = 0; i < an; ++i) {
      pair<char, pair<int, int> >p = val_c[i];
   }
   set_def();
}

//�� ��������� ������� ������� - ������� ��������� �������;
String get_Cm(String s) {
   String ans = "";

   for (int i = 1; i <= s.Length(); ++i) {
      for (int j = 0; j < an; ++j) {
         char ctr;
         if (j >= 207)
            ctr = s[i];
         AnsiString c = val_c[j].ff;
         AnsiString cc = s[i];
         if (cc == c) {
            int ask = 0; // shifr

            pair<pair<int, int>, pair<int, int> >cm = g_cm(val_c[j].ss);
            ans += cm.ff.ff;
            ans += " ";
            ans += cm.ff.ss;
            ans += " ";
            ans += cm.ss.ff;
            ans += " ";
            ans += cm.ss.ss;
            ans += "\r\n";
            break;
         }
      }
   }
   return ans;
}

//������� ���������������� �������, �� 4 ������ ���� ������;
AnsiString get_sym(pair<pair<int, int>, pair<int, int> >cm) {
   AnsiString ans = "";
   // deshifr
   pair<int, int>rp = rev(cm);
   if (rp.ff < 0) {
      int trt = 0;
   }
   //���� ������ ���������;
   for (int i = 0; i < CLEN; ++i) {
      if (rp == c_val[i].ff) {
         ans += val_c[i].ff;
         break;
      }
   }


   return ans;
}
