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
    int o, z;
    cin >> z >> o;
    if(o > 2*(z+1) || z > o+1) {
    	cout << -1 << endl;
    	exit(0);
    }
    string ans;
    if(z == o+1) {
    	ans.push_back('0');
    	--z;
    }
    while(o && z && o > z) {
    	ans += "110";
    	o -= 2;
    	--z;
    }
    while(o && z) {
    	ans += "10";
    	--o, --z;
    }
    while(o) {
    	ans.push_back('1');
    	--o;
    }
    cout << ans << endl;

    return 0;
}