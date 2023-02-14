//runge kutta trapezoid rk2

#include <iostream>
#include <iomanip>

using namespace std;

double f(double t, double y);
void rungeKuttaTrapezoid(double t0, double tf, double w0,double h);

int main()
{
	rungeKuttaTrapezoid(0,1,1,0.2);

	return 0;
}

double f(double t, double y)
{
	return t * y + t * t * t;
}

//w0 = y0 = y(t0)
void rungeKuttaTrapezoid(double t0, double tf, double w0,double h)
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
		k2 = f(t + h,w + k1 * h);
		w = w + h*(k1 + k2)/2;
		t = t + h;
	}
}

/*
  i     t            k1            k2             w
  0     0             0             0             1
  1   0.2             0         0.208        1.0208
  2   0.4       0.21216      0.489293       1.09095
  3   0.6      0.500378      0.930613       1.23404
  4   0.8      0.956427       1.65226       1.49491
  5     1       1.70793        2.8365       1.94936
*/
