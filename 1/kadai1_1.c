#include <stdio.h>

int main(void)
{
	int a, b;
	double d1, d2;

	printf("Put in two integers and press Enter.\n");
	printf("First integer ( = a ) is...");
	scanf("%d", &a);
	printf("Second integer ( = b ) is...");
	scanf("%d", &b);

	d1 = ( a * 1.0) / b;
	d2 = ( b * 1.0) / a;

	printf("a + b = %d\n", a+b);
	printf("a - b = %d\n", a-b);
	printf("b - a = %d\n", b-a);
	printf("a * b = %d\n", a*b);
	printf("a / b = %lf\n", d1);
	printf("b / a = %lf\n", d2);

	return 0;
}
