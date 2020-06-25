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

int n, m;

int ask(int idx) {
	int res;
	cout << "? " << idx << endl;
	cin >> res;
	return res;
}

void answer(int idx) {
	cout << "! " << idx << endl;
	exit(0);
}

int getd(int idx) {
	int a1 = ask(idx);
	int a2 = ask(idx+m);
	return a2-a1;
}

inline int sign(int x) { return x > 0 ? 1 : -1; }

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    m = n/2;
    int s = getd(1);
    if(s & 1) answer(-1);
    int l = 1, r = 1+m;
    while(l < r) {
    	int mid = (l+r)/2;
    	int d = getd(mid);
    	if(d == 0) answer(mid);
    	else if(sign(d) == sign(s)) l = mid+1;
    	else r = mid-1;
    }
    answer(l);

    return 0;
}