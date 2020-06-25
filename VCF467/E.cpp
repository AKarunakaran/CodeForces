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
    string s, t;
    cin >> s >> t;
    vector<int> ans;
    REP(i, n) {
    	string ns = s;
    	rotate(ns.begin(), ns.begin()+i, ns.end());
    	int l = 0, r = n-1;
    	while(ns[l] == t[l]) ++l;
    	while(ns[r] == t[r]) --r;
    	bool p = true;
    	FOR(j, 0, (r-l+1)/2) {
    		if(ns[l+j] != t[r-j]) {
    			p = false;
    			break;
    		}
    	}
    	if(!p) continue;
    	// DEBUG(ns);
    	// DEBUG(i);
    	// DEBUG(l);
    	// DEBUG(r);
    	int firstShift = i ? (n-i) : 0;
    	int secondShift = n-1-r;
    	int shiftLength = (r-l+1);
    	int thirdShift = n - (secondShift+shiftLength);
    	ans.resize(ans.size()+firstShift, 1);
    	ans.resize(ans.size()+secondShift, 1);
    	ans.push_back(shiftLength);
    	ans.resize(ans.size()+thirdShift, 1);
    	break;
    }
    if(ans.size()) {
    	cout << ans.size() << endl;
    	for(int i : ans) cout << i << ' ';
    	cout << endl;
    } else {
    	cout << -1 << endl;
    }

    return 0;
}