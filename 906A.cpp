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
    int cur = (1 << 26) - 1, ans = 0;
    bool good = false;
    REP(com, n-1) {
    	char cmd;
    	string s;
    	cin >> cmd >> s;
    	if(cmd == '?') {
    		int mask = 1 << (s[0]-'a');
    		if(cur & mask) cur &= ~mask;
    		else if(good) ++ans;
    		if(!(cur & (cur-1))) good = true;
    		continue;
    	}
    	if(good) ++ans;
    	int cmdNum = 0;
    	REP(i, s.size()) cmdNum |= (1 << (s[i]-'a'));
    	cur &= (cmd == '.') ? ~cmdNum : cmdNum;
    	DEBUG(cur);
    	if(!(cur & (cur-1))) good = true;
    }
    cout << ans << endl;

    return 0;
}