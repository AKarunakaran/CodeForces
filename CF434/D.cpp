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
	trieNode *next[10] = {};
	int num = 0;
};

trieNode start[10];
int best;
string ans;

void insert(string& s, int j) {
	auto itr = &start[j];
	FOR(i, j, s.size()-1) {
		if(!itr->next[s[i]-'0']) {
			trieNode* toAdd = new trieNode;
			itr->next[s[i]-'0'] = toAdd;
		}
		itr = itr->next[s[i]-'0'];
		++(itr->num);
	}
}

void remove(string& s, int j) {
	auto itr = &start[j];
	FOR(i, j, s.size()-1) {
		itr = itr->next[s[i]-'0'];
		--(itr->num);
	}
}

void findBest(string& s, int j) {
	trieNode *itr[10];
	REP(i, 10) itr[i] = &start[i];
	string cur = "";
	FOR(i, j, s.size()-1) {
		cur.push_back(s[i]);
		//DEBUG(cur);
		REP(k, 10) {
			if(!itr[k]) continue;
			itr[k] = itr[k]->next[s[i]-'0'];
		}
		int sum = 0;
		REP(k, 10) {
			if(!itr[k]) continue;
			sum += itr[k]->num;
		}
		if(sum == 0) {
			REP(k, 10) {
				if(!itr[k]) continue;
				if(i-j+1 < best) {
					best = i-j+1;
					ans = cur;
				}
				return;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) {
    	cin >> s[i];
    	REP(j, 10) insert(s[i], j);
    }
    REP(i, n) {
		best = 11;
    	ans = "";
    	REP(j, 10) remove(s[i], j);
    	REP(j, 10) findBest(s[i], j);
    	REP(j, 10) insert(s[i], j);
    	cout << ans << endl;
    }

    return 0;
}