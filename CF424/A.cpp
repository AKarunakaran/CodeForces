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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int sec = 0;
    bool good = true;
    FOR(i, 1, n-1) {
    	if(a[i]-a[i-1] > 0 && sec != 0) {
    		good = false;
    		break;
    	}
    	if(a[i]-a[i-1] == 0) {
    		if(sec == 0) {
    			sec = 1;
    		} else if(sec == 2) {
    			good = false;
    			break;
    		}
    	}
    	if(a[i]-a[i-1] < 0) {
    		if(sec == 1 || sec == 0) {
    			sec = 2;
    		}
    	}
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}