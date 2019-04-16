#include <stdio.h>

void Heun(double x, double y, double a, double b, int n);
double f(double x, double y);

int main(void)
{
	int n;
	double a = 0.0, b = 0.3, x = 0.0, y = 1.0;	/* ���[a,b]�Ə�������:x0 = 0, y(x0) = y(0) = 1.0 ��ݒ� */

	printf("Please input n : ");	/* ������n��[������̓��͂Ŏ擾 */
	scanf("%d", &n);

	Heun(x, y, a, b, n);	/* Heun�@���s */
	return 0;
}

void Heun(double x, double y, double a, double b, int n)	/* Heun�@�̃A���S���Y���Ɖ��̕\����S���֐� */
{
	double k1, k2, h = (b - a) / n;
	int i;

	/* i = 0�̎��� X1, Y1�̌v�Z */
	x = a;
	printf("(X 0, Y 0) = (%.10f, %.10f)\n", x, y);	/* ���̕\�� (�����_�ȉ�10���܂ŕ\��) */

	/* i = 1 ���� n �܂ł̎��� Xi, Yi�̌v�Z */
	for (i = 1; i <= n; i++)
	{
		k1 = f(x, y);
		k2 = f(x + h, y + h * k1);

		y += h * (k1 + k2) / 2.0;
		x += h;
		printf("(X%2d, Y%2d) = (%.10f, %.10f)\n", i, i, x, y);	/* ���̕\�� (�����_�ȉ�10���܂ŕ\��) */
	}

	/* ���ʂƂ��ĉ���(x0, y0)����(xn, yn)��n+1���\������� */
}

double f(double x, double y)
{
	return (-x * y);	/* f(x,y)�̖{�� */
}
