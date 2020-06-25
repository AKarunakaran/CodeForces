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
string s;
int n;

int ones(int k) {
	int res = 0;
	while(k) {
		k -= k & (-k);
		++res;
	}
	return res;
}

bool square(int k) {
	// DEBUG(k);
	int m = 1;
	string num;
	FORD(i, n-1, 0) {
		if(k & m) {
			num.push_back(s[i]);
		}
		m <<= 1;
	}
	reverse(num.begin(), num.end());
	if(num[0] == '0') return false;
	int l = stoi(num);
	// DEBUG(num);
	// DEBUG(l);
	int sq = sqrt(l);
	return sq*sq == l;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> s;
    n = s.size();
    int mask = 1;
    int upper = 1 << n;
    int best = 11;
    while(mask < upper) {
    	if(n-ones(mask) < best && square(mask)) {
    		best = n-ones(mask);
    	}
    	mask++;
    }
    cout << (best == 11 ? -1 : best) << endl;

    return 0;
}