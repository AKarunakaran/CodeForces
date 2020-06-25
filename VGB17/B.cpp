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

string seq;
vector<vector<bool>> g;
vector<int> d(4);
int n, m;
pii s, e;

bool run() {
	pii pos = s;
	REP(i, seq.size()) {
		switch(d[seq[i]-'0']) {
			case 4:
				--pos.first;
				break;
			case 1:
				++pos.first;
				break;
			case 2:
				--pos.second;
				break;
			case 3:
				++pos.second;
				break;
		}
		if(pos == e) return true;
		if(pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m || !g[pos.first][pos.second]) return false;
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    g.resize(n, vector<bool> (m));
    REP(i, n) {
    	REP(j, m) {
    		char c;
    		cin >> c;
    		if(c == 'S') s = {i, j};
    		if(c == 'E') e = {i, j};
    		g[i][j] = (c != '#');
    	}
    }
    cin >> seq;
    iota(d.begin(), d.end(), 1);
    int ans = 0;
    do {
    	if(run()) ++ans;
    } while(next_permutation(d.begin(), d.end()));
    cout << ans << endl;

    return 0;
}