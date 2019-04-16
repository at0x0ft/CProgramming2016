#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double bisec(double a, double b, double eps);
double f(double x);

int main(void)
{
	double a, b, eps;

	eps = pow(2.0, -30.0);
	a = 0.0; b = 1.0;

	printf("answer = %f\n", bisec(a, b, eps));

	return 0;
}


double bisec(double a, double b, double eps)
{
	/* 2分法の本体．ここを作成する */

	double x1, x2, x, d;
	int i = 0;

	x1 = a;
	x2 = b;

	/* 区間 [a,b] に解が存在するか否かの判定 */

	if(f(x1) * f(x2) > 0)
	{
		printf("Error : Only one solution does not necessarily exist in this interval!!\n");
		exit(1);
	}
	else if(f(x1) * f(x2) == 0)
	{
		printf("Error : f(a) = 0 or f(b) = 0 (Solution is a or b) !!\n");
		exit(1);
	}
	else
	{
	}

	do
	{
		++i;	/* ( 今回は表示しないが ) 試行回数 i を記録しておく */

		x = (x1 + x2) / 2;

		if(f(x1) * f(x) < 0)
		{
			x2 = x;
		}
		else if(f(x1) * f(x) > 0)
		{
			x1 = x;
		}
		else
		{
			return x;	/* 序盤の解の存在判定で、x1が解である可能性は排除しているため、
					   f(x1) * f(x) = 0 ならば、f(x) = 0 で xが解となる */
		}

		d = fabs(x1 - x2);
	}
	while(!(d < eps));

	return ((x1 + x2) / 2);
}

double f(double x)
{
	/* f(x)の本体．ここも作成 */
	return (pow(x, 3.0) - 3 * x + 1);
}
