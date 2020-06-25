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

const int N = 1e5+1;

int n, a[N], sieve[N], dp[N];
vector<int> p;
map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(sieve, sieve+N, 0);
    fill(dp, dp+N, 0);
    for(int i = 2; i < N; ++i) {
    	if(sieve[i] == 0) {
    		p.push_back(i);
    		for(int j = i; j < N; j += i) {
    			sieve[j] = i;
    		}
    	}
    }
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int ans = 1;
    for(int x : p) m[x] = 0;
    FOR(i, 1, n) {
    	set<int> pf;
    	while(a[i] != 1) {
    		pf.insert(sieve[a[i]]);
    		a[i] /= sieve[a[i]];
    	}
    	for(int x : pf) {
    		dp[i] = max(dp[i], dp[m[x]]+1);
    		m[x] = i;
    	}
    	ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}