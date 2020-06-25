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

void no() {
	cout << "NO" << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    cin >> s;
    int n = s.size();
    int idx = 0, a, b, c;
    while(idx < n) {
    	if(s[idx] != 'a') break;
    	++idx;
    }
    if(idx == 0) no();
    a = idx;
    while(idx < n) {
    	if(s[idx] == 'a') no();
    	if(s[idx] != 'b') break;
    	++idx;
    }
    b = idx-a;
    if(b == 0) no();
    while(idx < n) {
    	if(s[idx] == 'a' || s[idx] == 'b') no();
    	++idx;
    }
    c = idx-(a+b);
    if(c != a && c != b) no();
    cout << "YES" << endl;

    return 0;
}