#include <stdio.h>

int main(void)
{
	int data[]={10,8,6,4,2};
	int *p=data, i;

	printf("%d\n", (*p)++);
	printf("%d\n", *p++);
	printf("%d\n", --(*p));
	for (i=0; i<5; i++)
		printf("%d ", data[i]);
	printf("\n");
	return 0;
}
