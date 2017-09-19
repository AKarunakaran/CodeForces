#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

typedef unsigned long long ull;
#define forn(i, n) for(int i = 0; i < (int) n; i++)
#define forn1(i, n) for(int i = 1; i <= (int) n; i++)

int main() {
	string in;
	cin >> in;
	int l = 1;
	int sum = 0;
	forn(i, in.size()) {
		int n = in[i] - 'a' + 1;
		sum += min(abs(l-n), 26 - abs(l-n));
		l = n;
	}
	cout << sum << endl;

	return 0;
}