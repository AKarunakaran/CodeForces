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
    REP(i, n) cin >> a[i+1];
    string s;
    cin >> s;
    s.push_back('0');
    vector<bool> c(n+1);
    REP(i, n) c[i+1] = (s[i] == '1');
    int l, r = 0;
    while(r < n) {
    	l = r+1;
    	r = l;
    	while(c[r]) ++r;
    	// DEBUG(l);
    	// DEBUG(r);
    	FOR(i, l, r) {
    		if(a[i] < l || a[i] > r) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    	}
    }
    cout << "YES" << endl;

    return 0;
}