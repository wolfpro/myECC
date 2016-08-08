#include <iostream>


#define mapa make_pair
#define ff first
#define ss second

using namespace std;

const int MOD = 751;

int d[MOD][MOD], nb = 45, k = 3;
pair<int, int> G, Pm, Pb, Cm, E;

void set_def() {
   E = mapa(-1, 1);
   G = mapa(0, 1);
   Pm = mapa(66, 552);
   Pb = mapa(406, 397);
   for (int i = 0; i < MOD; ++i) {
      for (int j = 0; j < MOD; ++j) {
         d[i][j] = (i * j) % MOD;
      }
   }
}

int divv(int a, int b) {
   a %= MOD, b %= MOD;
   while (a < 0 || b <= 0) {
      a < 0 ? a = a + MOD : a;
      b < 0 ? b = b + MOD : b;
   }
   int t = 0;
   while (d[b][t] != a)
      t++;

   return t;
}

pair<int, int> sum(pair<int, int> a,  pair<int, int> b) {
   long long lam = 0, x1 = a.ff, x2 = b.ff, y1 = a.ss, y2 = b.ss, x3 = -1, y3 = -1;
   if (a != b)
      lam = divv(y2 - y1, x2 - x1);
   else
      lam = divv(3 * x1 * x1 + E.ff, 2 * y1);

   while (x3 < 0 || y3 < 0) {
      x3 = (lam * lam - x1 - x2) % MOD;
      y3 = (lam * (x1 - x3) - y1) % MOD;

      x3 < 0 ? x3 = x3 + MOD : x3;
      y3 < 0 ? y3 = y3 + MOD : y3;
   }

   return mapa(x3, y3);
}

pair<int, int> mns(pair<int, int> a,  pair<int, int> b) {
   for (int i = 0; i < MOD; ++i) {
      for (int j = 0; j < MOD; ++j) {
         if (sum(b, mapa(i, j)) == a) {
            return mapa(i, j);
         }
      }
   }
   return mapa(-1, -1);
}

//get Cm
pair <pair <int, int>, pair <int, int> > g_cm(pair <int, int> data) {
   pair <int, int> a = G, b  = Pb;
   for (int i = 1; i < k; ++i) {
      a = sum(a, G);
      b = sum(b, Pb);
   }
   b  = sum(data, b);

   return mapa(a, b);
}

pair <int, int> rev(pair <pair <int, int>, pair <int, int> > cm) {
   //cm.ss - nb*cm.ff
   pair <int, int> kg = cm.ff;
   for (int i = 1; i < nb; ++i) {
      kg = sum(kg, cm.ff);
   }

   kg = mns(cm.ss, kg);
   // cout << kg.ff << "," << kg.ss << endl;
   return  kg;
}
/*
int main() {
   set_def();

   pair <pair <int, int>, pair <int, int>>  cm = g_cm(Pm);

   cout << "Cm{(" << cm.ff.ff << "," << cm.ff.ss << "), (" << cm.ss.ff << "," << cm.ss.ss << ")}\n";

   rev(cm);

   return 0;
}*/