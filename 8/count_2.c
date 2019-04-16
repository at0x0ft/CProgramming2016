#include <stdio.h>

int add_counter(void)
{
	static int count=0;
	
	return ++count;
}

int main(void)
{
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("%d\n", add_counter());
	}
	return 0;
}
