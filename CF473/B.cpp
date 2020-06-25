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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, k, m;
    cin >> n >> k >> m;
    vector<string> a(n+1);
    FOR(i ,1, n) {
    	cin >> a[i];
    }
    vector<int> c(n+1);
    FOR(i, 1, n) cin >> c[i];
    vector<set<pair<int, string>>> v(k);
    map<string, int> mp;
    REP(i, k) {
    	int x;
    	cin >> x;
    	REP(j, x) {
    		int idx;
    		cin >> idx;
    		string s = a[idx];
    		mp[s] = i;
    		v[i].insert({c[idx], s});
    	}
    }
    // REP(i, k) {
    // 	for(auto& p : v[i]) {
    // 		cout << p.first << ' ' << p.second << "  ";
    // 	}
    // 	cout << endl;
    // }
    // cout << endl;
    vector<string> ans(m);
    ll out = 0;
    REP(i, m) {
    	string s;
    	cin >> s;
    	out += v[mp[s]].begin()->first;
    }
    cout << out << endl;

    return 0;
}