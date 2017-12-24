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
    int n;
    cin >> n;
    int p = (n % 4) + 1;
    switch(n % 4) {
    	case 0:
    		cout << 0 << endl << n/2 << " ";
    		break;
    	case 1:
    		cout << 1 << endl << (n-1)/2 + 1 << " 1 ";
    		break;
    	case 2:
    		cout << 1 << endl << (n-2)/2 + 1 << " 1 ";
    		break;
    	case 3:
    		cout << 0 << endl << (n-3)/2 + 2 << " 1 2 ";
    		break;
    }
    for(int i = p; i < n+p-i; i += 2) cout << i << " " << n+p-i << " ";
	cout << endl;

    return 0;
}