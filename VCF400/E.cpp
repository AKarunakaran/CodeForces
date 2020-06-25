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
vector<ll> primes;
const ll M = 1000000007;

ll phi(ll n) {
	ll tn = n;
	vector<ll> cons;
	for(ll p : primes) {
		if(p*p > tn) break;
		if(tn % p == 0) {
			cons.push_back(p);
			while(tn % p == 0) {
				tn /= p;
			}
		}
	}
	if(tn != 1) cons.push_back(tn);
	for(ll p : cons) {
		n /= p;
		n *= p-1;
	}
	return n;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    vector<bool> p(1e6+1, 1);
    for(int i = 2; i*i <= 1e6; ++i) {
    	if(p[i]) {
    		for(int j= 2*i; j <= 1e6; j += i) {
    			p[j] = 0;
    		}
    	}
    }
    for(int i = 2; i <= 1e6; ++i) {
    	if(p[i]) primes.push_back(i);
    }
    ll n, k;
    cin >> n >> k;
    if((k & 1) == 0) --k;
    while(k > 0 && n != 1) {
    	n = phi(n);
    	k -= 2;
    }
    cout << n % M << endl;

    return 0;
}