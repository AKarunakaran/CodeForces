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
typedef pair<int, char> pic;

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    cin >> s;
    list<pci> g;
    int prev = 0;
    FOR(i, 1, s.size()-1) {
        if(s[i] != s[i-1]) {
            g.push_back({s[i-1], i-prev});
            prev = i;
        }
    }
    g.push_back({s.back(), s.size()-prev});
    int ans = 0;
    while(g.size() > 1) {
        ++ans;
        auto next = g.begin();
        ++next;
        for(auto itr = g.begin(); itr != g.end(); ) {
            // DEBUG(itr->second);
            if(itr == g.begin() || next == g.end()) itr->second -= 1;
            else itr->second -= 2;
            if(itr->second <= 0) {
                auto temp = itr++;
                g.erase(temp);
            } else ++itr;
            if(next != g.end()) ++next;
        }
        next = g.begin();
        ++next;
        for(auto itr = g.begin(); itr != g.end(); ) {
            if(itr->first == next->first) {
                itr->second += next->second;
                g.erase(next);
                next = itr;
            } else {
                ++itr;
            }
            if(next != g.end()) ++next;
        }
    }
    cout << ans << endl;

    return 0;
}