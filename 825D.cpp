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
#include <unordered_map>
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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    string t;
    cin >> s >> t;
    set<pair<int, char>> l;
    unordered_map<char, int> fT;
    vector<int> cnt(26, -1);
    REP(i, t.size()) {
    	++fT[t[i]];
    	cnt[t[i]-'a'] = 0;
    }
    REP(i, s.size()) {
    	if(fT.find(s[i]) != fT.end()) {
    		++cnt[s[i]-'a'];
    	}
    }
    REP(i, 26) {
    	if(cnt[i] != -1) {
    		l.insert({cnt[i]/fT['a'+i], 'a'+i});
    	}
    }
    REP(i, s.size()) {
    	/*for(auto itr = l.begin(); itr != l.end(); ++itr) cout << itr->first << itr->second << " ";
    	cout << endl;*/

    	if(s[i] == '?') {
    		s[i] = l.begin()->second;
    		int c = s[i]-'a';
    		++cnt[c];
    		l.erase(l.begin());
    		l.insert({cnt[c]/fT[s[i]], s[i]});
    	}
    }
    cout << s << endl;

    return 0;
}