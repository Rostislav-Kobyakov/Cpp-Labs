#include <iostream>
#include <iomanip>
#include "class_list.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	n *= 2;
	List L(n);
	cout << "All a: ";
	L.output_list();
	double sum = 0;
	L.Solution(sum);
	cout << "Sum: " << sum << endl;
	
}
