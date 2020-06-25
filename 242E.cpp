#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define cnt(c, x) ((c).find(x) != (c).end())
#define pb push_back
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int) (x).size())
#define mp(x,y) make_pair((x), (y))
#define mp3(x,y,z) make_pair((x), make_pair( (y), (z)))
#define foreach(C, i) for(auto i = (C).begin(); i != (C).end(); i++)
#define xx first
#define yy second
#define clr clear()
#define var(x) cout<< #x << " = "<<x<<"\n";
#define print(x) for_each((x).begin(), (x).end(), [](auto n) { cout<<x<<" " })
typedef int32_t i3;
typedef int64_t i6;
typedef vector<i3> vi;
typedef pair<i3,i3> ii;
typedef vector<pair<i3,i3> > vii;

int n; 
template<typename T>
class SegmentTree
{
	public:
		vector<T> tree;
		vector<T> lazy;
		int size;
		SegmentTree()
		{
			size = n;
			int s = (1 << ((int)ceil(log2(n))+1));
			tree = vector<T>(s, 0);
			lazy = vector<T>(s, 0);
		}
		void updateLazyChildren(int index, T value)
		{
			if (2*index + 1 < SZ(lazy))
				lazy[2*index+1] = (lazy[2*index + 1] + 1)%2;
			if (2*index + 2 < SZ(lazy))
				lazy[2*index + 2] = (lazy[2*index + 2] + 1)%2;
		}
		void updateRange(int l, int r, T value)
		{
			updateRange(0,size-1, 0, l, r, value);
		}
		void updateRange(int start, int end, int index, int l, int r, T value)
		{
			if (lazy[index] != 0)
			{
				updateLazyChildren(index, lazy[index]);
				tree[index] = (end - start + 1) - tree[index];
				lazy[index] = 0;
			}
			if (start > end || start > r || end < l)
				return;

			if( start >= l && end <= r)
			{
				tree[index] = (end - start + 1) - tree[index];
				updateLazyChildren(index, value);
				return;
			}
			int mid = start + (end - start)/2;
			updateRange(start, mid, 2*index + 1,l, r, value);
			updateRange(mid + 1, end, 2*index + 2,l, r, value);
			tree[index] = tree[2*index + 1] + tree[2*index + 2];

		}
		T getQuery(int l, int r)
		{
			return getQuery(0, size-1, 0, l, r);
		}
		T getQuery(int start, int end, int index, int l, int r)
		{
			if (start > end || start > r || end < l)
				return (0);
			if (lazy[index] != 0)
			{
				updateLazyChildren(index, lazy[index]);
				tree[index] = (end - start + 1) - tree[index];
				lazy[index] = 0;
			}
			if (start >= l && end <= r)
				return tree[index];
			int mid = start + (end - start)/2;
			T p1 = getQuery(start, mid, 2*index + 1, l, r);
			T p2 = getQuery(mid + 1, end, 2*index + 2, l,r);
			return (p1 + p2);
		}
};

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n;	
	vector<SegmentTree<i6> > segTree(20);
	REP(j,n)
	{
		int temp; cin >> temp;	
		for(int i = 0; i < 20; i++)
		{
			if ((temp >> i)&1)
				segTree[i].updateRange(j,j,1);
		}
	}
	int m; cin >> m;
	REP(j,m)
	{
		int type, l, r, x;
		cin >> type >> l >> r;
		l--; r--;
		if (type == 1)
		{
			i6 sum = 0;
			for(int i = 0; i < 20; i++)
				sum += (segTree[i].getQuery(l,r))*(1LL << i);
			cout << sum << "\n";
		}
		else 
		{
			cin >> x; 
			for(int i = 0; i < 20; i++)
			{
				if (( x >> i) & 1)
					segTree[i].updateRange(l, r, 1);
			}
		}
	}
	return (0);
}