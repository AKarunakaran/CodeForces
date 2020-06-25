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
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    REP(i, n) cin >> x[i];
    REP(j, m) cin >> y[j];
    vector<int> px(n, 0), py(m, 0);
    REP(i, n) px[i] = px[max(i-1, 0)]+x[i];
    REP(i, m) py[i] = py[max(i-1, 0)]+y[i];
    set<int> s;
    int ans = 0;
    REP(i, n) s.insert(px[i]);
    REP(i, m) if(s.count(py[i]) == 1) ++ans;
    cout << ans << endl;

    return 0;
}