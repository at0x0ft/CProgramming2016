#include <stdio.h>
#include <math.h>

#define MAX 10 /* MAX回数反復したら失敗 */

void newton(double x, double eps);
double f(double x);
double df(double x);

int main(void)
{
	double x;
	double eps = pow(2, -30.0);
	printf("Please input x0:");
	scanf("%lf", &x);
	newton(x, eps);
	return 0;
}

void newton(double x, double eps)
{
	/* ニュートン法の本体．ここを作成する */
	int n = 0;

	do
	{
		x = x - f(x) / df(x);
		n++;
	}
	while(!((fabs(f(x) / df(x)) < eps) || (n >= 10)));

	printf("The answer is x = %f\n", x);
}

double f(double x)
{
	return (pow(x, 3.0) - 2 * x - 5); /* f(x)の本体．ここも作成 */
}

double df(double x)
{
	return(3 * pow(x, 2.0) - 2); /* f'(x)の本体．ここも作成 */
}
