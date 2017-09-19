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
inline int two(int n) { return 1 << n; }
const int M = 1000000007;

/////////////////////////////////////////////////////////////////////

vector<bool> primes(5000001, 1);
int maxP = 2;

int f(int n) {
	ll num = n;
	for(int i = 2; i*i <= n; ++i) {
		if(primes[i]) {
			if(i >= maxP) {
				maxP = i;
				for(int j = i; j <= n; j += i) primes[j] = 0;
			}
			if(n % i == 0) {
				num = i;
				break;
			}
		}
	}
	num = num*(num-1)/2;
	return num % M;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t, l, r, ans = 0, curT = 1;
    cin >> t >> l >> r;
    FOR(i, l, r) {
    	if(i != l) curT = (curT*t) % M;
    	ans += curT+f(i);
    }
    cout << ans << endl;

    return 0;
}