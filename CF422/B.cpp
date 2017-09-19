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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int best = n+1, cur, bestIdx = -1;
    REP(i, m-n+1) {
    	cur = 0;
    	REP(j, n) {
    		if(s[j] != t[i+j]) ++cur;
    	}
    	if(cur < best) {
    		best = cur;
    		bestIdx = i;
    	}
    }
    cout << best << endl;
    REP(i, n) {
    	if(s[i] != t[bestIdx+i]) cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}