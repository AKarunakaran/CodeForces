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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long
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
int n, q;

int getPreviousRowNums(int r, bool odd) {
	if(n & 1) {
		if(r & 1) {
			return ((r-1)*n)/2;
		} else {
			if(odd) return ((r-1)*n)/2;
			else return ((r-1)*n+1)/2;
		}
	} else {
		return (r-1)*(n/2);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> q;
    while(q--) {
    	int r, c, rc;
    	cin >> r >> c;
		rc = (c+1)/2;
    	if((r + c) & 1) {
    		int offset = (n*n+1)/2;
    		cout << offset+getPreviousRowNums(r, 1)+rc << endl;
    	} else {
    		cout << getPreviousRowNums(r, 0)+rc << endl;
    	}
    }

    return 0;
}