//Bisection Method
 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double);
void bisection_method(double, double);

int main()
{
	double start_of_interval{1.5};
	double end_of_interval{3.0};

	bisection_method(start_of_interval, end_of_interval);

	return 0;
}

//2*sin(x) = x (initial expression)
//2*sin(x) - x = 0
//f(x) = 2*sin(x) - x
//interval: [a,b] = [1.5,3]
double f(double x)
{
	return 2*sin(x) - x;
}

//We want to find x such that f(x) = 0, where f(x) = 2*sin(x) - x.
void bisection_method(double a, double b)
{
	if(f(a) * f(b) > 0)
	{
		cout << "No root is contained in this interval.\n";
	}

	if(f(a) * f(b) < 0)
	{
		int i;
		int N{20};
		double x;
		double x_0{a};
		double error{1.0};

		cout << setw(2) << "i";
		cout << setw(9) << "a";
		cout << setw(9) << "b";
		cout << setw(9) << "x";
		cout << setw(14) << "f(x)";
		cout << setw(10) << "x_0";
		cout << setw(14) << "error";
		cout << setw(12) << "log(error)";
		cout << endl;

		for(i = 0; i < N; i++)
		{
			x = (a + b)/2.0;  //midpoint between a and b
			error = abs(x - 1.89549);
			cout << setw(2) << i;
			cout << setw(9) << a;
			cout << setw(9) << b;
			cout << setw(9) << x;
			cout << setw(14) << f(x);
 			cout << setw(10) << x_0;
 			cout << setw(14) << error;
 			cout << setw(12) << log(error);
 			cout << endl;
			if(f(a)*f(x) < 0)
			{
				//the root is in [a,x]
				b = x;
			}
			else
			{
				//the root is in [x,b]
				a = x;
			}
			x_0 = x;
		}

		cout << endl;
		cout << "f(" << x << "): " << setprecision(6) << fixed << f(x) << endl;
	}
}

/*
 i        a        b        x          f(x)       x_0         error  log(error)
 0      1.5        3     2.25     -0.693854       1.5       0.35451    -1.03702
 1      1.5     2.25    1.875     0.0331716      2.25       0.02049    -3.88782
 2    1.875     2.25   2.0625      -0.29944     1.875       0.16701     -1.7897
 3    1.875   2.0625  1.96875     -0.125038    2.0625       0.07326    -2.61374
 4    1.875  1.96875  1.92188    -0.0438704   1.96875      0.026385    -3.63496
 5    1.875  1.92188  1.89844   -0.00482936   1.92188     0.0029475     -5.8268
 6    1.875  1.89844  1.88672     0.0143016   1.89844    0.00877125    -4.73628
 7  1.88672  1.89844  1.89258    0.00476871   1.88672    0.00291187    -5.83896
 8  1.89258  1.89844  1.89551  -2.21883e-05   1.89258   1.78125e-05    -10.9356
 9  1.89258  1.89551  1.89404     0.0023753   1.89551    0.00144703    -6.53824
10  1.89404  1.89551  1.89478    0.00117706   1.89404   0.000714609    -7.24377
11  1.89478  1.89551  1.89514   0.000577564   1.89478   0.000348398    -7.96216
12  1.89514  1.89551  1.89532    0.00027772   1.89514   0.000165293    -8.70779
13  1.89532  1.89551  1.89542   0.000127774   1.89532   7.37402e-05    -9.51496
14  1.89542  1.89551  1.89546   5.27947e-05   1.89542   2.79639e-05    -10.4846
15  1.89546  1.89551  1.89548   1.53037e-05   1.89546   5.07568e-06     -12.191
16  1.89548  1.89551   1.8955  -3.44215e-06   1.89548   6.36841e-06    -11.9642
17  1.89548   1.8955  1.89549   5.93081e-06    1.8955   6.46362e-07    -14.2519
18  1.89549   1.8955  1.89549   1.24434e-06   1.89549   3.50739e-06    -12.5606
19  1.89549   1.8955  1.89549   -1.0989e-06   1.89549    4.9379e-06    -12.2186

f(1.89549): -0.000001
*/

