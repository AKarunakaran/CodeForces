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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m, left = 0;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> cp(n);
    vector<int> d(n, 0);
    REP(i, n) {
    	int co;
    	cin >> co;
    	cp[i] = co;
    	if(cp[i]) ++left;
    }
    REP(i, m) {
    	int s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    	++d[e];
    }
	vector<int> mfree, cfree;
    REP(i, n) {
    	if(d[i] == 0) {
    		if(cp[i]) cfree.push_back(i);
    		else mfree.push_back(i);
    	}
	}
	int ans = 0, mi = 0, ci = 0;
	while(left) {
		while(mi < mfree.size()) {
			int cur = mfree[mi];
			for(auto v : g[cur]) {
				--d[v];
				if(d[v] == 0) {
					if(cp[v]) cfree.push_back(v);
					else mfree.push_back(v);
				}
			}
			++mi;
		}
		// DEBUG(mi);
		while(ci < cfree.size()) {
			int cur = cfree[ci];
			for(auto v : g[cur]) {
				--d[v];
				if(d[v] == 0) {
					if(cp[v]) cfree.push_back(v);
					else mfree.push_back(v);
				}
			}
			--left;
			++ci;
		}
		// DEBUG(ci);
		++ans;
	}
	cout << ans << endl;

    return 0;
}