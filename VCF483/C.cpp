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

const ll M = 1e7+1;

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

ll n;

bool finite(ll q, ll b) {
	ll g = gcd(q, b);
	while(g != 1) {
		q /= g;
		g = gcd(q, g);
	}
	return q == 1;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    while(n--) {
    	ll p, q, b;
    	cin >> p >> q >> b;
    	ll g = gcd(p, q);
    	p /= g, q /= g;
    	if(p == 0) {
    		cout << "Finite" << endl;
    		continue;
    	}
    	cout << (finite(q, b) ? "Finite" : "Infinite") << endl;
    }

    return 0;
}