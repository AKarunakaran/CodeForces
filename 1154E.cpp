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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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

const int N = 2e5+10;
int n, k, a[N], ans[N];
list<pii> lst;
map<int, list<pii>::iterator> m;
map<int, int> mid;

void print() {
    for(auto& p : lst) cout << p.first << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        lst.push_back({a[i], i});
        auto itr = lst.end();
        --itr;
        m[a[i]] = itr;
        mid[a[i]] = i;
    }

    int team = 1;
    FORD(cur, n, 1) {
    	int id = mid[cur];
    	if(ans[id]) continue;
        // print();
    	auto itr = m[cur];
        int cnt;

        // forward k
        cnt = 0;
        auto temp = itr;
        ++temp;
        while(temp != lst.end() && cnt < k) {
            ans[temp->second] = team;
            lst.erase(temp);
            temp = itr;
            ++temp;
            ++cnt;
        }

        // backward k
        if(itr != lst.begin()) {
            cnt = 0;
            temp = itr;
            --temp;
            while(cnt < k) {
                ans[temp->second] = team;
                lst.erase(temp);
                if(itr == lst.begin()) break;
                temp = itr;
                --temp;
                ++cnt;
            }
        }

        ans[id] = team;
        lst.erase(itr);

    	team = 3-team;
    }
    // print();
    FOR(i, 1, n) cout << ans[i];
    cout << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

