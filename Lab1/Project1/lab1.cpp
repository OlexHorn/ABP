#include <iostream>

using namespace std;

int main()
{
	double x = 0;
	double y = 0;

	bool isEnd = false;

	while (!isEnd) {
		cout << "Commands: (x = " << x << ", y = " << y << ")\n";
		cout << "1: Input coordinates;\n";
		cout << "2: Output result;\n";
		cout << "3: Exit\n";

		int command = 0;
		cin >> command;

		switch (command) {
			case 1: {
				cout << "x: ";
				cin >> x;
				cout << "y: ";
				cin >> y;
				break;
			}
			case 2: {
				bool inUpperPart = (y <= 1 && y >= x && y >= -x);
				bool inLowerPart = (y >= -1 && y <= x && y <= -x);
				if (inUpperPart || inLowerPart) cout << "Point is in the area\n";
				else cout << "Point is out of the area\n";
				break;
			}
			case 3: {
				isEnd = true;
				break;
			}
			default: cout << "False command, try again\n";

		}
	}
}