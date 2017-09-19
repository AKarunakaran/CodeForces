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
#include <unordered_map>
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

int n, m;

int getNum(int r, int c) {
	return (r-1)*m + c;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int k, r, c;
    cin >> n >> m >> k;
    vector<vector<int>> g(k+1, vector<int>(k+1, -1));
    vector<vector<bool>> lit(n, vector<bool>(m, 0));
    unordered_map<int, int> index;
    cout << endl;
    REP(i, k) {
    	cin >> r >> c;
    	index[getNum(r, c)] = i;
    	lit[r-1][c-1] = 1;
    }
    lit[n-1][m-1] = 1;
    index[getNum(n, m)] = k;
    ++k;
    REP(i, n) {
    	REP(j, m) {
    		//DEBUG(i);
    		//DEBUG(j);
    		if(lit[i][j]) {
    			int idx1 = index[getNum(i+1, j+1)];
    			REP(a, n) {
    				if(a == i) continue;
					if(lit[a][j]) {
						int idx2 = index[getNum(a+1, j+1)];
						g[idx1][idx2] = (abs(a-i) == 1) ? 0 : 1;
					}
    			}
    			REP(a, m) {
    				if(a == j) continue;
					if(lit[i][a]) {
						int idx2 = index[getNum(i+1, a+1)];
						g[idx1][idx2] = (abs(a-j) == 1) ? 0 : 1;
					}
    			}
    		}
    	}
    }
    REP(i, k) {
    	REP(j, k) cout << g[i][j] << " ";
    	cout << endl;
    }
    int begin = index[getNum(1, 1)];
    int end = index[getNum(n, m)];
    vector<bool> checked(k, 0);
    vector<int> dist(k, INF);
    int cur = begin;
    cout << getNum(1, 1) << " " << getNum(n, m) << endl;
    cout << begin << " " << end << endl;
    dist[begin] = 0;
    while(cur != end) {
    	DEBUG(cur);
    	checked[cur] = 1;
    	REP(i, k) {
    		if(g[cur][i] != -1 && !checked[i]) {
    			dist[i] = min(dist[i], dist[cur]+g[cur][i]);
    		}
    	}
    	int i = 0;
    	while(checked[i]) ++i;
    	cur = i;
    	while(i < k) {
    		if(!checked[i] && dist[i] < dist[cur]) {
    			cur = i;
    		}
    		++i;
    	}
    }
    cout << ((dist[end] == INF) ? -1 : dist[end]) << endl;

    return 0;
}