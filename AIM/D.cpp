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
#include <cstdlib>
#include <ctime>
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
    srand(time(NULL));
    vector<pii> val;
    bool checked[50001] = {};
    int n, st, x, v, nxt;
    cin >> n >> st >> x;
    cout << "? " << st << endl;
    cin >> v >> nxt;
    val.push_back({v, nxt});
    nxt = st;
    checked[st] = 1;
    REP(i, 999) {
    	if(i+1 >= n) break;
    	while(checked[nxt]) nxt = (rand() % num) + 1;
    	cout << "? " << nxt << endl;
    	cin >> v >> nxt;
    	val.push_back({v, nxt});
    }
    sort(val.begin(), val.end());
    int high = lower_bound(val.begin(), val.end(), {x, -2})-val.begin();
    int low = high-1;
    REP(i, 999) {
    	//
    }

    return 0;
}