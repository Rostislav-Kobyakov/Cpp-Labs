#include <iostream>
#include <iomanip>
#include "class_list.h"
using namespace std;
	
int main()
{
	int size1, size2;
	cout << "Enter number of nodes for L1" << endl;
	cin >> size1;
	List L1(size1);
	cout << "L1: " << endl;
	L1.output_list();
	L1.insertionSort();
	cout << "Sorted L1: " << endl;
	L1.output_list();
	cout << "Enter number of nodes for L2" << endl;
	cin >> size2;
	List L2(size2);
	cout << "L2: " << endl;
	L2.insertionSort();
	cout << "Sorted L2: " << endl;
	L2.output_list();
	List L;
	Solution(L, L1, L2);
	cout << "L: " << endl;
	L.output_list();
}
