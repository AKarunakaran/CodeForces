#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;

int n, a[N], sieve[N];
vector<int> primes;
set<int> s;

void erastosthenes() {
    FOR(i, 2, 2e5) {
        if(!sieve[i]) {
            primes.push_back(i);
            for(int j = i; j <= 2e5; j += i) {
                sieve[j] = i;
            }
        }
    }
}

void update(pii& p, int x) {
    if(x < p.first) {
        p.second = p.first;
        p.first = x;
    } else if(x < p.second) {
        p.second = x;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    erastosthenes();
    cin >> n;
    REP(i, n) {
        cin >> a[i];
        int x = a[i];
        while(x != 1) {
            s.insert(sieve[x]);
            x /= sieve[x];
        }
    }
    int ans = 1;
    for(int p : s) {
        pii mn = {2*N, 2*N};
        REP(i, n) {
            int cnt = 0;
            while(a[i] % p == 0) {
                a[i] /= p;
                ++cnt;
            }
            update(mn, cnt);
            if(mn == (pii){0, 0}) break;
        }
        REP(i, mn.second) ans *= p;
    }
    
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
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
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
