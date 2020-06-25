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
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////
int n, m, k, ans = 0;
vector<set<int>> d;
vector<vector<int>> amt;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    d.resize(n);
    amt.resize(n);
    int total = 0;
    REP(i, n) {
    	string s;
    	cin >> s;
    	REP(j, m) {
    		if(s[j] == '1') d[i].insert(j);
    	}
    	if(d[i].size() == 0) continue;
    	if(*d[i].begin() == *d[i].rbegin()) total += 1;
    	else total += *d[i].rbegin() - *d[i].begin()+1;
    }
    if(k == 0) {
    	cout << total << endl;
    	exit(0);
    }
    REP(i, n) {
    	auto& s = d[i];
    	int maxSkip = min((int)s.size(), k);
    	amt[i].resize(maxSkip+1, INF);
    	FOR(j, 0, maxSkip) {
    		if(j == maxSkip && maxSkip == s.size()) {
    			amt[i][j] = 0;
    			break;
    		}
    		auto back = s.begin();
    		auto front = s.end();
    		--front;
    		REP(r, j) --front;
    		while(front != s.end()) {
    			amt[i][j] = min(amt[i][j], *front-*back+1);
    			++front;
    			++back;
    		}
    		// DEBUG(i);
    		// DEBUG(j);
    		// DEBUG(amt[i][j]);
    	}
    }
    vector<vector<ll>> dp(n, vector<ll>(k+1, INF));
    REP(i, n) {
    	if(i == 0) {
    		FORD(j, k, 0) {
    			if(k-j > amt[i].size()-1) break;
    			dp[i][j] = amt[i][k-j];
    		}
    		continue;
    	}
    	FORD(j, k, 0) {
    		FORD(r, j, 0) {
    			if(j-r > amt[i].size()-1) break;
    			dp[i][r] = min(dp[i][r], dp[i-1][j]+amt[i][j-r]);
    		}
    	}
    }
    // FORD(j, k, 0) {
    // 	FOR(i, 0, n-1) cout << dp[i][j] << ' ';
    // 	cout << endl;
    // }
    // cout << endl;
    int ans = INF;
    FORD(i, k, 0) ans = min(ans, (int)dp[n-1][i]);
    cout << ans << endl;

    return 0;
}