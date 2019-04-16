#include <stdio.h>

char *num2str(int i, char *str)
{
	sprintf(str, "%d", i);
	return str;
}

int main(void)
{
	int num1, num2;
	char str[30];

	printf("Input number 1: ");
	scanf("%d", &num1);
	printf("Input number 2: ");
	scanf("%d", &num2);
	printf("%s", num2str(num1, str));
	printf(" %s\n", num2str(num2, str));

	return 0;
}
