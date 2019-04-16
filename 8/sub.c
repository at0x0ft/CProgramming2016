#include <stdio.h>

extern int x;	/* 外部変数 */

void func(void)
{
	printf("func1: x = %d\n", x);
}
