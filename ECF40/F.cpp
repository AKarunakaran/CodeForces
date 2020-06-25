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

void mod(vector<vector<ll>>& mat, ll M) {
	REP(i, mat.size()) {
		REP(j, mat[i].size()) {
			mat[i][j] %= M;
		}
	}
}

void mod(vector<ll>& mat, ll M) {
	REP(i, mat.size()) {
		mat[i] %= M;
	}
}

vector<ll> mult(vector<vector<ll>>& mat, vector<ll>& v) {
	vector<ll> newV(v.size(), 0);
	REP(i, v.size()) {
		REP(j, mat[i].size()) {
			v[i] += mat[i][j]*v[j];
		}
	}
	return newV;
}

vector<vector<ll>> mult(vector<vector<ll>>& m1, vector<vector<ll>>& m2) {
	DEBUG(m1.size());
	DEBUG(m1[0].size());
	DEBUG(m2.size());
	DEBUG(m2[0].size());
	vector<vector<ll>> resM(m1.size(), vector<ll>(m2[0].size(), 0));
	REP(i, m1.size()) {
		REP(j, m2[0].size()) {
			DEBUG(i);
			DEBUG(j);
			REP(k, m2.size()) {
				resM[i][j] += m1[i][k]*m2[k][j];
			}
			DEBUG(resM[i][j]);
		}
	}
	return resM;
}

const ll M = 1e9+7;

vector<vector<ll>> fastMatrixPowMod(vector<vector<ll>>& base, ll power) {
    vector<vector<ll>> res(3, vector<ll>(3, 0));
    res[0][0] = res[1][1] = res[2][2] = 1;
    while(power) {
    	DEBUG(power);
        if(power & 1) {
        	res = mult(res, base);
        	mod(res, M);
        }
        base = mult(base, base);
        mod(base, M);
        power >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll n, m;
    cin >> n >> m;
    vector<ll> pos = {1, 0, 0};
    vector<vector<ll>> mat[8];
    mat[0] = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    mat[1] = {{0, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    mat[2] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    mat[4] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 0}};
    mat[3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    mat[5] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    mat[6] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    mat[7] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    vector<pll> obsBegin(n), obsEnd(n);
    REP(i, m) {
    	cin >> obsBegin[i].second >> obsBegin[i].first >> obsEnd[i].first;
    	obsEnd[i].second = obsBegin[i].second;
    }
    sort(obsBegin.begin(), obsBegin.end());
    sort(obsEnd.begin(), obsEnd.end());
    ll curObs = 0, curX = 1, obsBIdx = 0, obsEIdx = 0;
    while(curX < m) {
    	cerr << "{" << pos[0] << ", " << pos[1] << ", " << pos[2] << "}" << endl;
    	DEBUG(curObs);
    	DEBUG(curX);
    	ll next, nextObs = curObs;
    	if(obsEIdx == n && obsBIdx == n) {
    		next = m;
    	} else {
    		if(obsEIdx == n) next = obsEnd[obsEIdx].first;
    		else if(obsBIdx == n) next = obsBegin[obsBIdx].first;
    		else if(obsEnd[obsEIdx].first <= obsBegin[obsBIdx].first) next = obsEnd[obsEIdx].first;
    		else next = obsBegin[obsBIdx].first;

    		while(obsEIdx < n && obsEnd[obsEIdx].first == next) {
    			nextObs = nextObs & ~(1 << (obsEnd[obsEIdx].second-1));
    			obsEIdx++;
    		}
    		while(obsBIdx < n && obsBegin[obsBIdx].first == next) {
    			nextObs = nextObs | (1 << (obsBegin[obsBIdx].second-1));
    			obsBIdx++;
    		}
    	}
    	DEBUG(next);
    	ll p = next-curX;
    	vector<vector<ll>> step;
    	DEBUG(nextObs);
    	step = fastMatrixPowMod(mat[curObs], p);
    	DEBUG("T1");
    	pos = mult(step, pos);
    	DEBUG("T2");
    	mod(pos, M);
    	DEBUG("T3");
    	curX = next;
    	curObs = nextObs;
    }
    ll ans = (pos[0]+pos[1]+pos[2]) % M;
    cout << ans << endl;

    return 0;
}