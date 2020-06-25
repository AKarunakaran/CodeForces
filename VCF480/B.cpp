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
    cin >> n >> k;
    cout << "YES" << endl;
    vector<vector<char>> g(4, vector<char>(n, '.'));
    int row = 1;
    while(k > n-2) {
    	fill(g[row].begin()+1, g[row].end()-1, '#');
    	k -= (n-2);
    	++row;
    }
    if(k & 1) {
    	fill(g[row].begin()+(n-k)/2, g[row].begin()+(n-k)/2+k, '#');
    } else {
    	++k;
    	fill(g[row].begin()+(n-k)/2, g[row].begin()+(n-k)/2+k, '#');
    	g[row][n/2] = '.';
    }
    REP(i, 4) {
    	REP(j, n) cout << g[i][j];
    	cout << endl;
    }

    return 0;
}