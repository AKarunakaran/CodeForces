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

vector<int> bit;
int n;

int getSum(int index) {
	int sum = 0;
	++index;
	while(index > 0) {
		sum += bit[index];
		index -= (index & -index);
	}
	return sum;
}

void update(int index, int val) {
	++index;
	while(index <= n) {
		bit[index] += val;
		index += (index & -index);
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    set<pair<int, pii>> intervals;
    int idx = 1, last = 0, intN = 0;
    while(idx < n) {
    	if(a[idx] != a[last]) {
    		intervals.insert({idx-last, intN++});
    		last = idx;
    	}
    	++idx;
    }
    intervals.insert({idx-last, intN++});
    bit.resize(intN+1, 0);
    REP(i, intN) update(i, 1);
    int ans = 0;
    while(!intervals.empty()) {
    	auto cur = *intervals.begin();
    	update(cur.second.first, -1);
    	int left, right;
    	int l = 0, r = intN-1;
    	while(l < r) {
    		int m = (l+r)/2;
    		if(getSum(m) >= cur.second.first) r = m;
    		else l = m+1;
    	}
    	left = r;
    	l = 0, r = intN-1;
    	while(l < r) {
    		int m = (l+r)/2;
    		if(getSum(m) >= cur.second.first+1) r = m;
    		else l = m+1;
    	}
    	right = r;
    	//I have an indexing problem
    	// auto 
    	intervals.erase(intervals.begin());
    	++ans;
    }
    cout << ans << endl;

    return 0;
}