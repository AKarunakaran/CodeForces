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
    ll k;
    cin >> n >> k;
    k = min(n-1, k);
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    if(a[1] > a[0]) swap(a[0], a[1]);
    while(1) {
    	int i = 1;
    	while(a[i] < a[0]) ++i;
    	if(i-1 >= k) {
    		cout << a[0] << endl;
    		exit(0);
    	}
    	vector<int> b(n);
    	REP(j, i, n-1) b[j-i] = a[i];
    	REP(j, 1, i-1) b[j+(n-i)-1] = a[j];
    	b[n-1] = a[0];
    	a = b;
    }

    return 0;
}