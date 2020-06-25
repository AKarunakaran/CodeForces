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
int n;
map<ll, ll> m;
string str[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> str[i];
    REP(i, n) {
    	int k = str[i].size();
    	int bal = 0, mn = 0;
    	REP(j, k) {
    		if(str[i][j] == '(') ++bal;
    		else --bal;
    		mn = min(mn, bal);
    	}
    	if(bal >= 0 && mn == 0) m[bal]++;
    	else if(bal < 0 && mn == bal) m[bal]++;
    }
    ll ans = 0;
    for(auto& p : m) {
    	if(p.first >= 0 && m.find(-p.first) != m.end()) ans += p.second*m[-p.first];
    }
    cout << ans << endl;


    return 0;
}