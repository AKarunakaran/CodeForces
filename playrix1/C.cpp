#include <iostream>
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
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define srt(v) sort(v.begin(), v.end())
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

/////////////////////////////////////////////////////////////////////

int maxTwo(vector< pair<int, int> >& f, int m) {
    int ans = -1;
    vector<int> maxb(f.size());
    sort(f.begin(), f.end(), [](auto &left, auto &right) {return left.second < right.second;});
    maxb[0] = f[0].first;
    FOR(i, 1, f.size()-1) maxb[i] = max(maxb[i-1], f[i].first);
    FOR(i, 1, f.size()-1) {
        FORD(j, i-1, 0) {
            if(f[i].second + f[j].second <= m) {
                ans = max(ans, f[i].first + maxb[j]);
                break;
            }
        }
    }
    return ans;
}

int maxOE(vector< pair<int, int> >& fc, vector< pair<int, int> >& fd, int c, int d) {
    int ic = fc.size()-1, id = fd.size()-1;
    while(ic >= 0 && id >= 0) {
        if(fc[ic].second <= c && fd[id].second <= d) break;
        if(fc[ic].second > c) --ic;
        if(fd[id].second > d) --id;
    }
    return (ic < 0 || id < 0) ? -1 : fc[ic].first + fd[id].first;
}

int main() {
    int n, c, d, b, p, ans = 0;
    cin >> n >> c >> d;
    vector< pair<int, int> > fc, fd;
    char temp;
    REP(i, n) {
    	cin >> b >> p >> temp;
        if(temp == 'C') fc.push_back({b, p});
        else fd.push_back({b, p});
    }
    srt(fc);
    srt(fd);
    ans = max(ans, maxOE(fc, fd, c, d));
    if(fc.size()) ans = max(ans, maxTwo(fc, c));
    if(fd.size()) ans = max(ans, maxTwo(fd, d));
    cout << ans << endl;

    return 0;
}