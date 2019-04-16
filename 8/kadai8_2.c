#include <stdio.h>

int gcd(int x, int y)
{
	if(y == 0)
	{
		return x;
	}

	else
	{
		return gcd(y, x % y);
	}
}

int main()
{
	int x, y;

	printf("Put in x, y for gcd(x, y) (ex:12 4) : ");
	scanf("%d %d", &x, &y);

	printf("gcd(x, y) = %d\n", gcd(x, y));

	return 0;
}
