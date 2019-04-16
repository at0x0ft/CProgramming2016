#include <stdio.h>

void swap(int *s, int *t)
{
	int u;

	u = *s;
	*s = *t;
	*t = u;
}

int main(void)
{
	int x = 100, y = 200;

	printf("x=%d, y=%d\n", x, y);
	swap(&x, &y);
	printf("Swap: x=%d, y=%d\n", x, y);
	return 0;
}
