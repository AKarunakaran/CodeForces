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
#include <unordered_map>
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
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    int n = s.size();
    double ans = 0;
    vector<vector<string>> letstr(26);
    REP(i, n) {
        letstr[s[0]-'a'].push_back(s);
        rotate(s.begin(), s.begin()+1, s.end());
    }
    REP(i, 26) {
        double p = 0;
        FOR(j, 1, n-1) {
            vector<int> freq(26, 0);
            int good = 0;
            for(string& str : letstr[i]) {
                ++freq[str[j]-'a'];
                if(freq[str[j]-'a'] == 1) ++good;
                if(freq[str[j]-'a'] == 2) --good;
            }
            p = max(p, good/(double) n);
        }
        ans += p;
    }
    cout << ans << endl;

    return 0;
}