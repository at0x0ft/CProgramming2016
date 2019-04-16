#include <stdio.h>
#include <string.h>

void upper(char *a, unsigned int k)
{
	for(k = 0; k <= strlen(a); k++)
	{
		if(a[k] >= 97 && a[k] <= 122)
		{
			a[k] = a[k] - 32;
		}
		else
		{
		}
	}
}

void lower(char *a, unsigned int k)
{
	for(k = 0; k <= strlen(a); k++)
	{
		if(a[k] >= 65 && a[k] <= 90)
		{
			a[k] = a[k] + 32;
		}
		else
		{
		}
	}
}

int main(void)
{
	unsigned int i = 0;
	char str[62];

	printf("Input?(within 60 letters): ");
	fgets(str, sizeof(str), stdin);

	upper(str, i);
	printf("%s", str);

	lower(str, i);
	printf("%s", str);

	return 0;
}
