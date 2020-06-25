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

const int N = 50;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, a[N], seen[1001];
    fill(seen, seen+1001, 0);
    cin >> n;
    REP(i, n) cin >> a[i];
    reverse(a, a+n);
    int idx = 0;
    REP(i, n) {
    	if(!seen[a[i]]) {
    		a[idx++] = a[i];
    		seen[a[i]] = 1;
    	}
    }
    reverse(a, a+idx);
    cout << idx << endl;
    REP(i, idx) cout << a[i] << ' ';
    cout << endl;

    return 0;
}