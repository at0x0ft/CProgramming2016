#include <stdio.h>

int rowCheck(int table[9][9])	// 行の重複をチェック
{
	int i, j, k, ans = 0;

	for(i = 0; i < 9; i++)	// i行についてチェック
	{
		for(j = 0; j < 9; j++)	// j列成分とそれより右側の成分を比べて一致しているか否かを調べる
		{
			for(k = j + 1; k < 9; k++)
			{
				if(table[i][j] == table[i][k])	// どこか1つでも一致したら
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
		if(ans > 0)
		{
			break;
		}
	}

	return ans;
}

int columnCheck(int table[9][9])	// 列の数字の重複をチェック
{
	int i, j, k, ans = 0;

	for(j = 0; j < 9; j++)	// j行についてチェック
	{
		for(i = 0; i < 9; i++)	// i列成分とそれより右側の成分を比べて一致しているか否かを調べる
		{
			for(k = i + 1; k < 9; k++)
			{
				if(table[i][j] == table[k][j])	// どこか1つでも一致したら
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
		if(ans > 0)
		{
			break;
		}
	}

	return ans;
}

int squareCheck(int table[9][9])	// 3×3正方領域内の数字の重複をチェック
{
	int i, j, k, l, m, n, ans = 0;

	for(m = 0; m < 3; m++)	// 3×3個の3×3正方領域を固定
	{
		for(n = 0; n < 3; n++)
		{
			for(i = m * 3; i < m * 3 + 3; i++)	// 3×3正方領域内で順にチェックしていく
			{
				for(j = n * 3; j < n * 3 + 3; j++)
				{
					for(k = m * 3; k < m * 3 + 3; k++)
					{
						for(l = n * 3; l < n * 3 + 3; l++)
						{
							if((i != k && j != l) && table[i][j] == table[k][l])	// どこか1つでも一致したら
							{	// "i != k && j != l" の "&&" は "||" でも良いが、rowCheck や columnCheck で既にチェックしているため省く
								ans++;	// 1を返す
								break;
							}
						}
						if(ans > 0)
						{
							break;
						}
					}
					if(ans > 0)
					{
						break;
					}
				}
				if(ans > 0)
				{
					break;
				}
			}
			if(ans > 0)
			{
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

int diagonalCheck(int table[9][9])	// 対角線上の数字の重複をチェック
{
	int i, k, ans = 0;

	for(i = 0; i < 9; i++)	// 左上から右下へチェック
	{
		for(k = i + 1; k < 9; k++)
		{
			if(table[i][i] == table[k][k])	// どこか1つでも一致したら
			{
				ans++;	// 1を返す
				break;
			}
		}
		if(ans != 0)
		{
			break;
		}
	}

	for(i = 0; i < 9; i++)	// 左下から右上へチェック
	{
		if(ans != 0)
		{
			break;
		}
		for(k = i + 1; k < 9; k++)
		{
			if(table[8 - i][i] == table[8 - k][k])	// どこか1つでも一致したら
			{
				ans++;	// 1を返す
				break;
			}
		}
	}

	return ans;
}

int refCheck(int table[9][9])	// 全ての候補がただ1つに絞りきれているかチェック
{
	int i, j, ans = 0;

	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(table[i][j] >= 10)	// どこかのマス1つでも候補が2つ以上残っているのなら
			{
				ans++;	// 1を返す
				break;
			}
		}
		if(ans != 0)
		{
			break;
		}
	}

	return ans;
}

int solvedCheck(int table[9][9])	// 解けたかどうかを確かめる
{
	int ans = 1;

	if((rowCheck(table) == 0 && columnCheck(table) == 0) && (squareCheck(table) == 0 && diagonalCheck(table) == 0) && refCheck(table) == 0)
	{	// 行、列、正方領域、対角線上の全てのマスの数字が一致せず、かつ全てただ1つに確定してるなら
		ans = 0;	// 解けたことを知らせる
	}

	return ans;
}