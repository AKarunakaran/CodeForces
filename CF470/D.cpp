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
#include <cassert>
#include <functional>
using namespace std; 
// #define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

struct trieNode {
	int num;
	trieNode *z;
	trieNode *o;
};

trieNode head{0, 0, 0};

void buildTrie(vector<int>& v) {
	REP(i, v.size()) {
		int m = 1 << 30;
		trieNode *cur = &head;
		while(m) {
			if(m & v[i]) {
				if(!cur->o) cur->o = new trieNode{0, 0, 0};
				cur = cur->o;
			} else {
				if(!cur->z) cur->z = new trieNode{0, 0, 0};
				cur = cur->z;
			}
			cur->num += 1;
			m >>= 1;
		}
	}
}

int findMin(int a) {
	trieNode *cur = &head;
	int m = 1 << 30;
	int x = 0;
	while(m) {
		// DEBUG(a);
		// DEBUG(m);
		// DEBUG(x);
		// DEBUG((bool)cur);
		// DEBUG((bool)cur->o);
		// DEBUG((bool)cur->z);
		if((a & m) && cur->o) {
			// DEBUG("test1");
			cur = cur->o;
			// DEBUG("test2");
			x += m;
			// DEBUG("test3");
		} else if(!(a & m) && cur->z) {
			cur = cur->z;
		} else if(cur->o) {
			cur = cur->o;
			x += m;
		} else if(cur->z) {
			cur = cur->z;
		} else assert(false);
		m >>= 1;
	}
	return x;
}

void remove(int x, trieNode *cur, int m) {
	if(m) {
		if(m & x) {
			remove(x, cur->o, m>>1);
			if(cur->o->num == 0) {
				delete cur->o;
				cur->o = 0;
			}
		} else {
			remove(x, cur->z, m>>1);
			if(cur->z->num == 0) {
				delete cur->z;
				cur->z = 0;
			}
		}
	}
	cur->num -= 1;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> p[i];
    buildTrie(p);
    // REP(i, n) cout << p[i] << ' ';
    // cout << endl;
    REP(i, n) {
    	// DEBUG(a[i]);
    	int x = findMin(a[i]);
    	remove(x, &head, 1 << 30);
    	cout << (int)(a[i]^x) << ' ';
    }
    cout << endl;

    return 0;
}