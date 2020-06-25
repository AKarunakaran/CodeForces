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

const ll M = 1000000007;

ll fastPowMod(ll base, ll power) {
    ll res = 1;
    while(power) {
        if(power & 1) res = (res*base) % M;
        base = (base*base) % M;
        power >>= 1;
    }
    return res;
}

int main() {
    DEBUG("HI");
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll k;
    cin >> k;
    DEBUG(k);
    FOR(n, 1, 100) {
    	ll choose[5001];
    	ll chooseG[5001][5001];
    	chooseG[0][0] = 1;
    	FOR(i, 1, 5000) {
    		FOR(j, 0, i) {
    			if(j == i || j == 0) chooseG[i][j] = 1;
    			else chooseG[i][j] = (chooseG[i-1][j-1]+chooseG[i-1][j]) % M;
    		}
    	}
	    fill(choose, choose+5001, 0);
	    choose[0] = 1;
    	FOR(i, 1, 5000) {
    		if(i > n) break;
    		choose[i] = choose[i-1]*(n+1-i);
    		choose[i] /= i;
    	}
    	FOR(i, 1, 5000) choose[i] %= M;

    	ll dd[5001];
	    fill(dd, dd+5001, 0);
	    dd[1] = 1;
	    FOR(i, 2, 5000) {
	    	if(i > k) break;
	    	ll s = 0;
	    	FOR(j, 1, i-1) {
	    		s = s+((chooseG[i][j]*dd[j]) % M) % M;
	    	}
	    	dd[i] = fastPowMod(i, k)-s;
	    }


    	ll ans = 0;
    	FOR(i, 1, n) {
    		ans = (ans+choose[i]*fastPowMod(i, k)) % M;
    	}
    	ll ans2 = 0;
    	FOR(i, 1, min((ll)n, k)) {
    		ll add = choose[i];
    		add = (add*fastPowMod(2, n-i)) % M;
    		add = (add*dd[i]) % M;
    		DEBUG(i);
    		DEBUG(add);
    		ans2 = (ans2+add) % M;
    	}
    	cout << n << ' ' << ans << ' ' << ans2 << endl;
    }

    return 0;
}