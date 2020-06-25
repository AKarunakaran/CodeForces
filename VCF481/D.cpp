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

const int N = 1e5, bad = 1e5+1;
int n, b[N], d[N];

int test(int t) {
	DEBUG(t);
	int tb[N], res = 0;
	REP(i, n) tb[i] = b[i];
	if(tb[1]-tb[0] == t+2) {++tb[0]; ++res;}
	else if(tb[1]-tb[0] == t-2) {--tb[0]; ++res;}
	FOR(i, 0, n-2) {
		if(tb[i+1]-tb[i] == t) {
		} else if(tb[i+1]-tb[i] == t-1) {
			++tb[i+1];
			++res;
		} else if(tb[i+1]-tb[i] == t+1) {
			--tb[i+1];
			++res;
		} else return bad;
	}
	DEBUG(res);
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> b[i];
    if(n < 2) {
    	cout << 0 << endl;
    	exit(0);
    }
    REP(i, n-1) d[i] = b[i+1]-b[i];
    --n;
	int ans = bad;
	FOR(i, d[0]-2, d[0]+2) ans = min(ans, test(i));
	cout << (ans == bad ? -1 : ans) << endl;

    return 0;
}