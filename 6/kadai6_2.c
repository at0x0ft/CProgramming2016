#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int str2int(char a[])
{
	int num = strlen(a);
	int adjust = '0' - 0;
	int answer = 0;
	int i;
	int neg = 0;

	/* 符号の判定(負なら、neg = 1とし、後に処理をする) */
	if(a[0] == '-')
	{
		neg++;
	}
	else
	{
	}

	for(i = 0; i < num; i++)
	{
		/* 最初以外に負号があれば、異常終了 */
		if(a[i] == '-')
		{
			if(i != 0)
			{
				printf("Error! Invalid argument is used!!\nThis function must be used only for integers, so please put them!\n");
				exit(1);
			}
			else
			{
			}
		}

		else if(a[i] < '0' || a[i] > '9')
		{
			printf("Error! Invalid argument is used!!\nThis function must be used only for integers, so please put them!\n");
			exit(1);
		}
		else
		{
			answer += (a[i] - adjust) * pow(10, num - i - 1);
		}
	}

	/* 負号が存在した場合の処理 */
	if(neg == 1)
	{
		answer *= -1;
	}
	else
	{
	}

	return answer;
}


double str2double(char a[])
{
	int num = strlen(a);
	int adjust = '0' - 0;
	double answer = 0.0;
	int i;
	int j = num;
	int neg = 0;

	if(a[0] == '-')
	{
		neg++;
	}
	else
	{
	}

	/* 小数点位置の特定と、関数の仕様外の文字が含まれていないかのチェック */
	for(i = 0; i < num; i++)
	{
		if(a[i] == '-')
		{
			if(i != 0)
			{
				printf("Error! Invalid argument is used!!\nThis function must be used only for integers, so please put them!\n");
				exit(1);
			}
			else
			{
			}
		}

		/* 小数点が二つ以上ある場合は異常終了、一つならjに記録 */
		else if(a[i] == '.')
		{
			if(j != num)
			{
				printf("Error! String has multiple dots!\n");
				exit(1);
			}
			else
			{
				j = i;
			}
		}
		else if(a[i] < '0' || a[i] > '9')
		{
			printf("Error! Invalid argument is used!!\nThis function must be used only for real numbers, so please put them!\n");
			exit(1);
		}
		else
		{
		}
	}

	/* 整数部分と小数部分では10にかかる指数と配列の要素を用いた数がずれるため、処理を分割して行う */

	/* 整数部分を数値に変換 */
	i = 0;
	if(neg == 1)
	{
		i++;
	}
	else
	{
	}

	while(a[i] != '.')
	{
		answer += (a[i] - adjust) * pow(10, j - i - 1);
		i++;
	}

	i++;	/* ドットは何もせずに通過 */

	/* 小数部分を数値に変換 */
	while(a[i] != '\0')
	{
		answer += (a[i] - adjust) * pow(10, j - i);
		i++;
	}

	if(neg == 1)
	{
		answer *= -1;
	}
	else
	{
	}

	return answer;
}


int main(void)
{
	char a[6];
	char b[6];
	char c[6];
	char d[6];
	strcpy(a, "-360");
	strcpy(b, "-3.14");
	strcpy(c, "--360");
	strcpy(d, "-3.5.6");
	int num = str2int(a);
	double num2 = str2double(b);

	printf("%d\n", num);
	num /= 60;
	printf("%d\n", num);


	printf("%f\n", num2);
	num2 /= 2;
	printf("%f\n", num2);

	/* 以下の処理を行うといずれか一つでも行うと異常終了する */

	// int num3 = str2int(c);
	// printf("%d\n", num3);
	// double num4 = str2double(d);
	// printf("%f\n", num4);

	return 0;
}
