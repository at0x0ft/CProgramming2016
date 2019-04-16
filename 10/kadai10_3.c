#include <stdio.h>
#include <string.h>

const char str[] = "abcdefghijklmnopqrstuvwxyz";

unsigned int item_num = strlen(str);

int linear_s(const char str[], const char strs[])
{
	unsigned int i = 0, j = 0, tmp;
	int resultid = -1;

	/* 一致処理 */
	for(i = 0; i < strlen(str); i++)
	{
		if(str[i] == strs[j])	/* 最初の一文字が一致したら */
		{
			for(tmp = i; tmp < i + strlen(strs); tmp++)	/* iの位置をtmpに記録し、文字列の一致を判定 */
			{
				if(str[tmp] != strs[j])	/* 一致しなければ、検索元の文字列のループ変数jを元に戻し、一致判定ループを抜ける */
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

	return resultid;
}

int main(void)
{
	int ret;
	const char strs[] = "pqr";

	ret = linear_s(str, strs);
	printf("\"pqr\" begins from %d.\n", ret);

	return 0;
}
