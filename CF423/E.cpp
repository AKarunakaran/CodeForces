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
    string s;
    int q;
    cin >> s >> q;
    REP(event, q) {
    	int type;
    	cin >> type;
    	if(type == 1) {
    		int x;
    		cin >> x;
    		cin >> s[x-1];
    	} else {
    		int l, r, es;
    		string e;
    		cin >> l >> r >> e;
    		--l;
    		--r;
    		es = e.size();
    		int impact = 0;
    		FOR(i, l, r) {
    			if(e[(i-l)%es] == s[i]) ++impact;
    		}
    		cout << impact << endl;
    	}
    }

    return 0;
}