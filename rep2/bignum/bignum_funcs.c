#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int digit;
extern int decimal;

void initialize0(int num[digit])	// num = 0 (numに0を代入)
{
	int i;

	for(i = 0; i < digit; i++)	// numの各位に0を代入して初期化する
	{
		num[i] = 0;
	}
}

void subNum4int(int num[digit], int a)	// num = a (numにaを代入)
{
	int i;

	initialize0(num);	// 代入する前に全ての桁に0を代入して初期化しておく

	for(i = 0; a > 0; i++)	// int型変数aをnum1の下の位から順に代入していく
	{
		num[i] = a % decimal;
		a /= decimal;
	}
}

void subNum4Num(int num1[digit], int num2[digit])	// num1 = num2 (num1にnum2を代入)
{
	int i;

	initialize0(num1);	// 代入する前に全ての桁に0を代入して初期化しておく

	for(i = 0; i < digit; i++)	// 各位ごとに、下の位から順にnum1にnum2を代入していく
	{
		num1[i] = num2[i];
	}
}

void printnum(int num[digit])	// numの表示
{
	int i;
	char formatstr[20];	// decimalが変動するため、表示する際にフォーマット指定子内の数値も変動する
	// そのために、decimalから数値を計算し、文字列として保存するための変数を宣言する

	for(i = digit - 1; i >= 0; i--)
	{
		if(i == 0)
		{
			printf("%d", num[i]);	// 最小の位ならそのまま表示 (下の条件のみでは、num = 0 の時に表示されずに関数が終了してしまうため、ここで先に処理をする)
		}
		else if(num[i] != 0)
		{
			printf("%d", num[i]);	// numの最大の桁までforループで探して表示し、ループを抜ける
			i--;
			break;
		}
	}

	sprintf(formatstr,"%%.%.0fd", log10(decimal));	// 最大桁未満の桁では空白の位に0を表示するためにlog(10)decimalだけ桁を指定して表示する必要がある
	while(i >= 0)
	{
		printf(formatstr, num[i]);
		i--;
	}

	printf("\n");
}

void numAdd(int num1[digit], int num2[digit])	// num1 += num2 (num1 + num2 の計算結果をnum1に代入)
{
	int i;

	for(i = 0; i < digit; i++)
	{
		num1[i] += num2[i];	// int型は2,147,483,647までなので、999,999,999 + 999,999,999 = 1,999,999,998 < 2,147,483,647で各桁足してもoverflowしない
		if(num1[i] >= decimal)	// 繰り上がり処理
		{
			if(i + 1 != digit)
			{
				num1[i + 1] += num1[i] / decimal;
				num1[i] %= decimal;
			}
			else	// 万が一繰り上がり時にnumの桁が足りない場合はこの足し算のプロセスで異常が発生したことを報告し、終了
			{
				printf("numAdding overflow!\n");
				exit(1);
			}
		}
	}
}

void numMultiple(int num[digit], int a)	// num *= a (num × a の計算結果をnumに代入)
{
	int i;

	if(a < 0)	// 今回の状況設定では負の数は扱わないため、万が一引数に負の数が与えられた場合は確認のため異常終了とする
	{
		printf("Neg multiple is not supported in this program!\n");
		exit(1);
	}
	else if(a == 0)	// 0を掛けた場合はいかなる数でも0となるので、numに0を代入して終了する
	{
		initialize0(num);
	}
	else if(a >= decimal)	// 今回の状況設定において、割る数としての最大は2000であり、2000 < decimal = 10000 である
	{	// int型の最大が2147483647であるため、decimalはdecimal ^ 2 < 2147483647となるように設定しており、桁溢れ防止と確認のため、aをdecimal未満に設定しておく
		printf("Multiplying too large d is not supported in this program!\n");
		exit(1);
	}

	for(i = 0; i < digit; i++)	// 各桁についてaを掛けていく
	{
		num[i] *= a;
	}

	for(i = 0; i < digit; i++)	// 繰り上がり処理
	{
		if(num[i] >= decimal)
		{
			if(i + 1 != digit)
			{
				num[i + 1] += num[i] / decimal;
				num[i] %= decimal;
			}
			else	// 万が一繰り上がり時にnumの桁が足りない場合はこの掛け算のプロセスで異常が発生したことを報告し、終了
			{
				printf("numMultiplying overflow!\n");
				exit(1);
			}
		}
	}
}

int numDivide(int num[digit], int d)	// num /= d & return ( num % d ) (numをdで割った商をnumに代入し、その余りを関数の戻り値として返す)
{
	int i, r;

	if(d == 0)	// d = 0 で割ることは出来ない
	{
		printf("0 dividing is not defined!\n");
		exit(1);
	}
	else if(d < 0)	// 今回の状況設定では負の数は扱わないため、万が一引数に負の数が与えられた場合は確認のため異常終了とする
	{
		printf("Neg dividing is not supported in this program!\n");
		exit(1);
	}
	else if(d >= decimal)	// 今回の状況設定において、割る数としての最大は1000であり、1000 < decimal = 10000 である
	{	// 確認のため、dをdecimal未満に設定しておく
		printf("Dividing by too large d is not supported in this program!\n");
		exit(1);
	}

	for(i = digit - 1; i >= 0; i--)	// 筆算と同じ要領で、1桁ずつdで割っていき、余りの数はもう一つ下の位へ繰り下げる
	{
		if(i != 0)
		{
			num[i - 1] += ( num[i] % d ) * decimal;
		}
		else
		{
			r = num[i] % d;	// 最も下の位まで到達したら、その余りを記録し、戻り値として返す
		}
		num[i] /= d;
	}

	return r;
}

void numPower(int num[digit], int a, int x)	// num = a ^ x (a ^ x の計算結果をnumに代入する)
{
	if(a == 0)	// a = 0 の時は何乗しても0のままなので、numに0を代入して終了
	{
		initialize0(num);
	}
	else if(x == 0)	// x = 0 の場合には底aがいかなる数字でも1となるため、numに1を代入して終了
	{
		subNum4int(num, 1);
	}
	else if(a < 0 || x < 0)	// 今回の状況設定では負の数は扱わないため、万が一引数に負の数が与えられた場合は確認のため異常終了とする
	{
		printf("Neg power is not supported in this program!\n");
		exit(1);
	}

	subNum4int(num, a);	// num = a (numにaを代入する(つまりnumに1回分だけaを掛けることと等しい))

	while(x > 1)	// numにx-1回だけaを掛ける
	{
		numMultiple(num, a);
		x--;
	}
}

void numCombi(int num[digit], int n, int r)	// num = C(n,r) = n*...n-r+1/r! (n個からr個を選ぶ組合せの総数をnumに代入する)
{
	int i, check;

	if(n < 0 || r < 0)	// nやrが負の数は定義されていないので異常終了
	{
		printf("Neg n or r is not defined in Combination!\n");
		exit(1);
	}
	else if(n < r)	// n < r の場合も定義されていないので異常終了
	{
		printf("n < r is not defined in Combination!\n");
		exit(1);
	}

	subNum4int(num, 1);	// 掛け算と割り算を行うのであらかじめ1で初期化しておく

	for(i = 1; i <= r; i++)
	{
		numMultiple(num, n - i + 1);	// nから n - r + 1 までを順に掛けていく
		check = numDivide(num, i);	// 1からrまでの数字を順に掛けていく
		if(check != 0)	// 組合せの総数は必ず自然数であるため、上記の手順で掛けて割った場合、途中の場合でも必ず割りきれるはずなので確認する
		{
			printf("Dividing error in Combination calculating!\n");
			exit(1);
		}
	}
}
