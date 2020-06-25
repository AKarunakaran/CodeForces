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
const int N = 2000;
int n, m, l[N];
string s[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    fill(l, l+n, 0);
    REP(i, n) cin >> s[i];
    REP(i, n) {
    	REP(j, m) {
    		l[j] += (s[i][j] == '1');
    	}
    }
    REP(i, n) {
    	bool good = true;
    	REP(j, m) {
    		l[j] -= (s[i][j] == '1');
    		if(l[j] == 0) good = false;
    	}
    	REP(j, m) {
    		l[j] += (s[i][j] == '1');
    	}
    	if(good) {
    		cout << "YES" << endl;
    		exit(0);
    	}
    }
    cout << "NO" << endl;

    return 0;
}