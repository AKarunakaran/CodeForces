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
    int n;
    unordered_map<string, unordered_set<string>> e;
    map<string, vector<string>> ans;
    cin >> n;
    REP(i, n) {
    	string s;
    	int m;
    	cin >> s >> m;
    	auto& entries = e[s];
    	REP(j, m) {
    		string num;
    		cin >> num;
    		if(entries.find(num) != entries.end()) {
    			ans[s].push_back(num);
    		}
    		int k = 0;
    		while(k != num.size() && entries.find(num.substr(k)) != entries.end()) {
    			entries.insert(num.substr(k));
    			++k;
    		}
    	}
    }
    for(auto& itr : ans) {
    	auto& v = itr.second;
    	cout << itr.first << " " << v.size() << " ";
    	REP(i, v.size()) cout << v[i] << " ":
    	cout << endl;
    }

    return 0;
}