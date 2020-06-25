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
using namespace std; 
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
const ll INF = (((1LL<<62)-1)<<1)+1;
const int nINF = 1<<31;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int n, a[N];
map<int, int> m;
vector<pii> v;

int solve() {
	int res = INF;
	int l = 0, r = 1;
	ll s = v[0].second;
	int k = v.size();
	while(1) {
		if(s >= n) {
			int a = v[r-1].first-v[l].first, b;
			if(l == 0) {
				if(s == n) b = v[k-1].first-v[r].first;
				else b = v[k-1].first-v[r-1].first;
			} else if (r == k) {
				if(s == n) b = v[l-1].first-v[0].first;
				else b = v[l].first-v[0].first;
			} else {
				b = v[k-1].first-v[0].first;
			}
			res = min(res, a*b);
			s -= v[l].second;
			++l;
		} else {
			if(r == k) break;
			s += v[r].second;
			++r;
		}
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, 2*n) cin >> a[i];
    REP(i, 2*n) ++m[a[i]];
    for(auto& p : m) v.push_back({p.first, p.second});
    cout << solve() << endl;

    return 0;
}