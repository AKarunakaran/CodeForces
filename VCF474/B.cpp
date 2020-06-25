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
    int n, k, k1, k2;
    cin >> n >> k1 >> k2;
    k = k1+k2;
    vector<ll> a(n), b(n);
    REP(i,n ) cin >> a[i];
    REP(i,n ) cin >> b[i];
    priority_queue<ll> pq;
    REP(i, n) pq.push(abs(a[i]-b[i]));
    while(k && pq.top()) {
    	int cur = pq.top();
        // DEBUG(k);
        // DEBUG(cur);
    	pq.pop();
    	pq.push(cur-1);
    	--k;
    }
    ll ans = k & 1;
    while(!pq.empty()) {
    	ans += pq.top()*pq.top();
    	pq.pop();
    }
    cout << ans << endl;

    return 0;
}