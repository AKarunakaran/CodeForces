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

int n;

void preFill(vector<int>& a, vector<int>& lo, vector<int>& lt) {
	FOR(i, 1, n) {
    	if(a[i] == 1) {
    		lo[i] = lo[i-1]+1;
    		lt[i] = max(lt[i-1], lo[i]);
    	} else {
    		lo[i] = lo[i-1];
    		lt[i] = lt[i-1]+1;
    	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    vector<int> a(n+1);
    FOR(i, 1, n) cin >> a[i];
    vector<int> lo(n+1, 0), lt(n+1, 0);
    vector<int> rlo(n+2, 0), rlt(n+2, 0);
    preFill(a, lo, lt);
    reverse(a.begin(), a.end());
    preFill(a, rlo, rlt);
    reverse(a.begin(), a.end());
    reverse(rlo.begin(), rlo.end());
    reverse(rlt.begin(), rlt.end());
    

    return 0;
}