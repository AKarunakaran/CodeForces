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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int idx = 0, i = 1;
    while(1) {
    	while(i < n && a[i] < a[idx]) ++i;
    	if(i == n) {
    		cout << a[idx] << endl;
    		exit(0);
    	}
    	if(idx == 0) {
    		if(i-idx-1 >= k) {
    			cout << a[idx] << endl;
    			exit(0);
    		}
    	} else {
    		if(i-idx >= k) {
    			cout << a[idx] << endl;
    			exit(0);
    		}
    	}
    	idx = i;
    	i++;
    }

    return 0;
}