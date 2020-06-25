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
const int N = 1e6;
int n, k, a[N];
multiset<int> s;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, n) s.insert(a[i]);
    auto itr = s.begin();
    auto prev = itr++;
    while(itr != s.end()) {
    	// DEBUG(*itr);
    	// DEBUG(*prev);
    	if(*itr <= *prev+k && *itr != *prev) {
	    	while(*itr <= *prev+k && *itr != *prev) {
	    		s.erase(prev);
	    		prev = itr;
	    		if(itr != s.begin()) --prev;
	    		else {
	    			++itr;
	    			break;
	    		}
	    	}
    	} else {
    		++itr, ++prev;
    	}
    }
    cout << s.size() << endl;

    return 0;
}