#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

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

const int K = 20;
int k, N, ts, c[K], p[K], bs[K];
vector<int> boxes[K], nums(1);
map<int, int> idm, bm; //id map, box map

void bad() {
	cout << "No" << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> k;
    FOR(i, 1, k) {
    	int n;
    	cin >> n;
    	REP(j, n) {
    		int x;
    		cin >> x;
    		idm[x] = N+j+1;
    		bm[x] = i;
    		boxes[i].push_back(x);
    		nums.push_back(x);
    		ts += x;
    		bs[i] += x;
    	}
    	N += n;
    }

    if(ts % k != 0) bad();
    int rsum = ts/k;

    // 1..k source boxes, k+1..2k target boxes, 2k+1..2k+N source ints, 2k+N+1..2k+2N target ints, 2k+2N+1 src, 2k+2N+2 tgt
    int src = 2*k+2*N+1, tgt = 2*k+2*N+2;

    FOR(i, 1, k) {
    	int delta = rsum-bs[i];
    	g[src].push_back({i, 1});
    	g[k+i].push_back({tgt, 1});
    	REP(j, boxes[i].size()) {
    		int num = boxes[i][j];
    		int curid = idm[num];
    		g[i].push_back({2*k+curid, 1});
    		g[2*k+N+curid].push_back({k+i, 1});
    		if(delta == 0 || (bm.count(num+delta) && bm[num+delta] != i)) {
    			int need = idm[num+delta];
    			g[2*k+need].push_back({2*k+N+curid, 1});
    		}
    	}
    }

    FOR(i, 1, tgt) {
    	for(auto [v, w] : g[i]) {
    		cout << "{" << v << ", " << w << "} ";
    	}
    	cout << endl;
    }
    cout << endl << endl;

    int res = max_flow(src, tgt, tgt);

    FOR(i, 1, tgt) {
    	for(auto [v, w] : g[i]) {
    		cout << "{" << v << ", " << w << "} ";
    	}
    	cout << endl;
    }

    if(res != k) bad();
    FOR(i, 1, k) {
    	REP(j, g[i].size()) {
    		map<int, int> caps;
    		caps[g[i][j].first] += g[i][j].second;
    		for(auto [d, cap] : caps) {
	    		if(cap == 0) {
	    			c[i] = nums[d-2*k];
	    			break;
	    		}
    		}
    	}
    }
    FOR(i, 1, k) {
    	int curid = 2*k+idm[c[i]];
    	DEBUG(c[i]);
    	DEBUG(curid);
    	REP(j, g[curid].size()) {
    		map<int, int> caps;
    		caps[g[curid][j].first] += g[curid][j].second;
    		for(auto [d, cap] : caps) {
	    		if(cap == 0) {
	    			p[i] = bm[nums[d-2*k-N]];
	    			break;
	    		}
    		}
    	}
    }
    cout << "Yes" << endl;
    FOR(i, 1, k) cout << c[i] << ' ' << p[i] << endl;

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
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
