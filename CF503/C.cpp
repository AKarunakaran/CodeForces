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
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1LL<<62)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 3010;
int n, m, idx[N];
pii p[N];
vector<int> par[N];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) {
    	cin >> p[i].second >> p[i].first;
    	par[p[i].second].push_back(p[i].first);
    }
    sort(p, p+n);
    int hi = 0;
    FOR(i, 2, m) {
    	sort(par[i].begin(), par[i].end());
    	hi = max(hi, (int)par[i].size());
    }
    if(par[1].size() > hi) {
    	cout << 0 << endl;
    	exit(0);
    }
    int ans = INF;
    FOR(lev, 1, min(hi+1, n)) {
    	memset(idx, 0, sizeof(idx));
    	int cur = 0;
    	int v = par[1].size();
    	FOR(i, 2, m) {
    		while((int)par[i].size()-idx[i] >= lev) {
    			cur += par[i][idx[i]++];
    			++v;
    		}
    	}
    	int i = 0;
    	while(v < lev) {
    		int party = p[i].second;
    		if(party != 1 && par[party][idx[party]] == p[i].first) {
    			cur += p[i].first;
    			++idx[party];
    			++v;
    		}
    		++i;
    	}
    	ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}