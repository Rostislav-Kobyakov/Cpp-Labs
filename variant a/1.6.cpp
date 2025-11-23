#include <iostream>
using namespace std;
int main()
{
	double x, y, z;
	cout << "enter cathetus x" << endl;
	cin >> x;
	cout << "enter cathetus y" << endl;
	cin >> y;
	cout << "enter hypotenuse z" << endl;
	cin >> z;
	x + y > z ? cout << "xyz is triangle" << endl : cout << "xyz is not triangle" << endl;
	if (x * x + y * y > z * z)
		cout << "xyz is acute-angled triangle" << endl;
	else
		cout << "xyz is not acute-angled triangle" << endl;
	return 0;
}
