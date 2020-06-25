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
const int N = 2e5+10;
int a[N], cb[N], n, ans = 0;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(cb, cb+N, 0);
    cin >> n;
    REP(i, n) {
    	cin >> a[i];
    	a[i] = min(a[i], n);
    }
    REP(i, n) {
    	if(a[i] < i+1) {
    		++cb[a[i]];
    	}
    }
    FORD(i, n-1, 1) cb[i] += cb[i+1];
    FOR(i, 1, n) ans += cb[i];
    cout << ans << endl;

    return 0;
}