#include <windows.h> //for stable test;

#include <iostream>
#include <map>

#define mapa make_pair
#define ff first
#define ss second
#define puba push_back

using namespace std;

const int MOD = 751;

//old
int d[MOD][MOD];

//new
pair<int, int> dataMns[724];

int divvOld(int a, int b) {
	int t = 0;
	while (d[b][t] != a && t < MOD)
		t++;
	return t;
}

void setDefOld() {
	for (int i = 0; i < MOD; ++i) {
		for (int j = 0; j < MOD; ++j) {
			d[i][j] = (i * j) % MOD;
		}
	}
}

//new
map <pair <int, int>, int > mapDiv;// a / b = c;

void setDefNew() {
	for (int i = 0; i < MOD; ++i) {
		for (int j = 0; j < MOD; ++j) {
			mapDiv.emplace(mapa((i * j) % MOD, i), j);
		}
	}
}

int divvNew(int a, int b) {
	return mapDiv.find(mapa(a, b))->ss;
}

int main() {
	int lenght = 0;
	for (int i = 1; i < MOD; ++i) {
		int t = i * i * i - i + 1;
		t %= MOD;
		for (int j = 1; j < MOD; ++j) {
			if ((j * j) % MOD == t) {
				if (i == 206)
					cout << i << " " << j << endl;
				//cout << i << "," << j << endl;
			}
		}
	}

	int tS;
	int num = 1000 * 1000 * 10;

	tS = GetTickCount();
	setDefOld();
	cout << "setting OLD:" << GetTickCount() - tS << endl;

	tS = GetTickCount();
	for (int i = 0; i < num; ++i) {
		int a = i / MOD, b = i % MOD;
		divvOld(a, b);
	}
	cout << "clac OLD:" << GetTickCount() - tS << endl;

	tS = GetTickCount();
	setDefNew();
	cout << "setting NEW:" << GetTickCount() - tS << endl;

	tS = GetTickCount();
	for (int i = 0; i < num; ++i) {
		int a = i / MOD, b = i % MOD;
		divvNew(a, b);
	}
	cout << "clac NEW:" << GetTickCount() - tS << endl;



	return 0;
}