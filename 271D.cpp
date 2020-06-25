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

struct trieNode {
	trieNode *c[26];
} head = {{0}};

ll ans = 0;
bool bad[26];

void add(string& s) {
	trieNode *cur = &head;
	REP(i, s.size()) {
		if(!cur->c[s[i]-'a']) {
			// DEBUG(s);
			// DEBUG(i);
			++ans;
			cur->c[s[i]-'a'] = new trieNode{{0}};
		}
		cur = cur->c[s[i]-'a'];
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s, badb;
    int k;
    cin >> s >> badb >> k;
    REP(i, 26) bad[i] = 1-(badb[i]-'0');
    REP(i, s.size()) {
    	string cur;
    	int curb = 0;
    	FOR(j, i, s.size()-1) {
    		if(bad[s[j]-'a'] && curb == k) {
    			break;
    		}
    		if(bad[s[j]-'a']) ++curb;
    		cur.push_back(s[j]);
    	}
    	// DEBUG(cur);
    	add(cur);
    }
    cout << ans << endl;

    return 0;
}