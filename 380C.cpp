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

typedef pair<int, pii> trip;

const int N = 1e6+1;  // limit for array size
int n;  // array size
trip a[N][20];

trip func(trip x, trip y) {
	int l = min(x.second.first, y.second.second);
	return {x.first+y.first+2*l, {x.second.first+y.second.first-l, x.second.second+y.second.second-l}};
}

trip query(int l, int r) {
    // DEBUG(l);
    // DEBUG(r);
    int d = r-l+1;
    int two = 1, idx = 0;
    while(two << 1 <= d) {
        two <<= 1;
        ++idx;
    }
    return (two == d) ? a[l][idx] : func(a[l][idx], query(l+two, r));
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    int q;
    cin >> s >> q;
    n = s.size();
    s = " " + s;
    int two = 1, idx = 0;
    while(two <= n) {
        FOR(i, 1, n) {
            if(i + two - 1 > n) break;
            if(idx == 0) {
                if(s[i] == '(') a[i][idx] = {0, {1, 0}};
                else a[i][idx] = {0, {0, 1}};
            } else a[i][idx] = func(a[i][idx-1], a[i+two/2][idx-1]);
        }
        two <<= 1, ++idx;
    }

    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	cout << query(l, r).first << endl;
    }

    return 0;
}