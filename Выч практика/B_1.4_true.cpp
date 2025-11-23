#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
double f1(double x)
{
	return (x + 3)* (x + 3)* (x + 3) - 8;
}
double df1(double x)
{
	return 3 * (x + 3) * (x + 3);
}
double f2(double x, double s)
{
	return cos(M_PI * x) - pow(x, s);
}
double df2(double x, double s)
{
	return -sin(M_PI * x) * M_PI - s * pow(x, s - 1);
}

int RootFinder(int a, int &b, int k_iter, double &x, double(*f)(double), double(*df)(double), const double epsilon = 1e-6)
{
	if (abs(f(b)) <= abs(f(a)))
		x = b;
	else
		x = a;
	for (; abs(f(x)) >= epsilon; k_iter++)
	{
		double newtone = f(x) / df(x);
		x -= newtone;
	}
	return k_iter;
}
int BadAssRootFinder(int a, int& b, int k_iter, double& x, double& s, double(*f)(double, double), double(*df)(double, double), const double epsilon = 1e-6)
{
	x = (a + b) / 2;
	for (; abs(f(x, s)) >= epsilon; k_iter++)
	{
		double newtone = f(x, s) / df(x, s);
		x -= newtone;
	}
	return k_iter;
}
void Output(double &x, double (*f)(double), int &k_iter)
{
	cout << setw(5) << ":)" << setw(16) << setprecision(12) << x << setw(20) << f(x) << setw(7) << k_iter << endl << endl;
}
void TableCreationTool()
{
	cout << setw(5) << "s" << setw(16) << "x" << setw(20) << "f(x)" << setw(7) << "k_iter" << endl;
}
void BadAssOutput(double &s, double& x, double (*f)(double, double), int& k_iter)
{
	cout << setw(5) << s << setw(16)  <<  x << setw(20) << f(x, s) << setw(7) << k_iter << endl;
}
int main()
{
	const double epsilon = 1e-6;
	int k_iter = 0;
	int a = -2;
	int b = 1;
	double x = 0;
	k_iter = RootFinder(a, b, k_iter, x, f1, df1, epsilon);
	TableCreationTool();
	Output( x, f1, k_iter);
	k_iter = 0;
//приколы
	a = 0;
	b = 2;
	double s = 2.8;
	double ds = 0.1;
	cout << "Prikoly online bez SMS i registracii: " << endl << endl;
	TableCreationTool();
	for (; s <= 3.2; s += ds)
	{
		k_iter = BadAssRootFinder(a, b, k_iter, x, s, f2, df2, epsilon);
		BadAssOutput(s, x, f2, k_iter);
		k_iter = 0;
	}


}
