#include <stdio.h>
#include "numplace_print.h"
#include "numplace_refine.h"

int main(int argc, char **argv)
{
	int table[80][9][9];	// ナンプレを解くための9×9の表を用意する
	// (最大 9 × 9 - 1 = 80か所の仮定が必要となる可能性があるため、表を更に配列として確保する)

	initialize(argc, argv, table[0]);	// 例外処理と問題の表示と読み込み

	solve(table);	// 問題を解いて結果を表示

	finalPrintTable(table[0]);	// 最終結果の表示

	return 0;
}
