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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> prev(n, -1);
    vector<bool> vis(n, 0);
    int i = 0;
    vector<int> z, o;
    int zidx = 0, oidx = 0;
    while(i < n && s[i] != '1') {
    	z.push_back(i);
    	++i;
    }
    while(i < n) {
	    while(i < n && s[i] == '1') {
	    	o.push_back(i);
	    	if(zidx == z.size()) {
	    		cout << -1 << endl;
	    		exit(0);
	    	}
	    	prev[i] = z[zidx++];
	    	++i;
	    }
	    if(i == n) {
	    	cout << -1 << endl;
	    	exit(0);
	    }
	    while(i < n && s[i] == '0') {
	    	z.push_back(i);
	    	if(oidx < o.size()) {
	    		prev[i] = o[oidx++];
	    	}
	    	++i;
	    }
    }
    if(oidx < o.size()) {
    	cout << -1 << endl;
    	exit(0);
    }
	vector<vector<int>> ans;
	FORD(i, n-1, 0) {
		if(!vis[i]) {
			vector<int> cur;
			int idx = i;
			while(idx != -1) {
				vis[idx] = 1;
				cur.push_back(idx);
				idx = prev[idx];
			}
			reverse(cur.begin(), cur.end());
			ans.push_back(cur);
		}
	}
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i].size() << ' ';
		REP(j, ans[i].size()) cout << ans[i][j]+1 << ' ';
		cout << endl;
	}

    return 0;
}