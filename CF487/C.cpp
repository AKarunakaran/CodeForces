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
vector<vector<char>> ans(12, vector<char>(50, '.'));

int row = 12;

bool border(int r, int c, char ch) {
	if(r > 0 && ans[r-1][c] == ch) return true;
	if(r < row-1 && ans[r+1][c] == ch) return true;
	if(c > 0 && ans[r][c-1] == ch) return true;
	if(c < 49 && ans[r][c+1] == ch) return true;
	return false;
}

void print() {
	REP(i, 12) {
    	REP(j, 50) cout << ans[i][j];
    	cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    pair<int, char> v[4];
    REP(i, 4) v[i].second = 'A'+i;
    REP(i, 4) cin >> v[i].first;
    // sort(v, v+4);
    REP(i, 4) {
    	REP(j, 50) ans[3*i+1][j] = 'A'+i;
    	v[i].first--;
    }
    // print();
    REP(i, 12) {
    	REP(j, 50) {
    		if(ans[i][j] == '.') {
    			bool placed = false;
    			REP(k, 4) {
    				// DEBUG(i);
    				// DEBUG(j);
    				// DEBUG(v[k].first);
    				// DEBUG(v[k].second);
    				if(v[k].first && !border(i, j, v[k].second)) {
    					placed = true;
    					ans[i][j] = v[k].second;
    					--v[k].first;
    					break;
    				}
    			}
    			if(!placed) {
    				if(i % 3 == 0) {
    					ans[i][j] = ans[i+1][j];
    					if(i && ans[i-1][j] == ans[i][j]) {
    						++v[ans[i][j]-'A'].first;
    						// DEBUG(i);
    						// DEBUG(j);
    					}
    				} else ans[i][j] = ans[i-1][j];
    			}
    		}
    	}
    }
    int row = 12;
    vector<char> newr(50);
    if(v[0].first || v[1].first || v[2].first || v[3].first) {
    	++row;
    	REP(i, 50) {
    		bool placed = false;
    		REP(j, 4) {
    			if(v[j].first && ans[0][i] != v[j].second) {
    				newr[i] = v[j].second;
    				--v[j].first;
    				placed = true;
    				break;
    			}
    		}
    		if(!placed) newr[i] = ans[0][i];
    	}
    }
    cout << row << " 50" << endl;
    if(row == 13) {
    	REP(i, 50) cout << newr[i];
    	cout << endl;
    }
    print();

    return 0;
}