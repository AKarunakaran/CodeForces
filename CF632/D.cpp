#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e3+10;

int n, k, tot;
string s;
vector<vector<int>> min_ans;

void get_minimum() {
	REP(j, n) {
		min_ans.push_back({});
		REP(i, n-1) {
			if(s[i] == 'R' && s[i+1] == 'L') {
				swap(s[i], s[i+1]);
				min_ans[j].push_back(i+1);
				++i;
				++tot;
			}
		}
		if(min_ans.back().empty()) {
			min_ans.pop_back();
			break;
		}
	}
}

void print_split(vector<int> v, int split_size) {
	int id = 0;
	while(split_size > 1) {
		printf("1 %d\n", v[id]);
		--split_size;
		++id;
	}
	printf("%d ", (int)v.size()-id);
	FOR(i, id, v.size()-1) printf("%d ", v[i]);
	printf("\n");
}

void bad() {
	printf("-1\n");
	exit(0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k >> s;
    get_minimum();
    // REP(i, min_ans.size()) {
    // 	for(int x : min_ans[i]) cout << x << ' ';
    // 	cout << endl;
    // }
    if(k < min_ans.size() || k > tot) bad();
    int need = k-min_ans.size();
    REP(id, min_ans.size()) {
    	if(need > min_ans[id].size()-1) {
    		int sz = min_ans[id].size();
    		print_split(min_ans[id], sz);
    		need -= sz-1;
    	} else {
    		print_split(min_ans[id], need+1);
    		need = 0;
    	}
    }

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
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
