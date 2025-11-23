#include <iostream>
#include <list>
using namespace std;
void output_list(list<double>& list)
{
	for (const auto& data : list)
	{
		cout << data << "->";
	}
	cout << endl;
}
void input_list(int& k, list <double>& list)
{
	double symbol;
	cout << "Enter numbers: " << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> symbol;
		list.push_front(symbol);
	}
}
void Solution(list <double> l,double& sum)
{
	auto current =l.begin();
	auto last = l.end();
	--last;
	sum = *current * *last;
	current++;
	for (; current != last;)
	{
		--last;
		sum += *current * *last;
		current++;
	}
}
int main()
{
	list <double> L;
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	n *= 2;
	input_list(n, L);
	cout << "All a: ";
	output_list(L);
	double sum = 0;
	Solution(L, sum);
	cout << "Sum: " << sum << endl;
}
