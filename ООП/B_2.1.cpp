#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class vector
{
private:
	int* m_data;
	int m_size;
public:
	vector():
		m_data(nullptr), m_size(0) {}
	vector(int size): m_data(new int [size]), m_size(size){}
	vector(const vector& other) : m_data(new int[other.m_size]), m_size(other.m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
		cout << "Copy" << endl;
	}
	vector(vector&& other) noexcept : m_data(other.m_data), m_size(other.m_size)
	{
		other.m_data = nullptr;
		other.m_size = 0;
		cout << "Move" << endl;
	}

	vector& operator=(const vector& other)
	{
		if (this != &other)
		{
			delete[] m_data;
			m_size = other.m_size;
			m_data = new int[m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = other.m_data[i];
			}
		}
		cout << "Copy operator" << endl;
		return *this;
	}
	vector & operator= (vector&& other) noexcept
	{
		if (this != &other)
		{
			delete[] m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			other.m_data = nullptr;
			other.m_size = 0;
		}
		cout << "Move operator" << endl;
		return *this;
	}
	~vector()
	{
		delete[] m_data;
	}

	void setSize(int size)
	{
		delete[] m_data;
		m_size = size;
		m_data = new int[m_size];
	}
	int getSize()
		const
	{
		return m_size;
	}
	void fillRandom()
	{
		srand(static_cast <unsigned int> (time(nullptr)));
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = rand() % 101;
		}
	}
	int& operator[](int index)
	{
		if (index >= m_size)
		{
			cerr << "Index out of range!" << endl;
			exit(EXIT_FAILURE);
		}
		return m_data[index];
	}
	const int &operator[](int index)
		const
	{
		if (index >= m_size)
		{
			cerr << "Index out of range!" << endl;
			exit(EXIT_FAILURE);
		}
		return m_data[index];
	}
	friend ostream& operator<<(ostream& out, const vector& v)
	{
		out << "[";
		for (int i = 0; i < v.m_size; i++)
		{
			out << v.m_data[i];
			if (i != v.m_size - 1)
			{
				out << ", ";
			}
		}
		out << "]";
		return out;
	}
	friend istream& operator>>(istream& in, vector& v)
	{
		for (int i = 0; i < v.m_size; i++)
		{
			in >> v.m_data[i];
		}
		return in;	
	}
};
void Input(int& n)
{
	cout << "Enter n:" << endl;
	cin >> n;
	if (n > 10e9)
		cout << "invalid n" << endl;
}

void CountingSort(int& n, int b[], const vector& a)
{
	for (int i = 0; i < n; i++)
	{
		int prikol = a[i];
		++b[prikol];
	}
}
void Output(int b[])
{
	for (int i = 10000; i >= 0; i--)
	{
		if (b[i] >= 2)
		{
			cout << setw(6) << i;
		}
	}
}
enum class enmArrayInit
{
	Uninited = 0, WithRand, ByUser,
};
int main()
{
	setlocale(LC_ALL, "rus");
	int* b = new int[10001]{ 0 };
	int n;
	Input(n);
	vector a(n);
	srand(time(NULL));
	cout << " Выберите тип инициализации:\n"
		<< (int)enmArrayInit::WithRand << ".случайными числами\n"
		<< (int)enmArrayInit::ByUser << ".ввести вручную\n";
	cout << "Любая другая кнопка завершит программу\n  Ваш выбор: ";

	int ch = 0;    cin >> ch;

	switch ((enmArrayInit)ch)
	{
	case enmArrayInit::WithRand:
	{ // Инициализация массива случайными числами
		a.fillRandom();
		break;
	}
	case enmArrayInit::ByUser:
	{   // ввод элементов массива с клавиатуры
		for (int i = 0; i < n; i++)  cin >> a[i];
		break;
	}
	default:  cout << "Программа завершается" << endl;
		return 0;
	}
	cout << a << endl;
	CountingSort(n, b, a);
	Output(b);
	delete[] b;
}
