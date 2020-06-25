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
#include <cstdlib>
#include <ctime>
using namespace std; 
#define int long long
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

const int N = 1e5;
const double R = 15e5;
int n, ans[N];
pii p, maybe[N];
pair<pii, int> v[N];

double norm(pii pt) {return sqrt(pt.first*pt.first+pt.second*pt.second);}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    srand(time(NULL));
    fill(ans, ans+N, 1);
    cin >> n;
    REP(i, n) {
    	cin >> v[i].first.first >> v[i].first.second;
    	v[i].second = i;
    }
    REP(t, 300) {
    	random_shuffle(v, v+n);
	    REP(i, n) maybe[i] = {-2*v[i].first.first, -2*v[i].first.second};
	    REP(i, n) p = {p.first+v[i].first.first, p.second+v[i].first.second};
	    REP(i, n) {
	    	double r = norm(p);
	    	if(r < R) break;
	    	pii test = {p.first+maybe[i].first, p.second+maybe[i].second};
	    	if(norm(test) < r) {
	    		p = test;
	    		ans[v[i].second] = -1;
	    	}
	    }
	    if(norm(p) < R) break;
    }
    // DEBUG(norm(p));
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}