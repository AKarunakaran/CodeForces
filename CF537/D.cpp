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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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

const int M = 1e9+7, N = 1e5+10;
int add(int a, int b) {return (a+b)%M;}
int mult(int a, int b) {return ((ll)a*b)%M;}

int n, q, len, f[N], invf[N], ans = 1;
string s;
map<char, int> num;
unordered_map<string, int> answers;
int tot, oth, arroth, numarr;
vector<bool> have;
unordered_map<int, int> m;

int conv(int idx, int sum) {
	return (sum << 6) + idx;
}

int findall(vector<int>& rest, int idx, int sum) {
	if(sum == 0) return 1;
	if(idx == rest.size()) return 0;
	if(sum < 0) return 0;
	int h = conv(idx, sum), res = 0;
	if(m.find(h) != m.end()) return m[h];
	res = add(res, findall(rest, idx+1, sum-rest[idx]));
	res = add(res, findall(rest, idx+1, sum));
	return m[h] = res;
}

int query(int x, int y) {
	char a = s[x], b = s[y];
	if(a > b) swap(a, b);
	string h;
	h.push_back(a);
	h.push_back(b);
	if(answers.find(h) != answers.end()) return answers[h];
	bool same = (a == b);
	int na = num[a], nb = num[b];
	tot = same ? na : na+nb;
	oth = len-tot;
	if(tot > len) return 0;

	vector<int> rest;
	for(auto& p : num) {
		if(p.first == a || p.first == b) continue;
		rest.push_back(p.second);
	}
	// DEBUG(oth);
	numarr = findall(rest, 0, oth);
	m.clear();
	// DEBUG(arroth);
	// DEBUG(numarr);

	return answers[h] = mult(ans, mult(numarr, 2));
}

int fastPowMod(int base, int power) {
    int res = 1;
    while(power) {
        if(power & 1) res = mult(res, base);
        base = mult(base, base);
        power >>= 1;
    }
    return res;
}

void precalc() {
	f[0] = 1;
	FOR(i, 1, 1e5) f[i] = mult(i, f[i-1]);
	FOR(i, 0, 1e5) invf[i] = fastPowMod(f[i], M-2);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    precalc();
    cin >> s >> q;
    n = s.size(), len = s.size()/2;
    for(char c : s) num[c]++;
    for(auto& p : num) ans = mult(ans, invf[p.second]);
    ans = mult(ans, mult(f[len], f[len]));
    // DEBUG(num.size());
    while(q--) {
    	int x, y;
    	cin >> x >> y;
    	--x, --y;
    	cout << query(x, y) << endl;
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

