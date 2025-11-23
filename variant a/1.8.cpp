#include <iostream>
using namespace std;
int main()
{
	int a, b, c, k, n;
	cout << "enter a" << endl;
	cin >> a;
	cout << "enter b" << endl;
	cin >> b;
	cout << "enter c" << endl;
	cin >> c;
	n = c & ~b;
		k = a | n;
		cout << "k is " << k << endl;
		return 0;
}

