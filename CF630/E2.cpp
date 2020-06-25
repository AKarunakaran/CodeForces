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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

int half(int l, int r) {return ((r-l+1)+1)/2;}

const int M = 998244353;

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

int n, m, l, r, ga, gb, p;
mint ans;

mint solve_odd() {
	mint a(ga), b(gb);
	return (a*(((a+b)^(p-1))-(mint(abs(ga-gb))^(p-1)))+b*(((a+b)^(p-1))+(mint(abs(ga-gb))^(p-1))))*;
}

mint solve_even() {
	mint a(ga), b(gb);
	return ((mint(abs(ga-gb))^p) + ((a+b)^p))*mint(HALF);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> l >> r;
    ga = half(((l+1)/2)*2, (r/2)*2), gb = half((l/2)*2 + 1, ((r+1)/2)*2-1);
    p = n*m;
    if(p & 1) ans = solve_odd();
    else ans = solve_even();
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
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
