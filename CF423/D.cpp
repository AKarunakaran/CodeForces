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

int minTree(int start, int end, int ex) {
	//DEBUG(start);
	//DEBUG(end);
	//DEBUG(ex);
	if(start == end) return start;
	int center = start;
	int nodesNC = end-start;
	int d = nodesNC/ex;
	int r = nodesNC % ex;
	int curS = start+1;
	REP(i, ex-r) {
		int nextC = minTree(curS, curS+d-1, 1);
		cout << center << " " << nextC << endl;
		curS += d;
	}
	REP(i, r) {
		int nextC = minTree(curS, curS+d, 1);
		cout << center << " " << nextC << endl;
		curS += d+1;
	}

	return center;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if((n-1)%k == 0) {
    	cout << 2*((n-1)/k) << endl;
    } else if((n-1)%k == 1) {
    	cout << (2*((n-1)/k))+1 << endl;
    } else {
    	cout << (2*((n-1)/k))+2 << endl;
    }
    minTree(1, n, k);


    return 0;
}