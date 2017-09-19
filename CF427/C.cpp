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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

vector<int> vsub(vector<int> v1, vector<int> v2) {
	vector<int> ret(v1.size());
	REP(i, v1.size()) ret[i] = v1[i]-v2[i];
	return ret;
}

vector<int> vsum(vector<int> v1, vector<int> v2) {
	vector<int> ret(v1.size());
	REP(i, v1.size()) ret[i] = v1[i]+v2[i];
	return ret;
}

void vprint(vector<int>& v) {
	REP(i, v.size()) cout << v[i] << " ";
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, c, q;
    cin >> n >> q >> c;
    vector<vector<int>> stars(101, vector<int>(101, -1));
    REP(i, n) {
    	int x, y, s;
    	cin >> x >> y >> s;
    	stars[y][x] = s;
    }
    vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>>(101, vector<vector<int>>(4, vector<int>(c+1, 0))));
    FOR(y, 2, 100) {
    	FOR(x, 2, 100) {
    		if(stars[y][x] != -1) ++dp[1][1][1][stars[y][x]];
    	}
    }
    FORD(y, 10, 1) {
    	FOR(x, 1, 10) cout << stars[y][x] << "\t";
    	cout << endl;
    }
    cout << endl;

    FOR(y, 1, 100) {
    	FOR(x, 1, 100) {
    		if(y == 1 && x == 1) continue;
    		if(x == 1) {
    			dp[y][x] = dp[y-1][x];
    			FOR(i, 2, 100) {
    				if(stars[y-1][i] != -1) ++dp[y][x][3][stars[y-1][i]];
    				if(stars[y][i] != -1) --dp[y][x][1][stars[y][i]];
    			}
    		} else {
    			dp[y][x] = dp[y][x-1];
    			FOR(i, 1, 100) {
    				if(stars[i][x-1] != -1) {
    					if(i > y) ++dp[y][x][0][stars[i][x-1]];
    					else if(i < y) ++dp[y][x][2][stars[i][x-1]];
    				}
    				if(stars[i][x] != -1) {
    					if(i > y) --dp[y][x][1][stars[i][x]];
    					if(i < y) --dp[y][x][3][stars[i][x]];
    				}
    			}
    		}
    	}
    }
    REP(test, q) {
    	ll ans = 0, t, x1, y1, x2, y2;
    	cin >> t >> x1 >> y1 >> x2 >> y2;
    	t = t % (c+1);
    	vector<int> rs = vsum(vsub(dp[y1][x1][1], vsum(vsum(dp[y2][x2][0], dp[y2][x2][1]), dp[y2][x2][3])), vsum(dp[y2][x1][0], dp[y1][x2][3]));
    	FOR(i, y1, y2) {
    		if(stars[i][x1] != -1) ++rs[stars[i][x1]];
    	}
    	FOR(i, x1+1, x2) {
    		if(stars[y1][i] != -1) ++rs[stars[y1][i]];
    	}
    	vprint(dp[y1][x1][1]);
    	vprint(dp[y2][x2][0]);
    	vprint(dp[y2][x2][1]);
    	vprint(dp[y2][x2][3]);
    	vprint(dp[y2][x1][0]);
    	vprint(dp[y1][x2][3]);
    	vprint(rs);
    	FOR(i, 0, c) {
    		ans += ((rs[i]+t)%(c+1));
    	}
    	cout << ans << endl;
    	cout << endl;
    }


    return 0;
}