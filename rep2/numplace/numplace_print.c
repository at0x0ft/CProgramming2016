#include <stdio.h>
#include <stdlib.h>

void initialize(int argc, char **argv, int table[9][9])	// 例外処理と問題の表示と読み込み
{
	int i = 0, j;
	char buffer[10];
	FILE *fp;

	if(argv[1] == NULL)	// ファイル指定がなかった時の処理
	{
		printf(".txt file is not assigned!\n");
		exit(1);
	}
	else if(argc != 2)	// CommandLine引数が多過ぎる場合の処理
	{	// 実行時の "./numberplace" で既にargc = 1なので、argcが異常な場合は3以上しか考えられない
		printf("Command line arguments are too many!\n");
		exit(1);
	}

	fp = fopen(argv[1], "r");	// CommandLine で指定された問題ファイルを開く
	if(fp == NULL)	// ファイルオープンエラー時の処理
	{
		printf("Cannot open %s!\n", argv[1]);
		exit(1);
	}

	printf("Queqtion:\n");	// 確認のため、問題を出力する

	do
	{
		fgets(buffer, 10, fp);	// 文字列の最後には '\0' が書き込まれるため、9 + 1 = 10文字分、一時的に読み込んでおく
		if(buffer[0] != ';')	// ';' から始まるコメントに当たる行ではないことを確認して読み込む
		{
			if(i % 3 == 0)	// 枠線の表示(3行おき)
			{
				printf("+---+---+---+\n");
			}
			for(j = 0; j < 9; j++)	// 9列取り込む
			{
				if(j % 3 == 0)	// 縦の枠線の表示(3列おき)
				{
					printf("|");
				}

				printf("%c", buffer[j]);	// 取り込む前に問題として数値を表示

				if(buffer[j] != ' ')	// 取り込んだ成分が空白(未定)でないなら正式に取り込む
				{
					table[i][j] = buffer[j] - ('1' - 1);
				}
				else	// 空白なら、候補を表すものとして数値123456789を代入する
				{
					table[i][j] = 123456789;
				}

				if(j == 8)	// 縦の枠線の表示(右端)
				{
					printf("|\n");
				}

			}
			if(i == 8)	// 枠線の表示(下端)
			{
				printf("+---+---+---+\n");
			}

			i++;
		}
	} while(i < 9);	// 9行分取り込む

	printf("\n");

	fclose(fp);	// 読み込みが終わったので、ファイルは閉じる
}

void finalPrintTable(int table[9][9])	// 最終的な結果の表示
{
	int i, j;

	printf("Answer:\n");

	for(i = 0; i < 9; i++)
	{
		if(i % 3 == 0)
		{
			printf("+---+---+---+\n");	// 枠線の表示(3行おき)
		}
		for(j = 0; j < 9; j++)
		{
			if(j % 3 == 0)
			{
				printf("|");	// 枠線の表示(3列おき)
			}

			printf("%d", table[i][j]);	// 確定した数字を表示

			if(j == 8)
			{
				printf("|\n");	// 枠線の表示(右端)
			}
		}
		if(i == 8)
		{
			printf("+---+---+---+\n");	// 枠線の表示(下端)
		}
	}
}