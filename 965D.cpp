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

// n must be total number of vertices
// If too slow, try to do something obvious before call this function
// This flow algorithm is level sensitive
// The depth of the graph would effect run time a lot
int max_flow(int s, int t, int n) {
    vector<int> ff(n + 1, 0);
    vector<int> fa(n + 1, 0);
    vector<int> h(n + 1, 0);
    vector<int> hh(n + 1, 0);
    vector<int> fi(n + 1, 0);
    
    int i = 0, now, ans = 0;
    hh[0] = n;
    
    i = s;
    now = INF;
    
    while (h[s] < n) {
        ff[i] = now;
        bool flag = false;
        vector<pair<int, int> >::iterator p = g[i].begin();
        while (p != g[i].end()) {
            if (p->second > 0 && h[p->first] + 1 == h[i]) {
                flag = true;
                if (p->second < now) now = p->second;
                fa[p->first] = i;
                fi[p->first] = p - g[i].begin();
                i = p->first;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        p = g[i].begin() + fi[tmp];
                        p->second -=now;
                        g[tmp].push_back(make_pair(i, now));
                    }
                    now = INF;
                }
                break;
            }
            ++p;
        }
        if (flag) continue;
        
        int minL = n - 1;
        p = g[i].begin();
        while (p != g[i].end()) {
            if (p->second > 0 && h[p->first] < minL) minL = h[p->first];
            ++p;
        }
        
        --hh[h[i]];
        if (hh[h[i]] == 0) break;
        h[i] = minL + 1;
        ++hh[h[i]];
        if (i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}

int l, w;

int getInto(int i) {
	return 2*i-1;
}

int getOutOf(int i) {
	return 2*i;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> w >> l;
    vector<int> d(w+1, 0);
    FOR(i, 1, w) cin >> d[i];
    int src = 2*w+1, tgt = 2*w+2;
    FOR(i, 1, l) {
    	if(d[i]) g[src].push_back({getInto(i), INF});
    	if(d[w-i]) g[getOutOf(w-i)].push_back({tgt, INF});
    }
    FOR(i, 1, w) {
    	if(d[i]) g[getInto(i)].push_back({getOutOf(i), d[i]});
    	FOR(j, i+1, min(w-1, i+l)) if(d[j]) g[getOutOf(i)].push_back({getInto(j), INF});
    }
    // FOR(i, 1, tgt) {
    // 	for(auto p : g[i]) {
    // 		cout << "{" << p.first << ", " << p.second << "}, ";
    // 	}
    // 	cout << endl;
    // }
    cout << max_flow(src, tgt, tgt) << endl;


    return 0;
}