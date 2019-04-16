#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bufferLimNum = 128;

int isWhat(char l)	// 0 = num, ( = 1, ) = -1, otherwise = 100
{
	int ans = 100;

	if(l >= '1' && l <= '9')
	{
		ans = 0;
	}
	else if(l == '(')
	{
		ans = 1;
	}
	else if(l == ')')
	{
		ans = -1;
	}
	else if(l == 'C')	// へんな演算子
	{
		ans = 2;
	}
	else if(l == '!')	// 左単項演算子
	{
		ans = -2;
	}
	else if(l == '*')	// 以下両サイド数字
	{
		ans = 3;
	}
	else if(l == '/')
	{
		ans = -3;
	}
	else if(l == '+')
	{
		ans = 4;
	}
	else if(l == '-')
	{
		ans = -4;
	}
	else if(l == ',')
	{
		ans = 5;
	}
	else if(l == ' ')
	{
		ans = -5;
	}

	return ans;
}

int main(void)
{
	char buffer[bufferLimNum];
	int parCount = 0, parSPointer, parGPointer;
	int i, j = 0;

	printf("This is calculater.\nNote:If you want to calculate \"10C5\", please write it as \"C(10,5)\".\n");
	printf("Input(within %d letters): ", bufferLimNum - 1);
	fgets(buffer, 128, stdin);

	for(i = 0; isWhat(buffer[i]) == -5; i++)	// syntax error detector
	{
		printf("%d\n", isWhat(buffer[i]));
		if(abs(isWhat(buffer[i])) >= 6)	// atodekesu
		{
			printf("Error! Please input figures, \"(\", \")\", \"C\", \"!\", \"*\", \"/\", \"+\", \"-\", \"*\", \"/\" or \",\"!\n");
			exit(1);
		}
		else if(isWhat(buffer[i]) == 1)
		{
			if((isWhat(buffer[i + 1]) != 0 && isWhat(buffer[i + 1]) != 1) && (isWhat(buffer[i + 1]) != 2 && isWhat(buffer[i + 1]) != -4))	// OK:fig ( C -
			{
				printf("Syntax error after \"(\" in %d!\n", i + 1);
				exit(1);
			}
			parCount++;
			parSPointer = i;
		}
		else if(isWhat(buffer[i]) == -1)
		{
			if(isWhat(buffer[i + 1]) == 0 || (isWhat(buffer[i + 1]) == 1 || isWhat(buffer[i + 1]) == 2))	// bad:fig ( C 
			{
				printf("Syntax error after \")\" in %d!\n", i + 1);
				exit(1);
			}
			parCount--;
			parGPointer = i;
			if(parCount < 0)
			{
			}
		}
		else if(isWhat(buffer[i]) == 2)
		{
			if(isWhat(buffer[i + 1]) != 1)	// only:(
			{
				printf("Syntax error after \"C\" in %d!\n", i + 1);
				exit(1);
			}
		}
		else if(isWhat(buffer[i]) == -2)
		{
			if(isWhat(buffer[i + 1]) == 0 || (isWhat(buffer[i + 1]) == 1 || isWhat(buffer[i + 1]) == 2))	// bad:fig ( C
			{
				printf("Syntax error after \"!\" in %d!\n", i + 1);
				exit(1);
			}
		}
		else if((abs(isWhat(buffer[i])) == 3 || abs(isWhat(buffer[i])) == 4) || isWhat(buffer[i]) == 5)	// math.h
		{
			if((isWhat(buffer[i + 1]) != 0 || isWhat(buffer[i + 1]) != 1) || isWhat(buffer[i + 1]) != 2)	// OK:fig ( C
			{
				if(isWhat(buffer[i]) == 3)
				{
					printf("Syntax error after \"*\" in %d!\n", i + 1);
					exit(1);
				}
				if(isWhat(buffer[i]) == -3)
				{
					printf("Syntax error after \"/\" in %d!\n", i + 1);
					exit(1);
				}
				if(isWhat(buffer[i]) == 4)
				{
					printf("Syntax error after \"+\" in %d!\n", i + 1);
					exit(1);
				}
				if(isWhat(buffer[i]) == -4)
				{
					printf("Syntax error after \"-\" in %d!\n", i + 1);
					exit(1);
				}
				if(isWhat(buffer[i]) == 5)
				{
					printf("Syntax error after \",\" in %d!\n", i + 1);
					exit(1);
				}
			}
		}
		else if(isWhat(buffer[i]) == 0)
		{
			if(isWhat(buffer[i + 1]) == 1 || isWhat(buffer[i + 1]) == 2)	// bad:( C 
			{
				printf("Syntax error after \"%c\" in %d!\n", buffer[i], i + 1);
				exit(1);
			}
		}

	// ()	C(,)	!	* /	+-	// fig () C ! * / + - ,	*/

	}

	if(parCount > 0)
	{
		printf("Syntax error(\"(\" is too many)!\n");
		exit(1);
	}
	else if(parCount < 0)
	{
		printf("Syntax error(\")\" is too many)!\n");
		exit(1);
	}


	printf("%s\n", buffer);	// atodekesu

	return 0;
}
