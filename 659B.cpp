#include <iostream>
using namespace std;

struct Person {
	string name;
	int region;
	int score;
};

void merge(Person* people, int start, int end, int prop) {
	//cout << "merge " << start << " " << end << endl;
	int half = (end - start)/2;
	int idxOne = start;
	int idxTwo = start + half + 1;
	Person* temp = new Person[end - start + 1];
	/*for (int i = start; i <= end; i++) {
		cout << people[i].name << " " << people[i].region << " " << people[i].score << endl;
	}
	cout << endl;*/
	while (idxOne <= start + half || idxTwo <= end) {
		if (idxOne > start + half) {
			temp[(idxOne - start) + (idxTwo - (start + half + 1))] = people[idxTwo];
			idxTwo++;
		} else if (idxTwo > end) {
			temp[(idxOne - start) + (idxTwo - (start + half + 1))] = people[idxOne];
			idxOne++;
		} else {
			switch (prop) {
				case 1:
					if (people[idxOne].region <= people[idxTwo].region) {
						temp[(idxOne - start) + (idxTwo - (start + half + 1))] = people[idxOne];
						idxOne++;
					} else {
						temp[(idxOne - start) + (idxTwo - (start + half + 1))] = people[idxTwo];
						idxTwo++;
					}
					break;

				case 2:
					if (people[idxOne].score >= people[idxTwo].score) {
						temp[(idxOne - start) + (idxTwo - (start + half + 1))] = people[idxOne];
						idxOne++;
					} else {
						temp[(idxOne - start) + (idxTwo - (start + half + 1))] = people[idxTwo];
						idxTwo++;
					}
					break;
			}
		}
	}
	for (int i = start; i <= end; i++) {
		people[i] = temp[i - start];
	}
	/*for (int i = start; i <= end; i++) {
		cout << people[i].name << " " << people[i].region << " " << people[i].score << endl;
	}
	cout << endl;*/

	delete[] temp; temp = 0;
}

void sortByProperty(Person* people, int start, int end, int prop) {
	//cout << "sBP " << start << " " << end << endl;
	if (end - start <= 1) {
		if (end - start == 1) {
			merge(people, start, end, prop);
		}
		return;
	}
	//cout << endl;
	int half = (end - start)/2;
	sortByProperty(people, start, start + half, prop);
	sortByProperty(people, start + half + 1, end, prop);
	merge(people, start, end, prop);
}

int main() {
	int n, m;
	cin >> n >> m;
	Person* people = new Person[n];
	for (int i = 0; i < n; i++) {
		cin >> people[i].name >> people[i].region >> people[i].score;
	}
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		cout << people[i].name << " " << people[i].region << " " << people[i].score << endl;
	}
	cout << endl;*/
	sortByProperty(people, 0, n - 1, 1);
	/*for (int i = 0; i < n; i++) {
		cout << people[i].name << " " << people[i].region << " " << people[i].score << endl;
	}
	cout << endl;*/
	int idxStart = 0;
	int idxEnd = 0;
	int* regionIndices = new int[m + 1];
	regionIndices[0] = 0;
	for (int i = 0; i < m; i++) {
		int currentRegion = people[idxEnd].region;
		//cout << "currentRegion: " << currentRegion << endl;
		while (people[idxEnd].region == currentRegion && idxEnd != n) {
			idxEnd++;
		}
		//cout << "idxEnd: " << idxEnd << endl;
		//cout << "region: " << people[idxEnd].region << endl;
		sortByProperty(people, idxStart, idxEnd - 1, 2);
		idxStart = idxEnd;
		regionIndices[i + 1] = idxStart;
	}
	/*for (int i = 0; i < n; i++) {
		cout << people[i].name << " " << people[i].region << " " << people[i].score << endl;
	}
	cout << endl;*/
	/*cout << "Region Indices: ";
	for (int i = 0; i < m; i++) {
		cout << regionIndices[i] << " ";
	}
	cout << endl;*/
	for (int i = 0; i < m; i++) {
		if (people[regionIndices[i] + 1].score != people[regionIndices[i]].score && people[regionIndices[i] + 1].score != people[regionIndices[i] + 2].score) {
			cout << people[regionIndices[i]].name << " " << people[regionIndices[i] + 1].name << endl;
		} else {
			cout << "?" << endl;
		}
	}
	delete regionIndices; regionIndices = 0;
	delete[] people; people = 0;

	return 0;
}