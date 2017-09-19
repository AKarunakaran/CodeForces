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
    int n, A;
    cin >> n >> A;
    vector<int> c(n);
    vector<int> cntA(n, 0);
    int maxC = A;
    REP(i, n) {
    	cin >> c[i];
    	maxC = max(maxC, c[i]);
    }
    cntA[0] = (c[0] == A);
    FOR(i, 1, n-1) cntA[i] = cntA[i-1]+(c[i] == A);
    int maxA = cntA.back();
    vector<set<int>> s(maxA+1);
    int low;
    FOR(i, 1, maxC) {
    	if(i == A) continue;
    	s[0].insert(i);
    }
    REP(j, n) {
    	low = cntA[j];
    	int cur = c[j];
    	int maxS = 0;
    	FOR(i, low, maxA) {
    		if(s[i].size() == 0) continue;
    		maxS = s[i].size();
    		if(s[i].find(cur) != s[i].end()) {
    			if(i+1 >= maxA) {
    				cout << cur << endl;
    				return 0;
    			}
    			s[i].erase(cur);
    			s[i+1].insert(cur);
    			break;
    		}
    	}
    	if(maxS == 0) {
    		cout << -1 << endl;
    		return 0;
    	}
    }
    cout << *(s[low].begin()) << endl;

    return 0;
}