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

bool sev(int t) {
	int m = t % 60;
	if(m % 10 == 7) return true;
	if(m/ 10 == 7) return true;
	int h = t / 60;
	if(h % 10 == 7) return true;
	if(h/ 10 == 7) return true;
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int x, h, m;
    cin >> x >> h >> m;
    int t = h*60 + m, ans = 0;

    while(!sev(t)) {
    	t = (t - x + 24*60) % (24*60);
    	++ans;
    }
    cout << ans << endl;

    return 0;
}