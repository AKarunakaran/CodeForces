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
#include <unordered_set>
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

const int N = 1e6+1, K = 10001;
int n, a[N], f[N];
vector<int> choices;

double foo(pii p) {
	int a = choices[p.first], b = choices[p.second];
	return (2*a+2*b)*(2*a+2*b)/(double)(a*b);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    cin >> t;
    while(t--) {
    	choices.clear();
    	cin >> n;
    	REP(i, n) cin >> a[i];
    	sort(a, a+n);
    	int cnt = 0;
    	if(a[0] == a[1]) cnt = 1;
    	FOR(i, 1, n-1) {
    		if(a[i] != a[i-1]) {
    			if(cnt >= 2) choices.push_back(a[i-1]);
    			if(cnt >= 4) choices.push_back(a[i-1]);
    			cnt = 1;
    		} else ++cnt;
    	}
    	if(cnt >= 2) choices.push_back(a[n-1]);
    	if(cnt >= 4) choices.push_back(a[n-1]);
    	int k = choices.size();
    	// REP(i, k) cout << choices[i] << ' ';
    	// cout << endl;
    	pii best = {0, 1};
    	REP(i, k-1) {
    		if(foo((pii){i, i+1}) < foo(best)) {
    			best = {i, i+1};
    		}
    	}
    	cout << choices[best.first] << ' ' << choices[best.first] << ' ' << choices[best.second] << ' ' << choices[best.second] << endl;
    }

    return 0;
}