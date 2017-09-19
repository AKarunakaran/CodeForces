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
inline int two(int n) { return 1 << n; }
const double PI = 3.141592654;

/////////////////////////////////////////////////////////////////////

double dist(pair<double, double> p1, pair<double, double> p2) {
	double dx = p1.first-p2.first;
	double dy = p1.second-p2.second;
	return sqrt(dx*dx+dy*dy);
}

double angle(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
	double a = dist(p1, p2);
	double b = dist(p2, p3);
	double c = dist(p1, p3);
	double ang = acos((a*a+b*b-c*c)/(2*a*b));
	return ang*180/PI;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    double a;
    cin >> n >> a;
    vector<pair<double, double>> pts(n, {0, 0});
    FOR(i, 1, n-1) {
    	double curD = (i-1)*(2*PI/n);
    	pts[i] = {pts[i-1].first+(20*cos(curD)), pts[i-1].second+(20*sin(curD))};
    }

    //REP(i, n) cout << pts[i].first << " " << pts[i].second << endl;

    int bestR = 1, bestL = n-1;
    double bestA = (PI-(2*PI/n));
    FORD(left, n-1, 2) {
    	/*FOR(right, 1, left-1) {
    		double curA = angle(pts[left], pts[0], pts[right]);
    		if(fabs(curA-a) < fabs(bestA-a)) {
    			bestR = right;
    			bestL = left;
    			bestA = curA;
    		}
    	}*/

    	int right = left/2, searchL = left, searchR = 0;
    	vector<bool> done(n, 0);
    	while(right <= searchL && right >= searchR) {
    		done[right] = 1;
    		double curA = angle(pts[left], pts[0], pts[right]);
    		//cout << right << " " << left << endl;
    		if(fabs(curA-a) < fabs(bestA-a)) {
    			bestR = right;
    			bestL = left;
    			bestA = curA;
    		}
    		if(curA < a) {
    			searchL = right;
    			right = (right+searchR)/2;
    		} else if(curA > a) {
    			searchR = right;
    			right = (right+searchL)/2;
    		}
    		if(done[right]) break;
    	}
    	//cout << endl;
    }
    cout << bestR+1 << " " << 1 << " " << bestL+1 << endl;

    return 0;
}