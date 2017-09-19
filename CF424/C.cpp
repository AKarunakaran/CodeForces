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
    int k, n;
    cin >> k >> n;
    unordered_map<int, int> nums;
    vector<int> a(k), ps(k);
    REP(i, k) cin >> a[i];
    ps[0] = a[0];
    FOR(i, 1, k-1) ps[i] = ps[i-1]+a[i];
    int test, tempIn;
    cin >> test;
    FOR(i, 1, n-1) {
    	cin >> tempIn;
    	nums[tempIn] = i;
    }
    set<int> ans;
    REP(i, k) {
    	vector<bool> used(n, 0);
    	used[0] = 1;
    	bool good = true;
    	int left = n-1;
    	REP(j, k) {
    		if(j == i) continue;
    		if(left == 0) {
				break;
			}
    		int val = ps[j]-ps[i]+test;
    		//DEBUG(j);
    		//DEBUG(i);
    		//DEBUG(val);
    		if(nums.find(val) == nums.end()) continue;
    		int idx = nums[val];
    		if(used[idx]) {
    			good = false;
    			break;
    		} else {
    			used[idx] = 1;
    			--left;
    		}
    	}
    	if(good && left == 0) {
    		ans.insert(test-ps[i]);
    	}
    }
    cout << ans.size() << endl;

    return 0;
}