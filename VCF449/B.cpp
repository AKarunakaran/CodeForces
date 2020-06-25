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

// k > 9, add 45+45*10
// k > 99, add 45+45*1000+9(45*100+45*10)
// k > 999, add 
ll k, p, ans = 0;

void solve(ll hp) {
	ll dig = hp*2;
	ll remain = k-(pow(10, hp)-1);
	
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> k >> p;
    ll hpa[7];
    hpa[1] = (45+45*10) % p;
    hpa[0] = 0;
    ll curP = 10;
    FOR(i, 2, 6) {
    	curP *= 100;
    	hpa[i] = (45+45*curP+hpa[i-1]*10+hpa[i-2]) % p;
    }
    ll hp = 1;
    curP = 10;
    while(k >= curP) {
    	ans = (ans+hpa[hp]) % p;
    	++hp;
    	curP *= 10;
    }
    solve(hp);

    return 0;
}