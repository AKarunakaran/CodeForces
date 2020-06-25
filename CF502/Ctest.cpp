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
// #define int long long
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

int lis(vector<int>& a) {
    int n = a.size(), ans = 1;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    REP(i, n) {
        int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[idx] = min(dp[idx], a[i]);
        ans = max(ans, idx);
    }
    return ans;
}

int solve(vector<int>& a) {
	int lo = lis(a);
	reverse(a.begin(), a.end());
	int hi = lis(a);
	reverse(a.begin(), a.end());
	return lo+hi;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n = 6;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int ans = INF;
    do {
    	ans = solve(a);
    	if(ans == 5) {
    		REP(i, n) cout << a[i] << ' ';
    		cout << endl;
    	}
    } while(next_permutation(a.begin(), a.end()));

    return 0;
}