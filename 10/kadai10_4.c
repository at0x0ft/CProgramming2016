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

int linear_s(PEOPLE data, char strs[])
{
	unsigned int i = 0, j = 0, tmp;
	int resultid = -1;

	/* 一致処理 */
	for(i = 0; i < strlen(data.code); i++)
	{
		if(data.code[i] == strs[j])	/* 最初の一文字が一致したら */
		{
			for(tmp = i; tmp < i + strlen(strs); tmp++)	/* iの位置をtmpに記録し、文字列の一致を判定 */
			{
				if(data.code[tmp] != strs[j])	/* 一致しなければ、検索元の文字列のループ変数jを元に戻し、一致判定ループを抜ける */
				{
					j = 0;
					break;
				}
				else if(tmp == i + strlen(strs) - 1)	/* 終端まで一致したら、検索元の文字列のループ変数jを元に戻し、その文字列の先頭のiを戻り値に記録して判定ループを終了 */
				{
					resultid = i;
					j = 0;
					break;
				}
				j++;	/* 検索元の文字列のループ変数jも(tmpとともに)インクリメントする */
			}
		}
	}

	return resultid;	/* resultidを返す(一致しなければ-1が返る) */
}

int main(int argc, char *argv[])
{
	int i, index, item_num, fndflg = -1;
	PEOPLE *data;
	FILE *fp;


	if(argc != 3)	/* コマンドライン引数の過不足が生じたら異常終了 */
	{
		printf("Error:Command line arguments was too short or too long!\n");
		exit(1);
	}

	if((fp = fopen(argv[1],"r")) == NULL)	/* data.txtを開き、読み込みエラーが発生したら異常終了 */
	{
		printf("Cannot open %s!\n", argv[1]);
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

	for(i = 0; i < item_num; i++)	/* コマンドライン引数に入力された文字列をcodeに含むデータを検索し、表示 */
	{
		index = linear_s(data[i], argv[2]);
		if(index >= 0)	/* indexが-1でないもののみを表示 */
		{
			++fndflg;	/* 一つでもデータが見つかれば、fndflgが0以上になる */
			printf("id: %d\ncode: %s\npos=%d\n\n", data[i].id, data[i].code, index);
		}
	}

	if(fndflg < 0)	/* 一つもデータが見つからなければ(fndflgが負で)not foundを表示 */
	{
		printf("not found\n");
	}

	free(data);

	return 0;
}
