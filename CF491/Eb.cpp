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

vector<int> f(10, 0);
set<string> s;
string cur;
int have = 0;

void rec(int now) {
	if(now == have) s.insert(cur);
	FOR(i, 0, 9) {
		if(f[i]) {
			--f[i];
			cur.push_back(i+'0');
			rec(now | (1 << i));
			cur.pop_back();
			++f[i];
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string str;
    cin >> str;
    REP(i, str.size()) {
    	f[str[i]-'0']++;
    	have |= (1 << (str[i]-'0'));
    }
    FOR(i, 1, 9) {
    	if(f[i]) {
    		--f[i];
			cur.push_back(i+'0');
			rec(1 << i);
			cur.pop_back();
			++f[i];
    	}
    }
    cout << s.size() << endl;

    return 0;
}