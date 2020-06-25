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
const int N = 1e5+1;
int n, d[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(d, d+N, 0);
    cin >> n;
    REP(i, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	++d[a], ++d[b];
    }
    int idx = -1;
    vector<int> leaves;
    FOR(i, 1, n) {
    	if(d[i] == 1) leaves.push_back(i);
    	else if(d[i] > 2) {
    		if(idx != -1) {
    			cout << "No" << endl;
    			exit(0);
    		}
    		idx = i;
    	}
    }
    if(idx == -1) {
    	cout << "Yes" << endl;
    	cout << 1 << endl;
    	cout << leaves[0] << ' ' << leaves[1] << endl;
    	exit(0);
    }
    cout << "Yes" << endl;
    cout << leaves.size() << endl;
    for(int v : leaves) cout << idx << ' ' << v << endl;

    return 0;
}