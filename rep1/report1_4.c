#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prmjdg(int n)
{
	int i;

	if( ( n == 2 || n == 3 ) ||n == 5)
	{
		return 0;
	}
	else if( ( n == 1 || n % 2 == 0 ) || ( n % 3 == 0 || n % 5 == 0 ) )
	{
		return 1;
	}

	for(i = 1; (6 * i + 1) <= sqrt(n); i++)
	{
		if(n % (6 * i + 1) == 0)
		{
			return 1;
		}
	}

	for(i = 1; (6 * i + 5) <= sqrt(n); i++)
	{
		if(n % (6 * i + 5) == 0)
		{
			return 1;
		}
	}

	return 0;
}


int main(void)
{
	int prmflag, n;
	long double pre_n;

	printf("Input Natural Number n (1 <= n <= 2147483647) : ");
	scanf("%Lf", &pre_n);

	if(pre_n < 1 || pre_n > 2147483647)
	{
		printf("Error : Please input valid n !\n");
		exit(1);
	}
	else
	{
		n = pre_n;
	}

	prmflag = prmjdg(n);

	if(prmflag == 0)
	{
		printf("n = %d is the Prime Number.\n", n);
	}

	else
	{
		printf("n = %d is NOT the Prime Number.\n", n);
	}

	return 0;
}
