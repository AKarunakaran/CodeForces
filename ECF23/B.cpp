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

ll choose(int n, int r) {
	ll p = 1;
	int k = min(r, n-r);
	FOR(i, 1, k) {
		p *= n--;
		p /= i;
	}
	return p;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    //cout << choose(5, 3) << " " << choose(5, 5) << " " << choose(6, 4) << endl;
    /*int end = 3;
    while(end < a.size() && a[end] == a[end-1]) ++end;
    --end;
    if(end == 2) {
    	cout << 1 << endl;
    	return 0;
    }
    if(a[0] == a[1]) {
    	if(a[1] == a[2]) {
    		cout << choose(end+1, 3) << endl;
    	} else {
    		cout << end-1 << endl;
    	}
    } else {
    	if(a[1] == a[2]) {
    		cout << choose(end, 2) << endl;
    	} else {
    		cout << end-1 << endl;
    	}
    }*/
    int diff = 1;
    int i;
    for(i = 1; i <= a.size()-1; ++i) {
    	if(a[i] != a[i-1]) {
    		if(diff == 3 || i > 2) break;
    		else ++diff;
    	}
    }
    --i;
    //cout << i << ' ' << diff << endl;
    if(diff == 1) {
    	cout << choose(i+1, 3) << endl;
    } else if(diff == 2) {
    	if(a[0] == a[1]) {
    		cout << i-1 << endl;
    	} else {
    		cout << choose(i, 2) << endl;
    	}
    } else {
    	cout << i-1 << endl;
    }


    return 0;
}