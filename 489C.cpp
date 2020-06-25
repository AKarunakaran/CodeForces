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

string big(int m, int s) {
	return m == 1 ? to_string(s) : to_string(min(9, s)) + big(m-1, s-min(9, s));
}

string small(int m, int s) {
	string str = big(m, s);
	reverse(str.begin(), str.end());
	if(str[0] == '0') {
		REP(i, str.size()) {
			if(str[i] != '0') {
				--str[i], ++str[0];
				break;
			}
		}
	}
	return str;
}


int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int m, s;
    cin >> m >> s;
    if(s == 0 && m == 1) cout << "0 0" << endl;
    else if(s == 0 || s > 9*m) cout << "-1 -1" << endl;
    else cout << small(m, s) << ' ' << big(m, s) << endl;

    return 0;
}