#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct base // <<Всё, это база, и это главное! (с) Б. Н. Ельцин>>
{
	 //string fio;
	 char fio[255];
	 bool sex; // ыыыыыыыыы
	 int age;
	 int grade;
	 int course;
	 base()
	 {
		 for (int i = 0; i < 255; i++)
		 {
			 fio[i] = '/ 0';
		 }
		 sex = 0;
		 age = 0;
		 grade = 0;
		 course = 0;
	 }
};
ostream& operator << (ostream& os, const base& human)
{
	return os << human.fio << " " << human.sex << " " << human.age << " " << human.grade << " " << human.course;
}


void writeBase(ofstream &file, base &human)
{
		cout << "Enter FIO" << endl;
		cin >> human.fio;
		cout << "Enter sex: 0 for female, 1 for male" << endl;
		cin >> human.sex;
		cout << "Enter age" << endl;
		cin >> human.age;
		cout << "Enter grade: from 0 to 10" << endl;
		cin >> human.grade;
		cout << "Enter course: from 1 to 5" << endl;
		cin >> human.course;
		file.write(reinterpret_cast <char*> (&human), sizeof(human));
}

	void readBase(ifstream &file, base &human)
	{
		file.read(reinterpret_cast <char*> (&human), sizeof(human));
	}
	void Solution(ifstream &file, ofstream &file2, int n)
	{
		base human;
		readBase(file, human);
		if (human.grade > 8 && human.course == n)
		{
			file2.write(reinterpret_cast <char*> (&human), sizeof(human));
		}
	}

int main()
{
	ofstream ofBase;
	base human;
	int k = 3; // количество челов в базе
	ofBase.open("f.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		writeBase(ofBase, human);
	}
	ofBase.close();
	int n;
	cout << "What course?" << endl;
	cin >> n;
	ifstream inBase;
	inBase.open("f.bin", ios::binary);
	ofBase.open("g.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		Solution(inBase, ofBase, n);
		cout << human << endl;
	}
	inBase.close();
	ofBase.close();
}
