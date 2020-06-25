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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    set<int> primes;
    vector<bool> p(1000001, 1);
    p[0] = p[1] = 0;
    for(int i = 2; i*i <= 1000000; ++i) {
    	if(p[i]) {
    		for(int j = 2*i; j <= 1000000; j += i) {
    			p[j] = 0;
    		}
    	}
    }
    FOR(i, 2, 1000000) {
    	if(p[i]) {
    		primes.insert(i);
    	}
    }
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<pii, int>> e;
    FOR(i, 1, n-2) {
    	e.push_back({{i, i+1}, 1});
    }
    auto pr = *primes.lower_bound(n-1);
    e.push_back({{n-1, n}, pr-(n-2)});
    FOR(i, 1, n) {
    	FOR(j, i+2, n) {
    		if(abs(i-j) <= 1) continue;
    		e.push_back({{i, j}, 1000000000});
    		if(e.size() == m) break;
    	}
    	if(e.size() == m) break;
    }
    cout << pr << ' ' << pr << endl;
    REP(i, m) {
    	cout << e[i].first.first << ' ' << e[i].first.second << ' ' << e[i].second << endl;
    }

    return 0;
}