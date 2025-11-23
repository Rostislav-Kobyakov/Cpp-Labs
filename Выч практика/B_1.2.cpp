//Сортировочка, потом поиск. Заменить каждый разделитель на /n

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	const unsigned int n = 100;
	char str[n];
	cout << "str= ";
	cin.getline(str, n);
	char del[9] = {' ', '.', ':', ';', '!', '?', '-', '(', ')'};
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < 9 ; j++)
		{
			if (str[i] == del[j])
			{
				str[i] = '/n';
			}
		}
	}

}
