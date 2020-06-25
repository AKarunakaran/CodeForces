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

const int N = 100;
string s[2];
int n, dp[N][4];

// b = 0: O
//        O
// b = 1: O
//        X
// b = 2: X
//        O
// b = 3: X
//        X
int rec(int k, int b) {
	if(k < 0) return 0;
	int& memo = dp[k][b];
	if(memo != -1) return memo;
	int res = 0;
	int curb = 0;
	if(s[0][k] == 'X') curb |= 2;
	if(s[1][k] == 'X') curb |= 1;
	if(!(b & 1) && s[0][k] == '0' && s[1][k] == '0') res = max(res, 1+rec(k-1, 3));
	if(!(b & 2) && s[0][k] == '0' && s[1][k] == '0') res = max(res, 1+rec(k-1, 3));
	if(b == 0 && s[1][k] == '0') {
		res = max(res, 1+rec(k-1, curb | 1));
	}
	if(b == 0 && s[0][k] == '0') {
		res = max(res, 1+rec(k-1, curb | 2));
	}
	res = max(res, rec(k-1, curb));
	return memo = res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    REP(i, N) fill(dp[i], dp[i]+4, -1);
    cin >> s[0] >> s[1];
    n = s[0].size();
    cout << rec(n-1, 3) << endl;

    return 0;
}