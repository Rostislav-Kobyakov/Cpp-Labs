#include <iostream>
using namespace std;
int main()
{
    double x[4];
    cout << "Enter x1, x2, x3, x4" << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> x[i];
    }
    bool flag = 0;
    do
    {
        flag = 0;
        for (int j = 0; j < 3; j++)
        {
            if (x[j] < x[j + 1])
            {
                double b = x[j];
                x[j] = x[j + 1];
                x[j + 1] = b;
                flag = 1;
            }
        }
    }
        while (flag == 1);
    cout << "x1 < x2 < x3 < x4 " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}

