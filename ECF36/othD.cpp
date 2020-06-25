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
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#ifdef _WIN32
#include <windows.h>
#define print(x) PRINT(x, #x)
template<typename T> inline const void PRINT(T VARIABLE, string NAME)
{
#ifndef ONLINE_JUDGE /// ONLINE_JUDGE IS DEFINED ON CODEFORCES
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cerr << NAME << " = " << VARIABLE;
    SetConsoleTextAttribute(hConsole, 7);
    cerr << '\n';
#endif
}
#else
#define print(x) 0
#endif
typedef long long ll;
typedef unsigned long long ull;
const ll INFLL = 2 * (ll)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
const double PI = atan(1) * 4;
const double EPS = 1e-12;
const int SEED = 1e3 + 7;

const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const int NMAX = 555;

int n, m;
V graf[NMAX];

int parent[NMAX];
bool vis_tot[NMAX], vis_cur[NMAX];
int start = -1, finish;

bool find_cycle(int nod, int p)
{
    vis_cur[nod] = 1;
    vis_tot[nod] = 1;
    parent[nod] = p;

    for(auto i: graf[nod])
    {
        if(vis_cur[i])
        {
            start = nod;
            finish = i;
            return true;
        }
        if(vis_tot[i]) continue;

        if(find_cycle(i, nod)) return true;
    }

    vis_cur[nod] = 0;
    return false;
}

void remove_edge(int a, int b)
{
    for(auto &i: graf[a])
        if(i == b)
        {
            swap(graf[a].back(), i);
            graf[a].pop_back();
            break;
        }
}

bool contains_cycle(int nod, int from, int to)
{
    print(nod);

    bool ret = 0;

    vis_cur[nod] = 1;
    vis_tot[nod] = 1;

    if(nod == 1) print(graf[nod].size());

    for(auto i: graf[nod])
    {
        if(nod == from && i == to) continue;
        if(vis_tot[i] && !vis_cur[nod]) continue;
        if(vis_cur[i]) return 1;
        if(contains_cycle(i, from, to)) return 1;
    }

    vis_cur[nod] = 0;
    return 0;
}

bool check(int from, int to)
{
    for1(i, n) vis_cur[i] = vis_tot[i] = 0;
    for1(i, n) if(!vis_tot[i] && contains_cycle(i, from, to)) { return 1;}
    return 0;
}



int main()
{
    FASTIO;
    cin >> n >> m;
    for1(i, m)
    {
        int a, b;
        cin >> a >> b;
        graf[a].pb(b);
    }

    for1(i, n) if(!vis_tot[i])
        find_cycle(i, -1);
    // cerr << start << ' ' << finish << endl;

    if(start == -1) return cout << "YES" << endl, 0;

    if(!check(start, finish)) return cout << "YES" << endl, 0;

    for(;;)
    {
        int p = parent[start];

//        cerr << start << ' ' << p << endl;

        if(!check(p, start)) return cout << "YES" << endl, 0;

        if(p == finish) break;
        start = p;
    }

    cout << "NO" << endl;

    return 0;
}