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
vector<bool> p(1e5+1, 1);
vector<int> primes;

bool prime(int n) {
	for(int i : primes) {
		if(i*i > n) break;
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int h, y, ans = -1;
    cin >> h >> y;
    p[0] = p[1] = 0;
    int l = min(h, (int)1e5);
    for(int i = 2; i <= l; ++i) {
    	if(p[i]) {
    		primes.push_back(i);
    		for(int j = 2*i; j <= l; j += i) p[j] = 0;
    	}
    }
    // DEBUG(primes.size());
    FORD(i, y, 0) {
    	if(prime(i)) {
    		if(i > h) ans = i;
    		break;
    	}
    }
    cout << ans << endl;

    return 0;
}