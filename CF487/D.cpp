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
ll n, l, w, ans = 0;
pll c[N];
vector<pair<double, int>> r;
bool used[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(used, used+N, 0);
    cin >> n >> l >> w;
    REP(i, n) cin >> c[i].first >> c[i].second;

    sort(r.begin(), r.end());
    int cur = 0;
    for(auto& p : r) {
    	used[p.second] = !used[p.second];
    	if(used[p.second]) {
    		ans += cur;
    		++cur;
    	} else --cur;
    }
    cout << ans << endl;

    return 0;
}