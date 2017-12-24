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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n+1, 0), b(n+1, 0);
    if(s[0] == 'a') a[0] = 0;
    else b[0] = 0;
    FOR(i, 1, n) {
		a[i] = a[i-1];
        b[i] = b[i-1];
        if(s[i-1] == 'a') ++a[i];
        else ++b[i];
    }
    // DEBUG(a[n]);
    // DEBUG(b[n]);
    int rm = n;
    FOR(i, 0, n) {
    	FOR(j, i, n) {
    		rm = min(rm, b[i]+(a[j]-a[i])+(b[n]-b[j]));
    	}
    }
    cout << n-rm << endl;

    return 0;
}