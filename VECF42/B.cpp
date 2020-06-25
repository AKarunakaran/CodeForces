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
int n, ans = 0;

void seat(int l, int r, int& mn, int& mx) {
	int len = r-l;
	int sub = min(mx, (len+1)/2);
	ans += sub;
	mx -= sub;
	sub = min(mn, len/2);
	ans += sub;
	mn -= sub;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int idx = 0;
    while(idx < n) {
    	while(idx < n && s[idx] == '*') ++idx;
    	int start = idx;
    	while(idx < n && s[idx] == '.') ++idx;
    	int end = idx;
    	seat(start, end, (a > b ? b : a), (a > b ? a : b));
    }
    cout << ans << endl;

    return 0;
}