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
    int n;
    cin >> n;
    vector<pair<double, string>> t(n);
    REP(i, n) {
    	string s;
    	cin >> s;
    	int sc = 0, hc = 0;
    	REP(j, s.size()) {
    		if(s[j] == 's') ++sc;
    		else ++hc;
    	}
    	t[i] = {(hc == 0 ? INF : (double)sc/(double)hc), s};
    }
    sort(t.begin(), t.end(), [](auto& left, auto& right){return left.first > right.first;});
    ll ans = 0, s = 0;
    REP(i, n) {
    	auto& str = t[i].second;
    	// DEBUG(str);
    	REP(j, str.size()) {
    		if(str[j] == 's') ++s;
    		else ans += s;
    	}
    }
    cout << ans << endl;

    return 0;
}