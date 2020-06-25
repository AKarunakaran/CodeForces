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
const int N = 1 << 18;
ll n, r, a[N], s = 0, k;

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    cin >> n >> r;
    k = 1 << n;
    REP(i, k) {
    	cin >> a[i];
    	s += a[i];
    }
    cout << s/(double)k << endl;
    while(r--) {
    	int i, v;
    	cin >> i >> v;
    	s += (v-a[i]);
    	a[i] = v;
    	cout << s/(double)k << endl;
    }

    return 0;
}