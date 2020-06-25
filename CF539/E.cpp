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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 0x7fffffffffffffffLL;
const int nINF = 1<<31;
const double eps = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;
int nt, a[N];

// struct two store two values in one node 
struct Node { 
    int sum; 
    int prefix;
    int id;
}; 
  
Node tree[2*N]; 
  
// // function to build the segment tree 
// void build(int index = 0, int beg = 0, int end = nt-1) 
// { 
//     if (beg == end) { 
//         tree[index].sum = a[beg]; 
//         tree[index].prefix = a[beg];
//         tree[index].id = beg;
//         return;
//     }
//     int mid = (beg + end) / 2; 

//     // If there are more than one elements, 
//     // then recur for left and right subtrees 
//     build(2 * index + 1, beg, mid); 
//     build(2 * index + 2, mid + 1, end); 

//     // adds the sum and stores in the index 
//     // position of segment tree 
//     tree[index].sum = tree[2 * index + 1].sum + 
//                       tree[2 * index + 2].sum;

//     // stores the min of prefix-sum either 
//     // from right or from left.
//     if(tree[2 * index + 1].prefix <= tree[2 * index + 1].sum + tree[2 * index + 2].prefix) {
//     	tree[index].prefix = tree[2*index+1].prefix;
//     	tree[index].id = tree[2*index+1].id;
//     } else {
//     	tree[index].prefix = tree[2 * index + 1].sum + tree[2 * index + 2].prefix;
//     	tree[index].id = tree[2 * index + 2].id;
//     }
// }

void update(int id, int val, int index = 0, int beg = 0, int end = nt-1) {
	if(beg > id || end < id) return;
	if(beg == end) {
		tree[index].sum = val;
		tree[index].prefix = val;
		tree[index].id = beg;
		return;
	}
	int mid = (beg+end)/2;
	// cout << id << ' ' << val << ' ' << index << ' ' << beg << ' ' << mid << ' ' << end << endl;
	update(id, val, 2 * index + 1, beg, mid); 
    update(id, val, 2 * index + 2, mid + 1, end); 
    tree[index].sum = tree[2 * index + 1].sum + 
                      tree[2 * index + 2].sum;
    if(tree[2 * index + 1].prefix <= tree[2 * index + 1].sum + tree[2 * index + 2].prefix) {
    	tree[index].prefix = tree[2*index+1].prefix;
    	tree[index].id = tree[2*index+1].id;
    } else {
    	tree[index].prefix = tree[2 * index + 1].sum + tree[2 * index + 2].prefix;
    	tree[index].id = tree[2*index+2].id;
    }
}

// function to do the range query in the segment  
// tree for the minimum prefix sum 
Node query(int l, int r, int index = 0, int beg = 0, int end = nt-1) 
{ 
    Node result; 
    result.sum = 0;
    result.prefix = INF;
    result.id = -1; 
  
    // If segment of this node is outside the given  
    // range, then return the minimum value. 
    if (beg > r || end < l) 
        return result; 
  
    // If segment of this node is a part of given 
    // range, then return the node of the segment 
    if (beg >= l && end <= r) 
        return tree[index]; 
  
    int mid = (beg + end) / 2; 
  
    // if left segment of this node falls out of 
    // range, then recur in the right side of 
    // the tree 
    if (l > mid) 
        return query(l, r, 2 * index + 2, mid + 1, end); 
  
    // if right segment of this node falls out of 
    // range, then recur in the left side of  
    // the tree 
    if (r <= mid) 
        return query(l, r, 2 * index + 1, beg, mid); 
  
    // If a part of this segment overlaps with 
    // the given range 
    Node left = query(l, r, 2 * index + 1, beg, mid); 
    Node right = query(l, r, 2 * index + 2, mid + 1, end); 
  
    // adds the sum of the left and right  
    // segment 
    result.sum = left.sum + right.sum; 
  
    // stores the min of prefix-sum 
    if(left.prefix <= left.sum+right.prefix) {
    	result.prefix = left.prefix;
    	result.id = left.id;
    } else {
    	result.prefix = left.sum+right.prefix;
    	result.id = right.id;
    }
  
    // returns the value 
    return result; 
} 

