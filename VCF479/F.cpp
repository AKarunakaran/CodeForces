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
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<pii> dp(n+1);
    FOR(i, 1, n) cin >> a[i];
    map<int, int> m;
    int best = 1, bestidx = 1;
    FOR(i, 1, n) {
        m[a[i]] = i;
        int idx = m[a[i]-1];
        if(idx) dp[i] = {dp[idx].first+1, idx};
        else dp[i] = {1, 0};
        if(dp[i].first > best) best = dp[i].first, bestidx = i;
    }
    vector<int> ans;
    while(bestidx) {
        ans.push_back(bestidx);
        bestidx = dp[bestidx].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}