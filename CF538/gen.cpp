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
#include <ctime>
#include <cstdlib>
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

// [l, r]
int randrange(int l, int r) { return (rand() % (r-l+1)) + l; }

int n, lo, d;
vector<int> a;

pii read_query() {
    char c;
    int x, y;
    cin >> c >> x;
    if(c == '!') {
        cin >> y;
        if(x == lo && y == d) cout << "Good" << endl;
        else cout << "Bad" << endl;
        exit(0);
    }
    if(c == '?') return {0, x};
    else return {1, x};
}

void answer_query(int i) {
    cout << a[i] << endl;
}

void answer_greater(int x) {
    cout << !(upper_bound(a.begin(), a.end(), x) == a.end()) << endl;
}

int main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    n = 1e6;
    lo = randrange(1, 10000), d = randrange(1, 100);
    a.resize(n);
    REP(i, n) a[i] = lo+d*i;
    random_shuffle(a.begin(), a.end());
    cout << n << endl;
    int l = 0, r = 1e9;
    REP(i, 30) {
        l = max(l, a[i]);
        cout << a[i] << ' ';
    }
    sort(a.begin(), a.end());
    while(l < r) {
        int m = (l+r)/2;
        if(a.back() > m) {
            l = m+1;
            cout << 1 << endl;
        } else {
            r = m;
            cout << 0 << endl;
        }
    }

    DEBUG(lo);
    DEBUG(d);
    // while(1) {
    //     pii q = read_query();
    //     if(q.first == 0) answer_query(q.second);
    //     else answer_greater(q.second);
    // }

    return 0;
}