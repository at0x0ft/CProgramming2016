#include <stdio.h>

int main (void)
{
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int i;
	int str[100];
	FILE *fp;

	fp = fopen("100 random numbers from 1 to 6.txt", "r");
	if(fp == NULL)
	{
		printf("Can't open a file!!");
		return 1;
	}
	else
	{
	}

	for(i = 0; i < 100; i++)
	{
		fscanf(fp, "%d", &str[i]);
		if(str[i] == 1)
		{
			++count1;
		}
		else if(str[i] == 2)
		{
			++count2;
		}
		else if(str[i] == 3)
		{
			++count3;
		}
		else if(str[i] == 4)
		{
			++count4;
		}
		else if(str[i] == 5)
		{
			++count5;
		}
		else if(str[i] == 6)
		{
			++count6;
		}
		else
		{
		}
	}

	printf("1:%2d\n", count1);
	printf("2:%2d\n", count2);
	printf("3:%2d\n", count3);
	printf("4:%2d\n", count4);
	printf("5:%2d\n", count5);
	printf("6:%2d\n", count6);

	fclose(fp);

	return 0;
}
