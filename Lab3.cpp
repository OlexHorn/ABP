#include <iostream>

using namespace std;

int main() {
	int n = 200;
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 101 - 50;
	}
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	int pairsCount = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] * arr[i + 1] > 0 || (arr[i] == 0 && arr[i + 1] == 0)) continue;
		pairsCount++;
	}
	
	cout << "Number of pairs: " << pairsCount << endl;
}