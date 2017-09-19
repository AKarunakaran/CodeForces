//Date: 4/4/16
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, a, b, k;
	cin >> n >> a >> b;
	k = (a + b > 0) ? (a + b) % n : (a + b) % (-n) + n;
	cout << (k == 0) ? n : k << endl;

	return 0;
}