#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define mkp(a,b)        make_pair(a,b)
#define PI              3.14159265359
#define ll              long long
#define ul              unsigned long long
#define ld              long double
#define mset(arr,val)   memset(arr,val,sizeof arr)
#define MAXN            (long long)2e5+5
#define eb              emplace_back
#define mod             (long long)(1e9+7)
#define FILE_READ       freopen("input.txt","r",stdin)
#define FILE_WRITE      freopen("output.txt","w",stdout)
#define IOS             ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ALL(x)          x.begin(),x.end()
#define ordered_set     tree<let, null_type,less_equal<let>, rb_tree_tag,tree_order_statistics_node_update> 
#ifndef ONLINE_JUDGE    
                        #define TRACE
#endif
#ifdef TRACE            
                        #define debug(...) __debug_printer(#__VA_ARGS__,__VA_ARGS__)
                        template<typename Arg1>
                        void __debug_printer(const char* name, Arg1&& arg1) {
                            std::cerr<<name << " = " << arg1<<"\n"; 
                        }
                        template<typename Arg1, typename ...Args>
                        void __debug_printer(const char* names, Arg1&& arg1, Args&&... args) {
                            const char* comma = strchr(names, ',');
                            std::cerr.write(names, comma - names) << " = " << arg1<<" |";
                            __debug_printer(comma+1, args...);
                        }
#else
                        #define debug(...)
#endif
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

pii printAndFetch(vector<int> &a) {
    assert(!a.empty());
    cout<<"? "<<a.size()<<" ";
    for(auto i: a) {
        cout<<i<<" ";
    }
    cout<<endl;
    fflush(stdout);
    int x, d;
    cin>> x>> d;
    assert(x!=-1 && d!=-1);
    return {x, d};
}

void dfs(int curr, int lvl, int par, vector<int> levels[], vector<int> nbs[]) {
    levels[lvl].push_back(curr);
    for(auto i:nbs[curr]) {
        if(i != par) {
            dfs(i, lvl + 1, curr, levels, nbs);
        }
    }
}

int main() {
    // #ifndef ONLINE_JUDGE
    //  FILE_READ;
    //  FILE_WRITE;
    // #endif
    // IOS;

    int t = 1;
    cin>>t;
    for(auto ___test_it___ = 1; ___test_it___ <= t; ++___test_it___) {
        int n;
        cin>>n;
        // if(___test_it___ == 9) assert(n == 10);
        vector<int> nbs[n + 1];
        for(int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            nbs[u].push_back(v);
            nbs[v].push_back(u);
        }       
        vector<int> all;
        for(int i = 1; i <= n; ++i) {
            all.eb(i);
        } 
        pii res = printAndFetch(all);
        // debug(res.first, res.second);
        vector<int> level[1001];
        dfs(res.first, 0, -1, level, nbs);
        int mxLevel;
        for(int i = 0; i < 1000 ; ++i) {
            if(level[i].empty()) break;
            mxLevel = i;
        }
        // debug(mxLevel);84660508
        int start = 0;
        int end = mxLevel;
        pii sel;
        int selLvl = -1;
        while(start <= end) {
            int mid = (start + end)/2;;
            pii ret = printAndFetch(level[mid]);
            // debug(ret.first, ret.second);
            if(ret.second > res.second) {
                end = mid - 1;
            }
            else {
                selLvl = mid;
                sel.first = ret.first;
                sel.second = ret.second;
                start = mid + 1;
            }
        }
        // if(___test_it___ == 9 && n == 10) {
        //  assert(res.first == 2 || res.first == 10);
        // }
        // debug(selLvl);
        int remDist = res.second - selLvl;

        // debug(remDist);
        if(2 * remDist == res.second) {
            level[remDist].erase(find(ALL(level[remDist]), sel.first));
            pii ret2 = printAndFetch(level[remDist]);
            cout<<"! "<<ret2.first<<" "<<sel.first<<endl;
        }

        else {
            // debug("Both at diff level");
            pii ret2 = printAndFetch(level[remDist]);
            cout<<"! "<<ret2.first <<" "<< sel.first<<endl;
        }
        string verdict;
        cin>>verdict;
        cout<<endl;
        assert(verdict == "Correct");
    }

    return 0;
}