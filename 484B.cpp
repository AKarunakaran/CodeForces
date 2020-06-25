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

const int N = 2e5, K = 2e6+1;
int pre[K], n, a[N];
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) s.insert(a[i]);
    s.insert(K);
    auto itr = s.begin();
    int lo = *itr;
    ++itr;
    pre[lo] = lo;
    FOR(i, lo+1, K-1) {
    	if(i-1 == *itr) {
    		pre[i] = *itr;
    		++itr;
    	} else pre[i] = pre[i-1];
    }
    s.erase(K);
    int ans = 0;
    for(auto& x : s) {
    	for(int i = 2*x; i < K; i += x) {
    		ans = max(ans, pre[i] % x);
    	}
    }
    cout << ans << endl;

    return 0;
}