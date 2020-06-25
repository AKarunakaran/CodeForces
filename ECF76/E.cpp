#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int n, m, k, a[N], b[N], c[N], tot;

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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    tot = n+m+k;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    REP(i, k) cin >> c[i];
    sort(a, a+n);
    sort(b, b+m);
    sort(c, c+k);
    vector<int> v;
    REP(i, n) v.push_back(a[i]);
    REP(i, m) v.push_back(b[i]);
    REP(i, k) v.push_back(c[i]);
    cout << tot-lis(v) << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
