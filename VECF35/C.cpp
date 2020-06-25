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

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    // int c = ((gcd(k1, k2) == 1) << 2) + ((gcd(k1, k3) == 1) << 1) + ((gcd(k3, k2) == 1) << 0);
    // if(c == 0) {
    // 	//
    // } else if(c == 1) {
    // 	//
    // } else if(c == 2) {
    // 	//
    // } else if(c == 3) {
    // 	//
    // } else if(c == 4) {
    // 	//
    // } else if(c == 5) {
    // 	//
    // } else if(c == 6) {
    // 	//
    // } else {
    // 	cout << "NO" << endl;
    // }
    vector<ll> k = {k1, k2, k3};
    sort(k.begin(), k.end());
    if(k[0] == 1) {
    	cout << "YES" << endl;
    } else if(k[0] == 2 && k[1] == 4 && k[2] == 4) {
    	cout << "YES" << endl;
    } else if(k[0] == 2 && k[1] == 2) {
    	cout << "YES" << endl;
    } else if(k[0] == 3 && k[1] == 3 && k[2] == 3) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }

    return 0;
}