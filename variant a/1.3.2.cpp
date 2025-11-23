
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, T, S;
	cout << "Enter a " << endl;
	cin >> a;
	cout << "Enter b " << endl;
	cin >> b;
	cout << "Enter c " << endl;
	cin >> c;
	T = a && !b || a && !c;
	S = a && !b && !c;
	if (T = S)
		cout << "True" << endl;
	else cout << "False" << endl;
	return 0;
}

