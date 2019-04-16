#include <stdio.h>
#include <stdlib.h>

#define STKSIZE 100

void stk_push(int);
int stk_pop(void);
int stk_top(void);
int stk_size(void);
int stk_free(void);
int stk_empty(void);
void stk_clear(void);

int stack[STKSIZE];
int sp = 0;

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

int main(void)
{
	int i;
	int num1 = 12, num2 = 345, num3 = 6789;
	char str[]="stack sample program";

	stk_clear();
	printf("num1=%d, num2=%d, num3=%d \n", num1, num2, num3);
	stk_push(num1);
	stk_push(num2);
	stk_push(num3);
	printf("top=%d size=%d free=%d\n", stk_top(), stk_size(), stk_free());
	num1 = stk_pop();
	num2 = stk_pop();
	num3 = stk_pop();
	printf("num1=%d, num2=%d, num3=%d\n", num1, num2, num3);

	printf("str=%s\n", str);
	for(i = 0; str[i] != '\0'; i++)
	{
		stk_push(str[i]);
	}

	printf("top=%d size=%d free=%d\n", stk_top(), stk_size(), stk_free());

	while(!stk_empty())
	{
		printf("%c", stk_pop());
	}
	printf("\n");

	return 0;
}
