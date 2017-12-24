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
    vector<pii> cmd;
    REP(i, n) {
    	string s;
    	int k;
    	cin >> s >> k;
    	if(s == "|") {
    		cmd.push_back({1, k});
    	} else if(s == "&") {
    		cmd.push_back({2, k});
    	} else {
    		cmd.push_back({3, k});
    	}
    }
    vector<int> eff(10);
    REP(i, 10) {
    	int res[2];
    	REP(j, 2) {
    		int k = j << i;
    		REP(l, n) {
    			if(cmd[l].first == 1) {
    				k |= cmd[l].second;
    			} else if(cmd[l].first == 2) {
    				k &= cmd[l].second;
    			} else {
    				k ^= cmd[l].second;
    			}
    		}
    		res[j] = !!(k & (1 << i));
    	}
    	if(res[0] == 0 && res[1] == 0) {
    		eff[i] = 0; //set to 0
    	} else if(res[0] == 0 && res[1] == 1) {
    		eff[i] = 1; //do nothing
    	} else if(res[0] == 1 && res[1] == 0) {
    		eff[i] = 2; //flip
    	} else {
    		eff[i] = 3; //set to 1
    	}
    }
    // REP(i, 10) cout << eff[i] << " ";
    // cout << endl;
    int ans[3] = {0, 0x000003ff, 0};
    REP(i, 10) {
    	// DEBUG(ans[0]);
    	// DEBUG(ans[1]);
    	// DEBUG(ans[2]);
    	if(eff[i] == 0) {
    		ans[1] -= (1 << i);
    	} else if(eff[i] == 2) {
    		ans[2] += (1 << i);
    	} else if(eff[i] == 3) {
    		ans[0] += (1 << i);
    	}
    }
    cout << 3 << endl;
    cout << "| " << ans[0] << endl;
    cout << "& " << ans[1] << endl;
    cout << "^ " << ans[2] << endl;

    return 0;
}