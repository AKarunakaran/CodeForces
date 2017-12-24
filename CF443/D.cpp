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
    int n, k, m;
    cin >> n >> k >> m;
    bool easy = true;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    REP(i, n) {
    	if(a[i] != a[0]) easy = false;
    }
    if(easy) {
    	cout << (n*m) % k << endl;
    	exit(0);
    }
    int l = 0, r = n-1, left = n*m, ll = 0, lr = n-1;
    while(l < r) {
    	if(a[l] != a[r]) {
    		cout << left << endl;
    		exit(0);
    	} else {
    		while(l < r && a[l] == a[r]) {
    			++l;
    			--r;
    		}
    		int num = l-ll+1+(lr-r+1);
    		left -= (num/k) * (m-1);
    		if(num % k == 0) {
    			ll = l-1;
    			lr = r+1;
    		} else {
    			cout << left << endl;
    			exit(0);
    		}
    	}
    }
    cout << 0 << endl;

    return 0;
}