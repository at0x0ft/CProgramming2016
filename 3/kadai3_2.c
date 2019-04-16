#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int rdmnum, i;
	FILE *fp;
	time_t t = time(NULL);

	srand(t); /* srand((unsigned)time(NULL)); */

	fp = fopen("100 random numbers from 1 to 6.txt", "w");
	if(fp == NULL)
	{
		printf("Can't open a file!!\n");
		return 1;
	}
	else
	{
	}

	for(i = 0; i < 100; i++)
	{
		rdmnum = rand() % 6 + 1;
		fprintf(fp,"%d", rdmnum);

		if(i < 99)
		{
			fprintf(fp,"\n");
		}
		else
		{
		}
	}

	fclose(fp);

	return 0;
}
