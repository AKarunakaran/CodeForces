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
#include <unordered_map>
#include <unordered_set>
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
    unordered_map<string, unordered_map<string, int>> e;
    unordered_map<string, set<string>> pnums;
    map<string, vector<string>> ans;
    cin >> n;
    REP(i, n) {
    	string s;
    	int m;
    	cin >> s >> m;
    	auto& nums = pnums[s];
    	auto& entries = e[s];
    	REP(j, m) {
    		string num;
    		cin >> num;
    		nums.insert(num);
    	}
    }
    for(auto& itr : pnums) {
    	auto& nums = itr.second;
    	auto& entries = e[itr.first];
		for(auto& num : nums) REP(k, num.size()) entries[num.substr(k)]++;
    }
	for(auto& itr : pnums) {
    	auto& nums = itr.second;
    	auto& entries = e[itr.first];
		for(auto& num : nums) if(entries[num] == 1) ans[itr.first].push_back(num);
    }
    cout << ans.size() << endl;
    for(auto& itr : ans) {
    	auto& v = itr.second;
    	cout << itr.first << " " << v.size() << " ";
    	REP(i, v.size()) cout << v[i] << " ";
    	cout << endl;
    }

    return 0;
}