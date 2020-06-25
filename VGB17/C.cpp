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
    cout << fixed << setprecision(7);
    int n, r;
    cin >> n >> r;
    vector<int> x(n);
    vector<double> h(n, r);
    REP(i, n) cin >> x[i];
    REP(i, n) {
    	REP(j, i) {
    		if(abs(abs(x[j]-x[i]) - 2*r) < 1e7) {
    			h[i] = max(h[i], h[j]+sqrt((4*r*r)-(x[i]-x[j])*(x[i]-x[j])));
    		}
    	}
    	cout << h[i] << " ";
    }
    cout << endl;

    return 0;
}