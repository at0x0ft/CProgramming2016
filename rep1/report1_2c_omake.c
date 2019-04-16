#include <stdio.h>
#include <stdlib.h>

long double combination(int n, int r)
{
	int i;
	long double ans = 1.0;

	if(n < 0 || r < 0)
	{
		printf("Error : Please input POSITIVE integer or 0 for n and r to Combination.\n");
		exit(1);
	}
	else if(n < r)
	{
		printf("Error : Please input n and r which satisfies n >= r.\n");
		exit(1);
	}

	if(n == r || r == 0)
	{
		return 1;
	}
	else if(n < 60)
	{
		for(i = n; i >= r + 1; i--)
		{
			ans *= i;
			ans /= (i - r);
		}
		return ans;
	}
	else
	{
		return (combination(n - 1, r) + combination(n - 1, r - 1));
	}
}

int main(void)
{
	int n, r;

	printf("Put in n for Combination(n, r) (n >= r) : ");
	scanf("%d", &n);
	printf("Put in r for Combination(n, r) (n >= r) : ");
	scanf("%d", &r);

	printf("Combination(%d, %d) = %.0Lf\n", n, r, combination(n, r));

	return 0;
}
