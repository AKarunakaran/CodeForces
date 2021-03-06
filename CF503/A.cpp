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

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, a, b, h, k;
    cin >> n >> h >> a >> b >> k;
    while(k--) {
    	int ta, fa, tb, fb;
    	cin >> ta >> fa >> tb >> fb;
    	if(ta == tb) {
    		cout << abs(fa-fb) << endl;
    		continue;
    	}
    	int ans = 0;
    	if(fa < a) ans += a-fa;
    	if(fa > b) ans += fa-b;
    	ans += abs(ta-tb);
    	if(fa < a) ans += abs(a-fb);
    	else if(fa > b) ans += abs(fb-b);
    	else ans += abs(fa-fb);
    	cout << ans << endl;
    }

    return 0;
}