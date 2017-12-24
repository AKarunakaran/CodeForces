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

vector<int> a;
vector<vector<int>> d;
set<int> nums;
int n;

void rec(int cur, int k) {
	// DEBUG(cur);
	// DEBUG(k);
	nums.insert(cur);
	if(k == n) {
		return;
	}
	REP(i, 6) {
		// DEBUG(i);
		// DEBUG(a[k]);
		rec(cur*10+d[a[k]-1][i], k+1);
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    a.resize(n);
    d.resize(n, vector<int>(6));
    iota(a.begin(), a.end(), 1);
    REP(i, n) REP(j, 6) cin >> d[i][j];
    do {
    	rec(0, 0);
    } while(next_permutation(a.begin(), a.end()));
    auto itr = nums.begin();
    auto next = itr;
    bool hasOne = false;
    ++next;
    while(next != nums.end()) {
    	if(*itr == 1) hasOne = true;
    	if(*itr != *next-1) break;
    	++itr;
    	++next;	
    }
    cout << (hasOne ? *itr : 0) << endl;

    return 0;
}