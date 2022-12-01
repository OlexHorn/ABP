#include <iostream>

using namespace std;

enum Movement {
	DOWN,
	LEFT,
	UP,
	RIGHT
};


void fillMatrix(int** matrix, int size) {
	int number = 1;
	int i = 0;
	int j = 0;
	
	int step = 1;
	int iteration = 1;
	Movement move = DOWN;	                        	
	matrix[0][0] = number;
	
	do {
		switch (move) {
			case DOWN:
				for (int k = i; k < size - step; k++) {
					i++;
					number++;
					matrix[i][j] = number;	
				}
				move = LEFT;
				break;
			case LEFT:
				for (int k = j; k < size - step; k++) {
					j++;
					number++;
					matrix[i][j] = number;	
				}
				move = UP;
				break;
			case UP:
				for (int k = size - i - 1; k < size - step; k++) {
					i--;
					number++;
					matrix[i][j] = number;	
				}
				move = RIGHT;
				break;
			case RIGHT:
				for (int k = size - j - 1; k < size - step; k++) {
					j--;
					number++;	
					matrix[i][j] = number;
				}
				move = DOWN;
				break;
		}
		
		iteration++;
		
		if (iteration == 4) {
			step++;
			iteration = 0;
		}
	} while (i != size / 2 && j != size / 2);
	
	
	if (size % 2 == 1) {
		matrix[size / 2][size / 2] = size * size;
	}
	else {
		matrix[size / 2][size / 2] = size * size - 1; 
		matrix[size / 2 - 1][size / 2] = size * size;	
	}
	
}


int main() {
	int size;
	
	cout << "Enter size of matrix: ";
	cin >> size;
	
	int** matrix = new int*[size];
	
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	
	
	fillMatrix(matrix, size);
	
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
			if (matrix[i][j] < 10) cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}