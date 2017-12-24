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
    ios::sync_with_stdio(false); cin.tie(0);
    //cout << fixed << setprecision(7);
    ll b, q, l, m;
    cin >> b >> q >> l >> m;
    if(abs(b) > l) {
    	cout << 0 << endl;
    	exit(0);
    }
    set<ll> bad;
    REP(i, m) {
    	int num;
    	cin >> num;
    	if(abs(num) <= l) bad.insert(num);
    }
    m = bad.size();
    if(b == 0) {
    	cout << (bad.count(0) ? "0" : "inf") << endl;
		exit(0);
    }
    if(q == 0) {
    	cout << (bad.count(0) ? (bad.count(b) ? "0" : "1") : "inf") << endl;
		exit(0);
    }
    if(q == 1) {
    	cout << (bad.count(b) ? "0" : "inf") << endl;
		exit(0);
    }
    if(q == -1) {
    	cout << (bad.count(b) && bad.count(-b) ? "0" : "inf") << endl;
		exit(0);
    }
    ll ans = 0;
    ll n = b;
    while(abs(n) <= l) {
    	if(!(bad.count(n))) ++ans;
    	n *= q;
    }
    cout << ans << endl;

    return 0;
}