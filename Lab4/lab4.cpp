#include <iostream>

using namespace std;

enum Movement {
	LEFT,
	DOWN,
	RIGHT,
	UP
};

int main() {
	int n = 9;
	int arr[9][9];
	
	int number = 1;
	int i = 4;
	int j = 4;
	
	int circle = 1;
	int circleIteration = 0;
	Movement move = LEFT;	                        	
	arr[i][j] = number;
	
	do {
		switch (move) {
			case LEFT:
				for (int k = 0; k < circle; k++) {
					j--;
					number++;
					arr[i][j] = number;	
				}
				move = DOWN;
				break;
			case DOWN:
				for (int k = 0; k < circle; k++) {
					i++;
					number++;
					arr[i][j] = number;	
				}
				move = RIGHT;
				break;
			case RIGHT:
				for (int k = 0; k < circle; k++) {
					j++;
					number++;
					arr[i][j] = number;	
				}
				move = UP;
				break;
			case UP:
				for (int k = 0; k < circle; k++) {
					i--;
					number++;	
					arr[i][j] = number;
				}
				move = LEFT;
				break;
		}
		
		circleIteration++;
		
		if (circleIteration == 2) {
			circle++;
			circleIteration = 0;
		}
	} while (i > 0 || j > 0);
	
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
			if (arr[i][j] < 10) cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}