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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    map<int, int> m;
    REP(i, n) {
    	if(m.find(a[i]) != m.end()) {
    		cout << -1 << endl;
    		exit(0);
    	}
    	m[a[i]] = i;
    }
    auto next = m.begin();
    auto cur = next++;
    int temp = cur->first;
    while(next != m.end()) {
    	a[cur->second] = next->first;
    	cur = next++;
    }
    a[cur->second] = temp;
    REP(i, n) cout << a[i] << " ";
    cout << endl;

    return 0;
}