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
//inline ll two(ll n) { return 1 << n; }
const int M = 1000000007;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<ll> tp(n);
    REP(i, n) cin >> x[i];
    sort(x.begin(), x.end());
    tp[0] = 1;
    FOR(i, 1, n-1) tp[i] = (tp[i-1]*2) % M;
    ll ans = 0;
    FOR(i, 1, n-1) {
    	ll toAdd = ((tp[i]-1+M)*(tp[n-i]-1+M)) % M;
    	ans = (ans + (x[i]-x[i-1])*toAdd) % M;
    }
    cout << ans << endl;

    return 0;
}