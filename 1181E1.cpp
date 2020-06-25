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
#include <cassert>
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

void bad() {
	cout << "NO" << endl;
	exit(0);
}

const int N = 1e5+10;
int n;
pair<int, pii> ev[2*N]; // {x, {id, type}}
pair<pii, pii> r[N];
vector<pii> verts[N]; // {y, type}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> r[i].first.first >> r[i].first.second >> r[i].second.first >> r[i].second.second;
    REP(i, n) {
    	ev[2*i] = {r[i].first.first, {i, 0}};
    	ev[2*i+1] = {r[i].second.first, {i, 1}};
    }
    sort(ev, ev+2*n, [](auto& left, auto& right){return left.first < right.first || (left.first == right.first && left.second.second > right.second.second);});
    stack<int> st;
    int in_process = 0, vid = 0;
    REP(i, 2*n) {
    	// cout << ev[i].first << ' ' << ev[i].second.first << ' ' << ev[i].second.second << endl;
    	if(ev[i].second.second == 0) {
    		++in_process;
    	} else {
			st.push(ev[i].second.first);
    		--in_process;
    		if(in_process == 0) {
    			// DEBUG(ev[i].first);
    			while(!st.empty()) {
    				int cur = st.top();
    				// DEBUG(cur);
    				verts[vid].push_back({r[cur].first.second, 0});
    				verts[vid].push_back({r[cur].second.second, 1});
    				st.pop();
    			}
				++vid;
    		}
    	}
    }
    REP(i, vid) {
    	assert(verts[i].size());
    	// DEBUG(i);
    	sort(verts[i].begin(), verts[i].end(), [](auto& left, auto& right){return left.first < right.first || (left.first == right.first && left.second > right.second);});
    	// REP(j, verts[i].size()) cout << verts[i][j].first << ' ' << verts[i][j].second << endl;
    	FOR(j, 1, verts[i].size()-1) if(verts[i][j].second != 1-verts[i][j-1].second) bad();
    }
    cout << "YES" << endl;


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

