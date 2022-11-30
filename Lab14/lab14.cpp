#include <iostream>

using namespace std;

template <typename T>
class TwoDimensionalArray {

public:
	T** array;
	int n;
	int m;
	
	TwoDimensionalArray() {
		array = NULL;
		n = 0;
		m = 0;
	}
	
	
	TwoDimensionalArray(int _n) {
		int** array = new int*[_n];
		n = _n;
		m = 0;
	}
	
	TwoDimensionalArray(int _n, int _m) {
		n = _n;
		m = _m;
		
		int** array = new int*[n];
		
		for (int i = 0; i < n; i++) {
			array[i] = new int[m];
		}
		
	}
	
	TwoDimensionalArray(T** _array, int _n, int _m) {
		array = _array;
		n = _n;
		m = _m;
	}
	
	
	TwoDimensionalArray(TwoDimensionalArray& tdarr) {
		array = tdarr.array;
	}
	
	void setElem(int n, int m, T value) {
		array[n][m] = value;
	}
	
	T getElem(int n, int m) {
		return array[n][m];
	}
	
	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << array[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	T max() {
		T tmp = array[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (array[i][j] > tmp) {
					tmp = array[i][j];
				}
			}
		}
		return tmp;
	}
	
	T min() {
		T tmp = array[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (array[i][j] < tmp) {
					tmp = array[i][j];
				}
			}
		}
		return tmp;
	}
};


int main() {
	int n = 3;
	int m = 5;
	
	int* a = new int[m]{1, 2, 3, 4, 5};
	int* b = new int[m]{66, 6, 6, 6, 66};
	int* c = new int[m]{10, 9, 8, 7, -1};
	
	int** array = new int*[n]{a, b, c};
	
	TwoDimensionalArray<int> tdaInt(array, n, m);
	
	tdaInt.show();
	cout << "Max: " << tdaInt.max() << endl;
	cout << "Min: " << tdaInt.min() << endl;
	
	cout << endl;
	
	int k = 2;
	int p = 3;
	
	string* strArr1 = new string[p] {"BMW", "Mercedes-Benz", "Honda"};
	string* strArr2 = new string[p] {"Ford", "Skoda", "Toyota"};
	
	string** strTd = new string*[k] {strArr1, strArr2};
	
	TwoDimensionalArray<string> tdaString(strTd, k, p);
	
	tdaString.show();
	
	cout << "Max: " << tdaString.max() << endl;
	cout << "Min: " << tdaString.min() << endl;
	
	
}