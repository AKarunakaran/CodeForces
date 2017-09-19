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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int tri[100001] = {};
    tri[0] = tri[1] = 0;
    tri[2] = 1;
    FOR(i, 3, 100000) tri[i] = tri[i-1]+i-1;
    //REP(i, 100) cout << tri[i] << " ";
    //cout << endl;
    int k;
    cin >> k;
    if(k == 0) {
    	cout << "a" << endl;
    	return 0;
    }
    char c = 'a';
    string ans;
    while(k) {
    	//DEBUG(k);
    	auto n = lower_bound(tri, tri+100001, k);
    	if(*n != k) n -= 1;
    	//cout << n-tri << endl;
    	//DEBUG(*n);
    	k -= *n;
    	ans.resize(ans.size()+(n-tri), c);
    	++c;
    }
    cout << ans << endl;

    return 0;
}