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
#include <ctime>
#include <cstdlib>
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

ll randll() {
	ll res = rand();
	res <<= 32;
	return res | rand();
}

// [l, r]
ll randrangell(ll l, ll r) { return (randll() % (r-l+1)) + l; }

// [l, r]
int randrange(int l, int r) { return (rand() % (r-l+1)) + l; }

// [l, r)
double frandrange(double l, double r) { return (rand() / ((double)(RAND_MAX)+1))*(r-l) + l;}

int main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n = 1000;
    cout << n << endl;
    REP(i, n) {
        cout << (1 << 25)-1 << endl;
    }

    return 0;
}