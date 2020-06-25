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

const int N = 1e5+1;
int good[N], ans = 0;

void finddiv(string& s) {
	int n = s.size();
	vector<int> ps;
	FOR(i, 1, n) if(n % i == 0) ps.push_back(i);
	for(int x : ps) {
		int k = n/x;
		bool flag = true;
		REP(i, x) {
			char cur = s[i];
			REP(j, k) {
				if(s[j*x+i] != cur) {
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) ++good[x];
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(good, good+N, 0);
    string s, t;
    cin >> s >> t;
    REP(i, min(s.size(), t.size())) {
    	if(s[i] != t[i]) {
    		cout << 0 << endl;
    		exit(0);
    	}
    }
    finddiv(s);
    finddiv(t);
    FOR(i, 1, N-1) ans += (good[i] == 2);
    cout << ans << endl;

    return 0;
}