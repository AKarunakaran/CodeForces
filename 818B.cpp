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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    set<int> used;
    set<int> unused;
    FOR(i, 1, n) unused.insert(i);
    vector<int> ans(n+1, 0);
    int prev, cur;
    cin >> prev;
    FOR(i, 1, m-1) {
    	cin >> cur;
    	int num;
    	if(cur > prev) num = cur-prev;
    	else num = n-(prev-cur);

    	if(ans[prev] != 0 && ans[prev] != num) {
    		cout << -1 << endl;
    		return 0;
    	}
    	if(ans[prev] == 0) {
    		if(used.find(num) != used.end()) {
	    		cout << -1 << endl;
	    		return 0;
	    	} else {
	    		used.insert(num);
	    		unused.erase(num);
	    	}
	    	ans[prev] = num;
    	}
    	prev = cur;
    }
    auto itr = unused.begin();
    FOR(i, 1, n) {
    	if(ans[i] == 0) {
    		ans[i] = *itr;
    		++itr;
    	}
    }
	FOR(i, 1, n) cout << ans[i] << " ";
	cout << endl;

    return 0;
}