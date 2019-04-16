#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, ltrnum;
	char str[62];
	FILE *fp;


	printf("Input?(within 60 letters): ");
	fgets(str, sizeof(str), stdin);

	ltrnum = strlen(str) - 2;

	fp = fopen("data.txt", "w");
	if(fp == NULL)
	{
		printf("Can't open a file!!");
		return 1;
	}
	else
	{
	}

	for(i = ltrnum; i >= 0 ; i--)
	{
		fprintf(fp,"%c", str[i]);
	}

	fprintf(fp,"\n");

	fclose(fp);

	return 0;
}
