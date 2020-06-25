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
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

string s;
vector<int> v[2], ans;
int n, t;

void print(vector<int>& vec) {
	for(int x : vec) cout << x << ' ';
	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	v[0].clear(), v[1].clear(), ans.clear();
    	cin >> n >> s;
    	bool good = true, two = false;
    	int lo = 10;
    	REP(i, n) {
    		// print(v[0]);
    		// print(v[1]);
    		if(two) {
    			// DEBUG(lo);
    			// DEBUG(s[i]);
    			// DEBUG(s[v[1].back()]);
    			if(s[i] == lo && s[v[1].back()] == lo) {
    				v[1].push_back(i);
    			} else if(s[i] <= lo) {
    				if(!v[0].empty() && s[i] < s[v[0].back()]) {
    					good = false;
    					break;
    				} else {
    					v[0].push_back(i);
    				}
    			} else {
    				if(!v[1].empty() && s[i] < s[v[1].back()]) {
    					good = false;
    					break;
    				} else {
    					v[1].push_back(i);
    				}
    			}
    		} else {
	    		if(!v[0].empty() && s[i] < s[v[0].back()]) {
	    			two = true;
	    			vector<int> temp;
	    			while(!v[0].empty() && s[i] < s[v[0].back()]) {
	    				temp.push_back(v[0].back());
	    				v[0].pop_back();
	    			}
	    			lo = s[temp.back()];
	    			while(!temp.empty()) {
	    				v[1].push_back(temp.back());
	    				temp.pop_back();
	    			}
	    		}
	    		v[0].push_back(i);
    		}
    	}
    	ans.resize(n, 1);
    	REP(i, v[1].size()) {
    		ans[v[1][i]] = 2;
    	}
    	if(!good) cout << "-" << endl;
    	else {
	    	for(int x : ans) cout << x;
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

