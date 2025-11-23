#include <iostream>
#include <stack>
using namespace std;
void solution(stack<int> &s, int a[], int ans[], int &i)
{
	
	ans[i] = -1;
	if (!s.empty() && s.top() != -1 && a[s.top() - 1] >= a[i])
	{
		while (!s.empty() && a[s.top() - 1] >= a[i])
			s.pop();
		if (!s.empty() && a[s.top() - 1] < a[i])
			ans[i] = s.top();
		s.push(i + 1);
	}
	else if (!s.empty())
	{
		ans[i] = s.top();
		s.push(i + 1);
	}
	else
		s.push(i + 1);
}

int main()
{
	stack<int> s;
	const int n = 9;
	int a[n]{6, 5, 9, 8, 7, 1 , 2, 3, 5};
	int ans[n];
	for (int i = n - 1; i >= 0; i--)
	{
		solution(s,a,ans,i);
	}
	cout << "Min right: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	while (!s.empty())
		s.pop();

	for (int i = 0; i < n; i++)
	{
		solution(s, a, ans, i);
	}
	cout << "Min left: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}