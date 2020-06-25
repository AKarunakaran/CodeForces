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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

vector<ll> ans;
// ll bits = 0;

// bool rec(ll n, ll k, ull mask, ll p, ull nMask, ll np) {
// 	if(n == 0) return true;
// 	// DEBUG(n);
// 	// DEBUG(k);
// 	while(nMask && !(nMask & n)) {
// 		nMask >>= 1;
// 		--np;
// 	}
// 	// DEBUG(mask);
// 	// DEBUG(p);
// 	ll two = 1, psub = 0;
// 	while(two*2 <= k && (np == -1 || (np != -1 && p-psub-1 >= np))) {
// 		two *= 2;
// 		++psub;
// 	}
// 	while(two) {
// 		ans.resize(ans.size()+two, p-psub);
// 		if(rec(n-mask, k-two, nMask, np, nMask >> 1, np-1)) {
// 			return true;
// 		}
// 		ans.resize(ans.size()-two);
// 		two /= 2;
// 		--psub;
// 	}
// 	return false;
// }

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ld n;
    ll k;// p = 63;
    cin >> n >> k;
 //    ull mask = 1LL << 63;
 //    while(mask) {
 //    	if(mask & n) ++bits;
 //    	mask >>= 1;
 //    }
 //    mask = 1LL << 63;
 //    while(!(mask & n)) {
 //    	mask >>= 1;
 //    	--p;
 //    }
 //    if(bits > k) {
 //    	cout << "No" << endl;
 //    	exit(0);
 //    }
 //    rec(n, k, mask, p)
	// cout << "Yes" << endl;
	// REP(i, ans.size()) cout << ans[i] << ' ';
	// cout << endl;
	ld cur = 1;
	ll p = 0;
	while(cur*k < n) {
		cur *= 2;
		++p;
	}
	while(n) {
		while(cur > n) {
			cur /= 2;
			--p;
		}
		n -= cur;
		--k;
		ans.push_back(p);
	}
	if(k != 0 || n > 0) {
		cout << "No" << endl;
		exit(0);
	}
	cout << "Yes" << endl;
	REP(i, ans.size()) cout << ans[i] << ' ';
	cout << endl;


    return 0;
}