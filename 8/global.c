#include <stdio.h>
int x = 10;	/* global */

void func1(void)
{
	int x = 1;	/* local */
	printf("func1: x = %d\n", x);
}

void func2(void)
{
	printf("func2 1: x = %d\n", x);
	x = 20;	/* global */
	printf("func2 2: x = %d\n", x);
	{
		int x = 3;	/* block内local */
		printf("func2 3: x = %d\n", x);
	}
	printf("func2 4: x = %d\n", x);
}

void func3(int y)
{
	printf("func3 1: y = %d\n", y);
	y = 8;	/* 引数はlocal変数 */
	printf("func3 2: y = %d\n", y);
}

int main(void)
{
	int y = 5;

	printf("main 1: x = %d\n", x);
	func1();
	printf("main 2: x = %d\n", x);
	func2();
	printf("main 3: x = %d\n", x);
	func3(y);
	printf("main 4: y = %d\n", y);

	return 0;
}
