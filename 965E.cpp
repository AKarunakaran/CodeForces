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

ll ans = 0;

struct trieNode {
	trieNode* let[26];
	int num;
} head;

void insert(string& s) {
	trieNode *cur = &head;
	for(char c : s) {
		DEBUG(c);
		if(!cur->let[c-'a']) cur->let[c-'a'] = new trieNode{{}, 0};
		cur = cur->let[c-'a'];
		++cur->num;
	}
}

void buildTrie(vector<string>& words) {
	for(string& s : words) {
		DEBUG(s);
		insert(s);
	}
}

void dfs(trieNode *cur, int len) {
	// DEBUG(len);
	// DEBUG(cur->num);
	ans += len;
	if(cur->num == 1) return;
	REP(i, 26) if(cur->let[i]) dfs(cur->let[i], len+1);
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<string> words(n);
    REP(i, n) {
    	cin >> words[i];
    	DEBUG(words[i]);
    }
    buildTrie(words);
    REP(i, 26) if(head.let[i]) dfs(head.let[i], 1);
    cout << ans << endl;

    return 0;
}