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
    string s;
    cin >> s;
    bool found = false;
    REP(i, s.size()) {
    	if(s.substr(i, 5) == "Danil" || s.substr(i, 5) == "Slava") {
    		if(found) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    		found = true;
    	}
    	if(s.substr(i, 4) == "Olya") {
    		if(found) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    		found = true;
    	}
    	if(s.substr(i, 3) == "Ann") {
    		if(found) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    		found = true;
    	}
    	if(s.substr(i, 6) == "Nikita") {
    		if(found) {
    			cout << "NO" << endl;
    			exit(0);
    		}
    		found = true;
    	}
    }

    cout << (found ? "YES" : "NO") << endl;
    return 0;
}