#include <stdio.h>

int gcd(int x, int y)
{
	int tmp;

	while(y != 0)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}

	return x;
}

int main()
{
	int x, y;

	printf("Put in x, y for gcd(x, y) (ex:12 4) : ");
	scanf("%d %d", &x, &y);

	printf("gcd(x, y) = %d\n", gcd(x, y));

	return 0;
}
