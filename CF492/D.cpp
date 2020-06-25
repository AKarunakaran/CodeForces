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
const int N = 200;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    n *= 2;
    REP(i, n) cin >> a[i];
    int ans = 0;
    REP(i, n/2) {
    	int idx = 0;
    	FOR(j, 2*i+1, n-1) {
    		if(a[j] == a[2*i]) {
    			idx = j;
    			break;
    		}
    	}
    	// DEBUG(idx);
    	ans += idx-(2*i+1);
    	rotate(a+(2*i+1), a+idx, a+idx+1);
    }
    cout << ans << endl;

    return 0;
}