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
    int x;
    cin >> x;
    vector<bool> prime(1e6+1, 1);
    vector<int> sieve(1e6+1, 0);
    vector<int> p;
    for(int i = 2; i <= 1e6; ++i) {
        if(prime[i]) {
            p.push_back(i);
            for(int j = i; j <= 1e6; j += i) {
                prime[j] = 0;
                if(sieve[j] == 0) sieve[j] = i;
            }
        }
    }
    // cout << p.size() << endl;
    int l;
    FORD(i, p.size()-1, 0) {
        if(x % p[i] == 0) {
            l = x - p[i]+1;
            break;
        }
    }
    // DEBUG(l);
    int ans = INF;
    // REP(i, p.size()) {
    //  if(2*p[i]+1 >= l) {
    //      cout << p[i]+1 << endl;
    //      exit(0);
    //  }
    // }
    FOR(i, l, x) {
    	int n = i, t;
    	while(n != 1) {
	    	t = sieve[n];
	        while(n % t == 0) n /= t;
    	}
	    if(i != t) ans = min(ans, i-t+1);
    }
    cout << ans << endl;

    return 0;
}