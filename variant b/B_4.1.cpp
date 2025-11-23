#include <iostream>
using namespace std;
int main()
{
	unsigned int counter, length;
	const int MAX = 100;
	char str[MAX];
	cout << "Enter String: " << endl;
	cin.getline(str, MAX);
	length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		counter = 0;
		for (int k = i + 1; k < length; k++)
		{
			if (str[i] == str[k])
			{
				++counter;
				if (str[i] == str[k] && counter > 0)
				{
					for (int j = k; j <= length; j++) // сдвиг влево каждой совпадающей
					{
						str[j] = str[j + 1];
					}
					--length;
					--k;
				}
			}
		}
		if (counter > 0)
		{
			for (int j = i; j <= length - 1; j++) // сдвиг влево исходной буквы
			{
				str[j] = str[j + 1];
			}
			--i;
			--length;
		}
	}
	cout << endl;
	cout << "string after: " << endl;
	cout << str << endl;
	return 0;
}
