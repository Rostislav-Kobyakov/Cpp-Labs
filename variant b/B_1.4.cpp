#include <iostream>
using namespace std;
int main()
{
	int LadX, LadY, SlonX, SlonY;
	cout << "enter LadX" << endl;
	cin >> LadX;
	cout << "enter LadY" << endl;
	cin >> LadY;
	cout << "enter SlonX" << endl;
	cin >> SlonX;
	cout << "enter SlonY" << endl;
	cin >> SlonY;
	if (LadX > 0 && LadX < 9 && LadY > 0 && LadY < 9 && SlonX > 0 && SlonX < 9 && SlonY > 0 && SlonY < 9)
	{
		if (LadX == SlonX ||
			LadY == SlonY) // проверка на ход ладьи
		{
			cout << "Lad attacks" << endl;
		}
		else if (abs(LadX - SlonX) == abs(LadY - SlonY)) // проверка на ход слона
		{
			cout << "Slon attacks" << endl;
		}
		else
		{
			cout << "Lad attacks after 1 move" << endl; // ладья всегда будет бить через один ход
				if ((SlonX + SlonY) % 2 == 1 && (LadX + LadY) % 2 == 1 || // проверка на белую клетку
					(SlonX + SlonY) % 2 == 0 && (LadX + LadY) % 2 == 0) // првоерка на черную клетку
				{
					cout << "Slon attacks after 1 move" << endl;

				}
		}
	}
	else cout << "bad coordinates!" << endl;
	return 0;
}
