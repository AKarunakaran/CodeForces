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
    int n = s.size();
    ll ae = 0, ao = 0, be = 0, bo = 0, e = 0, o = n;
    REP(i, n) {
    	if(s[i] == 'a') {
    		if(i & 1) {
    			e += ae;
    			o += ao;
    			++ao;
    		} else {
    			e += ao;
    			o += ae;
    			++ae;
    		}
    	} else {
    		if(i & 1) {
    			e += be;
    			o += bo;
    			++bo;
    		} else {
    			e += bo;
    			o += be;
    			++be;
    		}
    	}
    }
    cout << e << ' ' << o << endl;

    return 0;
}