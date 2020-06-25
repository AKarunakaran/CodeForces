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
    set<ll> a;
    int n;
    cin >> n;
    REP(i,n) {
    	int num;
    	cin >> num;
    	a.insert(num);
    }
    cin >> k;
    a.insert(1);
    while(a.size() < k) {
    	for(auto i = a.begin(); i != a.end(); ++i) {
    		for(auto j = a.begin(); j != i; ++j) {
    			// if()
    		}
    	}
    }
    int kt = 1;
    for(auto itr = a.begin(); itr != a.end(); ++itr, ++kt) {
    	if(kt == k) {
    		cout << *itr << endl;
    		break;
    	}
    }

    return 0;
}