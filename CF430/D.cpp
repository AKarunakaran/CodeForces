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
#include <unordered_map>
#include <unordered_set>
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

void flipB(int& x, int b) {
	int c = 1 << b;
	if(x & c) x &= (~c);
	else x |= c;
}

int bc(int x, int k) {
	int check = 1;
	REP(i, 30) {
		if(k & check) flipB(x, i);
		check = check << 1;
	}
	return x;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m, a[300001] = {};
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    unordered_set<int> arr;
    REP(i, n) arr.insert(a[i]);
    unordered_map<int, int> ans;
    int x = 0;
    REP(i, m) {
    	int xIn, sol;
    	cin >> xIn;
    	x ^= xIn;
    	if(ans.find(x) != ans.end()) {
    		cout << ans[x] << endl;
    		continue;
    	}
    	sol = 0;
    	while(arr.find(bc(x, sol)) != arr.end()) {
    		++sol;
    	}
    	ans[x] = sol;
    	cout << sol << endl;
    }

    return 0;
}