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
const int N = 1e5;
int n, k, g[257], p[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(g, g+257, -1);
    cin >> n >> k;
    REP(i, n) cin >> p[i];
    REP(c, n) {
    	int cur = p[c];
    	if(g[cur] == -1) {
    		int newg = cur-k+1, idx = cur-k+1;
    		FORD(i, cur, cur-k+1) {
    			if(g[i] != -1) {
    				idx = i+1;
    				if(cur-g[i] < k) newg = g[i];
    				else newg = i+1;
    				break;
    			}
    		}
    		FOR(i, idx, cur) g[i] = newg;
    	}
    	cout << g[cur] << ' ';
    }
    cout << endl;

    return 0;
}