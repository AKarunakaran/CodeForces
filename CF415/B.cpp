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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, f;
    scanf("%d %d", &n, &f);
    vector< pair<int, int> > kl(n);
    REP(i, n) scanf("%d %d", &kl[i].first, &kl[i].second);
    sort(kl.begin(), kl.end(), [](auto &left, auto &right){
    	return min(left.first*2, left.second)-min(left.first, left.second) > min(right.first*2, right.second)-min(right.first, right.second);
    });
    //cout << endl;
    //REP(i, n) cout << kl[i].first << " " << kl[i].second << endl;
    int ans = 0;
    FOR(i, 0, f-1) ans += min(kl[i].first*2, kl[i].second);
    FOR(i, f, n-1) ans += min(kl[i].first, kl[i].second);
    cout << ans << endl;

    return 0;
}