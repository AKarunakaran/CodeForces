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
#include <numeric>
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
    vector<int> a(10);
    iota(a.begin(), a.end(), 0);
    int ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> e(10, vector<int>(n));
    REP(c, 10) {
    	int cur = -1;
    	FORD(i, n-1, 0) {
    		if(s[i] == c+'0') cur = i;
    		e[c][i] = cur;
    	}
    }
    // REP(i, 10) {
    // 	REP(j, n) {
    // 		cout << e[i][j] << ' ';
    // 	}
    // 	cout << endl;
    // }
    do {
    	int idx = 0, i = 0;
    	while(idx != 10 && i != -1) {
    		i = e[a[idx++]][i];
    	}
    	ans += (idx == 10 && i != -1);
    } while(next_permutation(a.begin(), a.end()));
    cout << ans << endl;

    return 0;
}