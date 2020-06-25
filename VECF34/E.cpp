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

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n, k;
    cin >> k >> n;
    set<string> strset;
    vector<string> strs;
    REP(i, k) {
    	string str;
    	cin >> str;
    	strset.insert(str);
    }
    k = strset.size();
    for(auto& s : strset) strs.push_back(s);
    if(k == 1) {
    	swap(strs[0][0], strs[0][1]);
    	cout << strs[0]<< endl;
    	exit(0);
    }
    vector<int> f(26, 0);
    REP(i, n) ++f[strs[0][i]-'a'];
	for(auto& s : strs) {
		vector<int> tf(26, 0);
    	REP(i, n) ++tf[s[i]-'a'];
    	REP(i, 26) {
    		if(f[i] != tf[i]) {
    			cout << -1 << endl;
    			exit(0);
    		}
    	}
	}
    vector<int> idxs;
    REP(i, n) {
    	if(strs[0][i] != strs[1][i]) idxs.push_back(i);
    }
    if(idxs.size() > 4) {
    	cout << -1 << endl;
    	exit(0);
    }
    set<string> poss;
    REP(i, idxs.size()) {
    	REP(j, n) {
    		string s = strs[0];
    		swap(s[idxs[i]], s[j]);
    		poss.insert(s);
    	}
    }
    bool distinct = true;
    string temp = strs[0];
    sort(temp.begin(), temp.end());
    REP(i, n-1) if(temp[i] == temp[i+1]) distinct = false;
    for(auto& s : poss) {
    	bool good = true;
    	REP(i, k) {
    		int cnt = 0;
    		REP(j, n) if(strs[i][j] != s[j]) ++cnt;
    		if(cnt != 0 && cnt != 2) {
    			good = false;
    			break;
    		}
    		if(cnt == 0 && distinct) {
    			good = false;
    			break;
    		}
    	}
    	if(!good) continue;
    	cout << s << endl;
    	exit(0);
    }
    cout << -1 << endl;

    return 0;
}