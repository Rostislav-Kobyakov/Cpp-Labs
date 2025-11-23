#include <iostream>

using namespace std;

int main()
{
    int n, num, digit, rev = 0;
    cout << "Enter n" << endl;
    cin >> num; // Ввод числа

    n = num;
    if (n >= 1000 && n <= 9999)
    {
        do
        {
            digit = num % 10; // Последняя цифра числа
            rev = (rev * 10) + digit; // Написание реверсированного числа
            num = num / 10; // Отбрасывание последней цифры числа
        } while (num != 0); // Пока число не равно нулю - программа делает дело
        cout << " The reverse of the number is: " << rev << endl;
        if
            (n == rev)
            cout << "The number is a palindrome." << endl;
        else
            cout << "The number is not a palindrome." << endl;
    }
    else cout << "The number is not 4 digit";
    return 0;
}

;