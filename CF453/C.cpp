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
    vector<int> a(n+1);
    vector<vector<int>> g(n+1);
    vector<vector<int>> g2(n+1);
    REP(i, n+1) cin >> a[i];
    int last = 1;
    REP(i, a[0]) g[0].push_back(0);
    REP(i, a[0]) g2[0].push_back(0);
    bool good = true;
    FOR(i, 1, n) {
    	REP(j, a[i]) g[i].push_back(last);
    	REP(j, a[i]) g2[i].push_back(last);
    	if(good && a[i-1] != 1 && a[i] != 1) {
    		good = false;
    		g[i][1] = last+1;
    	}
    	last += a[i-1];
    }
    if(good) {
    	cout << "perfect" << endl;
    } else {
    	cout << "ambiguous" << endl;
    	REP(i, n+1) {
    		REP(j, g2[i].size()) cout << g2[i][j] << " ";
    	}
    	cout << endl;
    	REP(i, n+1) {
    		REP(j, g[i].size()) cout << g[i][j] << " ";
    	}
    	cout << endl;
    }
 
    return 0;
}