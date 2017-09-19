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
    int n;
    cin >> n;
    vector<int> a(n), s(n);
    REP(i, n) cin >> a[i];
    REP(i, n) s[i] = a[i];
    sort(s.begin(), s.end());
    vector<bool> checked(n, 0);
    vector<vector<int>> ans;
    REP(i, n) {
    	if(!checked[i]) {
    		vector<int> ansT;
    		checked[i] = 1;
    		int cur = a[i];
    		ansT.push_back(i);
    		int idx = lower_bound(s.begin(), s.end(), cur)-s.begin();
    		while(idx != i) {
    			checked[idx] = 1;
    			cur = a[idx];
    			ansT.push_back(idx);
    			idx = lower_bound(s.begin(), s.end(), cur)-s.begin();
    		}
    		ans.push_back(ansT);
    	}
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
    	cout << ans[i].size() << " ";
		REP(j, ans[i].size()) cout << ans[i][j]+1 << " ";
		cout << endl;
    }

    return 0;
}