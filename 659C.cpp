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
    int n, m;
    cin >> n >> m;
    set<int> t;
    vector<int> sol;
    REP(i, n) {
    	int tIn;
    	cin >> tIn;
    	t.insert(tIn);
    }
    int i = 1;
    while(i <= m) {
    	if(t.find(i) == t.end()) {
    		m -= i;
    		sol.push_back(i);
    	}
    	++i;
    }
    cout << sol.size() << endl;
    REP(i, sol.size()) cout << sol[i] << " ";
    cout << endl;


    return 0;
}