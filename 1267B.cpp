#include <bits/stdc++.h>
using namespace std;

void bad() {
    cout << 0 << endl;
    exit(0);
}

int main() {
    string s;
    cin >> s;
    s.push_back('#');
    int n = s.size(), last = 0;
    vector<pair<char, int>> v;
    for(int i = 1; i < n; ++i) {
        if(s[i] != s[i-1]) {
            v.push_back({s[i-1], i-last});
            last = i;
        }
    }
    n = v.size();
    for(auto& p : v) cout << p.first << ' ' << p.second << "  ";
	cout << endl;
    int m = n/2;
    if(n % 2 == 0) bad();
    for(int i = 0; i < m; ++i) {
        if(v[i].first != v[n-1-i].first) bad();
        if(v[i].second + v[n-1-i].second < 3) bad();
    }
    if(v[m].second < 2) bad();
    cout << v[m].second+1 << endl;
    
    return 0;
}