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

string a, b, c;
vector<int> af(11, 0);

bool can(int test, int k) {
	vector<int> taf = af;
	--taf[test];
	FOR(i, k, b.size()-1) {
		FOR(j, 0, (b[i]-'0')-1) {
			if(taf[j]) {
				return true;
			}
		}
		if(taf[b[i]-'0']) --taf[b[i]-'0'];
		else return false;
	}
	return false;
}

int run() {
	fill(af.begin(), af.end(), 0);
	c = "";
	REP(i, a.size()) ++af[a[i]-'0'];
	if(a.size() == b.size() && !can(10, 0)) {
		return 0;
	}
    if(b.size() == a.size()) {
	    REP(i, b.size()) {
	    	bool less = false;
	    	FORD(j, b[i]-'0', 0) {
	    		if(af[j] && ((can(j, i+1) && (j == b[i]-'0')) || (j < b[i]-'0'))) {
	    			c.push_back('0'+j);
	    			--af[j];
	    			if(j < (b[i]-'0')) less = true;
	    			break;
	    		}
	    	}
	    	if(less) break;
	    }
    }
    FORD(i, 9, 0) {
    	while(af[i]) {
    		--af[i];
    		c.push_back('0'+i);
    	}
    }
    return stoi(c);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    FOR(ai, 1, 10000) {
    	FOR(bi, 1, 10000) {
    		a = to_string(ai), b = to_string(bi);
    		int ans;
    		if(b.size() >= a.size()) {
    			ans = run();
    			if(ans >= bi) cout << ai << " " << bi << "    " << ans << endl;
    		}
    	}
    }

    return 0;
}