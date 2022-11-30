#include <iostream>

using namespace std;


class Detail {

public:
	string name;
	char type;
	unsigned int number;
	unsigned int weight;
	
	void set(string _name, char _type, unsigned int _number, unsigned int _weight) {
		name = _name;
		type = _type;
		number = _number;
		weight = _weight;
	}
	
	void get(string& _name, char& _type, unsigned int& _number, unsigned int& _weight) {
		_name = name;
		_type = type;
		_number = number;
		_weight = weight;
	}
	
	void show() {
		cout << "Class instance: " << name << " " << type << " " << number << " " << weight << endl;
	}
};


int main() {
	string name;
	char type;
	unsigned int number;
	unsigned int weight;
	
	string name2;
	char type2;
	unsigned int number2;
	unsigned int weight2;
	
	Detail detail;
	
	cout << "Enter the class instance: ";
	cin >> name >> type >> number >> weight;
	
	detail.set(name, type, number, weight);
	detail.get(name2, type2, number2, weight2);	
	detail.set(name2, type2, number2, weight2);
	detail.show();
	
	
	return 0;
}