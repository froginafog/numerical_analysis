/*
composite simpson rule for evaluating an integral
author: froginafog
*/

#include <iostream>
#include <cmath>

using namespace std;

double f(double);
double compositeSimpsonRule(double,double,int);

int main()
{
	cout << "integral value: " << compositeSimpsonRule(1.0 , 2.0 , 4) << endl;

	return 0;
}

double f(double x)
{
	return log(x);
}

double compositeSimpsonRule(double a, double b,int m)
{
	int i;
	double h;
	double x[m + 1];
	double fx[m + 1];
	double result = 0;

	h = (b - a)/m;

	for(i = 0; i <= m; i++)
	{
		x[i] = a + i * h;
		fx[i] = f(x[i]);
	}

	for(i = 0; i <= m; i++)
	{
		if(i == 0 || i == m)
		{
			result = result + fx[i];
		}
		else if(i % 2 != 0)
		{
			result = result + 4 * fx[i];
		}
		else
		{
			result = result + 2 * fx[i];
		}
	}
	result = (h/3) * result;
	return result;
}

/*
integral value: 0.38626
*/
