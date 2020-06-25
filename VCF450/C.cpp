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

int n;

int getSum(vector<int>& bit, int index) {
    int sum = 0;
    ++index;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}
 

//assumes global n
void updateBIT(vector<int>& bit, int index, int val) {
    ++index;
    while (index <= n+1) {
       bit[index] += val;
       index += index & (-index);
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int maxSoFar = 0;
    cin >> n;
    if(n == 1) {
    	cout << 1 << endl;
    	exit(0);
    }
    vector<int> bit(n+2, 0);
    vector<int> a(n), poss(n+1, 0);
    REP(i, n) cin >> a[i];
    REP(i, n) {
    	// DEBUG(a[i]);
    	// DEBUG(getSum(bit, a[i]-1));
    	if(i-getSum(bit, a[i]) == 0) {
    		--poss[a[i]];
    	}
    	if(maxSoFar > a[i] && i-getSum(bit, a[i]) == 1) {
    		++poss[maxSoFar];
    	}
    	maxSoFar = max(maxSoFar, a[i]);
    	updateBIT(bit, a[i], 1);
    }
    int ans = 0;
    poss[0] = -1;
    FOR(i, 1, n) if(poss[i] > poss[ans]) ans = i;
    // FOR(i, 1, n) cout << poss[i] << ' ';
    // cout << endl;
    cout << (ans == 0 ? 1 : ans) << endl;

    return 0;
}