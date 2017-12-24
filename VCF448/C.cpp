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
const int M = 1000000007;

/////////////////////////////////////////////////////////////////////

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int toPrime(int k) {
	int res = 0;
	REP(i, 19) {
		while(k % primes[i] == 0) {
			res ^= (1 << i);
			k /= primes[i];
		}
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    REP(i, n) a[i] = toPrime(a[i]);
    map<int, int> m;
    REP(i, n) {
    	vector<pii> toAdd;
    	for(auto itr : m) {
    		toAdd.push_back({itr.first ^ a[i], itr.second});
    	}
    	toAdd.push_back({a[i], 1});
    	REP(j, toAdd.size()) {
    		auto& tgt = m[toAdd[j].first];
    		tgt = (tgt + toAdd[j].second) % M;
    	}
    }
    cout << m[0] << endl;

    return 0;
}