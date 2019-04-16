#include <stdio.h>
#include <stdlib.h>
#include "newsort.h"

int main(void)
{
	PEOPLE *data;
	int i, item_num;
	FILE *fp;

	/* data.txtを読み込む */

	if((fp = fopen("data.txt", "r")) == NULL)	/* data.txtを開き、読み込みエラーが発生したら異常終了 */
	{
		printf("Cannot open data.txt!\n");
		exit(1);
	}

	fscanf(fp, "%d", &item_num);	/* item_numの取り込み */

	if((data = (PEOPLE *)malloc(sizeof(PEOPLE) * item_num)) == NULL)	/* 構造体PEOPLEの配列の確保(失敗したら異常終了) */
	{
		printf("Memory allocation was failed!!\n");
		exit(1);
	}

	for(i = 0; i < item_num; i++)	/* ファイルの内容を構造体配列PEOPLEに取り込む */
	{
		fscanf(fp, "%d\n", &data[i].id);
		fgets(data[i].code, 31, fp);
		fscanf(fp, "%d\n%d\n", &data[i].age, &data[i].height);
	}

	fclose(fp);	/* data.txtを閉じる */

	selectsort(data, item_num);	/* height */
	for(i = 0; i < item_num; i++)
	{
		printf("id=%d, height=%d\n", data[i].id, data[i].height);
	}
	printf("\n"); 

	quick_sort(data, 0, item_num - 1);	/* code */
	for(i = 0; i < item_num; i++)
	{
		printf("id=%d, code=%s\n", data[i].id, data[i].code);
	}

	free(data);

	return 0;
}
