/*
 * Fixed Point Iteration for finding x such that f(x) = 0.
 * author: froginafog
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double);
void fixed_point_iteration(double);

int main()
{
	double initialGuess{2.25};

	fixed_point_iteration(initialGuess);

	return 0;
}

//We want to find x such that f(x) = 2 * sin(x) - x = 0.
double f(double x)
{
    return 2 * sin(x) - x;
}

//2*sin(x) = x (initial expression)
//let g(x) = 2*sin(x)
//interval: [a,b] = [1.5,3]
double g(double x)
{
	return 2*sin(x);
}

//We want to find x such that g(x) = x, where g(x) = 2*sin(x).
void fixed_point_iteration(double x_0)
{
	int N = 20;
	int i;
	double x;
	double error;

	cout << setw(2) << "i";
	cout << setw(10) << "x_0";
	cout << setw(10) << "g(x_0)";
	cout << setw(10) << "x";
	cout << setw(14) << "error";
	cout << setw(14) << "log(error)";
	cout << endl;

	for(i = 0; i < N; i++)
	{
		x = g(x_0);
		error = abs(x - 1.89549);

		cout << setw(2) << i;
		cout << setw(10) << x_0;
		cout << setw(10) << g(x_0);
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
 i       x_0    g(x_0)         x         error    log(error)
 0      2.25   1.55615   1.55615      0.339344      -1.08074
 1   1.55615   1.99979   1.99979      0.104295      -2.26053
 2   1.99979   1.81877   1.81877     0.0767166      -2.56764
 3   1.81877   1.93882   1.93882     0.0433318      -3.13887
 4   1.93882   1.86608   1.86608     0.0294109      -3.52639
 5   1.86608   1.91344   1.91344     0.0179498      -4.02018
 6   1.91344   1.88374   1.88374     0.0117504      -4.44387
 7   1.88374   1.90286   1.90286    0.00737314      -4.90991
 8   1.90286   1.89074   1.89074    0.00474882      -5.34986
 9   1.89074   1.89851   1.89851    0.00301553      -5.80398
10   1.89851   1.89356   1.89356    0.00192565      -6.25249
11   1.89356   1.89672   1.89672    0.00123211      -6.69903
12   1.89672   1.89471   1.89471   0.000780579      -7.15547
13   1.89471   1.89599   1.89599    0.00050445      -7.59204
14   1.89599   1.89517   1.89517    0.00031511      -8.06259
15   1.89517    1.8957    1.8957   0.000207947      -8.47823
16    1.8957   1.89536   1.89536   0.000125729      -8.98138
17   1.89536   1.89558   1.89558   8.71945e-05      -9.34737
18   1.89558   1.89544   1.89544    4.8651e-05      -9.93084
19   1.89544   1.89553   1.89553   3.80284e-05      -10.1772

f(1.89553): -0.000055
*/
