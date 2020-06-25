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

ll threes(ll k) {
	ll res = 0;
	while(k % 3 == 0) {
		k /= 3;
		++res;
	}
	return res;
}

ll twos(ll k) {
	ll res = 0;
	while(k % 2 == 0) {
		k /= 2;
		++res;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end(), [](ll left, ll right){return threes(left) > threes(right) || (threes(left) == threes(right) && twos(left) < twos(right));});
    REP(i, n) cout << a[i] << ' ';
    cout << endl;

    return 0;
}