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

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int g = a[0];
    REP(i, n) g = gcd(g, a[i]);
    if(g != 1) {
    	cout << -1 << endl;
    	exit(0);
    }
    int ones = 0;
    REP(i, n) if(a[i] == 1) ++ones;
    if(ones) {
    	cout << n-ones << endl;
    	exit(0);
    }
    int best = INF;
    FOR(i, 0, n-1) {
    	int g = a[i];
    	FOR(j, i+1, n-1) {
    		g = gcd(g, a[j]);
    		if(g == 1) {
    			best = min(best, j-i+1);
    			break;
    		}
    	}
    }
    cout << n+best-2 << endl;

    return 0;
}