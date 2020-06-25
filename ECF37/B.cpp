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
    int t;
    cin >> t;
    REP(test, t) {
    	int n;
    	cin >> n;
    	vector<pii> s(n);
    	REP(i, n) {
    		cin >> s[i].first >> s[i].second;
    	}
	    vector<int> ans(n, 0);
	    queue<int> p;
	    int idx = 0;
	    FOR(sec, 1, 5000) {
	    	while(idx < n && s[idx].first == sec) p.push(idx++);
	    	if(!p.empty()) {
	    		bool f = true;
	    		int cur = p.front();
	    		p.pop();
	    		while(s[cur].second < sec) {
	    			ans[cur] = 0;
	    			if(p.empty()) {
	    				f = false;
	    				break;
	    			}
	    			cur = p.front();
	    			p.pop();
	    		}
	    		if(f) {
	    			ans[cur] = sec;
	    		}
	    	}
	    }
	    REP(i, n) cout << ans[i] << ' ';
	    cout << endl;
    }

    return 0;
}