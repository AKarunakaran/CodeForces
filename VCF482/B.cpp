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
    ll n, k;
    cin >> n;
    string s[3];
    REP(i, 3) cin >> s[i];
    k = s[0].size();
    ll score[3];
    map<char, ll> m[3];
    fill(score, score+3, 0);
    REP(p, 3) {
    	REP(i, k) ++m[p][s[p][i]];
    	for(auto pr : m[p]) {
    		if(pr.second == k && n == 1) {
    			score[p] = k-1;
    			break;
    		}
    		score[p] = max(score[p], min(k, pr.second+n));
    	}
    }
    if(score[0] > score[1] && score[0] > score[2]) cout << "Kuro" << endl;
    else if(score[1] > score[0] && score[1] > score[2]) cout << "Shiro" << endl;
    else if(score[2] > score[1] && score[2] > score[0]) cout << "Katie" << endl;
    else cout << "Draw" << endl;

    return 0;
}