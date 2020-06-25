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

const ll N = 501;
ll n, a[N][N];
vector<ll> p, ans;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
    p.resize(n);
    REP(i, n) cin >> p[i];
    reverse(p.begin(), p.end());
    ll idx = 0;
    for(ll k : p) {
    	for(ll i : p) {
    		for(ll j : p) {
    			a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
    		}
    	}
    	ll s = 0;
    	for(ll i : p) {
    		for(ll j : p){
    			s += a[i][j];
    			if(j == k) break;
    		}
    		if(i == k) break;
    	}
    	ans.push_back(s);
    	++idx;
    }
    reverse(ans.begin(), ans.end());
    for(ll x : ans) cout << x << ' ';
    cout << endl;

    return 0;
}