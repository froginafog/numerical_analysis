/*
runge kutta midpoint rk2 for solving initial value problem
author: froginafog
*/

#include <iostream>
#include <iomanip>

using namespace std;

double f(double t, double y);
void rungeKuttaMidpoint(double t0, double tf, double w0,double h);

int main()
{
	rungeKuttaMidpoint(0,1,1,0.2);

	return 0;
}

double f(double t, double y)
{
	return t * y + t * t * t;
}

//w0 = y0 = y(t0)
void rungeKuttaMidpoint(double t0, double tf, double w0,double h)
{
	int i;
	double t;
	double w;
	double k1;
	double k2;

	cout << setw(3) << "i"
	     << setw(6) << "t"
		 << setw(14) << "k1"
		 << setw(14) << "k2"
		 << setw(14) << "w" << endl;
	t = t0;
	w = w0;
	k1 = 0;
	k2 = 0;
	for(i = 0; t <= tf ; i++)
	{
		cout << setw(3) << i
		     << setw(6) << t
			 << setw(14) << k1
			 << setw(14) << k2
			 << setw(14) << w << endl;
		k1 = f(t,w);
		k2 = f(t + h/2,w + (1.0/2.0) * k1 * h);
		w = w + h * k2;
		t = t + h;
	}
}

/*
  i     t            k1            k2             w
  0     0             0             0             1
  1   0.2             0         0.101        1.0202
  2   0.4       0.21204      0.339421       1.08808
  3   0.6      0.499234      0.694004       1.22689
  4   0.8      0.952131       1.26847       1.48058
  5     1       1.69646        2.2142       1.92342
*/

