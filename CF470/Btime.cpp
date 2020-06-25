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

int solve(int x) {
    vector<bool> prime(1e6+1, 1);
    vector<int> p;
    for(int i = 2; i <= 1e6; ++i) {
        if(prime[i]) {
            p.push_back(i);
            for(int j= 2*i; j <= 1e6; j += i) {
                prime[j] = 0;
            }
        }
    }
    // cout << p.size() << endl;
    int l;
    FORD(i, p.size()-1, 0) {
        if(x % p[i] == 0) {
            l = x - p[i]+1;
            break;
        }
    }
    // DEBUG(l);
    int ans = INF;
    // REP(i, p.size()) {
    //  if(2*p[i]+1 >= l) {
    //      cout << p[i]+1 << endl;
    //      exit(0);
    //  }
    // }
    FOR(i, l, min(x, (int)floor(l+2*log2(x)))) {
        FORD(j, p.size()-1, 0) {
            if(i % p[j] == 0 && i != p[j]) {
                ans = min(ans, i-p[j]+1);
                // DEBUG(i);
                // DEBUG(p[j]);
                // DEBUG(ans);
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    srand(time(NULL));
    int s = 100;
    while(s--) {
        int x = (rand() % 1000000)+1;
        clock_t begin = clock();
        solve(x);
        clock_t end = clock();
        double t = (end-begin)/CLOCKS_PER_SEC;
            cout << x << " ";
        if(t > 1.5) {
            cout << "bad" << endl;
        } else {
            cout << "good" << endl;
        }
    }

    return 0;
}