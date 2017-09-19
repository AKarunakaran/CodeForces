#include <iostream>
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
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

/////////////////////////////////////////////////////////////////////

int main() {
	int n, m;
	cin >> n;
	vector< pair<ull, pair<int, int> > > s(n);
	vector<bool> t(n, 0);
	REP(i, n) cin >> s[i].first;
	REP(i, n) cin >> s[i].second.first;
	REP(i, n) cin >> s[i].second.second;
	cin >> m;
	vector<int> c(m);
	REP(i, m) cin >> c[i];
	sort(s.begin(), s.end());

	/*REP(i, n) cout << s[i].first << " ";
	cout << endl;
	REP(i, n) cout << s[i].second.first << " ";
	cout << endl;
	REP(i, n) cout << s[i].second.second << " ";
	cout << endl;*/

	vector<int> x(3, 0);
	int j;
	REP(i, m) {
		//DEBUG(i);
		//DEBUG(c[i]);
		j = c[i]-1;
		//DEBUG(x[j]);
		while(x[j] < n && ((s[x[j]].second.first != c[i] && s[x[j]].second.second != c[i]) || t[x[j]])) ++x[j];
		if(x[j] == n) {
			cout << -1 << " ";
		} else {
			t[x[j]] = true;
			cout << s[x[j]].first << " ";
			++x[j];
		}
		//REP(k, n) cout << t[k] << " ";
		//cout << endl;
		//DEBUG(x[j]);
	}
	cout << endl;

    return 0;
}