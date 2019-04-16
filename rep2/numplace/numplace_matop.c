#include <stdio.h>

void matcpy(int a[9][9], int b[9][9])	// table2をtable1にコピーする
{
	int i, j;

	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void minCandiSearch(int table[9][9], int *i, int *j)
{	// 候補数が最小の(i, j)成分を探して、i, jを返す(与えられた2変数に書き込む)
	int k, l, tmp = 123456789;

	for(k = 0; k < 9; k++)
	{
		for(l = 0; l < 9; l++)
		{
			if(table[k][l] >= 10 && table[k][l] <= tmp)	// 候補が2つ以上で
			{	// 前に調べたものより小さければ、その行成分と列成分を書き込む
				tmp = table[k][l];
				*i = k;
				*j = l;
			}
		}
	}
}

int matMatch(int table1[9][9], int table2[9][9])	// table1とtable2が一致しているか否かを調べる
{
	int i, j, ans = 0;

	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(table1[i][j] != table2[i][j])	// 1つでも異なれば
			{
				ans++;	// 1を返す
				break;
			}
		}
		if(ans > 0)
		{
			break;
		}
	}

	return ans;
}