int q, rates[N];
map<int, int> tid;
vector<int> queries[N], vt;
set<int, greater<int>> curtb;
set<int> ts, curtf;

pii get_neighbor_ids(int t) {return {tid[*curtb.upper_bound(t)], tid[*curtf.upper_bound(t)]};}

void print_tree() {
	REP(i, 2*nt-1) cout << "[" << tree[i].sum << ", " << tree[i].prefix << ", " << tree[i].id << "] ";
	cout << endl;
}

void add_time(int t) {
	int id = tid[t];
	pii p = get_neighbor_ids(id);
	// DEBUG(p.first);
	// DEBUG(p.second);
	int l = vt[p.first], r = vt[p.second];
	update(p.first, rates[p.first]*(t-l));
	update(id, rates[id]*(r-t));
	// print_tree();
	curtf.insert(t);
	curtb.insert(t);
}

void remove_time(int t) {
	int id = tid[t];
	pii p = get_neighbor_ids(id);
	// DEBUG(p.first);
	// DEBUG(p.second);
	int l = vt[p.first], r = vt[p.second];
	update(p.first, rates[p.first]*(r-l));
	update(id, 0);
	// print_tree();
	curtf.erase(t);
	curtb.erase(t);
}

double get_actual_time(int l, int r, int v, int id) {
	cout << l << ' ' << r << ' ' << v << ' ' << id << endl;
	Node cur{0, 0, 0};
	if(id > l) cur = query(l, id-1);
	int need = -v-cur.sum;
	DEBUG(id);
	DEBUG(cur.sum);
	DEBUG(need);
	DEBUG(rates[id]);
	DEBUG(vt[id]);
	return vt[id]+need/(double)rates[id];
}

double answer_query(int l, int r, int v) {
	if(v == 0) return 0;
	pii p = get_neighbor_ids(r);
	int latest = p.first;
	if(vt[latest] < l) return -1;
	p = get_neighbor_ids(l);
	int earliest = p.second;
	Node cur = query(earliest, latest);
	DEBUG(cur.prefix);
	DEBUG(cur.id);
	if(cur.prefix <= -v) {
		double res = get_actual_time(earliest, latest, v, cur.id);
		if(res <= r+eps) return res;
		else return -1;
	}
	else return -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(7);
    ts.insert(0);
    ts.insert(1e9+1);
    cin >> q;
    REP(i, q) {
    	int type;
    	cin >> type;
    	if(type == 1) {
    		int t, s;
    		cin >> t >> s;
    		queries[i] = {1, t, s};
    		ts.insert(t);
    	} else if(type == 2) {
    		int t;
    		cin >> t;
    		queries[i] = {2, t};
    	} else {
    		int l, r, v;
    		cin >> l >> r >> v;
    		queries[i] = {3, l, r, v};
    	}
    }
    for(auto itr = ts.begin(); itr != ts.end(); ++itr) {
    	vt.push_back(*itr);
    	tid[*itr] = nt++;
    }
    curtf.insert(0);
    curtf.insert(nt-1);
    curtb.insert(0);
    curtb.insert(nt-1);
    REP(i, q) {
    	auto& cur = queries[i];
    	int type = cur[0];
    	if(type == 1) {
    		int t = cur[1], s = cur[2];
    		rates[tid[t]] = s;
    		if(s) add_time(t);
    	} else if(type == 2) {
    		int t = cur[1];
    		rates[tid[t]] = 0;
    		remove_time(t);
    	} else {
    		int l = cur[1], r = cur[2], v = cur[3];
    		cout << answer_query(l, r, v) << endl;
    	}
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

