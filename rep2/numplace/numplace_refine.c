#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numplace_check.h"
#include "numplace_matop.h"

static int paradox = 0;	// 数値を仮定した後に矛盾が生じた際に、矛盾を知らせるための変数

void refine(int table[9][9], int i, int j);

void delete0(int *candis)	// 候補を表す数値の下位の桁に0があった時にそれを削除する
{
	if(*candis != 0)
	{
		while(*candis % 10 == 0)	// 最下位の桁の数値は10で割った余りと一致する
		{
			*candis /= 10;	// int型なので、小数は切り捨てられる
		}
	}
}

int canDelete(int *candis, int x)	// 候補から削除対象の数字を除く
{
	int i, tmp, ans = 0;

	if(*candis == x)	// 候補を削除対象が一致した場合には矛盾が生じたことを知らせる
	{
		paradox++;
	}
	else if(*candis >= 10)	// 候補が二つ以上あることを確認
	{
		tmp = *candis;	// tmpで候補内に削除対象が含まれているかどうかを確認する
		for(i = 0; i < 9; i++)	// 候補は最大で9桁なので、ループ回数は最大9回
		{
			if(tmp % 10 == x)	// 削除対象と一致した場合には削除し、ループを抜ける
			{
				*candis -= x * pow(10, i);
				break;
			}
			else	// そうでなければtmpの桁を1つ少なくしてもう一度実行
			{
				tmp /= 10;
			}
		}

		delete0(candis);	// 削除した後に、候補の下位の桁の数値に0が残っていれば0を削除

		if(*candis >= 1 && *candis <= 9)	// 候補が確定したら確定したことを戻り値として返す
		{
			ans++;
		}
	}

	return ans;
}

void rowRefine(int table[9][9], int i, int j)
{	// 確定した成分の数字をその成分の属する行の候補から外す
	int k;

	for(k = 0; k < 9; k++)	// 列成分を動かす
	{
		if(k != j)	// 候補が確定した成分自身ではないことを確認して
		{
			if(canDelete(&table[i][k], table[i][j]) == 1)	// 候補を絞り込む
			{	// 但し、候補を絞り込んで確定した場合には
				refine(table, i, k);	// すぐにその成分の周りも絞り込む
			}
		}
	}
}

void columnRefine(int table[9][9], int i, int j)
{	// 確定した成分の数字をその成分の属する列の候補から外す
	int k;

	for(k = 0; k < 9; k++)	// 行成分を動かす
	{
		if(k != i)	// 候補が確定した成分自身ではないことを確認して
		{
			if(canDelete(&table[k][j], table[i][j]) == 1)	// 候補を絞り込む
			{	// 但し、候補を絞り込んで確定した場合には
				refine(table, k, j);	// すぐにその成分の周りも絞り込む
			}
		}
	}
}

void squareRefine(int table[9][9], int i, int j)
{	// 確定した成分の数字をその成分の属する正方行列の候補から外す
	int k, l;

	for(k = (i / 3) * 3; k < (i / 3) * 3 + 3; k++)	// 正方行列内の行を動かす
	{
		for(l = (j / 3) * 3; l < (j / 3) * 3 + 3; l++)	// 正方行列内の列を動かす
		{
			if(k != i && l != j)	// 候補が確定した成分自身ではないことを確認して
			{	// ("||"でも良いが、"&&"とするとrowRefineやcolumnRefineで既に絞り込んだものを省ける)
				if(canDelete(&table[k][l], table[i][j]) == 1)	// 候補を絞り込む
				{	// 但し、候補を絞り込んで確定した場合には
					refine(table, k, l);	// すぐにその成分の周りも絞り込む
				}

			}
		}
	}
}

void diagonalRefine(int table[9][9], int i, int j)
{	// 確定した成分の数字が対角成分なら、その成分の属する対角線上の候補から外す
	int k;

	if(i == j)	// 左上から右下へ至る対角線上の成分なら
	{
		for(k = 0; k < 9; k++)	// 対角線上を動かす
		{
			if(k != i)	// 候補が確定した成分自身ではないことを確認して
			{
				if(canDelete(&table[k][k], table[i][i]) == 1)	// 候補を絞り込む
				{	// 但し、候補を絞り込んで確定した場合には
					refine(table, k, k);	// すぐにその成分の周りも絞り込む
				}
			}
		}
	}

	if(i + j == 8)	// 左下から右上へ至る対角線上の成分なら
	{
		for(k = 0; k < 9; k++)	// 対角線上を動かす
		{
			if(k != j)	// 候補が確定した成分自身ではないことを確認して
			{
				if(canDelete(&table[8 - k][k], table[i][j]) == 1)	// 候補を絞り込む
				{	// 但し、候補を絞り込んで確定した場合には
					refine(table, 8 - k, k);	// すぐにその成分の周りも絞り込む
				}
			}
		}
	}
}

