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

int n, m;

int lis(vector<int>& a, vector<int>& rec) {
    int ans = 1;
    vector<int> dp(m+1, INF);
    dp[1] = a[0];
    rec[0] = 1;
    FOR(i, 1, m-1) {
        int idx = upper_bound(dp.begin()+1, dp.begin()+ans+1, a[i])-dp.begin();
        dp[idx] = a[i];
        ans = max(ans, idx);
        rec[i] = ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    vector<int> s(m, 0);
    int l, r, ans = 0;
    REP(i, n) {
    	cin >> l >> r;
    	--l, --r;
    	s[l]++;
    	if(r < m-1) s[r+1]--;
    }

    FOR(i, 1, m-1) s[i] += s[i-1];
    vector<int> lisv(m), ldsv(m);
    lis(s, lisv);
    reverse(s.begin(), s.end());
    lis(s, ldsv);
    reverse(ldsv.begin(), ldsv.end());

    REP(i, m-1) ans = max(ans, lisv[i]+ldsv[i+1]);
    ans = max(ans, max(lisv.back(), ldsv[0]));
    cout << ans << endl;

    return 0;
}