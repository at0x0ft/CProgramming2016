#include <stdio.h>
#include <stdlib.h>

long double combination(int n, int r)
{
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

	if(n == r || r == 0)	/* nCn = nC0 = 1 を再帰の初項の条件として設定 */
	{
		return 1;
	}
	else	/* 初項の条件以外は再帰呼び出し */
	{
		return (combination(n - 1, r) + combination(n - 1, r - 1));
	}
}

int main(void)
{
	int n, r;

	printf("Put in n for Combination(n, r) (n >= r) : ");	/* nCrのnを端末から入力 */
	scanf("%d", &n);
	printf("Put in r for Combination(n, r) (n >= r) : ");	/* nCrのrを端末から入力 */
	scanf("%d", &r);

	printf("Combination(%d, %d) = %.0Lf\n", n, r, combination(n, r));	/* 値の表示 */

	return 0;
}
