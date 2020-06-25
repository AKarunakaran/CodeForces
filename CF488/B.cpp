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

const ll N = 1e5;
ll n, k, c[N], ans[N];
pll p[N];
set<pll> s;

ll sum() {
	ll res = 0;
	for(auto itr = s.begin(); itr != s.end(); ++itr) {
		res += itr->first;
	}
	return res;
}

void print() {
	for(auto itr = s.begin(); itr != s.end(); ++itr) {
		cout << itr->second << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) {
    	cin >> p[i].first;
    	p[i].second = i;
    }
    REP(i, n) cin >> c[i];
    sort(p, p+n);
    REP(i, n) {
    	int cur = p[i].second;
    	// DEBUG(i);
    	// DEBUG(cur);
    	// print();
    	ans[cur] = sum() + c[cur];
    	s.insert({c[cur], cur});
    	if(s.size() > k) s.erase(s.begin());
    }
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}