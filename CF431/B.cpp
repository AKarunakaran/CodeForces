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
    vector<int> p(n);
    REP(i, n) cin >> p[i];
    if(n == 3) {
    	cout << (p[1]-p[0] == p[2]-p[1] ? "No" : "Yes") << endl;
    	return 0;
    }
    double s = p[1]-p[0];
    vector<int> second;
    FOR(i, 2, n-1) {
    	if(!EQ((p[i]-p[0])/(double)i, s)) second.push_back(i);
    }
    if(second.size() == 1) {
    	cout << "Yes" << endl;
    	return 0;
    }
    if(second.size() == 0) {
    	cout << "No" << endl;
    	return 0;
    }
    double s2 = (double)(p[second[1]]-p[second[0]])/(double)(second[1]-second[0]);
    bool flag = true;
    for(int i : second) {
    	if(i == second[0]) continue;
    	if(!EQ(p[i]-p[second[0]]/(i-second[0]), s2)) flag = false;
    }
	if(flag && EQ(s, s2)) {
		cout << "Yes" << endl;
		return 0;
	}
	vector<pair<double, double>> sl(n);
	FOR(i, 2, n-1) {
		sl[i].first = (double)(p[i]-p[0])/(double)(i);
		sl[i].second = (double)(p[i]-p[1])/(double)(i-1);
	}
	if(EQ(sl[3].first, sl[2].first) || EQ(sl[3].first, sl[2].second)) s = sl[3].first;
	else if(EQ(sl[3].second, sl[2].first) || EQ(sl[3].second, sl[2].second)) s = sl[3].second;
	else {
		cout << "No" << endl;
		return 0;
	}
	FOR(i, 3, n-1) {
		if(!EQ(sl[i].first, s) && !EQ(sl[i].second, s)) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

    return 0;
}