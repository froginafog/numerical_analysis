/*
 * Neton Method for finding x such that f(x) = 0.
 * autho: froginafog
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double);
double dfdx(double);
void newton_method(double);

int main()
{
	double initialGuess{2.25};

	newton_method(initialGuess);
}

//2*sin(x) = x (initial expression)
//2*sin(x) - x = 0
//f(x) = 2*sin(x) - x
//interval: [a,b] = [1.5,3]
double f(double x)
{
	return 2*sin(x) - x;
}

double dfdx(double x)
{
	return 2*cos(x) - 1;
}

void newton_method(double x_0)
{
	int N{5};
	int i;
	double x;
	double error;

	cout << setw(2) << "i";
	cout << setw(10) << "x_0";
	cout << setw(14) << "f(x_0)";
	cout << setw(12) << "dfdx(x_0)";
	cout << setw(10) << "x";
	cout << setw(14) << "error";
	cout << setw(14) << "log(error)";
	cout << endl;

	for(i = 0; i < N; i++)
	{
		x = x_0 - f(x_0)/dfdx(x_0);

		error = abs(x - 1.89549);

		cout << setw(2) << i;
		cout << setw(10) << x_0;
		cout << setw(14) << f(x_0);
		cout << setw(12) << dfdx(x_0);
		cout << setw(10) << x;
		cout << setw(14) << error;
		cout << setw(14) << log(error);
		cout << endl;

		x_0 = x;
	}

	cout << endl;
	cout << "f(" << x << "): " << setprecision(6) << fixed << f(x) << endl;
}

/*
 i       x_0        f(x_0)   dfdx(x_0)         x         error    log(error)
 0      2.25     -0.693854    -2.25635   1.94249     0.0469981      -3.05765
 1   1.94249    -0.0790596    -1.72638   1.89669    0.00120319      -6.72278
 2   1.89669   -0.00196525    -1.64032    1.8955   5.09732e-06      -12.1868
 3    1.8955  -1.36005e-06    -1.63805   1.89549   4.26703e-06      -12.3646
 4   1.89549  -6.53255e-13    -1.63805   1.89549   4.26703e-06      -12.3646

f(1.89549): 0.000000
 */
