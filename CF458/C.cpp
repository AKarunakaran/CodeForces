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

const ll M = 1000000007;

int numBits(int n) {
	int res = 0;
	while(n) {
		int mask = n & (-n);
		++res;
		n -= mask;
	}
	return res;
}

int redNum(int n) {
	int res = 0;
	while(n != 1) {
		n = numBits(n);
		++res;
	}
	return res;
}

vector<vector<ll>> choose(1001, vector<ll>(1001, 0));

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    int k;
    cin >> s >> k;
    if(k == 0) {
    	cout << 1 << endl;
    	exit(0);
    }
    if(k == 1) {
    	cout << s.size()-1 << endl;
    	exit(0);
    }
    if(k > 5) {
    	cout << 0 << endl;
    	exit(0);
    }
    FOR(i, 0, 1000) {
    	FOR(j, 0, i) {
            if(i == 0 && j == 0) choose[i][j] = 0;
    		if(j == 0 || j == i) choose[i][j] = 1;
    		else choose[i][j] = (choose[i-1][j]+choose[i-1][j-1]) % M;
    	}
    }
    vector<int> imp;
    FOR(i, 1, 1000) {
    	if(redNum(i) == k-1) imp.push_back(i);
    }
    ll n = s.size(), ans = 0;
    // DEBUG(n);
    for(int i : imp) {
    	// DEBUG(i);
    	ans = (ans + choose[n][i]) % M;
    	// DEBUG(ans);
    	int ones = 0;
    	REP(j, n) {
    		if(s[j] == '1') {
    			++ones;
    			if(i-ones-1 < 0) break;
    		} else {
    			ans = (ans + M - choose[n-j-1][i-ones-1]) % M;
    		}
    	}
    	// DEBUG(ans);
    }
    cout << ans << endl;

    return 0;
}