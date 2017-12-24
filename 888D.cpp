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
    int n, k;
    cin >> n >> k;
    int f[5], c[5];
    int prod = 1;
    f[0] = 1;
    FOR(i, 1, k) {
    	prod *= i;
    	f[i] = prod;
    }
    FOR(i, 1, k) FOR(j, 0, i-1) f[i] -= f[j];
    prod = 1;
    FOR(i, 1, k) {
    	prod *= (n+1-i);
    	prod /= i;
    	c[i] = prod;
    }
    FOR(i, 1, k) cout << f[i] << " ";
    cout << endl;
    FOR(i, 1, k) cout << c[i] << " ";
    cout << endl;
    int ans = 1;
    FOR(i, 1, k) ans += f[i]*c[i];
    cout << ans << endl;

    return 0;
}