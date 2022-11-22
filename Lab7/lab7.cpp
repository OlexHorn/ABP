#include <iostream>

using namespace std;

struct detail {
	string name;
	char type;
	int number;
	int weight;
};

int main() {
	
	int detailNumber = 0;
	
	cout << "Enter the number of details: ";
	cin >> detailNumber;
	
	struct detail* details = new struct detail[detailNumber];
	
	for (int i = 0; i < detailNumber; i++) {
		cout << "Enter detail info with number " << i + 1 << ": ";
		cin >> details[i].name >> details[i].type >> details[i].number >> details[i].weight;
	}
	
	struct detail tmp;
	
	for (int i = 0; i < detailNumber; i++) {
		for (int j = i + 1; j < detailNumber; j++) {
			if (details[i].name > details[j].name) {
				tmp = details[i];
				details[i] = details[j];
				details[j] = tmp;
			}
		}
	}
	
	for (int i = 0; i < detailNumber; i++) {
		cout << i + 1 << " detail: " << details[i].name << ", " << details[i].type 
			<< ", " << details[i].number << ", " << details[i].weight << endl;
	}
	
	delete [] details;
	
	return 0;
}
