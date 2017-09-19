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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int s = 0;
vector<vector<int>> g;
vector<int> val;
int sol = -1, root;

bool dfs(int src) {
	bool flag = false;
	REP(i, g[src].size()) {
		flag = dfs(g[src][i]) || flag;
		val[src] += val[g[src][i]];
	}
	if(src != root) {
		if(flag && val[src] == 2*s) {
			printf("%d %d\n", src+1, sol+1);
			exit(0);
		}
		if(!flag && val[src] == s) {
			if(sol != -1) {
				printf("%d %d\n", src+1, sol+1);
				exit(0);
			} else {
				flag = true;
				sol = src;
			}
		}
	}
	return flag;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    scanf("%d", &n);
    g.resize(n);
    val.resize(n);
    REP(i, n) {
    	int d, v;
    	scanf("%d %d", &d, &v);
    	val[i] = v;
    	s += v;
    	--d;
    	if(d != -1) g[d].push_back(i);
    	else root = i;
    }

    if(s % 3) {
    	printf("-1\n");
    	return 0;
    }

    s /= 3;

    dfs(root);
    printf("-1\n");

    return 0;
}