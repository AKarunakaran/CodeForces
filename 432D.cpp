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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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

const int N = 1e5+10;
string s;
int n, z[N], f[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> s;
    n = s.size();
	int l = 0, r = 0;
	FOR(i, 1, n-1) {
		if(i > r) {
			l = r = i;
			while (r < n && s[r-l] == s[r]) r++;
			z[i] = r-l; r--;
		} else {
			int k = i-l;
			if(z[k] < r-i+1) z[i] = z[k];
			else {
				l = i;
				while (r < n && s[r-l] == s[r]) r++;
				z[i] = r-l; r--;
			}
		}
	}
	vector<int> ans;
    FORD(i, n-1, 1) {
    	if(z[i]+i == n) ans.push_back(z[i]);
    	++f[z[i]];
    }
    FORD(i, n-1, 1) f[i] += f[i+1];
    ans.push_back(n);
    cout << ans.size() << endl;
    for(int x : ans) cout << x << ' ' << f[x]+1 << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
