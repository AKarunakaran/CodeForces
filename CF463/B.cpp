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

vector<ll> g(1e6+1, 0);
vector<ll> prefs[10];

ll f(ll n) {
	ll res = 1;
	while(n) {
		if(n % 10) res *= (n%10);
		n /= 10;
	}
	return res;
}

ll findG(ll n) {
	if(g[n]) return g[n];
	return g[n] = (n < 10 ? n : findG(f(n)));
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, 10) prefs[i].resize(1e6+1, 0);
    FOR(i, 1, 1e6) findG(i);
    FOR(i, 1, 1e6) {
    	REP(j, 10) {
    		if(j == g[i]) prefs[j][i] = prefs[j][i-1]+1;
    		else prefs[j][i] = prefs[j][i-1];
    	}
    }
    ll q;
    scanf("%lld", &q);
    while(q--) {
    	ll l, r, k;
    	scanf("%lld %lld %lld", &l, &r, &k);
    	printf("%lld\n", prefs[k][r]-prefs[k][l-1]);
    }

    return 0;
}