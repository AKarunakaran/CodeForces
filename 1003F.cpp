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

const int N = 300;
int n, w = 1, ans = INF, tot;
pii a[N];
string s[N];
map<string, int> m;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    tot = n-1;
    REP(i, n) {
    	cin >> s[i];
    	if(m[s[i]] == 0) m[s[i]] = w++;
    	tot += s[i].size();
    }
    REP(i, n) a[i] = {m[s[i]], s[i].size()};
    FOR(i, 0, n-1) {
    	FOR(j, i+1, n-1) {
    		int len = min(j-i, n-j);
    		int sum = 0, num = len;
    		REP(k, len) {
    			if(a[i+k].first != a[j+k].first) {
    				num = k;
    				break;
    			}
    			sum += a[i+k].second;
    		}
    		int shorten = sum+max(0, num-1)-num;
    		// DEBUG(i);
    		// DEBUG(j);
    		// DEBUG(sum);
    		// DEBUG(num);
    		// DEBUG(shorten);
    		// cout << endl;
    		ans = min(ans, tot-2*shorten);
    	}
    }
    cout << ans << endl;

    return 0;
}