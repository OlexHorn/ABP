#include <iostream>
#include <cmath>


using namespace std;

int main() {
	double sum = 0;
	double term = 0;
	int n = 0;
	
	double k1 = 0;
	double k2 = 0;
	short sign = 1;
	
	// an = (-1)^n * (n^2 + 1) * (n^3 + 3)
	
	do {
		k1 = pow(n, 2) + 1;
		k2 = pow(n, 3) + 3;
		term = sign * k1 / k2;
		sum += term;
		
		if (n == 9) cout << "10: " << sum << endl;
		
		sign *= -1;
		n++;
		
	} while (abs(term) >= 0.000001);
	
	cout << "Series: " << sum << endl;
	cout << "Number of iterations: " << --n << endl;
	
	return 0;
}
