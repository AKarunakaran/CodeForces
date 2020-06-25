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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/////////////////////////////////////////////////////////////////////

const int N = 200001;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    //cout << fixed << setprecision(7);
    int n, q;
    unsigned char a[N];
    scanf("%d", &n);
    REP(i, n) scanf("%hhu", a+i+1);
    scanf("%d", &q);
    REP(i, q) {
    	int l, r;
    	unsigned char x, y;
    	scanf("%d %d %hhu %hhu", &l, &r, &x, &y);
    	FOR(j, l, r) a[j] = (a[j] == x ? y : a[j]);
    }
    REP(i, n) printf("%hhu ", a[i+1]);
    printf("\n");

    return 0;
}