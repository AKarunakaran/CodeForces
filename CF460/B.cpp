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

int k;

void rec(int d, string& s, int left) {
	if(s.size() == d) {
		if(left) return;
		--k;
		if(k == 0) {
			cout << s << endl;
			exit(0);
		}
		return;
	}
	FOR(i, 0, 9) {
		if(s.size() == 0 && i == 0) continue;
		if(i > left) break;
		s.push_back(i+'0');
		rec(d, s, left-i);
		s.pop_back();
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> k;
    FOR(d, 1, 100) {
    	string s = "";
    	rec(d, s, 10);
    }

    return 0;
}