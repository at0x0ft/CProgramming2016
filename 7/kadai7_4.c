#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(int n)	// 階乗を計算する関数
{
	double ans = 1.0;
	if(n < 0)
	{
		printf("Can't calcurate n!\n");
		exit(1);
	}
	else if(n == 0 || n == 1)
	{
		return ans;
	}
	else
	{
		return(n * factorial(n - 1));
	}
}

int main(void)
{
	int n, i, k;
	double e = 0.0;

	/* 小数第何位まで表示するかを入力する (小数第1位から小数第15位まで). */
	printf("Show the result by the ** decimal place.\nPut ** in the integer which is bigger than 0 and smaller than 16:** = ");
	scanf("%d", &k);
	if(!(k >= 1 && k <= 15))
	{
		printf("Error:Please put the integer which is bigger than 0 and smaller than 16.\n");
		exit(1);
	}

	// 小数第k位までを表示する必要があるので、小数第(k+1)位までの正確な自然対数の値を求める必要がある.
	// そこで、eに足す1/(n!)が10の-(k+1)乗よりも小さくなるnを以下で決定している.

	n = 0;
	while(!(factorial(n) > pow(10, k + 1)))	// pow(10, -16) > 1 / n! つまり n! > pow(10, 16)を終了条件としている.
	{
		n++;
	}

	for(i = 0; i <= n + 10; i++)
	{
		e += 1.0 / factorial(i);
	}

	/* 表示する小数の位を変数で指定しているため、kの値を文字列として出力し、文字列の連結を使ってformatstrに格納し、改めてformatstrとprintfを使って表示する. */
	char formatstr[1024];
	sprintf(formatstr,"e = %%.%df\n", k);
	printf(formatstr, e);

	return 0;
}
