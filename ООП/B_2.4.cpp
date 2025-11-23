#include <iostream>
std::size_t gAllocCounter = 0;
std::size_t gDeallocCounter = 0;

void* operator new(std::size_t size) {
	++gAllocCounter;
	return std::malloc(size);
};

void operator delete(void* ptr) {
	if (ptr == nullptr)
		return;
	std::free(ptr);
	++gDeallocCounter;
};

void LeakState() {
	std::cout << std::endl;
	if (gAllocCounter > gDeallocCounter)
	{
		std::cout << "!!! LEAKS FOUND !!!" << std::endl;
		std::cout << "=== ALLOCATIONS COUNT: " << gAllocCounter << " ===" << std::endl;
		std::cout << "=== DEALLOCATIONS COUNT: " << gDeallocCounter << " ===" << std::endl;
	}
	else if (gAllocCounter < gDeallocCounter)
	{
		//TODO Что написать?
	}
	else {
		std::cout << "=== LEAKS NOT FOUND ===" << std::endl;
	}
};
using namespace std;
class vector
{
private:
	char* m_data;
	int m_size;
public:
	vector() :
		m_data(nullptr), m_size(0) {}
	vector(int size) : m_data(new char[size]), m_size(size) {}
	vector(const vector& other) : m_data(new char[other.m_size]), m_size(other.m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
		//cout << "Copy" << endl;
	}
	vector(vector&& other) noexcept : m_data(other.m_data), m_size(other.m_size)
	{
		other.m_data = nullptr;
		other.m_size = 0;
		//cout << "Move" << endl;
	}

	vector& operator=(const vector& other)
	{
		if (this != &other)
		{
			delete[] m_data;
			m_size = other.m_size;
			m_data = new char[m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = other.m_data[i];
			}
		}
		//cout << "Copy operator" << endl;
		return *this;
	}
	vector& operator= (vector&& other) noexcept
	{
		if (this != &other)
		{
			delete[] m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			other.m_data = nullptr;
			other.m_size = 0;
		}
		//cout << "Move operator" << endl;
		return *this;
	}
	~vector()
	{
		cout << "destructor" << endl;
		delete[] m_data;
	}

