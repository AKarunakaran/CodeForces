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

/////////////////////////////////////////////////////////////////////

int lR(string& s) {
	//cout << s << endl;
	int start = 0, best = 0;
	int i;
	for(i = 1; i < s.size(); ++i) {
		if(s[i] != s[i-1]) {
			best = max(best, i-start);
			start = i;
		}
	}
	best = max(best, i-start);
	return best;
}

int perm(string& s, int m, char c, int k) {
	if(m == 0 || k == s.size()) {
		return lR(s);
	}
	int ans = perm(s, m, c, k+1);
	if(s[k] != c) {
		char temp = s[k];
		s[k] = c;
		ans = max(ans, perm(s, m-1, c, k+1));
		s[k] = temp;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, q;
    string s, temp;
    cin >> n >> s >> q;
    int m, ans;
    char c;
    REP(i, q) {
    	cin >> m >> c;
    	temp = s;
    	ans = perm(temp, m, c, 0);
    	cout << ans << endl;
    }

    return 0;
}