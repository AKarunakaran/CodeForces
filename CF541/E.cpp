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

int n, have[26];
vector<int> longest(26, 0);

bool allone(string& s) {
	int sz = s.size();
	FOR(i, 1, sz-1) if(s[i] != s[0]) return false;
	return true;
}

vector<int> getruns(string& s) {
	vector<int> res(26, 0);
	s.push_back('#');
	int sz = s.size();
	int last = 0;
	FOR(i, 1, sz-1) {
		if(s[i] != s[last]) {
			res[s[last]-'a'] = max(res[s[last]-'a'], i-last);
			last = i;
		}
	}
	s.pop_back();
	return res;
}

vector<int> first_run(string& s) {
	vector<int> res(26, 0);
	int sz = s.size();
	FOR(i, 1, sz-1) {
		if(s[i] != s[0]) {
			res[s[0]-'a'] = max(res[s[0]-'a'], i);
			return res;
		}
	}
	return res;
}

vector<int> back_run(string& s) {
	reverse(s.begin(), s.end());
	vector<int> res = first_run(s);
	reverse(s.begin(), s.end());
	return res;
}

void update_exist(string& s) {
	for(char& c : s) have[c-'a'] = 1;
}

void print(vector<int>& v) {
	for(int x : v) cout << x << ' ';
	cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
	string s;
    cin >> n >> s;
    longest = getruns(s);
    // print(longest);
    update_exist(s);
    REP(i, n-1) {
    	cin >> s;

    	vector<int> old = longest;
    	longest = getruns(s);
    	if(allone(s)) {
    		int id = s[0]-'a';
    		if(have[id]) {
    			longest[id] = old[id]+(old[id]+1)*s.size();
    		} else {
    			//longest[id] is the run, so we are fine
    		}
    	} else {
    		vector<int> ff = first_run(s), bf = back_run(s);
    		REP(i, 26) {
    			if(have[i]) {
    				longest[i] = max(longest[i], 1+ff[i]+bf[i]);
    			}
    		}
    	}
    	REP(i, 26) if(have[i]) longest[i] = max(longest[i], 1);
	    // print(longest);
    	update_exist(s);
    }
    int ans = 0;
    REP(i, 26) ans = max(ans, longest[i]);
    cout << ans << endl;

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

