#include <stdio.h>
#include "stack.h"
#include "que.h"

int main(void)
{
	int num1 = 12, num2 = 345;
	int i;
	char str[] = "stack & queue program";

	stk_clear();
	que_clear();
	printf("num1=%d, num2=%d\n", num1, num2);
	stk_push(num1);
	stk_push(num2);
	que_enqueue(num1);
	que_enqueue(num2);
	printf("stack size=%d free=%d\n", stk_size(), stk_free());
	printf("queue size=%d free=%d\n", que_size(), que_free());

	num1 = stk_pop();
	num2 = stk_pop();
	printf("From stack: num1=%d, num2=%d\n", num1, num2);
	num1 = que_dequeue();
	num2 = que_dequeue();
	printf("From queue: num1=%d, num2=%d\n", num1, num2);

	printf("\nstr=%s\n", str);
	for(i = 0; str[i] != '\0'; i++)
	{
		stk_push(str[i]);
		que_enqueue(str[i]);
	}

	printf("stack: size=%d free=%d\n", stk_size(), stk_free());
	printf("From stack: ");
	while(!stk_empty())
	{
		printf("%c", stk_pop());
	}
	printf("\n");

	printf("queue: size=%d free=%d\n", que_size(), que_free());
	printf("From queue: ");
	while(!que_empty())
	{
		printf("%c",que_dequeue());
	}

	printf("\n");

	return 0;
}
