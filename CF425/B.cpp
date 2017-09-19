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
inline int two(int n) { return 1 << n; }

/////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    string s;
    vector<bool> good(26, 0);
    int n;
    cin >> s;
    REP(i, s.size()) good[s[i]-'a'] = 1;
    int star = -1;
    cin >> s >> n;
    REP(i, s.size()) {
    	if(s[i] == '*') {
    		star = i;
    		break;
    	}
    }
    string in;
    REP(i, n) {
    	cin >> in;
    	bool yes = true;
    	if(star != -1) {
    		if(in.size() < s.size()-1) {
    			cout << "NO" << endl;
    			continue;
    		}
    		FOR(i, 0, star-1) {
    			if(s[i] == '?') {
    				if(!good[in[i]-'a']) {
    					yes = false;
    					break;
    				}
    			} else {
    				if(in[i] != s[i]) {
    					yes = false;
    					break;
    				}
    			}
	    	}
	    	if(!yes) {
	    		cout << "NO" << endl;
	    		continue;
	    	}
	    	int inSz = in.size(), sSz = s.size();
	    	FORD(i, sSz-1, star+1) {
    			if(s[i] == '?') {
    				if(!good[in[i-sSz+inSz]-'a']) {
    					yes = false;
    					break;
    				}
    			} else {
    				if(in[i-sSz+inSz] != s[i]) {
    					yes = false;
    					break;
    				}
    			}
	    	}
	    	if(!yes) {
	    		cout << "NO" << endl;
	    		continue;
	    	}
	    	FOR(i, star, star-sSz+inSz) {
	    		if(good[in[i]-'a']) {
	    			yes = false;
	    			break;
	    		}
	    	}
	    	if(yes) cout << "YES" << endl;
	    	else cout << "NO" << endl;
    	} else {
    		int inSz = in.size(), sSz = s.size();
    		if(inSz != sSz) {
    			cout << "NO" << endl;
    			continue;
    		}
    		REP(i, sSz) {
    			if(s[i] == '?') {
    				if(!good[in[i]-'a']) {
    					yes = false;
    					break;
    				}
    			} else {
    				if(s[i] != in[i]) {
    					yes = false;
    					break;
    				}
    			}
    		}
    		if(yes) cout << "YES" << endl;
	    	else cout << "NO" << endl;
    	}
    }

    return 0;
}