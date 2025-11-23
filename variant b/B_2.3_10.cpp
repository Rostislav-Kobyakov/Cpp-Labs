#include <iostream>
using namespace std;
int main()
{
	int n = 1001, rev, digit, num;
    for (;n <= 9997;)
    {
        num = n;
        bool pr = true;
        for (int k = 2; (k <= num / 2) && pr; k++)
        {
            if (!(num % k))
                pr = false;
        }
            if (pr)
            {
                rev = 0;
                bool pr_rev = true;
                do
                {
                    digit = num % 10; // Последняя цифра числа
                    rev = (rev * 10) + digit; // Написание реверсированного числа
                    num = num / 10; // Отбрасывание последней цифры числа
                } while (num != 0);
                for (int k = 2; (k <= rev / 2) && pr_rev; k++)
                    if (!(rev % k))
                        pr_rev = false;
                if (pr && pr_rev)
                    cout << n << " and " << rev << endl;
            }
            ++n;
    }

    return 0;
}
