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

const int N = 12, K = 1 << 12, M = 5e5+1;
int n, m, q, k, w[N], s[K], wu[K], ans[M], lomask;
vector<pair<pii, int>> sol[K];

int binary(string& str) {
	int res = 0;
	int t = 1;
	FORD(i, str.size()-1, 0) {
		if(str[i] == '1') res += t;
		t <<= 1;
	}
	return res;
}

int findwu(int b) {
	int idx = 0, res = 0;
	while(b) {
		if(b & 1) res += w[idx];
		b >>= 1;
		++idx;
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(s, 0, sizeof(s));
    cin >> n >> m >> q;
    k = 1 << n;
    lomask = k-1;
    REP(i, n) cin >> w[i];
    reverse(w, w+n);
    REP(i, m) {
    	string str;
    	cin >> str;
    	int cur = binary(str);
    	++s[cur];
    }
    REP(i, q) {
    	string str;
    	int mx;
    	cin >> str >> mx;
    	int cur = binary(str);
    	sol[cur].push_back({{mx, i}, 0});
    }
    REP(i, k) sort(sol[i].begin(), sol[i].end());
    REP(i, k) wu[i] = findwu(i);
    REP(i, k) {
    	if(sol[i].size() == 0) continue;
		// DEBUG(i);
    	REP(j, k) {
    		if(!s[j]) continue;
    		int mask = ~(i ^ j) & lomask;
    		// DEBUG(mask);
    		int cur = wu[mask];
    		pair<pii, int> b = {{cur, 0}, 0};
    		auto itr = lower_bound(sol[i].begin(), sol[i].end(), b);
    		// DEBUG(j);	
    		// DEBUG(cur);
    		// DEBUG(s[j]);
    		if(itr != sol[i].end()) {
    			itr->second += s[j];
    		}
    	}
    }
    REP(i, k) {
    	FOR(j, 1, (int)sol[i].size()-1) {
    		sol[i][j].second += sol[i][j-1].second;
    	}
    	REP(j, sol[i].size()) {
    		ans[sol[i][j].first.second] = sol[i][j].second;
    	}
    }

    REP(i, q) cout << ans[i] << endl;

    return 0;
}