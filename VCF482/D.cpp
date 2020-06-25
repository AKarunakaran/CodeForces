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
const int N = 1e5+1;
int q, t, x, k, s, have[N];
set<int> all;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> q;
    while(q--) {
    	cin >> t;
    	if(t == 1) {
    		cin >> x;
    		have[x] = 1;
    		all.insert(x);
    	} else {
    		cin >> x >> k >> s;
    		if(x % k || all.upper_bound(s-x) == all.begin()) cout << -1 << endl;
    		
    	}
    }

    return 0;
}