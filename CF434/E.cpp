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

int n, e = 0;

int toNum(string& s) {
	int num = 0;
	REP(i, s.size()) {
		if(s[i] >= '0' && s[i] <= '9') num = num*10 + (s[i]-'0');
		else return -1;
		if(num > n) return -1;
	}
	return num;
}

string toStr(int n) {
	string cur = "";
	while(n) {
		cur.push_back((n%10) + '0');
		n /= 10;
	}
	reverse(cur.begin(), cur.end());
	return cur;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    vector<pair<string, bool>> a;
    vector<int> rec(n, -1), bad;
    vector<pair<string, string>> cmd;

    REP(i, n) {
    	cin >> a[i].first >> a[i].second;
    	int num = toNum(a[i].first);
    	if(num != -1) rec[num] = a[i].second;
    	else bad.push_back(i);
    	e += a[i].second;
    }
    set<int> ele, ege;
    vector<int> wle, wge;
    REP(i, n) {
    	if(rec[i] == -1) {
    		if(i < e) ele.insert(i);
    		else ege.insert(i);
    	} else {
    		if(i < e && rec[i] == 0) wle.push_back(i);
    		else if(i > e && rec[i] == 1) wge.push_back(i);
    	}
    }
    if(ele.size()) {
    	while(wle.size() && wge.size()) {
    		int l = wle.back(), g = wge.back();
    		int idx = *ele.begin();
    		cmd.push_back({toStr(g+1), toStr(idx+1)});
    		cmd.push_back({toStr(l+1), toStr(g+1)});
    		ele.erase(ele.begin());
    		ele.insert(l);
    		wle.pop_back();
    		wge.pop_back();
    	}
    }
    if(ege.size()) {
    	while(wle.size() && wge.size()) {
    		int l = wle.back(), g = wge.back();
    		int idx = *ele.begin();
    		cmd.push_back({toStr(g+1), toStr(idx+1)});
    		cmd.push_back({toStr(l+1), toStr(g+1)});
    		ele.erase(ele.begin());
    		ele.insert(l);
    		wle.pop_back();
    		wge.pop_back();
    	}
    }
    for(int i : bad) {
    	if(i < e && ele.size()) {
    		cmd.push_back({a[i].first, toStr(*ele.begin()+1)});
    		ele.erase(ele.begin());
    	}
    	if(i > e && ege.size()) {
    		cmd.push_back({a[i].first, toStr(*ege.begin()+1)});
    		ege.erase(ege.begin());
    	}
    }
    string empty = "qursfw";
    if(wle.size()) {
    	cmd.push_back({toStr(wle.back()+1), empty});
    	int emp = wle.back();
    	wle.pop_back();
    	while(wle.size()) {
    		cmd.push_back({toStr(wge.back()+1), toStr(emp+1)});
    		cmd.push_back({toStr(wle.back()+1), toStr(wge.back()+1)});
    		emp = wle.back();
    		wle.pop_back();
    		wge.pop_back();
    	}
    	cmd.push_back({toStr(wge.back()+1), toStr(emp+1)});
    	cmd.push_back({empty, toStr(wge.back()+1)});
    }
    cout << cmd.size() << endl;
    REP(i, cmd.size()) cout << "move " << cmd[i].first << " " << cmd[i].second << endl;

    return 0;
}