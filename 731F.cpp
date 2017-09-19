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

void merge(vector<int>& arr, int start, int end) {
	int half = (end - start)/2;
	int idxOne = start;
	int idxTwo = start + half + 1;
	int* temp = new int[end - start + 1];
	while (idxOne <= start + half || idxTwo <= end) {
		if (idxOne > start + half) {
			temp[(idxOne - start) + (idxTwo - (start + half + 1))] = arr[idxTwo];
			idxTwo++;
		} else if (idxTwo > end) {
			temp[(idxOne - start) + (idxTwo - (start + half + 1))] = arr[idxOne];
			idxOne++;
		} else {
			if (arr[idxOne] <= arr[idxTwo]) {
				temp[(idxOne - start) + (idxTwo - (start + half + 1))] = arr[idxOne];
				idxOne++;
			} else {
				temp[(idxOne - start) + (idxTwo - (start + half + 1))] = arr[idxTwo];
				idxTwo++;
			}
		}
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i - start];
	}

	delete[] temp; temp = 0;
}

void mergeSort(vector<int>& arr, int start, int end) {
	if (end - start <= 1) {
		if (end - start == 1) {
			merge(arr, start, end);
		}
		return;
	}
	int half = (end - start)/2;
	mergeSort(arr, start, start + half);
	mergeSort(arr, start + half + 1, end);
	merge(arr, start, end);
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	vector<int> ps(n);
	forn(i, n) cin >> ps[i];
	mergeSort(ps, 0, n-1);
	int max = 0;
	int ld = 1;
	int sum = 0;
	forn(i, n) {
		if (gcd(ps[i], ld) == 1) ld = ps[i];
		else continue;
		sum = 0;
		for(int j = i; j < n; j++) {
			sum += ps[j] - (ps[j] % ld);
		}
		if (sum > max) max = sum;
	}
	cout << max << endl;

	return 0;
}