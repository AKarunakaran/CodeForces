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

const int N = 2e5+2;
int n, m, t[9];
pii q[N];
set<int> r[N], c[N], d1[N], d2[N];

// d1 is top left to bottom right diagonals
pii findd1(pii p) {
	pii res;
	res.first = (p.first-1)+(n-p.second);
	res.second = p.first;
	return res;
}

pii findd2(pii p) {
	pii res;
	res.first = (p.first-1)+(p.second-1);
	res.second = p.first;
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(t, t+9, 0);
    cin >> n >> m;
    REP(i, m) {
    	cin >> q[i].first >> q[i].second;
    	r[q[i].first].insert(q[i].second);
    	c[q[i].second].insert(q[i].first);
    	pii d1coor = findd1(q[i]);
    	d1[d1coor.first].insert(d1coor.second);
    	pii d2coor = findd2(q[i]);
    	d2[d2coor.first].insert(d2coor.second);
    }
    REP(i, m) {
    	int cur = 0;

    	auto itr = r[q[i].first].find(q[i].second);
    	if(itr != r[q[i].first].begin()) ++cur;
    	if(*itr != *r[q[i].first].rbegin()) ++cur;

    	itr = c[q[i].second].find(q[i].first);
    	if(itr != c[q[i].second].begin()) ++cur;
    	if(*itr != *c[q[i].second].rbegin()) ++cur;

    	pii d1coor = findd1(q[i]);
    	itr = d1[d1coor.first].find(d1coor.second);
    	if(itr != d1[d1coor.first].begin()) ++cur;
    	if(*itr != *d1[d1coor.first].rbegin()) ++cur;

    	pii d2coor = findd2(q[i]);
    	itr = d2[d2coor.first].find(d2coor.second);
    	if(itr != d2[d2coor.first].begin()) ++cur;
    	if(*itr != *d2[d2coor.first].rbegin()) ++cur;

    	++t[cur];
    }
    REP(i, 9) cout << t[i] << ' ';
    cout << endl;

    return 0;
}