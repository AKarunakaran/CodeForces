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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

struct person {
	int x, v, t;
	double tm;
};

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    int n, s;
    cin >> n >> s;
    vector<person> p(n);
    vector<double> tm(n);
    REP(i, n) {
    	cin >> p[i].x >> p[i].v >> p[i].t;
    	if(p[i].t == 1) p[i].tm = (double)(p[i].x/p[i].v);
    	else p[i].tm = (double)((1000000-p[i].x)/p[i].v);
    }
    REP(i, n) cout << i << " " << p[i].tm << endl;
    sort(p.begin(), p.end(), [](person& left, person& right){return 
    	left.t < right.t || (left.t == right.t && (left.x < right.x || (left.x == right.x && left.tm < right.tm)));});
    int rIdx = 0;
    REP(i, n) {
    	if(p[i].t == 2) {
    		rIdx = i;
    		break;
    	}
    }
    FOR(i, 0, 1000000)

    return 0;
}