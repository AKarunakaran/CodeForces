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

////////////////////////////////////////////////////////w/////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, a, b, rnd = 1;
    cin >> n >> a >> b;
    --a; --b;
    a >>= 1;
    b >>= 1;
    while(1) {
    	// DEBUG(a);
    	// DEBUG(b);
    	if(a == b) {
    		if(rnd == log2(n)) {
    			cout << "Final!" << endl;
    		} else {
    			cout << rnd << endl;
    		}
    		exit(0);
    	}
    	a >>= 1, b >>= 1, ++rnd;
    }

    return 0;
}