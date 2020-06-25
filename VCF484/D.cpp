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
// typedef pair<int, int> pii;
typedef pair<ll, ll> pii;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////
const ll N = 1e5+1;
ll n, l[N], a[N], v[N], ans, bestnum, intlens = 1;
set<pii> ints;
map<ll, ll> m;

void print() {
	for(auto p : ints) cout << "{" << p.first << ", " << p.second << "}, ";
	cout << endl;
	FOR(i, 1, 20) cout << l[i] << ' ';
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(l, l+N, 0);
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	m[a[i]] = i;
    	v[i] = a[i];
    }
    if(n == 1) {
    	cout << a[1]+1 << endl;
    	exit(0);
    }
    sort(v+1, v+n+1);
    ans = v[n]+1;
    bestnum = 1;
    ints.insert({n, n}); //last index, llerval length
    l[n]++;
    FORD(i, n, 2) {
    	// print();
    	ll cur = v[i];
    	ll curidx = m[cur];
    	pii curint = *ints.lower_bound({curidx, 0});
    	ll len1 = curint.first-curidx;
    	ll len2 = curint.second-1-len1;
    	if(l[curint.second] == 1) --intlens;
    	--l[curint.second];
    	if(len1) {
    		ints.insert({curint.first, len1});
    		if(l[len1] == 0) ++intlens;
    		++l[len1];
    	}
    	if(len2) {
    		ints.insert({curidx-1, len2});
    		if(l[len2] == 0) ++intlens;
    		++l[len2];
    	}
    	ints.erase(curint);
    	if(intlens == 1 && l[ints.begin()->second] >= bestnum) {
    		ans = v[i-1]+1;
    		bestnum = l[ints.begin()->second];
    	}
    	// if(len1 && l[len1] == ints.size() && l[len1] >= bestnum) {
    	// 	ans = v[i-1]+1;
    	// 	bestnum = l[len1];
    	// }
    	// if(len2 && l[len2] == ints.size() && l[len2] >= bestnum) {
    	// 	ans = v[i-1]+1;
    	// 	bestnum = l[len2];
    	// }
    }
    cout << ans << endl;

    return 0;
}