	void setSize(int size)
	{
		delete[] m_data;
		m_size = size;
		m_data = new char[m_size];
	}
	int getSize()
		const
	{
		return m_size;
	}
	char getData(int i)
	{
		return m_data[i];
	}
	void fillRandom()
	{
		srand(static_cast <unsigned int> (time(nullptr)));
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = rand() % 101;
		}
	}
	char& operator[](char index)
	{
		if (index >= m_size)
		{
			cerr << "Index out of range!" << endl;
			exit(EXIT_FAILURE);
		}
		return m_data[index];
	}
	const char& operator[](int index)
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
	void add(char data)
	{
		char* temp = new char[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		temp[m_size] = data;
		m_size++;
		delete[]m_data;
		m_data = temp;
		temp = nullptr;
	}
	void erase(int index)
	{
		while (index <= m_size - 1)
		{
			m_data[index] = m_data[index + 1];
				index++;
		}
		m_size--;
	}
	friend istream& operator>>(istream& in, vector& v)
	{
		for (int i = 0; i < v.m_size; i++)
		{
			in >> v.m_data[i];
		}
		return in;
	}
	void doublesErase()
	{
		for (int i = 0; i < m_size - 1; i++)
		{
			for (int j = 1; j < m_size; j++)
			{
				if (i != j && m_data[i] == m_data[j])
				{
					erase(j);
					--j;
				}
			}
		}
	}
	void merge(vector& a, vector& b, vector& c) // A U B = C
	{
		vector work_a(a);
		vector work_b(b);
		work_a.doublesErase();
		work_b.doublesErase();
		for (int i = 0; i < a.m_size; i++)
		{
			 c.add(work_a.m_data[i]);
		}
		for (int i = 0; i < b.m_size; i++)
		{
			c.add(work_b.m_data[i]);
		}
	}
	void intersection(vector& a, vector& b, vector& c) // A n B = C
	{

		vector work_a(a);
		vector work_b(b);
		work_a.doublesErase();
		work_b.doublesErase();
		for (int i = 0; i < work_a.m_size; i++)
		{
			for (int j = 0; j < work_b.m_size; j++)
			{
				if (work_a.m_data[i] == work_b.m_data[j])
				{
					c.add(work_a.m_data[i]);
					work_a.erase(i);
					--i;
					work_b.erase(j);
					--j;
					break;
				}
			}
		}
		
	}
	void difference(vector& a, vector& b, vector& c)
	{
		vector work_a(a);
		vector work_b(b);
		work_a.doublesErase();
		work_b.doublesErase();
		for (int i = 0; i < work_a.m_size; i++)
		{
			bool flag = 0;
			for (int j = 0; j < work_b.m_size; j++)
			{
				if (work_a.m_data[i] == work_b.m_data[j])
				{
					flag = 1;
				}
				if (flag)
					break;
			}
			if (!flag)
				c.add(work_a.m_data[i]);
		}
		for (int i = 0; i < work_b.m_size; i++)
		{
			bool flag = 0;
			for (int j = 0; j < work_a.m_size; j++)
			{
				if (work_a.m_data[i] == work_b.m_data[j])
				{
					flag = 1;
				}
				if (flag)
					break;
			}
			if (!flag)
				c.add(work_b.m_data[i]);
		}
	}
	friend vector operator+(vector &a,vector& b) //слияние
	{
		vector work_a(a);
		vector work_b(b);
		vector c;
		work_a.doublesErase();
		work_b.doublesErase();
		for (int i = 0; i < a.m_size; i++)
		{
			c.add(work_a.m_data[i]);
		}
		for (int i = 0; i < b.m_size; i++)
		{
			c.add(work_b.m_data[i]);
		}
		return c;
	}
	friend vector operator-(vector& a, vector& b)//разность
	{
		vector work_a(a);
		vector work_b(b);
		vector c;
		work_a.doublesErase();
		work_b.doublesErase();
		for (int i = 0; i < work_a.m_size; i++)
		{
			bool flag = 0;
			for (int j = 0; j < work_b.m_size; j++)
			{
				if (work_a.m_data[i] == work_b.m_data[j])
				{
					flag = 1;
				}
				if (flag)
					break;
			}
			if (!flag)
				c.add(work_a.m_data[i]);
		}
		for (int i = 0; i < work_b.m_size; i++)
		{
			bool flag = 0;
			for (int j = 0; j < work_a.m_size; j++)
			{
				if (work_a.m_data[i] == work_b.m_data[j])
				{
					flag = 1;
				}
				if (flag)
					break;
			}
			if (!flag)
				c.add(work_b.m_data[i]);
		}
		return c;
	}
	friend vector operator/(vector& a, vector& b) //пересечение
	{
		vector work_a(a);
		vector work_b(b);
		vector c;
		work_a.doublesErase();
		work_b.doublesErase();
		for (int i = 0; i < work_a.m_size; i++)
		{
			for (int j = 0; j < work_b.m_size; j++)
			{
				if (work_a.m_data[i] == work_b.m_data[j])
				{
					c.add(work_a.m_data[i]);
					work_a.erase(i);
					--i;
					work_b.erase(j);
					--j;
					break;
				}
			}
		}
		return c;
	}
	vector& operator-(int index)
	{
		while (index <= m_size - 1)
		{
			m_data[index] = m_data[index + 1];
			index++;
		}
		m_size--;
		return *this;
	}
	vector& operator+(char data)
	{
		char* temp = new char[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		temp[m_size] = data;
		m_size++;
		delete[]m_data;
		m_data = temp;
		temp = nullptr;
		return *this;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	vector str;
	str.add('s');
	str.add('a');
	str.add('b');
	cout << str << endl;
	vector str2;
	//str2.add('a');
	str2.add('s');
	str2.add('c');
	cout << str2 << endl;
	vector c1;
	vector c2;
	vector c3;
	//c1.merge(str, str2, c1);
	c1 = str + str2;
	cout << c1 << endl;
	//c2.intersection(str, str2, c2);
	c2 = str / str2;
	cout << c2 << endl;
	//c3.difference(str, str2, c3);
	c3 = str - str2;
	cout << c3 << endl;
	LeakState();
}
