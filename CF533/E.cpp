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
// const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int MAXN = 200100;
const int INF = 1000000000;

// destination, capacity
vector<pair<int, int> > g[MAXN];

int max_flow(int s, int t, int n) {
    vector<int> ff(n + 1, 0);
    vector<int> fa(n + 1, 0);
    vector<int> fi(n + 1, 0);
    vector<bool> z(n + 1, 0);
    
    int i = s, now = INF, ans = 0;
    
    while(1) {
        z[i] = true;
        ff[i] = now;
        bool flag = false;
        auto p = g[i].begin();
        while(p != g[i].end()) {
             if(p->second > 0 && !z[p->first]) {
                flag = true;
                if (p->second < now) now = p->second;
                fa[p->first] = i;
                fi[p->first] = p - g[i].begin();
                i = p->first;
                if(i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        p = g[i].begin() + fi[tmp];
                        p->second -=now;
                        g[tmp].push_back(make_pair(i, now));
                    }
                    now = INF;
                    z = vector<bool> (n + 1, false);
                }
                break;
            }
            ++p;
        }
        if(flag) continue;
        if(!flag && i == s) break;
        
        if(i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}

const int N = 1e5+10;
pair<int, int> e[N];
map<string, int> nameid;
int n, m, nid = 1;

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    FOR(i, 1, n) {
    	int type;
    	cin >> type;
    	e[i].first = type;
    	if(type == 2) {
    		string name;
    		cin >> name;
    		if(nameid.find(name) == nameid.end()) nameid[name] = nid++;
    		e[i].second = nameid[name];
    	}
    }

    // 0 offset, 1..n events, n+1..n+m friends, n+m+1 src, n+m+2 tgt

	int last, src = n+m+1, tgt = n+m+2;
    FOR(i, 1, n) {
    	// DEBUG(e[i].first);
    	// DEBUG(e[i].second);
    	if(e[i].first == 1) {
    		last = i;
    		g[src].push_back({last, 1});
    	} else {
    		int curid = e[i].second;
    		g[last].push_back({n+curid, 1});
    	}
    }
    FOR(i, 1, m) g[n+i].push_back({tgt, 1});

    // FOR(i, 1, tgt) {
    // 	for(auto& p : g[i]) cout << "{" << p.first << ", " << p.second << "} ";
    // 	cout << endl;
    // }

    cout << max_flow(src, tgt, tgt) << endl;

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
