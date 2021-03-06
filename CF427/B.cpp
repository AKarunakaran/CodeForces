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
    char c;
    string n;
    ll k, s = 0;
    vector<int> d(10, 0);
    cin >> k >> n;
    REP(i, n.size()) {
    	s += (n[i]-'0');
    	++d[n[i]-'0'];
    }
    ll ans = 0, i = 0;
    //DEBUG(s);
    //DEBUG(k);
    while(s+(9-i)*d[i] < k) {
    	s += (9-i)*d[i];
    	ans += d[i];
    	++i;
    }
    if(s < k) ans += ceil((double)(k-s)/(double)(9-i));
    cout << ans << endl;

    return 0;
}