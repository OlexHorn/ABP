#include <iostream>

#define N 3

using namespace std;

class Detail {
	friend ostream& operator << (ostream& stream, Detail& d1);
	friend istream& operator >> (istream& stream, Detail& d1);
	friend void head();
	friend int isvalid(int n);

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
	
	
	Detail operator = (Detail& d2) {
		name = d2.name;
		type = d2.type;
		number = d2.number;
		weight = d2.weight;
		
		return *this;
	}
	
	int operator == (Detail& d1) {
		if (d1.name == name && d1.type == type && d1.number == number && d1.weight == weight)
			return 1;
		return 0;
	}
	
	Detail operator + (Detail& d1) {
		Detail tmp;
		tmp.name = name + d1.name;
		tmp.type = d1.type;
		tmp.number = number + d1.number;
		tmp.weight = weight + d1.weight;
		
		return tmp;
	}
	
	Detail() {
		name = "Uknown";
		type = 'U';
		number = 0;
		weight = 0;
	}
	
	Detail(string _name, char _type, unsigned int _number, unsigned int _weight) {
		name = _name;
		type = _type;
		number = _number;
		weight = _weight;
	}
	
	
};


void head() {
	cout << endl << "Name Type Number Weight" << endl; 
}


int isvalid(int n) {
	if (n < N) return 1;
	return 0;
}


ostream& operator << (ostream& stream, Detail& d1) {
	stream << d1.name << " " << d1.type << " " << d1.number << " " << d1.weight << endl;
	
	return stream;
}


istream& operator >> (istream& stream, Detail& d1) {
	string name;
	char type;
	unsigned int number;
	unsigned int weight;
	
	cin >> name >> type >> number >> weight;
	
	d1.set(name, type, number, weight);
	
	return stream;
}


int main() {
	Detail d1, d2, d3;
	
	cin >> d1 >> d2 >> d3;
	head();
	cout << d1 << d2 << d3;
}