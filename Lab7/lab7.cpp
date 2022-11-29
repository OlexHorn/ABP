#include <iostream>

using namespace std;

struct detail {
	string name;
	char type;
	int number;
	int weight;
};

void printDetails(struct detail* details, int n) {
	int maxNameLen = 4;
	int maxNumberLen = 6;
	int maxWeightLen = 6;
	
	for (int i = 0; i < n; i++) {
		
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
	
	string topline = "|";	
	for (int i = 0; i < maxNameLen + maxNumberLen + maxWeightLen + 7; i++){
		topline += "-";
	}
	topline += "|";	
	
	string line = "|";	
	for (int i = 0; i < maxNameLen; i++){
		line += "-";
	}	
	line += "|----|";
	for (int i = 0; i < maxNumberLen; i++){
		line += "-";
	}	
	line += "|";
	for (int i = 0; i < maxWeightLen; i++){
		line += "-";
	}
	line += "|";	
		
	cout << topline << endl;
		
	string nameSpace = "";
	string numberSpace = "";
	string weightSpace = "";
	
	for (int i = 0; i < maxNameLen - 4; i++){
		nameSpace += " ";
	}		
	for (int i = 0; i < maxNumberLen - 6; i++){
		numberSpace += " ";
	}
	for (int i = 0; i < maxWeightLen - 6; i++){
		weightSpace += " ";
	}
	
	cout << "|" << "Name" << nameSpace << "|" << "Type" << "|" << "Number" 
		<< numberSpace << "|" << "Wegiht" << weightSpace << "|" << endl;
	
	
	for (int i = 0; i < n; i++){
		cout << line << endl;
		
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
		
		cout << "|" << name << nameSpace << "|" << details[i].type << "   |" << numberStr 
			<< numberSpace << "|" << weightStr << weightSpace << "|" << endl;
		
	}
	
	cout << topline << endl;
}

int main() {
	
	struct detail* details = new struct detail[10];
	
	int n = 0;
	string input;
	
	do {
		cout << "Enter detail info with number " << n + 1 << ": ";
		
		cin >> details[n].name;
		
		if (details[n].name == "***") break;
		
		cin >> details[n].type >> details[n].number >> details[n].weight;
		n++;	
			
	} while (n < 10);
	
	
	struct detail tmp;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (details[i].name > details[j].name) {
				tmp = details[i];
				details[i] = details[j];
				details[j] = tmp;
			}
		}
	}
	
	
	printDetails(details, n);
	
	delete [] details;
	
	return 0;
}
