#include <iostream>

using namespace std;

class Car {

public:
	string name;
	unsigned int year;
	string color;
	
	Car() {
		name = "DefaultCar";
		year = 2000;
		color = "Black";
	}
	
	Car(string _name, unsigned int _year, string _color) {
		name = _name;
		year = _year;
		color = _color;
	}
	
	Car(Car& car) {
		name = car.name;
		year = car.year;
		color = car.color;
	}
	
	~Car() {
		name.clear();
		color.clear();
	}
	
	void setYear(unsigned int _year) {
		year = _year;
	}
	
	void setName(string _name) {
		name = _name;
	}
	
	void setColor(string _color) {
		color = _color;
	}
	
	void getColor(string& _color) {
		_color = color;
	}
	
	void get(string& _name, unsigned int& _year, string& _color) {
		_name = name;
		_year = year;
		_color = color;
	}
	
	void showColor() {
		cout << "Color: " << color << endl;
	}
	
	void show() {
		cout << "Car: " << name << ", " << year << ", " << color << endl;
	}
};


class SoldCar: public Car {

public:
	string ownerFullName;
	
	SoldCar() 
		: Car()
	{
		ownerFullName = "Uknown";
	}
	
	SoldCar(string _name, unsigned int _year, string _color, string _ownerFullName) 
		: Car(_name, _year, _color)
	{
		ownerFullName = _ownerFullName;
	}
	
	void show() {
		cout << "Sold car: " << name << ", " << year << ", " << color << ", " << ownerFullName << endl;
	}
	
	~SoldCar()
	{
		ownerFullName.clear();
	}

};


int main() {
	cout << "Default ---------------" << endl;
	Car defaultCar;
	defaultCar.show();
	
	cout << "Initialized--------------" << endl;
	Car car("BMW", 2001, "Black");
	car.show();
	car.showColor();
	
	cout << "Sold-------------------" << endl;
	SoldCar soldCar("Mercedes", 1991, "White", "Ivanov Ivan Ivanocich");
	soldCar.show();
	soldCar.showColor();
	
	cout << "Copy of sold-------------" << endl;
	Car copyCar(soldCar);
	copyCar.show();
	
	return 0;
}