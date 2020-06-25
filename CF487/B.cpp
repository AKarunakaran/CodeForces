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
int n, p;
string s;

void bad() {
	REP(i, n) {
		if(s[i] == '.') s[i] = '1';
	}
	cout << s << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> p >> s;
    REP(i, p) {
    	int must;
    	if(s[i] == '0') must = 0;
    	else must = 1;
    	// DEBUG(i);
    	// DEBUG(must);
    	for(int j = i; j < n; j += p) {
    		if(s[j] != must+'0' && (j+p < n || j-p >= 0)) {
    			// DEBUG(j);
    			s[j] = (1-must)+'0';
    			bad();
    		}
    	}
    }
    cout << "No" << endl;

    return 0;
}