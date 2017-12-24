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
    int n;
    cin >> n;
    vector<int> l(n);
    REP(i, n) cin >> l[i];
    vector<pii> ints;
    REP(i, n) if(l[i]) ints.push_back({max(0, i-l[i]), i-1});
    int ans = n;
    if(ints.size()) {
	    sort(ints.begin(), ints.end());
        // REP(i, ints.size()) cout << '{' << ints[i].first << ", " << ints[i].second << "} ";
        // cout << endl;
	    vector<pii> newInts;
    	pii cur = ints[0];
		FOR(i, 1, ints.size()-1) {
			if(ints[i].first <= cur.second) cur.second = max(cur.second, ints[i].second);
			else {
				newInts.push_back(cur);
				cur = ints[i];
			}
		}
		newInts.push_back(cur);
        // REP(i, newInts.size()) cout << '{' << newInts[i].first << ", " << newInts[i].second << "} ";
        // cout << endl;
    	REP(i, newInts.size()) ans -= (newInts[i].second-newInts[i].first+1);
    }
    cout << ans << endl;

    return 0;
}