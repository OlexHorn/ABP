#include <iostream>

using namespace std;

struct detailType {
	string name;
	char type;
	int number;
	int weight;
};

struct stack {
	struct detailType detail;
	stack* next; 
};


stack* createStack() {
	int detailNumber;
	stack* elem = NULL;
	stack* st = NULL;
	
	cout << "Enter the number of details: ";
	cin >> detailNumber;
	
	for(int i = 0; i < detailNumber; i++) {
		elem = new(stack);
		
		cout << "Enter detail info with number " << i + 1 << ": ";
		cin >> elem->detail.name >> elem->detail.type >> elem->detail.number >> elem->detail.weight;
			
		elem->next = st;
		st = elem;	
	}
	
	return st;
	
}

stack* getElementFromStack(stack* st) {
	stack* elem = st;
	st = st->next;
	
	return elem;
}

stack* addElementToStack(stack* st, struct detailType detail) {
	stack* elem = new(stack);
	elem->detail = detail;
	elem->next = st;
	
	return elem;
}

void printStack(stack* st) {
	int i = 0;
	
	do {
		cout << i + 1 << " detail: " << st->detail.name << ", " << st->detail.type 
			<< ", " << st->detail.number << ", " << st->detail.weight << endl;
		st = st->next;
		i++;
	} while (st != NULL);
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
	
	struct detailType tmp1, tmp2;
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