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
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    int tr = 0, er = 0;
    REP(i, n) {
    	if(a[i] > a[tr]) tr = i;
    	if(a[i] >= a[er]) er = i;
    }
    int tc = 0;
    REP(i, m) {
    	if(b[i] > b[tc]) tc = i;
    }
    int bs = 0, os = 0;
    FOR(i, 0, tr) {
    	bs += a[i];
    	os += b[0];
    }
    FOR(i, 1, tc) {
    	bs += a[tr];
    	os += b[i];
    }
    FOR(i, tr+1, er) {
    	bs += a[i];
    	os += b[tc];
    }
    FOR(i, tc+1, m-1) {
    	bs += a[er];
    	os += b[i];
    }
    FOR(i, er+1, n-1) {
    	bs += a[i];
    	os += b[m-1];
    }
    ll ans = (ll)bs*(1e9)+os;
    cout << ans << endl;
    
    return 0;
}