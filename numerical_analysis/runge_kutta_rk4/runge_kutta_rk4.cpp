//runge kutta rk4 method for solving initial value problem

#include <iostream>
#include <iomanip>

using namespace std;

double f(double t, double y);
void rungeKuttaRK4(double t0, double tf, double w0,double h);

int main()
{
	rungeKuttaRK4(0,1,1,0.2);

	return 0;
}

double f(double t, double y)
{
	return t * y + t * t * t;
}

//w0 = y0 = y(t0)
void rungeKuttaRK4(double t0, double tf, double w0,double h)
{
	int i;
	double t;
	double w;
	double k1;
	double k2;
	double k3;
	double k4;

	cout << setw(3) << "i"
	     << setw(6) << "t"
		 << setw(12) << "k1"
		 << setw(12) << "k2"
		 << setw(12) << "k3"
		 << setw(12) << "k4"
		 << setw(12) << "w" << endl;
	t = t0;
	w = w0;
	k1 = 0;
	k2 = 0;
	k3 = 0;
	k4 = 0;
	for(i = 0; t <= tf ; i++)
	{
		cout << setw(3) << i
		     << setw(6) << t
			 << setw(12) << k1
			 << setw(12) << k2
			 << setw(12) << k3
			 << setw(12) << k4
			 << setw(12) << w << endl;
		k1 = f(t,w);
		k2 = f(t + h/2.0,w + (h/2.0)*k1);
		k3 = f(t + h/2.0,w + (h/2.0)*k2);
		k4 = f(t + h,w + h*k3);
		w = w + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
		t = t + h;
	}
}

/*
  i     t          k1          k2          k3          k4           w
  0     0           0           0           0           0           1
  1   0.2           0       0.101     0.10201     0.21208      1.0206
  2   0.4    0.212121    0.339545    0.343367    0.499711     1.08986
  3   0.6    0.499943    0.694926    0.704676    0.954476     1.23165
  4   0.8    0.954988       1.272     1.29419     1.70439     1.49137
  5     1      1.7051     2.22469     2.27146     2.94566     1.94614
*/


