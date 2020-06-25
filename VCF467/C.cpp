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
typedef long double ld;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(1);
    ull k, d, t;
    cin >> k >> d >> t;
    ld eps = 1e-5;
    ld checksUntilOffD = k/(ld)d;
    ull checksUntilOff = (ceil(checksUntilOffD) != ceil(checksUntilOffD - eps)) ? round(checksUntilOffD) : ceil(checksUntilOffD);
    ull totalPeriodTime = d*checksUntilOff;
    ull periodMiss = totalPeriodTime-k;
    ld periodCookAmt = k + 0.5*(ld)periodMiss;
    ld totalPeriodsD = t/(ld)periodCookAmt;
    ull totalPeriods = (floor(totalPeriodsD) != floor(totalPeriodsD + eps)) ? round(totalPeriodsD) : floor(totalPeriodsD);
    ld totalPeriodCookAmt = totalPeriods*periodCookAmt;
    ld cookingLeft = t-totalPeriodCookAmt;
    ld extraCookingTime = min((ld) k, cookingLeft);
    ld newCookingLeft = cookingLeft - extraCookingTime;
    ld extraNonCookingTime = newCookingLeft*2;
    ld ans = totalPeriods*totalPeriodTime+extraCookingTime+extraNonCookingTime;

    // DEBUG(totalPeriodTime);
    // DEBUG(periodMiss);
    // DEBUG(periodCookAmt);
    // DEBUG(totalPeriods);
    // DEBUG(totalPeriodCookAmt);

    cout << ans << endl;

    return 0;
}