#include <stdio.h>

void Heun(double x, double y, double a, double b, int n);
double f(double x, double y);

int main(void)
{
	int n;
	double a = 0.0, b = 0.3, x = 0.0, y = 1.0;	/* 区間[a,b]と初期条件:x0 = 0, y(x0) = y(0) = 1.0 を設定 */

	printf("Please input n : ");	/* 分割数nを端末からの入力で取得 */
	scanf("%d", &n);

	Heun(x, y, a, b, n);	/* Heun法実行 */
	return 0;
}

void Heun(double x, double y, double a, double b, int n)	/* Heun法のアルゴリズムと解の表示を担う関数 */
{
	double k1, k2, h = (b - a) / n;
	int i;

	/* i = 0の時の X1, Y1の計算 */
	x = a;
	printf("(X 0, Y 0) = (%.10f, %.10f)\n", x, y);	/* 解の表示 (小数点以下10桁まで表示) */

	/* i = 1 から n までの時の Xi, Yiの計算 */
	for (i = 1; i <= n; i++)
	{
		k1 = f(x, y);
		k2 = f(x + h, y + h * k1);

		y += h * (k1 + k2) / 2.0;
		x += h;
		printf("(X%2d, Y%2d) = (%.10f, %.10f)\n", i, i, x, y);	/* 解の表示 (小数点以下10桁まで表示) */
	}

	/* 結果として解は(x0, y0)から(xn, yn)のn+1個が表示される */
}

double f(double x, double y)
{
	return (-x * y);	/* f(x,y)の本体 */
}
