#include <iostream>

#define mapa make_pair
#define ff first
#define ss second

using namespace std;

const int MOD = 751;

int nb = 45;
int k = 3;

pair <int, int> G, E;

struct node {
   int x, y;
};

bool eq(node a, node b) {
   bool fl = (a.x == b.x);// * (a.y == b.y);
   //cout << fl;
   return fl;
}

node sm(node a, node b) {
   double lam = 0.0;
   if (eq(a, b)) {
      lam = 1.0 * (3 * a.x * a.x + E.ff) / 2;
   } else {
      lam = 1.0 * (b.y - a.y) / (b.x - a.x);
   }

   //lam = (int)lam;
   /*   int t = lam;
      lam = t % MOD;
      if (lam < 0)
         lam += MOD;*/

   cout << lam << endl;

   int x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
   a.x = lam * lam - x1 - x2;
   a.x %= MOD;
   if (a.x < 0)
      a.x += MOD;

   a.y = lam * (x1 - a.x) - y1;
   a.y %= MOD;
   if (a.y < 0)
      a.y += MOD;

   return a;
}



int main() {
   //cout << "f";
   E = mapa(-1, 1);
   G = mapa(0, 1);
   node g;
   g.x = 0, g.y = 1;

   node pb = g;

   for (int i = 1; i < nb; ++i) {
      pb = sm(pb, g);
   }

   cout << pb.x << " " << pb.y;

   return 0;
}