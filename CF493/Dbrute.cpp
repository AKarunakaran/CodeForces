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

int n;
vector<char> c = {'I', 'V', 'X', 'L'};
vector<char> x = {1, 5, 10, 50};
set<int> vs, xs;

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    // FOR(i, 1, 1000) {
    // 	FOR(j, 1, 1000000) {
    // 		if(50*i+5*j == 10*(i+j)) {
    // 			bool good = true;
    // 			for(int num : xs) {
    // 				if((i+j) % num == 0) {
    // 					good = false;
    // 					break;
    // 				}
    // 			}
    // 			if(good) {
    // 				cout << i << " L, " << j << " V == " << i+j << "X" << endl;
    // 				xs.insert(i+j);
    // 			}
    // 		}
    // 		if(50*i+j == 10*(i+j)) {
    // 			bool good = true;
    // 			for(int num : xs) {
    // 				if((i+j) % num == 0) {
    // 					good = false;
    // 					break;
    // 				}
    // 			}
    // 			if(good) {
    // 				cout << i << " L, " << j << " I == " << i+j << "X" << endl;
    // 				xs.insert(i+j);
    // 			}
    // 		}
    // 	}
    // }
    FOR(i, 1, 100) {
    	FOR(j, 1, 1000) {
    		FOR(k, 1, 10000) {
    			if(50*i+10*j+1*k == 5*(i+j+k)) {
    				bool good = true;
					for(int num : vs) {
						if((i+j+k) % num == 0) {
							good = false;
							break;
						}
					}
					if(good) {
						cout << i << " L, " << j << " X, " << k << " I == " << i+j+k << "V" << endl;
						vs.insert(i+j+k);
					}
    			}
    			if(50*i+5*j+1*k == 10*(i+j+k)) {
    				bool good = true;
					for(int num : xs) {
						if((i+j+k) % num == 0) {
							good = false;
							break;
						}
					}
					if(good) {
						cout << i << " L, " << j << " V, " << k << " I == " << i+j+k << "X" << endl;
						xs.insert(i+j+k);
					}
    			}
    		}
    	}
    }

    return 0;
}