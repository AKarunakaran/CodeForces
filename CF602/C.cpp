#include <bits/stdc++.h>
using namespace std;
#define int long long
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

const int N = 1e6+10;
int n, m, ans;
string s[N], t[N];
queue<pii> nxt;
vector<vector<int>> tim, vis;
set<pii> time_sorted[N];

bool empty_neighbor(int r, int c) {
	FOR(i, -1, 1) {
		FOR(j, -1, 1) {
			if(!i && !j) continue;
			if(s[r+i][c+j] == '.') return true;
		}
	}
	return false;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    t[0] = t[n+1] = string(m+2, '.');
    FOR(i, 1, n) {
    	cin >> t[i];
    	t[i] = "." + t[i] + ".";
    }
    bool transpose = n > m;
    if(transpose) {
    	FOR(i, 0, m+1) s[i].resize(n+2);
    	FOR(i, 0, n+1) FOR(j, 0, m+1) s[j][i] = t[i][j];
    	swap(n, m);
    } else {
    	FOR(i, 0, n+1) s[i] = t[i];
    }
    tim.resize(n+2, vector<int>(m+2, -1));
    vis.resize(n+2, vector<int>(m+2, 0));
    n += 2, m += 2;
    int numx = 0;
    REP(i, n) {
    	REP(j, m) {
    		if(s[i][j] == 'X') numx++;
    		if(s[i][j] == 'X' && empty_neighbor(i, j)) {
    			nxt.push({i, j});
    			vis[i][j] = 1;
    			tim[i][j] = 0;
    		}
    	}
    }
    int hi = 0;
    while(!nxt.empty()) {
    	int r, c, curtm;
    	tie(r, c) = nxt.front();
    	curtm = tim[r][c];
    	time_sorted[curtm].insert({r, c});
    	nxt.pop();
    	FOR(i, -1, 1) {
    		FOR(j, -1, 1) {
    			if(!i && !j) continue;
    			if(!vis[r+i][c+j] && s[r+i][c+j] == 'X') {
    				vis[r+i][c+j] = 1;
    				nxt.push({r+i, c+j});
    				tim[r+i][c+j] = curtm+1;
    				hi = max(hi, curtm+1);
    			}
    		}
    	}
    }
    // FOR(i, 1, n-2) {
    // 	FOR(j, 1, m-2) cout << (tim[i][j] == -1 ? "." : to_string(tim[i][j])) << ' ';
    // 	cout << endl;
    // }
    int l = 0, r = hi;
    while(l < r) {
    	int cur_mark = 0;
    	int mid = (l+r+1)/2;
	    vis = vector<vector<int>>(n, vector<int>(m, 0));
	    vector<vector<int>> d(n, vector<int>(m, -1));
	    FORD(curtm, hi, mid) {
    		for(auto[r, c] : time_sorted[curtm]) {
    			vis[r][c] = 1;
    			d[r][c] = 0;
    			++cur_mark;
    			nxt.push({r, c});
    		}
    	}
		while(!nxt.empty()) {
	    	int r, c;
	    	tie(r, c) = nxt.front();
	    	nxt.pop();
	    	if(d[r][c] < mid) {
		    	FOR(i, -1, 1) {
		    		FOR(j, -1, 1) {
		    			if(!i && !j) continue;
		    			if(!vis[r+i][c+j] && s[r+i][c+j] == 'X') {
		    				++cur_mark;
		    				vis[r+i][c+j] = 1;
		    				nxt.push({r+i, c+j});
		    				d[r+i][c+j] = d[r][c] + 1;
		    			}
		    		}
		    	}
	    	}
	    }
	    if(cur_mark == numx) l = mid;
	    else r = mid-1;
    }
    ans = l;

    cout << ans << endl;
    n -= 2, m -= 2;
    if(transpose) {
	    FOR(i, 1, m) {
	    	FOR(j, 1, n) {
	    		if(tim[j][i] >= ans) cout << 'X';
	    		else cout << '.';
	    	}
	    	cout << endl;
	    }
    } else {
    	FOR(i, 1, n) {
	    	FOR(j, 1, m) {
	    		if(tim[i][j] >= ans) cout << 'X';
	    		else cout << '.';
	    	}
	    	cout << endl;
	    }
    }

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
