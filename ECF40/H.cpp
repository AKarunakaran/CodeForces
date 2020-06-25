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
const ll M = 1e9 + 7;
const ll half = 5e8 + 4;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n+1), c(n+1);
    c[1] = 1;
    FOR(i, 1, n) {
    	cin >> a[i];
    	if(i > 1) c[i] = (a[i-1]*c[i-1]) % M;
    }
    vector<ll> f(2*n-2+1, 0);
    vector<vector<ll>> h(n+1, vector<ll>(n+1, 0));
    FOR(i, 1, n) {
    	FOR(j, 1, n-i) {
    		if(j == 1) h[i][j] = a[i];
    		else h[i][j] = (a[i]*h[i][j-1]) % M;
    	}
    }
    FOR(i, 1, n) cerr << c[i] << ' ';
    cerr << endl << endl;
    FOR(i, 1, n) {
    	FOR(j, 1, n) cerr << h[i][j] << ' ';
    	cerr << endl;
    }
    cerr << endl;
    	
    FOR(k, 1, 2*n-2) {
		FOR(i, 1, n-k) {
			f[k] = (f[k] + c[i]*h[i][k]) % M;
		}
    	ans = 0;
	    DEBUG(k);
    	FOR(d, 1, n-1) {
    		ll inter = 0;
	    	FOR(i, 1, k-1) {
	    		inter = (inter + h[d][i]*h[d][k-i]) % M;
	    	}
	    	inter = (inter*half) % M;
	    	DEBUG(d);
	    	DEBUG(inter);
	    	ans = (ans + inter*c[d]) % M;
    	}
    	ans = (ans * half) % M;
    	f[k] = (f[k] + ans) % M;
    }
    FOR(k, 1, 2*n-2) cout << f[k] << ' ';
    cout << endl;

    return 0;
}