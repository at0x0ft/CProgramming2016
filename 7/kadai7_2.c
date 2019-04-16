#include <stdio.h>

void rk(double x, double y, double a, double b, int n);
double f(double x, double y);

int main(void)
{
	int n;
	double a = 0.0, b = 1.0, x = 0.0, y = 1.0;

	printf("Please input n:");
	scanf("%d", &n);

	rk(x, y, a, b, n);
	return 0;
}

void rk(double x, double y, double a, double b, int n)
{
	double k1, k2, k3, k4, h = (b - a) / n;
	int i;

	/* �����ɍ쐬���� */

	/* i = 0�̎��� X1, Y1�̌v�Z */
	x = a;
	printf("(X 0, Y 0) = (%f, %f)\n", x, y);

	/* i = 1 ���� n-1 �܂ł̎��� Xi, Yi�̌v�Z */
	for (i = 1; i <= n; i++)
	{
		k1 = f(x, y);
		k2 = f(x + h / 2, y + h * k1 / 2);
		k3 = f(x + h / 2, y + h * k2 / 2);
		k4 = f(x + h, y + h * k3);

		y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		x += h;
		printf("(X%2d, Y%2d) = (%f, %f)\n", i, i, x, y);
	}
}

double f(double x, double y)
{
	return(x + y);  /* f(x,y)�̖{�́D�������쐬 */
}
