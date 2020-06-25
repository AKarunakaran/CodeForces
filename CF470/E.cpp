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
    string s, t;
    cin >> s >> t;
    vector<int> ps(s.size()+1, 0), pt(t.size()+1, 0);
    FORD(i, s.size()-1, 0) ps[i] = ps[i+1] + (s[i] != 'A');
	FORD(i, t.size()-1, 0) pt[i] = pt[i+1] + (t[i] != 'A');
    int q;
    cin >> q;
    while(q--) {
    	int sl, sr, tl, tr;
    	cin >> sl >> sr >> tl >> tr;
    	--sl, --tl;
    	int sb = ps[sl]-ps[sr], tb = pt[tl]-pt[tr], slen = sr-sl, tlen = tr-tl;
    	int sa = slen-sb, ta = tlen-tb;
    	bool saa = sa == slen;
    	bool taa = ta == tlen;
    	// DEBUG(sl);
    	// DEBUG(sr);
    	// DEBUG(sa);
    	// DEBUG(sb);
    	// DEBUG(slen);
    	// DEBUG(saa);

    	// DEBUG(tl);
    	// DEBUG(tr);
    	// DEBUG(ta);
    	// DEBUG(tb);
    	// DEBUG(tlen);
    	// DEBUG(taa);
    	int good = -1;
    	if(sb > tb) {
    		good = 0;
    	} else {
	    	if(saa && !taa) {
	    		if(tb & 1) good = 0;
	    		else {
		    		int l = tl, r = tr;
		    		while(l < r) {
		    			int m = (l+r)/2;
		    			if(pt[m]-pt[tr] == 0) r = m;
		    			else l = m+1;
		    		}
		    		int tra = pt[l]-pt[tr];
		    		if(sa-1 < tra) good = 0;
		    		else good = 1;
	    		}
	    	} else if(saa && taa) {
	    		if(slen >= tlen && (slen-tlen)%3 == 0) good = 1;
	    		else good = 0;
	    	} else {
	    		int l = tl, r = tr;
	    		while(l < r) {
	    			int m = (l+r)/2;
	    			if(pt[m]-pt[tr] == 0) r = m;
	    			else l = m+1;
	    		}
	    		int tra = tr-l;
	    		l = sl, r = sr;
	    		while(l < r) {
	    			int m = (l+r)/2;
	    			if(ps[m]-ps[sr] == 0) r = m;
	    			else l = m+1;
	    		}
	    		int sra = sr-l;
	    		// DEBUG(sra);
	    		// DEBUG(tra);
	    		good = (sra == tra && (tb-sb)%2 == 0);
	    		good |= (sra > tra && (tb-sb)%2 == 0 && sb+2 <= tb);
	    	}
    	}
    	cout << good;
    }
    cout << endl;

    return 0;
}