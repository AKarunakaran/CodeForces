#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int M = 1e9+7;

struct mint {
    int x;
    mint() {}
    mint(int _x) {
        x = ((_x % M) + M) % M;
    }

    void operator=(int oth) {x = oth;}
    mint operator+(const mint& oth) const {return mint(x + oth.x);}
    mint operator-(const mint& oth) const {return mint(x + M - oth.x);}
    mint operator*(const mint& oth) const {return mint( ((ll)x * oth.x) % M );}
    mint operator^(int power) const {
        mint res(1);
        mint y = *this;
        while(power) {
            if(power & 1) res = res*y;
            y = y*y;
            power >>= 1;
        }
        return res;
    }
    mint operator/(mint oth) const {return (*this) * oth^(M-2);}
    bool operator==(const mint& oth) const {return x == oth.x;}
    bool operator!=(const mint& oth) const {return !(*this == oth);}
    bool operator<(const mint& oth) const {return x < oth.x;}
    bool operator<=(const mint& oth) const {return *this < oth || *this == oth;}
    bool operator>(const mint& oth) const {return !(*this <= oth);}
    bool operator>=(const mint& oth) const {return !(*this < oth);}

    friend ostream& operator<<(ostream& os, mint& x);
    friend istream& operator>>(istream& is, mint& x);
};

ostream& operator<<(ostream& os, mint& x) {
    os << x.x;
    return os;
}

istream& operator>>(istream& is, mint& x) {
    is >> x.x;
    return is;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int t;
    cin >> t;
    while(t--) {
        mint x, len = 0;
    	string s;
    	cin >> x >> s;
    	mint l = 0;
    	while(1) {
            l = l + 1;
            int rep = s[l.x-1]-'1';
            if(rep) {
                string nxt = s.substr(l.x);
                REP(_, rep) s += nxt;
            }
            if(mint(l) == x || x < s.size()) break;
        }
        len = s.size();
        if(mint(l) != x) {
            while(1) {
                l = l + 1;
	    		mint to_add = len - l;
	    		mint rep = s[l.x-1]-'1';
                len = len + (to_add * rep);
	    		if(mint(l) == x) break;
	    	}
    	}
    	cout << len << endl;
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
