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
    int n, k, d = 0;
    cin >> n >> k;
    vector<int> p(n), b;
    stack<int> s;
    vector<bool> done(n+1, 0);
    REP(i, k) cin >> p[i];
    int next = 1, idx = 0;
    while(idx < k) {
    	if(s.empty()) {
    		done[p[idx]] = 1;
    		++d;
    		s.push(p[idx++]);
    	} else if(p[idx] > s.top()) {
    		cout << -1 << endl;
    		exit(0);
    	} else {
    		done[p[idx]] = 1;
    		++d;
    		s.push(p[idx++]);
    	}
    	while(!s.empty() && s.top() == next) {
    		b.push_back(next++);
    		s.pop();
    	}
    }
    // DEBUG(d);
    while(!s.empty()) {
    	int cur = s.top();
    	FORD(i, cur-1, next) {
    		p[k++] = i;
    		done[i] = 1;
    		++d;
    	}
    	next = cur;
    	while(done[next]) ++next;
    	s.pop();
    }
    // DEBUG(d);
    FORD(i, n, 1) {
    	if(!done[i]) {
    		p[k++] = i;
    	}
    }
    REP(i, n) cout << p[i] << ' ';
    cout << endl;

    return 0;
}