#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

vector<int> cube(24);

void good() {
	bool res = true;
	REP(i, 6) res &= (cube[4*i] == cube[4*i+1] && cube[4*i+1] == cube[4*i+2] && cube[4*i+2] == cube[4*i+3]);
	if(res) {
		cout << "YES" << endl;
		exit(0);
	}
}

void R() {
	int temp = cube[5];
	cube[5] = cube[9];
	cube[9] = cube[22];
	cube[22] = cube[1];
	cube[1] = temp;
	temp = cube[7];
	cube[7] = cube[11];
	cube[11] = cube[20];
	cube[20] = cube[3];
	cube[3] = temp;
}

void U() {
	int temp = cube[5];
	cube[5] = cube[17];
	cube[17] = cube[21];
	cube[21] = cube[13];
	cube[13] = temp;
	temp = cube[16];
	cube[16] = cube[20];
	cube[20] = cube[12];
	cube[12] = cube[4];
	cube[4] = temp;
}

void F() {
	int temp = cube[3];
	cube[3] = cube[13];
	cube[13] = cube[8];
	cube[8] = cube[18];
	cube[18] = temp;
	temp = cube[2];
	cube[2] = cube[15];
	cube[15] = cube[9];
	cube[9] = cube[16];
	cube[16] = temp;
}

int main() {
    ios::sync_with_stdio(false);
    REP(i, 24) cin >> cube[i];

    R();
	good();
    R();
    R();
	good();
    R();

    U();
	good();
    U();
    U();
	good();
    U();

    F();
	good();
    F();
    F();
	good();

    cout << "NO" << endl;

    return 0;
}