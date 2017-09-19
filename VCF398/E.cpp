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
    ios::sync_with_stdio(false); cin.tie(0);
    //cout << fixed << setprecision(7);
    int n, m;
    cin >> n >> m;
    vector<int> c(n), w(n), d(n, 0);
    REP(i, n) cin >> c[i];
    REP(i, n) cin >> w[i];
    REP(i, n) d[i] = (100-(c[i]%100))*w[i];
    set<pair<int, int>> pq;
    vector<bool> ans(n, 0);
    ll dis = 0;
    REP(i, n) {
    	//cout << i << " " << m << endl;
    	if(c[i] % 100) pq.insert({d[i], i});
    	else continue;
    	while(m < (c[i]%100) && !ans[i]) {
    		int idx = pq.begin()->second;
    		dis += pq.begin()->first;
    		ans[idx] = 1;
    		if(idx == i) m += (100-(c[idx]%100));
    		else m += 100;
    		pq.erase(pq.begin());
    	}
    	if(!ans[i]) m -= (c[i]%100);
    }
    cout << dis << endl;
    REP(i, n) {
    	if(ans[i]) cout << c[i]/100+1 << " 0" << endl;
    	else cout << c[i]/100 << " " << c[i] % 100 << endl;
    }

    return 0;
}