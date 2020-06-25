#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

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
    int n = 500;
    cout << n << ' ' << n << endl;
    REP(i, n) {
        cout << randrange(1, 1e9) << ' ' << randrange(1, 1e9) << endl;
    }

    return 0;
}