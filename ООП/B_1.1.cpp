#include <iostream>
#include <fstream>
#include <assert.h>
#include <time.h>
using namespace std;
void readFile(ifstream &infile)
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
		int v = (rand() % 5 + 1)*2;
		outfile << v << endl;
	}
	for (int i = 1; i <= n / 2; i++)
	{
		int v = 2*(rand() % 5) + 1;
		outfile << v << endl;
	}
}
void Solution(ifstream &even, ifstream &odd, ofstream &outfile)
{
	int even_int = 0;
	int odd_int = 0;
	while (!(even.eof() && odd.eof()))
	{
		for (int i = 1; i <= 2;)
		{
			int data;
			even >> data;
			if (even.eof())
				break;
			if (data % 2 == 0)
			{
				outfile << data << endl;
				i++;
				even_int++;
			}
		}
		for (int i = 1; i <= 2;)
		{
			int data;
			odd >> data;
			if (odd.eof())
				break;
			
			if (!(data % 2 == 0))
			{
				outfile << data << endl;
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
	outfile.open("f.txt");
	assert(outfile.is_open());
	writeFile(outfile, n);
	outfile.close();
	ifstream infile1;
	infile1.open("f.txt");
	assert(infile1.is_open());
	readFile(infile1);
	infile1.clear();
	infile1.seekg(0, ios::beg);
	assert(!infile1.eof());
	ifstream infile2;
	infile2.open("f.txt");
	assert(infile2.is_open());
	ofstream outfile2;
	outfile2.open("g.txt");
	assert(outfile2.is_open());
	Solution(infile1, infile2, outfile2);
	infile1.close();
	infile2.close();
	outfile2.close();
}
