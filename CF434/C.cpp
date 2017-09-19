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
    string s;
    cin >> s;
    map<char, bool> m;
    REP(i, 26) m['a'+i] = 0;
    m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
    int cnt = 0, lastIdx = 0, idx = 0;
    REP(i, s.size()) {
    	if(m[s[i]]) cnt = 0;
    	else ++cnt;
    	if(cnt >= 3 && !(s[i] == s[i-1] && s[i-1] == s[i-2])) {
    		cout << s.substr(lastIdx, i-lastIdx) << " ";
    		lastIdx = i;
    		cnt = 1;
    	}
    }
    cout << s.substr(lastIdx, s.size()-lastIdx) << endl;

    return 0;
}