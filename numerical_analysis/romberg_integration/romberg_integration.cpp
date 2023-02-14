//romberg integration

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double romberg_integration(double (*f)(double), double a, double b);
double f(double);

int main()
{
	romberg_integration(f,1,2);

	return 0;
}

//interval of integration: [a,b]
double romberg_integration(double (*f)(double), double a, double b)
{
	int i;
	int j;
	int iMax = 5;
	int k;
	double h[iMax + 1];
	double R[iMax + 1][iMax + 1];
	double coefficient;

	for(i = 1; i < iMax + 1; i++)
	{
		h[i] = (b-a)/pow(2,i-1);
	}

	R[1][1] = (h[1]/2.0) * (f(a) + f(b));

	for(i = 2; i < iMax + 1; i++)
	{
		coefficient = 0;
		for(k = 1; k <= pow(2,i-2); k++)
		{
			coefficient = coefficient + f(a + (2 * k - 1) * h[i]);
		}
		R[i][1] = (1.0/2.0) * (R[i - 1][1] + h[i - 1] * coefficient);
	}

	for(i = 2; i < iMax + 1; i++)
	{
		for(j = 2; j <= i; j++)
		{
			R[i][j] = R[i][j - 1]
				      + (R[i][j - 1] - R[i - 1][j - 1])/(pow(4,j - 1) - 1);
		}
	}

	//print R[i][j]
	cout << setw(6) << " ";
	cout << setw(13) << "j = 1"
	     << setw(13) << "j = 2"
	     << setw(13) << "j = 3"
	     << setw(13) << "j = 4"
	     << setw(13) << "j = 5" << endl;
	for(i = 1; i <= iMax; i++)
	{
		cout << "i = " << i << ": ";
		for(j = 1; j <= i; j++)
		{
			cout << setw(12) << setprecision(6) << R[i][j] << " ";
		}
		cout << endl;
	}

	return R[iMax][iMax];
}

double f(double x)
{
	return log(x);
}

/*
              j = 1        j = 2        j = 3        j = 4        j = 5
i = 1:     0.346574
i = 2:     0.376019     0.385835
i = 3:       0.3837      0.38626     0.386288
i = 4:     0.385644     0.386292     0.386294     0.386294
i = 5:     0.386132     0.386294     0.386294     0.386294     0.386294
 */
