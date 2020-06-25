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

void print(map<ll, set<ll>>& m) {
	for(auto& p : m) {
		cout << '{' << p.first << ", {";
		for(auto& i : p.second) {
			cout << i << ", ";
		}
		cout << "}}, ";
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    ll MAX = 1000000001;
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, set<ll>> m, om, tm;
    REP(i, n) {
    	cin >> a[i];
    	tm[a[i]].insert(i);
    }
    for(auto& p : tm) {
    	if(p.second.size() != 1) {
    		// DEBUG(p.first);
    		m[p.first] = p.second;
    	} else {
    		om[p.first] = p.second;
    	}
    }
    ll ans = n;
    while(!m.empty()) {
    	// print(m);
    	// print(om);
    	auto& p = *m.begin();
    	ll low = p.first;
    	// DEBUG(low);
    	auto& s = p.second;
    	ll idx1 = *s.begin();
    	s.erase(s.begin());
    	ll idx2 = *s.begin();
    	s.erase(s.begin());
    	if(s.size() == 1) {
    		om.insert({low, s});
    	}
    	if(s.size() < 2) {
    		m.erase(low);
    	}
    	a[idx1] = MAX;
    	--ans;
    	a[idx2] = 2*low;
    	if(om[2*low].size() == 1) {
    		m[2*low].insert(*om[2*low].begin());
    		om.erase(2*low);
    		m[2*low].insert(idx2);
    	} else {
    		if(m.find(2*low) == m.end()) {
    			om[2*low].insert(idx2);
    		} else {
    			m[2*low].insert(idx2);
    		}
    	}
    }
    cout << ans << endl;
    REP(i, n) {
    	if(a[i] != MAX) cout << a[i] << ' ';
    }
    cout << endl;


    return 0;
}