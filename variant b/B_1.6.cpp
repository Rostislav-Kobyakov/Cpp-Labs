#include <iostream>
using namespace std;
int main()
{
	short int n, n1, n7;
	cout << "enter n" << endl;
	cin >> n;
	if (n % 2 == 1)
	{
		cout << "0 bit == 1" << endl;
	}
	else
	{
		cout << "o bit == 0" << endl;
	}
	if ((n >> 3) % 2 == 1)
	{
		cout << "3 bit == 1" << endl;
	}
	else
	{
		cout << "3 bit == 0" << endl;
	}
	if ((n >> 13) % 2 == 1)
	{
		cout << "13 bit == 1" << endl;
	}
	else
	{
		cout << "13 bit == 0" << endl;
	}
	n1 = n ^ 2;
	n7 = n ^ 128;
	cout <<"n with inverted 1 bit = " << n1 << endl;
	cout << "n with inverted 7 bit = " << n7 << endl;
	return 0;
} 
