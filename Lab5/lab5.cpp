#include <iostream>

using namespace std;

int main() {
	int size = 200;
	int* Ar = new int[size];
	int* Cr = Ar;
	int* Seq;
	int sum;
	
	for (int i = 0; i < size; i++) {
		int r = rand() % 101 - 50;
		*Cr = r;
		Cr += sizeof(int);
	}
	
	Cr = Ar;
	for (int i = 0; i < size; i++) {
		cout << *Cr << " ";
		Cr += sizeof(int);
	}
	
	cout << endl;
	cout << endl;
	
	Cr = Ar;
	for (int i = 0; i < size; i++) {
		Seq = Cr;
		sum = 0;
		
		for(int j = i; j < size; j++) {
			sum += *Seq;
			
			if (sum == 0) {
				Seq = Cr;
				cout << "Zero sequence: ";
				for (int k = i; k < j; k++) {
					cout << *Seq << " ";
					Seq += sizeof(int);
				}
				cout << *Seq << endl;
			}
			
			Seq += sizeof(int);
		}
		
		Cr += sizeof(int);
	}
}
