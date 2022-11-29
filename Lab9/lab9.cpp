#include <iostream>
#include <fstream>

using namespace std;


struct detailInfo {
	string name;
	char type;
	int number;
	int weight;
};


fstream file;

void initf(string filePath) {
 	file.open(filePath);	
}

void commit() {
	file.close();
}

void f_add(detailInfo* detail) {
	file.clear();
	file.seekg(0, ios_base::end);
	file << endl << detail->name << " " << detail->type << " " << detail->number << " " <<  detail->weight;
}

int fcheck_number(int n) {
	file.clear();
	file.seekg(0);
	string line;
	int lineNumber = 0;;
	
	while (getline(file, line)) {
		++lineNumber;
	}
        
    if (n < lineNumber) return -1;
    
    return 0;
}

void fshow_1(int n) {
	if (fcheck_number(n)) {
		file.clear();
		file.seekg(0);
		
		string line;
		for (int i = 0; i < n; i++) {
			getline(file, line);
		}
		
		struct detailInfo* detail = new(detailInfo);
		
		file >> detail->name >> detail->type >> detail->number >> detail->weight;
		cout << detail->name << " " << detail->type << " " << detail->number << " " <<  detail->weight << endl;
	} 	
}


struct detailInfo* fget_1(int n) {
	file.clear();
	file.seekg(0);
	
	string line;
	for (int i = 0; i < n; i++) {
		getline(file, line);
	}
	
	struct detailInfo* detail = new(detailInfo);
	
	file >> detail->name >> detail->type >> detail->number >> detail->weight;
	
	return detail;
}

void fshow_all() {
	file.clear();
	file.seekg(0);
	
	int maxNameLen = 4;
	int maxNumberLen = 6;
	int maxWeightLen = 6;
	
	struct detailInfo* detail;
	
	int n = 0;
	while (fcheck_number(n)) {
		detail = fget_1(n);
		
		string name = detail->name;
		string numberStr = to_string(detail->number);
		string weightStr = to_string(detail->weight);
		
		if (maxNameLen < name.length()) {
			maxNameLen = name.length();
		}
		
		if (maxNumberLen < numberStr.length()){
			maxNumberLen = numberStr.length();
		}
		
		if (maxWeightLen < weightStr.length()){
			maxWeightLen = weightStr.length();
		}
		
		n++;
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
	
	
	n = 0;
	while (fcheck_number(n)) {
		cout << line << endl;
			
		detail = fget_1(n);
		
		string name = detail->name;
		string numberStr = to_string(detail->number);
		string weightStr = to_string(detail->weight);
		
		
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
		
		cout << "|" << name << nameSpace << "|" << detail->type << "   |" << numberStr 
			<< numberSpace << "|" << weightStr << weightSpace << "|" << endl;
		
		n++;
		
	}
	cout << topline << endl;
}


void fdel_item(int n) {
	if (fcheck_number(n)) {
		file.clear();
		file.seekg(0);
		
		string line;
		for (int i = 0; i < n; i++) {
			getline(file, line);
		}
		
		string deleteline;		
    	getline(file, deleteline);
    	
    				
    	ofstream temp;
    	temp.open("temp.txt");
    	
    	
		
		file.clear();
		file.seekg(0);
		
		int end = 0;
		while (getline(file, line)) {
			if (line != deleteline) {
				if (!end) {
					temp << line;
				}
				else {
					temp << endl << line;
				}
    			end++;
			}
		}

		temp.close();
		file.close();
		remove("details.txt");
		rename("temp.txt", "details.txt");
    	
    	initf("details.txt");
    	
	}
}


void sortInFile(){
	int n = 0;
	string line;
	
	while (getline(file, line)) {
		n++;
	}
	

	for (int i = 0; i < n - 1; i++) {
		file.clear();
		file.seekg(0);
		
		struct detailInfo* maxDetail = new(detailInfo);
		struct detailInfo* tmpDetail = new(detailInfo);
		int maxn = 0;
		
		file >> maxDetail->name >> maxDetail->type >> maxDetail->number >> maxDetail->weight;
		
		for (int j = 1; j < n - i; j++) {
			file >> tmpDetail->name >> tmpDetail->type >> tmpDetail->number >> tmpDetail->weight;
			
			if (tmpDetail->name > maxDetail->name) {
				maxDetail = tmpDetail;
				maxn = j;
			}
		}
		
		fdel_item(maxn);
		f_add(maxDetail);
		
	}
	
	
} 



int main() {	
	initf("details.txt");
	
	sortInFile();
	fshow_all();
	
	commit();
	
	return 0;
	
}