#include <iostream>

using namespace std;

struct detail {
	string name;
	char type;
	int number;
	int weight;
};

void printArray(struct detail* details, int detailNumber) {
	int maxNameLen = 0;
	int maxNumberLen = 0;
	int maxWeightLen = 0;
	
	for (int i = 0; i < detailNumber; i++) {
		
		string name = details[i].name;
		string numberStr = to_string(details[i].number);
		string weightStr = to_string(details[i].weight); 
		
		if (maxNameLen < name.length()) {
			maxNameLen = name.length();
		}
		
		if (maxNumberLen < numberStr.length()){
			maxNumberLen = numberStr.length();
		}
		
		if (maxWeightLen < weightStr.length()){
			maxWeightLen = weightStr.length();
		}
	}
	
	string line = "|";	
	for (int i = 0; i < maxNameLen; i++){
		line += "-";
	}	
	line += "|-|";
	for (int i = 0; i < maxNumberLen; i++){
		line += "-";
	}	
	line += "|";
	for (int i = 0; i < maxWeightLen; i++){
		line += "-";
	}
	line += "|";	
	
	
	cout << line << endl;
	
	for (int i = 0; i < detailNumber; i++){
		string name = details[i].name;
		string numberStr = to_string(details[i].number);
		string weightStr = to_string(details[i].weight); 
		
		
		string nameSpace = "";
		string numberSpace = "";
		string weightSpace = "";
		
		for (int i = 0; i < maxNameLen - name.length(); i++){
			nameSpace += " ";
		}		
		for (int i = 0; i < maxNumberLen - numberStr.length(); i++){
			numberSpace += " ";
		}
		for (int i = 0; i < maxWeightLen - weightStr.length(); i++){
			weightSpace += " ";
		}
		
		cout << "|" << name << nameSpace << "|" << details[i].type << "|" << numberStr 
			<< numberSpace << "|" << weightStr << weightSpace << "|" << endl;
		
		cout << line << endl;
		
	}
	
	
}

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
	
	
	printArray(details, detailNumber);
	
	delete [] details;
	
	return 0;
}
