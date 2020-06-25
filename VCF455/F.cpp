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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    if(n & 1) cout << "NO" << endl;
    else {
    	cout << "YES" << endl;
    	vector<int> ans(n+1, 0);
    	int tn = n;
    	while(tn > 0) {
	    	int h = (1 << (int)floor(log2(tn)));
	    	for(int i = 1; i <= tn-h+1; ++i) {
	    		ans[h+i-1] = h-i;
	    		ans[h-i] = h+i-1;
	    	}
	    	tn = h-2-(tn-h);
    	}
    	FOR(i, 1, n) cout << ans[i] << " ";
    	cout << endl;
    }
    if(n <= 5 || !(n & n-1)) cout << "NO" << endl;
    else if(n == 6) cout << "YES\n3 6 2 5 1 4" << endl;
    else {
    	cout << "YES" << endl;
    	vector<int> ans(n+1, 0);
    	iota(ans.begin(), ans.end(), 0);
    	ans[1] = 7;
    	ans[2] = 3;
    	ans[3] = 6;
    	ans[4] = 5;
    	ans[5] = 1;
    	ans[6] = 2;
    	ans[7] = 4;
    	int prev = 8, next = 16;
    	while(prev <= n) {
    		rotate(ans.begin()+prev, ans.begin()+prev+1, ans.begin()+min(n+1, next));
    		prev <<= 1;
    		next <<= 1;
    	}
    	FOR(i, 1, n) cout << ans[i] << " ";
    	cout << endl;
    }


    return 0;
}