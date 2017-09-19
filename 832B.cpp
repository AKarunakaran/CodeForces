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

void good() {
	cout << "YES" << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    vector<vector<char>> b(10, vector<char>(10));
    REP(i, 10) REP(j, 10) cin >> b[i][j];
    REP(i, 10) {
    	REP(j, 6) {
            int cnt = 0;
            bool nc = true;
            REP(k, 5) {
                if(b[i][j+k] == 'O') nc = false;
                cnt += (b[i][j+k] == 'X');
            }
            if(cnt == 4 && nc) good();
    	}
    }
    REP(i, 6) {
        REP(j, 10) {
            int cnt = 0;
            bool nc = true;
            REP(k, 5) {
                if(b[i+k][j] == 'O') nc = false;
                cnt += (b[i+k][j] == 'X');
            }
            if(cnt == 4 && nc) good();
        }
    }
    REP(i, 6) {
        REP(j, 6) {
            int cnt = 0;
            bool nc = true;
            REP(k, 5) {
                if(b[i+k][j+k] == 'O') nc = false;
                cnt += (b[i+k][j+k] == 'X');
            }
            if(cnt == 4 && nc) good();
        }
    }
    REP(i, 6) {
        FOR(j, 4, 9) {
            int cnt = 0;
            bool nc = true;
            REP(k, 5) {
                if(b[i+k][j-k] == 'O') nc = false;
                cnt += (b[i+k][j-k] == 'X');
            }
            if(cnt == 4 && nc) good();
        }
    }
    cout << "NO" << endl;

    return 0;
}