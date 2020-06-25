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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+1;
int n, a[N];
vector<int> g[N];
unordered_map<int, ll> m[N];
map<int, ll> ans;

ll gcd(ll x, ll y) {return y ? gcd(y, x % y) : x;}

void dfs(int s, int p) {
	for(int v : g[s]) {
		if(v != p) {
			dfs(v, s);
			for(auto& i : m[s]) {
				for(auto& j : m[v]) {
					ans[gcd(i.first, j.first)] += i.second*j.second;
				}
			}
			for(auto& i : m[v]) {
				m[s][gcd(i.first, a[s])] += i.second;
				ans[gcd(i.first, a[s])] += i.second;
			}
		}
	}
	++m[s][a[s]];
	++ans[a[s]];
	// DEBUG(s);
	// for(auto& i : m[s]) cout << i.first << ' ' << i.second << endl;
	// for(auto& i : m[s]) ans[i.first] += i.second;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    REP(i, n-1) {
    	int s, t;
    	cin >> s >> t;
    	g[s].push_back(t);
    	g[t].push_back(s);
    }
    dfs(1, -1);
    for(auto& p : ans) cout << p.first << ' ' << p.second << endl;

    return 0;
}