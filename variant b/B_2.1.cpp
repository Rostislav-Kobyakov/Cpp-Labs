#include <iostream>
using namespace std;

int main()
{
    unsigned int n, n0 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, number = 0;
    cout << "enter n" << endl;
    cin >> n;
    do
    {
        number = n % 10;
        if (0 == number)
            n0++;
        else if (1 == number)
            n1++;
        else if (2 == number)
            n2++;
        else if (3 == number)
            n3++;
        else if (4 == number)
            n4++;
        else if (5 == number)
            n5++;
        else if (6 == number)
            n6++;
        else if (7 == number)
            n7++;
        else if (8 == number)
            n8++;
        else if (9 == number)
            n9++;
        n = n / 10;
    } while (n != 0);
    if (n0 > 1 ||
        n1 > 1 ||
        n2 > 1 ||
        n3 > 1 ||
        n4 > 1 ||
        n5 > 1 ||
        n6 > 1 ||
        n7 > 1 ||
        n8 > 1 ||
        n9 > 1)
    {
        cout << "there is same digit";
    }
    else cout << "all digits are not same";
            
    return 0;
}
