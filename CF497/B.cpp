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
const int N = 1e5;
int n;
pii p[N];

void bad() {
	cout << "NO" << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> p[i].first >> p[i].second;
    if(p[0].first < p[0].second) swap(p[0].first, p[0].second);
    FOR(i, 1, n-1) {
    	if(p[i].first > p[i-1].first && p[i].second > p[i-1].first) {
    		// DEBUG(i);
    		// DEBUG(i-1);
    		bad();
    	}
    	if((p[i].second <= p[i-1].first && p[i].first < p[i].second) || (p[i].first > p[i-1].first)) {
    		swap(p[i].first, p[i].second);
    	}
    }
    cout << "YES" << endl;

    return 0;
}