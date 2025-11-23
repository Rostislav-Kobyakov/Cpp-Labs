#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
void Input(long int &n)
{
	cout << "Enter n:" << endl;
	cin >> n;
	if (n > 10e9)
		cout << "invalid n" << endl;
}

void CountingSort(long int &n, int b[], int *a)
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
	int b[10001]{0};
	long int n;
	Input(n);
	int* a = new int[n];
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	cout << " Выберите тип инициализации:\n"
		<< (int)enmArrayInit::WithRand << ".случайными числами\n"
		<< (int)enmArrayInit::ByUser << ".ввести вручную\n";
	cout << "Любая другая кнопка завершит программу\n  Ваш выбор: ";

	int ch = 0;    cin >> ch;

	switch ((enmArrayInit)ch)
	{
	case enmArrayInit::WithRand:
		{ // Инициализация массива случайными числами
			for (int i = 0; i < n; i++) a[i] = rand() % 10001;
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
		CountingSort(n, b, a);
		Output(b);
}
