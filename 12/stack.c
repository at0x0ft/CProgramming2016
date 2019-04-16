#include <stdio.h>
#include <stdlib.h>

#define STKSIZE 100

static int stack[STKSIZE];
static int sp = 0;

void stk_push(int n)	/* スタックに積む */
{
	if(sp==STKSIZE)
	{
		printf("stack overflow\n");
		exit(1);
	}
	stack[sp++] = n;
}

int stk_pop(void)	/* スタックから取り出す */
{
	if(sp == 0)
	{
		printf("stack underflow\n");
		exit(1);
	}
	return stack[--sp];
}

int stk_top(void)	/* スタックの一番上の値を返す */
{
	if(sp == 0)
	{
		printf("no data\n");
		exit(1);
	}
	return stack[sp-1];
}

int stk_size(void)	/* 格納されているデータ数 */
{
	return sp;
}

int stk_free(void)	/* 空き容量を返す */
{
	return STKSIZE - sp;
}

int stk_empty(void)	/* スタックが空か？ */
{
	return sp == 0;
}

void stk_clear(void)	/* スタックを空にする */
{
	sp = 0;
}
