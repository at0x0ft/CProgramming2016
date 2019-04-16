#include <stdio.h>
#include "bignum_funcs.h"

int digit = 151;	// 多倍長整数を表すint型配列numの桁数を指定
int decimal = 10000;	// numの1桁の上限の数の設定

int main(void)
{
	int num1[digit], num2[digit];

	numPower(num1, 29, 400);	// num1 = 29 ^ 400

	printf("29 ^ 400 = \n");	// num1の計算結果の表示
	printnum(num1);
	printf("\n");

	numCombi(num2, 2000, 1000);	// num2 = 2000 C 1000 = Combination( 2000, 1000 )

	printf("Combination( 2000, 1000 ) = \n");	// num2の計算結果の表示
	printnum(num2);
	printf("\n");

	numAdd(num1, num2);	// num1 = num1 + num2

	printf("29 ^ 400 + Combination( 2000, 1000 ) = \n");	// num1 = 29 ^ 400 + 2000 C 1000 = 29 ^ 400 + Combination( 2000, 1000 )の計算結果の表示
	printnum(num1);

	return 0;
}
