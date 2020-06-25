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
string s;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> s;
    int n = s.size();
    int open, close, q, ans = 0;
    REP(i, n) {
        open = 0, close = 0, q = 0;
        FOR(j, i, n-1) {
            if(s[j] == '(') ++open;
            else if(s[j] == ')') ++close;
            else {
                ++close;
                ++q;
            }
            if(close > open) {
                if(q) {
                    --q;
                    ++open;
                    --close;
                } else break;
            }
            if((i-j+1) % 2 == 0 && open == close) {
                // DEBUG(i);
                // DEBUG(j);
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}