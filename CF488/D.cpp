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

const int N = 12;
int n, m, d1[N], d2[N];
pii s1[N], s2[N];
vector<pii> e;
set<int> poss, posse[2][N];

void bad() {
	cout << -1 << endl;
	exit(0);
}

bool match(pii x1, pii x2) {
	if(x1.first == x2.first && x1.second == x2.second) return false;
	if(x1.first == x2.second && x1.second == x2.first) return false;
	if(x1.first != x2.first && x1.second != x2.second && x1.first != x2.second && x1.second != x2.first) return false;
	return true;
}

int findmatch(int i1, int i2) {
	pii x1 = s1[i1], x2 = s2[i2];
	if(x1.first == x2.first) return x1.first;
	if(x1.first == x2.second) return x1.first;
	return x1.second;
}

void checkall(pii x1, pii x2) {
	cout << match(x1, x2) << ' ';
	swap(x2.first, x2.second);
	cout << match(x1, x2) << ' ';
	swap(x1.first, x1.second);
	cout << match(x1, x2) << ' ';
	swap(x2.first, x2.second);
	cout << match(x1, x2) << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    // pii x1 = {0, 1}, x2 = {0, 2};
    // checkall(x1, x2);
    // x1 = {0, 1}, x2 = {0, 1};
    // checkall(x1, x2);
    // x1 = {0, 1}, x2 = {1, 2};
    // checkall(x1, x2);
    // x1 = {0, 1}, x2 = {3, 2};
    // checkall(x1, x2);
    fill(d1, d1+N, 0);
    fill(d2, d2+N, 0);
    cin >> n >> m;
    REP(i, n) cin >> s1[i].first >> s1[i].second;
    REP(i, m) cin >> s2[i].first >> s2[i].second;
    REP(i, n) {
    	REP(j, m) {
    		if(match(s1[i], s2[j])) {
    			// DEBUG(i);
    			// DEBUG(j);
    			poss.insert(findmatch(i, j));
    			e.push_back({i, j});
    			++d1[i];
    			++d2[j];
    			posse[0][i].insert(findmatch(i, j));
    			posse[1][j].insert(findmatch(i, j));
    		}
    	}
    }
    if(poss.size() == 1) {
    	cout << *poss.begin() << endl;
    	exit(0);
    }
    REP(i, n) if(posse[0][i].size() > 1) bad();
    REP(i, m) if(posse[1][i].size() > 1) bad();
    cout << 0 << endl;

    return 0;
}