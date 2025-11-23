#include <iostream>
using namespace std;
int main()
{
	int k = 0, sum = 0;
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	do
	{
		k = k + 1;
			sum = sum + k*k;
	} while (k < n);
		cout << "sum is " << sum << endl;
	return 0;

}
