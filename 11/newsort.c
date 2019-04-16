#include <string.h>

typedef struct
{
	int id;
	char code[31];
	int age;
	int height;
} PEOPLE;

void swap(PEOPLE *a, PEOPLE *b)
{
	PEOPLE tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectsort(PEOPLE *data, int n)
{
	int tmp, i, j;

	for(j = 2; j < n; j++)
	{
		tmp = j - 1;
		for(i = j; i < n; i++)
		{
			if(data[tmp].height > data[i].height)
			{
				tmp = i;
			}
		}

		if(data[j - 2].height > data[tmp].height)
		{
			swap(&data[j - 2], &data[tmp]);
		}
	}

}

void quick_sort(PEOPLE *data, int left, int right)
{

	int i = left, j = right;
	char key[31];
	strcpy(key, data[(left + right) / 2].code);

	if(right - left + 1 >= 2)
	{

		while(i < j)
		{
			while(strcmp(key, data[i].code) > 0)
			{
				i++;
			}

			while(strcmp(key, data[j].code) < 0)
			{
				j--;
			}

			if(i >= j)
			{
				break;
			}

			swap(&data[i], &data[j]);
			i++;
			j--;
		}

			quick_sort(data, left, i - 1);
			quick_sort(data, j + 1, right);

	}
}
