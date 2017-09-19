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
    int n, need, dub;
    cin >> n;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    vector<int> freqA(n+1, 0);
    vector<int> freqB(n+1, 0);
    REP(i, n) {
    	++freqA[a[i]];
    	++freqB[b[i]];
    }
    FOR(i, 1, n) {
    	if(freqA[i] == 0) {
    		need = i;
    		break;
    	}
    }
    REP(i, n) {
    	if(freqA[a[i]] == 2 && b[i] == need) {
    		a[i] = need;
    		break;
    	} else if(freqA[a[i]] == 2 && freqB[b[i]] == 2) {
    		a[i] = need;
    		break;
    	}
    }
    REP(i, n) cout << a[i] << " ";
    cout << endl;

    return 0;
}