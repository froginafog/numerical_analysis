/*
dy/dt = f(t,y)
y(t_0) = y_0
t_0 <= t <= t_f
t_(i+1) = t_i + h
y is the solution
w is the approximate solution
 */
#include <iostream>
#include <iomanip>

using namespace std;

double f(double t, double y);
double euler_method_for_IVP(double t_0, double t_f, double y_0, double h);

int main()
{
	euler_method_for_IVP(1,4,1,0.5);

	return 0;
}

double f(double t, double y)
{
	return 1 + y / t;
}

double euler_method_for_IVP(double t_0, double t_f, double y_0, double h)
{
	int i;
	int iMax = 30;
	int count;
	double w[iMax];
	double t[iMax];

	count = 0;
	t[0] = t_0;
	w[0] = y_0;
	for(i = 0; i < iMax - 1 && t[i] <= t_f; i++, count++)
	{
		w[i+1] = w[i] + h*f(t[i],w[i]);
		t[i+1] = t[i] + h;
	}
	count = i;

	for(i = 0; i < count; i++)
	{
		cout << "t[" << i << "]: " << setw(4) << setprecision(3) << t[i] << "\t";
		cout << "w[" << i << "]: " << setw(8) << setprecision(6) << w[i] << endl;
	}
}

/*
t[0]:    1	w[0]:        1
t[1]:  1.5	w[1]:        2
t[2]:    2	w[2]:  3.16667
t[3]:  2.5	w[3]:  4.45833
t[4]:    3	w[4]:     5.85
t[5]:  3.5	w[5]:    7.325
t[6]:    4	w[6]:  8.87143
*/
