#include <iostream>
#include <fstream>
#include <assert.h>
#include <time.h>
using namespace std;
void readFile(ifstream& infile)
{
	int v;
	infile >> v;
	while (!infile.eof())
	{
		cout << v << " ";
		infile >> v;
	}
	cout << endl;
}
void writeFile(ofstream& outfile, int n)
{
	for (int i = 1; i <= n / 2; i++)
	{
		int v = (rand() % 5 + 1) * 2;
		outfile.write(reinterpret_cast <char*> (&v), sizeof(int));
	}
	for (int i = 1; i <= n / 2; i++)
	{
		int v = 2 * (rand() % 5) + 1;
		outfile.write(reinterpret_cast <char*> (&v), sizeof(int));
	}
}
void Solution(ifstream& even, ifstream& odd, ofstream& outfile)
{
	int even_int = 0;
	int odd_int = 0;
	while (!(even.eof() && odd.eof()))
	{
		for (int i = 1; i <= 2;)
		{
			int data;
			even.read(reinterpret_cast <char*> (&data), sizeof(int));
			if (even.eof())
				break;
			if (data % 2 == 0)
			{
				outfile.write(reinterpret_cast <char*> (&data), sizeof(int));
				i++;
				even_int++;
			}
		}
		for (int i = 1; i <= 2;)
		{
			int data;
			odd.read(reinterpret_cast <char*> (&data), sizeof(data));
			if (odd.eof())
				break;
			
			if (!(data % 2 == 0))
			{
				outfile.write(reinterpret_cast <char*> (&data), sizeof(data));
				i++;
				odd_int++;
			}
		}
	}
	if (!(even_int == odd_int))
		cout << "number of even != number of odd";
	else
		cout << "number of even == number of odd";

}
int main()
{
	srand((unsigned)time(NULL));
	int n = 8;
	ofstream outfile;
	outfile.open("f.bin", ios::binary);
	assert(outfile.is_open());
	writeFile(outfile, n);
	outfile.close();
	ifstream infile1;
	infile1.open("f.bin", ios::binary);
	assert(infile1.is_open());
	ifstream infile2;
	infile2.open("f.bin", ios::binary);
	assert(infile2.is_open());
	ofstream outfile2;
	outfile2.open("g.bin", ios::binary);
	assert(outfile2.is_open());
	Solution(infile1, infile2, outfile2);
	infile1.close();
	infile2.close();
	outfile2.close();
}

