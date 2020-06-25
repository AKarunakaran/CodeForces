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
    int t, n, k;
    cin >> t;
    REP(test, t) {
    	cin >> n >> k;
    	vector<int> x(k);
    	REP(i, k) cin >> x[i];
    	vector<bool> f(n+1, 0);
    	int j = 0, cnt = 0;
    	while(cnt != n) {
    		for(int s : x) {
    			// DEBUG(s);
    			FOR(i, max(1, s-j), min(n, s+j)) {
    				if(!f[i]) ++cnt;
    				f[i] = 1;
    			}
    		}
    		++j;
    	}
    	cout << j << endl;
    }

    return 0;
}