void refine(int table[9][9], int i, int j)
{	// 数字が確定した(i, k)成分の属する行、列、正方領域、(対角線上)からその数値を取り除き、絞り込む
	if(paradox == 0)	// 仮定した数値で進めた後に矛盾が生じた際にはそれ以上絞り込みを実行しない
	{
		rowRefine(table, i, j);	// (i, j)成分の属するi行に対して候補の絞り込みを実行
		columnRefine(table, i, j);	// (i, j)成分の属するj行に対して候補の絞り込みを実行
		squareRefine(table, i, j);	// (i, j)成分の属する正方領域に対して候補の絞り込みを実行

		if(i == j || i + j == 8)	// (i, j)が対角線上の成分なら
		{
			diagonalRefine(table, i, j);		// 対角線上の他の成分に対して絞り込みを実行
		}
	}
}

void solve(int table[80][9][9])	// 数値を仮定して絞り込んでいく
{
	int i, j, pcount = 0;	// 数値を仮定した際に、その仮定の回数を記録するための変数

	// 問題として与えられた初期条件を元に、候補を絞り込んでいく

	for(i = 0; i < 9; i++)	// 行成分のループ
	{
		for(j = 0; j < 9; j++)	// 列成分のループ
		{
			if(table[pcount][i][j] >= 1 && table[pcount][i][j] <= 9)	// 確定しているマスの数値は1桁なので
			{
				refine(table[pcount], i, j);	// そこに対してのみ絞り込み実行する
			}	// (但しその途中で確定したマスがあればそこの周りに対しても絞り込みを実行する)
		}
	}

	// 最初の絞り込みのみで確定できなければ、一番少ない候補を見つけて、数値を仮定して絞り込みを繰り返す

	while(solvedCheck(table[pcount]) != 0)	// 解けていなければ、数値を仮定して進める
	{
		pcount++;	// 1か所だけ数値を仮定する
		matcpy(table[pcount], table[pcount - 1]);	// 前の表を写す

		minCandiSearch(table[pcount], &i, &j);	// 候補数が最小のマスを検索する
		table[pcount][i][j] = table[pcount - 1][i][j] % 10;	// 候補を一つ仮定する

		refine(table[pcount], i, j);	// 仮定した成分の周りについて絞り込み

		if(paradox != 0)	// 絞り込んだ後、矛盾が生じた場合
		{
			while(1)
			{
				pcount--;	// 仮定が誤りであるため、表を仮定前に1段階戻す

				if(pcount < 0)	// この時、仮定回数が0を下回った場合(現実にはあり得ない)
				{
					printf("Error:This number place cannot solve!\n");	// 問題設定に矛盾があるとして
					exit(1);	// 異常終了する
				}

				minCandiSearch(table[pcount], &i, &j);	// 再度仮定したマスを検索
				table[pcount][i][j] /= 10;	// 1回目に仮定した数値を候補から除外

				if(table[pcount][i][j] != 0)	// 候補がまだ残っているのなら、
				{
					delete0(&table[pcount][i][j]);	// 候補の下位の桁の0を(あれば)消去

					if(table[pcount][i][j] >= 1 && table[pcount][i][j] <= 9)	// 候補が1つなら
					{
						refine(table[pcount], i, j);	// その成分の周りを絞り込む
					}
					break;
				}	// 候補が残っていない(候補=0)なら、更にその前の仮定が誤りであるとして再度戻る
			}

			paradox = 0;		// 矛盾が解消されたので元に戻す
		}

		if(matMatch(table[pcount], table[pcount - 1]) == 0)	// 仮定と操作の前後で表が全く変化していない場合は
		{
			printf("Error:This number place cannot solve!\n");	// 問題設定に矛盾があるとして
			exit(1);	// 異常終了する
		}
	}

	matcpy(table[0], table[pcount]);	// 確定した答えを0番目の表に写す
}
