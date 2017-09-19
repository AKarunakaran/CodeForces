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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<pii> p(n);
    REP(i, n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int cur = 1;
    int l = p[0].first, lid = 0;
    FOR(i, 1, n-1) {
        if(cur > 2) {
            cout << "NO" << endl;
            exit(0);
        }
        if(p[i].first <= p[lid].second) ++cur;
        else {
            while(p[i].first > p[lid].second) {
                ++lid;
                --cur;
            }
        }
    }
    if(cur > 2) {
        cout << "NO" << endl;
        exit(0);
    }
    cout << "YES" << endl;

    return 0;
}