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
    int h1, c1, a1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<string> cmd;
    int n = 0;
    while(1) {
    	if(h1 > a2 || h2 <= a1) {
    		cmd.push_back("STRIKE");
    		h2 -= a1;
    	} else {
    		cmd.push_back("HEAL");
    		h1 += c1;
    	}
    	if(h2 <= 0) break;
    	h1 -= a2;
    }
    cout << cmd.size() << endl;
    REP(i, cmd.size()) cout << cmd[i] << endl;

    return 0;
}