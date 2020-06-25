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

void zalg(string& s, int* z) {
	int n = s.size();
	int l = 0, r = 0;
	FOR(i, 1, n-1) {
		if(i > r) {
			l = r = i;
			while (r < n && s[r-l] == s[r]) r++;
			z[i] = r-l; r--;
		} else {
			int k = i-l;
			if(z[k] < r-i+1) z[i] = z[k];
			else {
				l = i;
				while (r < n && s[r-l] == s[r]) r++;
				z[i] = r-l; r--;
			}
		}
	}
}

const int N = 1e5+10, M = 1e6+10;
int zf[M], num[2];

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s, t;
    cin >> s >> t;
    int n = t.size(), k = s.size();
    if(s[0] == '1') {
	    for(char& c : s) c = '0'+'1'-c;
    }
	for(char& c : s) num[c-'0']++;

	if(n < k) {
		cout << 0 << endl;
		exit(0);
	}
	int ans = 0;
    zalg(t, zf);
	FOR(lf, 1, n-1) {
		if((n-num[0]*lf) % num[1] != 0) continue;
		int ls = (n-num[0]*lf) / num[1];
		if(ls <= 0) continue;
		int pad = 0;
		bool good = true;
		REP(i, k) {
			if(i == 0 || s[i] == '1') {
				pad += (s[i] == '0') ? lf : ls;
				continue;
			}
			if(zf[pad] < lf) {
				good = false;
				break;
			}
			pad += lf;
		}
		if(!good) continue;
		if(ans) {
			++ans;
		} else {
			pad = 0;
			string sec;
			REP(i, k) {
				if(s[i] == '0') {
					pad += lf;
					continue;
				}
				if(sec.empty()) sec = t.substr(pad, ls);
				else { //possbile TLE if all bad matches
					if(t.substr(pad, ls) != sec) {
						good = false;
						break;
					}
				}
				pad += ls;
			}
			if(good) {
				++ans;
			}
		}
	}
	if(n % (num[0]+num[1]) == 0) {
		int l = n / (num[0]+num[1]);
		int pad = 0;
		string sec;
		bool good = true;
		REP(i, k) {
			if(s[i] != '0') {
				if(sec.empty()) sec = t.substr(pad, l);
				else {
					if(t.substr(pad, l) != sec) {
						good = false;
						break;
					}
				}
			}
			pad += l;
		}
		if(good && sec == t.substr(0, l)) --ans;
	}
	cout << ans << endl;

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
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
