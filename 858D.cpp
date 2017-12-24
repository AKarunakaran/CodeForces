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
#include <unordered_map>
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

unordered_map<string, int> m;
vector<string> s;

void change(int k, bool add) {
	REP(i, 9) {
    	string word = "";
    	FOR(j, i, 8) {
    		word.push_back(s[k][j]);
    		m[word] += (2*add-1);
    	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    s.resize(n);
    REP(i, n) cin >> s[i];
    REP(i, n) change(i, 1);
    REP(k, n) {
    	change(k, 0);
	    string bestWord = "01234567890";
	    REP(i, 9) {
	    	string word = "";
	    	FOR(j, i, 8) {
	    		word.push_back(s[k][j]);
	    		if(m[word] == 0) {
	    			if(word.size() < bestWord.size()) bestWord = word;
	    			break;
	    		}
	    	}
	    }
	    change(k, 1);
	    cout << bestWord << endl;
    }

    return 0;
}