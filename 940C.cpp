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
    int n, k;
    string s, t;
    cin >> n >> k >> s;
    set<char> c;
    for(char ch : s) c.insert(ch);
    if(n < k) {
    	t = s;
    	t.resize(k, *c.begin());
    	cout << t << endl;
    	exit(0);
    }
    t.resize(k, '_');
    bool bigger = false;
    FORD(i, k-1, 0) {
    	if(bigger) {
    		t[i] = s[i];
    	} else {
    		if(s[i] == *c.rbegin()) {
    			t[i] = *c.begin();
    		} else {
    			t[i] = *c.upper_bound(s[i]);
    			bigger = true;
    		}
    	}
    }
    cout << t << endl;

    return 0;
}