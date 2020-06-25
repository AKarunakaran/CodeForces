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

ll find(ll n, ll x) {
	// DEBUG(n);
	// DEBUG(x);
	if(n == 2) return x;
	if(x & 1) return (x+1)/2;
	if(n & 1) return (n-(n+1)/2)+find((n+1)/2, x/2+1);
	else return (n-n/2)+find(n/2, x/2);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, q;
    cin >> n >> q;
    REP(t, q) {
    	ll x;
    	cin >> x;
    	cout << find(n, x) << endl;
    }

    return 0;
}