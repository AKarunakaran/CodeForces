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

const int N = 100;
int n, b, a[N];

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> b;
    REP(i, n) cin >> a[i];
    int even = 0, odd = 0;
    vector<int> cuts;
    REP(i, n) {
    	if(a[i] & 1) ++odd;
    	else ++even;
    	if(even == odd && i != n-1) {
    		cuts.push_back(abs(a[i]-a[i+1]));
    		// DEBUG(cuts.back());
    	}
    }
    sort(cuts.begin(), cuts.end());
    int ans = 0;
    // DEBUG(b);
    while(ans < cuts.size() && b >= cuts[ans]) {
    	b -= cuts[ans];
    	++ans;
    	// DEBUG(b);
    }
    cout << ans << endl;

    return 0;
}