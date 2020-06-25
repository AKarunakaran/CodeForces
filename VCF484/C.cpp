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
const int N = 1e5+1;
int n, vis[N], ans = 0;
vector<int> g[N];

int dfs(int s, int p) {
	int sum = 1;
	for(int v : g[s]) {
		if(v != p) {
			sum += dfs(v, s);
		}
	}
	if(sum % 2 == 0) ++ans;
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(vis, vis+N, 0);
    cin >> n;
    REP(i, n-1) {
    	int s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    	g[e].push_back(s);
    }
    if(n & 1) {
    	cout << -1 << endl;
    	exit(0);
    }
    FOR(i, 1, n) {
    	if(g[i].size() == 1) {
    		dfs(i, -1);
    		break;
    	}
    }
    cout << ans-1 << endl;

    return 0;
}