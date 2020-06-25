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
    multiset<pii> s;
    REP(i, n) {
    	int a, b;
    	cin >> a >> b;
    	s.insert({b, a});
    }
    s.insert({0, 0});
    auto nxt = s.begin();
    auto itr = nxt++;
    while(nxt != s.end()) {
    	// DEBUG(itr->first);
    	// DEBUG(itr->second);
    	// DEBUG(nxt->first);
    	// DEBUG(nxt->second);
    	if(itr->second > nxt->second) {
    		pii newp = *itr;
    		newp.first = newp.second;
    		nxt = itr;
    		--nxt;
    		s.erase(itr);
    		s.insert({newp});
    		itr = nxt;
    		++nxt;
    	} else itr = nxt++;
    }
    cout << s.rbegin()->first << endl;

    return 0;
}