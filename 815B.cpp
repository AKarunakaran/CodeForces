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
const int M = 1000000007;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    if(n == 1) {
    	int b;
    	cin >> b;
    	cout << b << endl;
    	return 0;
    }
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    bool plus = true;
    vector<int> ans(n);
    REP(i, n-1) {
    	REP(j, n-i-1) {
    		if(plus) ans[j] = (a[j]+a[j+1])%M;
    		else ans[j] = (a[j]-a[j+1])%M;
    		plus = !plus;
    	}
    	//REP(j, n-i-1) cout << ans[j] << " ";
    	//cout << endl;
    	a = ans;
    }
    cout << (ans[0]+M)%M << endl;

    return 0;
}