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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, m, k, md = 0;
    cin >> n >> m >> k;
    vector<int> milk(n);
    vector<pair<int, int>> store(m);
    REP(i, n) {
    	cin >> milk[i];
    	md = max(md, milk[i]);
    }
    sort(milk.begin(), milk.end());
    REP(i, m) {
    	cin >> store[i].first;
    	store[i].second = i+1;
    }
    sort(store.begin(), store.end());
    vector<int> days(10000000, 0);
    int day = md;
    FORD(i, n-1, 0) {
    	if(milk[i] > day) {
    		cout << -1 << endl;
    		return 0;
    	} else if(milk[i] < day) {
    		day = milk[i];
    	}
    	++days[day];
    	if(days[day] == k) --day;
    }

    //FOR(i, 0, md) cout << days[i] << " ";
    //cout << endl;

    day = 0;
    vector<int> sol;
    while(days[day] == k) ++day;
    REP(i, m) {
    	//DEBUG(day);
    	if(store[i].first >= day) {
    		++days[day];
    		sol.push_back(store[i].second);
    		while(days[day] == k) ++day;
    	}
    }

    cout << sol.size() << endl;
    REP(i, sol.size()) cout << sol[i] << " ";
    cout << endl;

    return 0;
}