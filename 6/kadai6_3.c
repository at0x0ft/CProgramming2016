#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char code[31];
	int age;
	int height;
} PEOPLE;

int item_num;

int main(int argc, char *argv[])
{
	int i;
	int max_age, max_age_id;
	int min_height, min_height_id;
	PEOPLE *data;
	FILE *fp;

	if(argc != 2) exit(1);

	if((fp = fopen(argv[1],"r")) == NULL)
	{
		printf("Cannot open %s\n", argv[1]);
		exit(1);
	}

	fscanf(fp, "%d", &item_num);

	if((data = (PEOPLE *)malloc(sizeof(PEOPLE) * item_num)) == NULL)
	{
		printf("Memory allocation was failed!!\n");
		exit(1);
	}

	for(i = 0; i < item_num; i++)
	{
		fscanf(fp, "%d\n", &data[i].id);
		fgets(data[i].code, 31, fp);
		fscanf(fp, "%d\n%d\n", &data[i].age, &data[i].height);
	}

	fclose(fp);

	/*
		PEOPLE構造体のageが最大値のもの
		heightが最小のものを探して表示
	*/

	max_age = data[0].age;
	max_age_id = data[0].id;

	for(i = 1; i < item_num; i++)
	{
		if(data[i].age > max_age)
		{
			max_age = data[i].age;
			max_age_id = data[i].id;
		}
		else
		{
		}
	}

	min_height = data[0].height;
	min_height_id = data[0].id;

	for(i = 1; i < item_num; i++)
	{
		if(data[i].height < min_height)
		{
			min_height = data[i].height;
			min_height_id = data[i].id;
		}
		else
		{
		}
	}

	printf("Max data is...\n");
	printf("%d\n%s\n%d\n%d\n", max_age_id, data[max_age_id - 120001].code, data[max_age_id - 120001].age, data[max_age_id - 120001].height);

	printf("\n");

	printf("Min data is...\n");
	printf("%d\n%s\n%d\n%d\n", min_height_id, data[min_height_id - 120001].code, data[min_height_id - 120001].age, data[min_height_id - 120001].height);

	free(data);

	return 0;
}
