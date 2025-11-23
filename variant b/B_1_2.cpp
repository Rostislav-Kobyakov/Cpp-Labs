#include <iostream>
using namespace std;

int main()
{
	double x, y, R1, R2;
	cout << "Enter x " << endl;
	cin >> x;
	cout << "Enter y " << endl;
	cin >> y;
	cout << "Enter R1 " << endl;
	cin >> R1;
	cout << "Enter R2 " << endl;
	cin >> R2;
	if ((x * x + y * y <= R1 * R1) && (x * x + y * y >= R2 * R2) && x * y > 0)
		cout << "Coordinate fit" << endl;
	else
		cout << "Coordinate not fit" << endl;
	return 0;
}