#include <stdio.h>

typedef struct
{
	char title[30];
	int pages;
	int id;
} BOOK;

BOOK item[8] =
{
	{"English Reading", 110, 980},
	{"C Prog.", 218, 3000},
	{"Perl Prog.", 120, 1800},
	{"C++ Prog.", 360, 4500}, 
	{"Pascal Prog.", 190, 2200},
	{"Lisp Prog.", 150, 1700},
	{"JAVA Prog.", 200, 2900},
	{"C# Prog.", 240, 3800}
};

int item_num = 8;

int linear_s_banpei(BOOK ary[], int n, int key)
{
	int i = 0, tmp;

	if(ary[n].id == '\0')	/* 配列がいっぱいの時の処理 */
	{
		if(key == ary[n - 1].id)	/* 配列の最後に番兵を置く前に、その要素がkeyと一致しているかどうかを確認 */
		{
			return n - 1;
		}

		tmp = ary[n - 1].id;	/* 一時的に最後のidを保存しておく */
		ary[n - 1].id = key;	/* 配列の最後の要素に番兵を一時的に置く */

		while(ary[i].id != key)
		{
			++i;	/* keyとary[i].idが一致するまでiをインクリメントし、探す */
		}
	
		if (i < n)
		{
			ary[n - 1].id = tmp;	/* 番兵を戻してiを返して終了 */
			return i;
		}

		else
		{
			ary[n - 1].id = tmp;	/* 番兵を戻して-1(見つからなかったことを表す値)を返して終了 */
			return -1;
		}
	}

	else	/* 配列の最後に余裕がある時の処理 */
	{
		ary[n].id = key;	/* 配列の最後の要素に番兵を置く */

		while(ary[i].id != key)
		{
			++i;	/* keyとary[i].idが一致するまでiをインクリメントし、探す */
		}

		if (i < n)
		{
			return i;	/* iを返して終了 */
		}

		else
		{
			return -1;	/* -1(見つからなかったことを表す値)を返して終了 */
		}
	}
}

int main(void)
{
	int ret;

	ret = linear_s_banpei(item, item_num, 1700);

	if(ret == -1)	/* retが-1である時、見つからなかったことを表示 */
	{
		printf("not found\n");
	}
	else	/* 検索に一致した結果を表示 */
	{
		printf("id=%d, name=%s\n", ret, item[ret].title);
	}

	return 0;
}
