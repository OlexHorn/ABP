#include <iostream>

using namespace std;

struct detailInfo {
	string name;
	char type;
	int number;
	int weight;
};

struct stack {
	struct detailInfo detail;
	stack* next; 
};


stack* createStack() {
	int n;
	stack* elem = NULL;
	stack* st = NULL;
	
	do {
		elem = new(stack);
		cout << "Enter detail info with number " << n + 1 << ": ";
		
		cin >> elem->detail.name;
		
		if (elem->detail.name == "***") break;
		
		cin >> elem->detail.type >> elem->detail.number >> elem->detail.weight;
		
		elem->next = st;
		st = elem;
		n++;	
			
	} while (n < 10);
		
	return st;
	
}

stack* getElementFromStack(stack* st) {
	stack* elem = st;
	st = st->next;
	
	return elem;
}

stack* addElementToStack(stack* st, struct detailInfo detail) {
	stack* elem = new(stack);
	elem->detail = detail;
	elem->next = st;
	
	return elem;
}


void printStack(stack* stToPrint) {
	int maxNameLen = 4;
	int maxNumberLen = 6;
	int maxWeightLen = 6;
		
	int i = 0;	
	stack* st = stToPrint;
	
	do {
		string name = st->detail.name;
		string numberStr = to_string(st->detail.number);
		string weightStr = to_string(st->detail.weight); 
		
		
		if (maxNameLen < name.length()) {
			maxNameLen = name.length();
		}
		
		if (maxNumberLen < numberStr.length()){
			maxNumberLen = numberStr.length();
		}
		
		if (maxWeightLen < weightStr.length()){
			maxWeightLen = weightStr.length();
		}
		
		st = st->next;
		i++;
	} while (st != NULL);
	
	
	string topline = "|";	
	for (int i = 0; i < maxNameLen + maxNumberLen + maxWeightLen + 7; i++){
		topline += "-";
	}
	topline += "|";	
	
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
	
		
	i = 0;	
	st = stToPrint;
	
	do {
		cout << line << endl;
		string name = st->detail.name;
		string numberStr = to_string(st->detail.number);
		string weightStr = to_string(st->detail.weight); 
		
		
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
		
		cout << "|" << name << nameSpace << "|" << st->detail.type << "   |" << numberStr 
			<< numberSpace << "|" << weightStr << weightSpace << "|" << endl;
				
		st = st->next;
		i++;
	} while (st != NULL);
	
	cout << topline << endl;
	
}


int countElements(stack* st) {
	int number = 0;
	
	while (st != NULL) {
		st = st->next;
		number++;
	}
	
	return number;
}

stack* sortStack(stack* st) {
	int length = countElements(st);
	
	struct detailInfo tmp1, tmp2;
	stack* tmpSt = NULL;
	stack* sortedSt = NULL;
	
	for (int i = 0; i < length - 1; i++) {
		tmp1 = st->detail;
	
		for (int j = 0; j < length - 1 - i; j++) {
			tmp2 = st->next->detail;
			
			if (tmp1.name > tmp2.name) {
				tmpSt = addElementToStack(tmpSt, tmp2);
				st->next = st->next->next;
			}
			else {
				
				tmpSt = addElementToStack(tmpSt, tmp1);	
				st = st->next;				
				tmp1 = tmp2;
			}
		}
		
		st = tmpSt;
		tmpSt = NULL;
		
		sortedSt = addElementToStack(sortedSt, tmp1);
		
	}
	
	sortedSt = addElementToStack(sortedSt, st->detail);
	
	return sortedSt;
}


int main() {
	stack* st = createStack();
	
	st = sortStack(st);
	
	printStack(st);
}
