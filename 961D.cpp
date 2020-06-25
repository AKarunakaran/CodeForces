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
inline bool EQ(double a, double b) { return abs(a-b) < 1e-11; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////
const int N = 1e5;
int n;
pll p[N];

double getSlope(int i, int j) {
	return (p[i].first == p[j].first) ? INF : (p[i].second-p[j].second)/((double)(p[i].first-p[j].first));
}

void finish(double slope, int idx) {
	vector<int> other;
	REP(i, n) {
		if(i == idx) continue;
		if(!EQ(getSlope(idx, i), slope)) {
			other.push_back(i);
		}
	}
	int k = other.size();
	if(k < 3) {
		cout << "YES" << endl;
		exit(0);
	}
	int start = other[0];
	double newslope = getSlope(other[0], other[1]);
	FOR(i, 1, k-1) {
		int curIdx = other[i];
		if(!EQ(getSlope(start, curIdx), newslope)) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> p[i].first >> p[i].second;
    if(n < 4) {
    	cout << "YES" << endl;
    	exit(0);
    }
    set<double> slopes;
    REP(start, 2) {
    	FOR(i, 1+start, n-1) {
	    	double cur = getSlope(start, i);
	    	// DEBUG(i);
	    	// DEBUG(cur);
	    	if(slopes.count(cur) == 1) finish(cur, start);
	    	slopes.insert(cur);
	    }
	    slopes.clear();
    }
    double sl = getSlope(0, 1);
    finish(sl, 0);

    return 0;
}