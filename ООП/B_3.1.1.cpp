#include <iostream>
#include <string>
using namespace std;
void eraser(string& str, char& max_symb)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == max_symb)
		{
			str.erase(i, 1);
			--i;
		}
	}
}
void algorithm(string &str)
{
	int max = 0;
	int index = 0;
	int max_old = 0;
	char max_symb = 0;
	for (int i = 0; i < str.length();)
	{
		if (str[i] == str[i + 1])
		{
			max = 0;
			index = i;
			while (str[i] == str[i + 1])
			{
				++max;
				++i;
			}
			if (max > max_old)
			{
				max_symb = str[index];
				max_old = max;
			}
		}
		else
			i++;
	}
	eraser(str, max_symb);
}

int main()
{
	string str;
	cout << "enter string: " << endl;
	cin >> str;
	algorithm(str);
	cout << "solution: " << endl;
	cout << str << endl;
}
	