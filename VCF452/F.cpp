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

vector<int> bit;
int n;

int getSum(int index) {
	int sum = 0;
	++index;
	while(index > 0) {
		sum += bit[index];
		index -= (index & -index);
	}
	return sum;
}

void update(int index) {
	++index;
	while(index <= n) {
		bit[index] += 1;
		index += (index & -index);
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int m;
    string s;
    cin >> n >> m >> s;
    map<char, set<int>> idxs;
    bit.resize(n+1, 0);
    REP(i, n) idxs[s[i]].insert(i);
    REP(qu, m) {
        // REP(i, n) cout << getSum(i)-getSum(i-1) << " ";
        // cout << endl;
    	int l, r;
    	char c;
    	string in;
    	cin >> l >> r >> in;
    	--l; --r; c = in[0];
        int adjl = 0, adjr = n-1;
        while(adjl < adjr) {
            int mid = (adjl+adjr)/2;
            if(mid-getSum(mid) >= l) adjr = mid;
            else adjl = mid+1;
        }
        l = adjr; adjl = 0, adjr = n-1;
        while(adjl < adjr) {
            int mid = (adjl+adjr)/2;
            if(mid-getSum(mid) >= r) adjr = mid;
            else adjl = mid+1;
        }
        r = adjr;
    	int num = 0, f;
    	auto& sIdx = idxs[c];
    	// DEBUG(qu);
    	// DEBUG(l);
    	// DEBUG(r);
        auto itr = sIdx.lower_bound(l);
    	while(itr != sIdx.end() && *itr <= r) {
            f = *itr;
    		// DEBUG(f);
    		++num;
    		update(f);
            sIdx.erase(f);
            itr = sIdx.lower_bound(l);
    	}
    }
    REP(i, n) if(getSum(i)-getSum(i-1) == 0) cout << s[i];
    cout << endl;

    return 0;
}