#include <iostream>
using namespace std;
int main()
{
    unsigned int k, digit, digit_final, k1 = 1, num, number, z;
    cout << "enter k" << endl;
    cin >> k;
    for (int i = 0; i <= k;)
    {
        number = pow(3, i);
        z = 0;
        num = number;
        do // счет кол-ва разрядов числа
        {
            num /= 10;
            ++z;
        } while (num != 0);
        do
        {
            num = number;
            digit = num / pow(10,z-1);
            digit_final = digit % 10;
            ++k1;
            --z;
        } while (z > 0 && k1 <= k);
        ++i;
        if (k1 > k)
            break;
    }
    cout << "k is " << digit_final << endl;
    return 0;
}
