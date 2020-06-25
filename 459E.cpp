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

const int N = 3e5+1;
int n, m, _a[N], _b[N], *a = _a, *b = _b;
pair<int, pii> e[N];

void print() {
	// FOR(i, 1, n) cout << a[i] << ' ';
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(a, a+N, 0);
    fill(b, b+N, 0);
    cin >> n >> m;
    REP(i, m) cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    sort(e, e+m);
    int ans = 0;
    int idx = 0;
    while(idx < m) {
    	int cur = e[idx].first;
    	vector<int> changed;
    	vector<bool> added(n+1, 0);
    	while(idx < m && e[idx].first == cur) {
    		pii edge = e[idx].second;
    		a[edge.second] = max(a[edge.second], max(b[edge.first]+1, b[edge.second]));
    		ans = max(ans, a[edge.second]);
    		if(!added[edge.second]) {
    			changed.push_back(edge.second);
    			added[edge.second] = 1;
    		}
    		++idx;
    	}
    	for(int v : changed) {
    		b[v] = a[v];
    	}
    	// print();
    	swap(a, b);
    }
    cout << ans << endl;

    return 0;
}