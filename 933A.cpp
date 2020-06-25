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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> liea(n, 0), ldsa(n, 0), lisa(n+1, 0);
    REP(i, n-1) {
    	if(a[i+1] == 2) {
    		FORD(j, i-1, 0) {
    			if(a[j] == 2) break;
    			++liea[i];
    		}
    	}
    }
    REP(i, n) {
    	if(a[i] == 2) {
    		FOR(j, i, n-1) {
    			if(a[j] == 2) break;
    			++ldsa[i];
    		}
    	}
    }
    REP(i, n) {
    	if(a[i] == 1) {
    		FOR(j, i, n-1) {
    			if(a[j] == 2) break;
    			++ldsa[i];
    		}
    	}
    }

    return 0;
}