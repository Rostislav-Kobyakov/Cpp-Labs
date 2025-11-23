#include <iostream>
#include <iomanip>
#include <clocale>	
using namespace std;

int main()
{
    const int N = 10, M = 7, K = 10;
    int A[N] = { 0 }, B[M] = { 0 }, C[K] = { 0 };
    bool flag;
    enum class enmArrayInit
    {
        Uninited = 0, WithConst, WithRand, ByUser,
    };
    setlocale(LC_ALL, "rus");
    cout << " Выберите тип инициализации:\n"
        << (int)enmArrayInit::WithConst << ".константами\n"
        << (int)enmArrayInit::WithRand << ".случайными числами\n"
        << (int)enmArrayInit::ByUser << ".ввести вручную\n";
    cout << "Любая другая кнопка завершит программу\n  Ваш выбор: ";
    int ch = 0;    cin >> ch;

    switch ((enmArrayInit)ch)
    {
    case enmArrayInit::WithConst:
    { // заполнение массива значениями индексов
        for (int i = 0; i < N; i++) A[i] = i;
        for (int i = 0; i < M; i++) B[i] = i;
        break;
    }
    case enmArrayInit::WithRand:
    { // Инициализация массива случайными числами
        for (int i = 0; i < N; i++) A[i] = rand() % 100;
        for (int i = 0; i < M; i++) B[i] = rand() % 100;
        break;
    }
    case enmArrayInit::ByUser:
    {   // ввод элементов массива с клавиатуры
        cout << "Массив A: " << endl;
        for (int i = 0; i < N; i++)  cin >> A[i];
        cout << "Массив B: " << endl;
        for (int i = 0; i < M; i++)  cin >> B[i];
        break;
    }
    default:  cout << "Программа завершается" << endl;
        return 0;
    }
    
    cout << "Массив A: " << endl;
    for (int i = 0; i < N; i++)   cout << setw(3) << A[i];
    cout << endl;
    cout << "Массив B: " << endl;
    for (int i = 0; i < M; i++)   cout << setw(3) << B[i];
    cout << endl;
    for (int i = 1; i < N; i++)
        for (int j = N - 1; j >= i; j--)
            if (A[j - 1] > A[j])
            {
                int x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
            }
    for (int i = 1; i < M; i++)
        for (int j = M - 1; j >= i; j--)
            if (B[j - 1] > B[j])
            {
                int x = B[j - 1];
                B[j - 1] = B[j];
                B[j] = x;
            }
    if (N <= M)
    {
        for (int j = 0, k = 0; j < M; j++)
        {
            for (int i = 0; i < N;i++)
            {
                if (A[j] == B[i])
                {
                    C[k++] = A[j];
                    int l = j + 1, h = i + 1;
                    while (A[j] == A[l])
                    {
                        ++j;
                    }
                    while (B[i] == B[h])
                    {
                        ++i;
                    }
                }
            }
        }
    }
    else
    {
        for (int j = 0, k = 0; j < N; j++)
        {
            for (int i = 0; i < M; i++)
            {
                if (A[j] == B[i])
                {
                    C[k++] = A[j];
                    int l = j + 1, h = i + 1;
                    while (A[j] == A[l])
                    {
                        ++j;
                    }
                    while (B[i] == B[h])
                    {
                        ++i;
                    }
                }
            }
        }
    }
    cout << "Отсортированный массив A: " << endl;
    for (int i = 0; i < N; i++)   cout << setw(3) << A[i];
    cout << endl;
    cout << "Отсортированный массив B: " << endl;
    for (int i = 0; i < M; i++)   cout << setw(3) << B[i];
    cout << endl;
    cout << "Массив C: " << endl;
    for (int i = 0; i < K; i++)   cout << setw(3) << C[i];
    return 0;
}
