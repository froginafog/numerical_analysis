/*
composite trapezoidal rule for evaluating an integral
author: froginafog
*/

#include <iostream>
#include <cmath>

using namespace std;

double f(double );
double compositeTrapezoidalRule(double a, double b, int m);

int main()
{
	cout << "integral value: " << compositeTrapezoidalRule(1.0 , 2.0 , 4) << endl;

	return 0;
}

double f(double x)
{
	return log(x);
}

double compositeTrapezoidalRule(double a, double b, int m)
{
	//a = start of interval
	//b = end of interval
	//m = number of points
	//h = step size
	int i;
	double h;
	double x;
	double sum;

	h = (b-a)/m;
	sum = 0;
	x = a + h;
	for(i = 1 ; i <= m - 1 ; i++)
	{
		sum = sum + f(x);
		x = x + h;
	}
	return (h/2.0)*(f(a) + f(b) + 2*sum);
}

/*
integral value: 0.3837
*/
