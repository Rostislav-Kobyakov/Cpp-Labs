#include <iostream>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
double function(double x, double s, double t)
{
	return (tan(x * x) + sqrt(x)) / (t * log10(x + s));
}
void BadAssOutput(double& s, double &t, double Int, int& k_iter)
{
	cout << setw(5) << s << setw(5) << t << setw(20) << Int << setw(7) << k_iter << endl;
	k_iter = 0;
}
void SuperIntegrator3000(double &a, double &b, double &s, double &t, double &Int, int& k_itter, double (*func)(double, double, double),const double epsilon = 1e-6)
{
	double x0 = a;
	double xn = b;
	int n = 2;
	double h;
	double Sum = 0;
	double postSum;
	double preSum = 0;
	for (;;)
	{
		h = (b - a) / n;
		int i = 0;
		preSum = Int;
		Sum = 0;
		for (double x = x0; i <= n - 1 && x <= xn; x += h, i++)
			Sum += func(x + h/2, s, t);
		Int = h * Sum;
		postSum = Int;
		if (abs(postSum - preSum) >= epsilon)
		{
			n *= 2;
			++k_itter;
		}
		else
			break;
	}
}
void TableCreationTool()
{
	cout << setw(5) << "s" << setw(5) << "t" << setw(20) << "Int" << setw(7) << "k_iter" << endl;
}
int main()
{
	double s1 = 1; // шоб знали с кем связались
	double s2 = 4;
	double ds = 0.5;
	double t1 = 0.4;
	double t2 = 1.2;
	double dt = 0.2;
	double a = 0.4;
	double b = 1.2;
	double x = 0;
	int k_iter = 0;
	double Int = 0;
	const double epsilon = 1e-6;
	TableCreationTool();
	for (double s = s1 ; s <= s2 ; s += ds)
	{
		for (double t = t1; t <= t2 ;t+= dt )
		{
			SuperIntegrator3000(a, b, s,t, Int, k_iter, function, epsilon);
			BadAssOutput(s,t,Int,k_iter);
		}
	}
}
