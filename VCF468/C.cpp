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
    int n;
    cin >> n;
    vector<int> x(n);
    REP(i, n) cin >> x[i];
    sort(x.begin(), x.end());
    int l = x[0], h = x.back(), m = x[0]+1;
    if(h-l < 2) {
    	cout << n << endl;
    	REP(i, n) cout << x[i] << ' ';
    	cout << endl;
    	exit(0);
    }
    int nl = 0, nh = 0, nm = 0;
    REP(i, n) {
    	if(x[i] == l) ++nl;
    	if(x[i] == m) ++nm;
    	if(x[i] == h) ++nh;
    }
    vector<int> y;
    if(nm/2 > min(nl, nh)) {
        int half = nm/2;
        y.resize(y.size()+nl+half, l);
        y.resize(y.size()+nm-2*half, m);
        y.resize(y.size()+nh+half, h);
        cout << n-2*half << endl;
    } else {
        int rm = min(nl, nh);
        int nnm = 2*rm;
        y.resize(y.size()+nl-rm, l);
        y.resize(y.size()+nm+nnm, m);
        y.resize(y.size()+nh-rm, h);
        cout << n-nnm << endl;
    }
    REP(i, n) cout << y[i] << ' ';
    cout << endl;

    return 0;
}