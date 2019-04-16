#include <stdio.h>
#include <stdlib.h>

long double combination(int n, int r)	/* 扱う値が大きいので、int型ではなく、long double型で答えの値を返す (この関数内の変数ansも同様) */
{
	int i;
	long double ans = 1.0;

	/* 例外処理:nCrの定義は、0 <= r <= n かつ r, nは整数ゆえ、定義に反する入力を排除する */

	if(n < 0 || r < 0)	/* nやrが負であれば異常終了 */
	{
		printf("Error : Please input POSITIVE integer or 0 for n and r to Combination.\n");
		exit(1);
	}
	else if(n < r)	/* nやrが負であれば異常終了 */
	{
		printf("Error : Please input n and r which satisfies n >= r.\n");
		exit(1);
	}

	/* nCr = n! / {r! × (n-r)!} = n×(n-1)×(n-2)×‥・×(n-r+1) / (n-r)! に沿って計算 */
	for(i = n; i >= r + 1; i--)
	{
		/* ansの数値を大きくし過ぎるとオーバーフローするので、同一ループ内で ans ×i ÷(i-r) (i = r+1, ‥・,n)として計算する	 */
		ans *= i;
		ans /= (i - r);
	}

	return ans;
}


int main(void)
{
	int i;

	for(i = 40; i <= 50; i++)	/* 65Cr を r = 40, 41, ‥・,50について順に値を表示 */
	{
		printf("Combination(%d, %d) (%d C %d) = %.0Lf\n", 65, i, 65, i, combination(65, i));
	}

	return 0;
}
