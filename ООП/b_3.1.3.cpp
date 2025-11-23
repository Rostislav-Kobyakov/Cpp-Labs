#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool hasDuplicates(const string &word)
{
	for (int i = 0; i < word.length(); i++)
	{
		for (int j = i + 1; j < word.length(); j++)
		{
			if (word[i] == word[j])
				return false;
		}
	}
	return true;
}
int main()
{
	string str;
	cout << "enter string : " << endl;
	getline(cin,str);
	istringstream wordChecker(str);
	string word;
	while (wordChecker >> word)
	{
		if (hasDuplicates(word))
			cout << word << " ";
	}
}
