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
    sort(p.begin(), p.end(), [](person& left, person& right){return left.t < right.t || (left.t == right.t && left.tm < right.tm)});
    int rIdx = 0;
    REP(i, n) {
    	if(p[i].t == 2) {
    		ridx = i;
    		break;
    	}
    }
    double best = p[0].tm + p[rIdx].tm;
    FOR(i, 0, 100000) {
    	double cur = 0;
    	FOR(j, 0, rIdx-1) {
    		if(i < p[j].x || ((i-p[j].x) % (s-p[j].v) != 0)) continue;
    		else cur += p[j].tm - (double)(i/s) + (i-p[j].x)/(s-p[j].v);
    		break;
    	}
    	FOR(j, rIdx, n-1) {
    		if(i > p[j].x || ((p[j].x-i) % (s-p[j].v) != 0)) continue;
    		else cur += p[j].tm - (double)((1000000-i)/s) + (p[j].x-i)/(s-p[j].v);
    		break;
    	}
    	best = min(cur, best);
    }
    cout << best << endl;

    return 0;
}