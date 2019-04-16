#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fib(int n)
{

	int ansneg = -1, e0 = 1, e1 = 0, anspos = 1, i;

	if(abs(n) > 40)
	{
		printf("Error:Please put n which is more than -41 and less than 41 (Current n = %d).\n", n);
		exit(1);
	}

	else if(n > 0)
	{
		for(i = 1; i < n; i++)
		{
			e0 = e1;
			e1 = anspos;
			anspos = e0 + e1;
		}

		return anspos;
	}

	else if(n == 0)
	{
		return e1;
	}
	else if(n == -1)
	{
		return e0;
	}

	else
	{
		for(i = -2; i > n; i--)
		{
			e1 = e0;
			e0 = ansneg;
			ansneg = e1 - e0;
		}

		return ansneg;
	}
}

int main()
{
	int n;

	printf("Put in n for F(n) (-40 <= n <= 40) : ");
	scanf("%d", &n);

	printf("F(%d) =  %d\n", n, fib(n));

	return 0;
}
