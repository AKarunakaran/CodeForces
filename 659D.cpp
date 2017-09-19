#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 1000;

int main() {
	int n, dangerousTurns = 0;
	cin >> n;
	int xValues[MAXN];
	int yValues[MAXN];
	for (int i = 0; i < n; i++) cin >> xValues[i] >> yValues[i];
	int dx, dy;
	int turns[MAXN - 1];
	for (int i = 0; i < n - 1; i++) {
		dx = xValues[i + 1] - xValues[i];
		dy = yValues[i + 1] - yValues[i];
		if (dx == 0) {
			if (dy > 0) {
				turns[i] = 0;
			} else {
				turns[i] = 2;
			}
		} else {
			if (dx > 0) {
				turns[i] = 1;
			} else {
				turns[i] = 3;
			}
		}
	}
	for (int i = 0; i < n-2; i++) 
		if(turns[i+1] - turns[i] == -1 || turns[i+1] - turns[i] == 3) dangerousTurns++;

	cout << dangerousTurns << endl;

	return 0;
}