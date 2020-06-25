#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, k, ssn[N];
string s;
queue<int> nxt;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> s;
    for(int i = 0; i < n; ++i) {
    	if(s[(i-1+n)%n] == s[i] || s[i] == s[(i+1)%n]) {
            ssn[i] = 0;
    		nxt.push(i);
        } else ssn[i] = k;
    }
    
    while(!nxt.empty()) {
    	int cur = nxt.front();
    	nxt.pop();
        vector<int> neighbors = {(cur-1+n)%n, (cur+1)%n};
        for(int nbr : neighbors) {
        	if(ssn[cur] < ssn[nbr]) {
        		nxt.push(nbr);
        		ssn[nbr] = ssn[cur]+1;
        	}
        }
    }
    for(int i = 0; i < n; ++i) if(ssn[i] & 1) s[i] = 'W'+'B'-s[i];
    cout << s << endl;

    return 0;
}