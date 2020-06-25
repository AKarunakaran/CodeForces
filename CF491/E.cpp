#pragma GCC optimize ("Ofast")

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
#include <numeric>
#include <unordered_map>
using namespace std; 
#define int long long
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

vector<int> f(10, 0);
int have = 0;
ll ans = 0;
string cur;

void print(vector<int>& v) {
	FOR(i, 0, v.size()-1) cout << v[i] << ' ';
	cout << endl;
}

ll genfact(vector<int>& tofact) {
	ll lo = 1;
	ll s = 0, p = 1;
	for(int x : tofact) s += x;
	for(int x : tofact) {
		int i = 1;
		while(i <= x) {
			p *= s--;
			p /= i++;
		}
	}
	// print(tofact);
	// cout << p << endl << endl;
	return p;
}

// void rem(int idx) {
// 	if(idx == cur.size()) return;
// 	ll torem = 0;
// 	vector<int> fr(10, 0);
// 	vector<int> tofact;
// 	FOR(i, idx, cur.size()-1) ++fr[cur[i]-'0'];
// 	FOR(i, 0, 9) if(fr[i]) tofact.push_back(fr[i]);
// 	torem = genfact(tofact)-1;
// 	ans -= torem;
// }

ll add(int idx) {
	// if(idx == cur.size()) return 0;
	// DEBUG(cur.substr(0, idx));
	ll toadd = 0;
	vector<int> fr(10, 0);
	vector<int> tofact;
	FOR(i, 0, idx-1) ++fr[cur[i]-'0'];
	FOR(i, 0, 9) if(fr[i]) tofact.push_back(fr[i]);
	toadd = genfact(tofact);
	if(fr[0]) {
		--fr[0];
		--tofact[0];
		toadd -= genfact(tofact);
	}
	return toadd;
}

// void checksub() {
// 	int now = 0;
// 	REP(i, cur.size()) {
// 		int num = cur[i]-'0';
// 		now |= (1 << num);
// 		if(now == have) {
// 			ans += add(i+1);
// 		}
// 	}
// }

void rec(int idx) {
	if(idx == 10) {
		ans += add(cur.size());
		return;
	}
	int oldsize = cur.size();
	REP(i, f[idx]) {
		cur.push_back(idx+'0');
		rec(idx+1);
	}
	if(f[idx] == 0) rec(idx+1);
	cur.resize(oldsize);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    //cout << fixed << setprecision(7);
    string s;
    cin >> s;
    REP(i, s.size()) {
    	int num = (s[i]-'0');
   		++f[num];
    }
    rec(0);
    cout << ans << endl;

    return 0;
}