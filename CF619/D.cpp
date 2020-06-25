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

const int N = 510;

int n, m, k, num_moves;
bool swapped = false;
map<char, char> swapmap;

vector<pair<string, int>> v;

string swapping(string s) {
	string res = s;
	if(swapped) REP(i, s.size()) res[i] = swapmap[s[i]];
	return res;
}

void answer() {
	cout << "YES" << endl;
	cout << v.size() << endl;
	for(auto p : v) {
		cout << p.second << ' ' << swapping(p.first) << endl;
	}
	exit(0);
}

void add_move(string s) {
	bool ans = false;
	if(num_moves + s.size() >= k) {
		s.resize(k-num_moves);
		ans = true;
	}
	num_moves += s.size();
	if(!v.empty() && s == v.back().first) ++v.back().second;
	else v.push_back({s, 1});
	if(ans) answer();
}

void dfirst() {
	num_moves = 0;
	v.clear();
	add_move("D");
	if(m & 1) {
		string right_move = "RURD";
		string left_move = "LDLU";
		int row = 1;
		while(1) {
			// DEBUG(row);
			int rmoves = (m-1)/2;
			REP(i, rmoves) add_move(right_move);
			if(row+1 == n) {
				add_move("L");
				break;
			}
			++row;
			int lmoves = rmoves-1;
			REP(i, lmoves) add_move(left_move);
			add_move("LDL");
			if(row+1 == n) {
				add_move("U");
				break;
			} else add_move("D");
			++row;
		}
	} else {
		string right_move = "RURD";
		string left_move = "DLUL";
		int row = 1;
		while(1) {
			int rmoves = (m-1)/2;
			REP(i, rmoves) add_move(right_move);
			if(row+1 == n) {
				add_move("L");
				break;
			} else add_move("R");
			++row;
			int lmoves = rmoves;
			REP(i, lmoves) add_move(left_move);
			add_move("DL");
			if(row+1 == n) {
				add_move("U");
				break;
			} else add_move("D");
			++row;
		}
	}
}

void bad() {
	cout << "NO" << endl;
	exit(0);
}

void two_move() {
	add_move("D");
	REP(i, m-1) {
		if(i & 1) add_move("RD");
		else add_move("RU");
	}
	add_move("L");
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    swapmap['R'] = 'D';
    swapmap['D'] = 'R';
    swapmap['L'] = 'U';
    swapmap['U'] = 'L';

    cin >> n >> m >> k;
    if(n == 1) {
    	REP(i, m-1) add_move("D");
    	bad();
    } else if(m == 1) {
    	REP(i, n-1) add_move("R");
    	bad();
    } else if(n == 2) {
    	two_move();
    	bad();
    } else if(m == 2) {
    	swap(n, m);
    	swapped = true;
    	two_move();
    	bad();
    }
    dfirst();
    swap(n, m);
    swapped = true;
    dfirst();
    bad();

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
