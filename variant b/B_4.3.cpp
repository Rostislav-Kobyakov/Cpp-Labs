#include <iostream>
using namespace std;
int main()
{
	unsigned int length_str, length_word = 0, length_word_pr = 0, counter = 0, counter_2;
	const unsigned int MAX = 100;
	char str[MAX], wrd[MAX];
	cout << "Enter String: " << endl;
	cin.getline(str, MAX);
	length_str = strlen(str) - 1; // длина с учетом массива начало с 0
	for (int i = length_str; i >= 0; i--) // проверка на разделители в конце
	{
		if (str[i] == ' ' ||
			str[i] == '.' ||
			str[i] == ',' ||
			str[i] == ':' ||
			str[i] == ';' ||
			str[i] == '!' ||
			str[i] == '?' ||
			str[i] == '-' ||
			str[i] == '(' ||
			str[i] == ')')
		{
			--length_str;
		}
		else break;
	}
	for (int i = length_str; i >= 0; i--) // считаем размер слова
	{
		if (!(str[i] == ' ' ||
			str[i] == '.' ||
			str[i] == ',' ||
			str[i] == ':' ||
			str[i] == ';' ||
			str[i] == '!' ||
			str[i] == '?' ||
			str[i] == '-' ||
			str[i] == '(' ||
			str[i] == ')'))
		{
			++length_word;
		}
		else break;
	}
	for (int i = 0; i <=length_str ; ) // заполнение словами
	{
		length_word_pr = 0; // обнуление проверки длины слова
		if (!(str[i] == ' ' ||
			str[i] == '.' ||
			str[i] == ',' ||
			str[i] == ':' ||
			str[i] == ';' ||
			str[i] == '!' ||
			str[i] == '?' ||
			str[i] == '-' ||
			str[i] == '(' ||
			str[i] == ')'))
		{
			for (int j = i; j <= length_str; j++) // проверка длины слова
			{
				if (!(str[j] == ' ' ||
					str[j] == '.' ||
					str[j] == ',' ||
					str[j] == ':' ||
					str[j] == ';' ||
					str[j] == '!' ||
					str[j] == '?' ||
					str[j] == '-' ||
					str[j] == '(' ||
					str[j] == ')'))
				{
					++length_word_pr;
				}
				else break;
			}
			if (length_word_pr == length_word) // заполнение массива
			{
				for (int j = 0; j < length_word; j++)
				{
					wrd[counter] = str[j + i];
					++counter;
				}
			}
		}
		if (length_word_pr == 0)
		{
			++i;
		}
		else
		{
			counter_2 = length_word_pr;
			i += counter_2;
		}
	}
	for (int i = 0; i < strlen(wrd); i++)
	{
		cout << wrd[i];
	}
	return 0;
}
