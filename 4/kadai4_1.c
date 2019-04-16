#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gauss(double **a, double *b, int N);

int main(int argc, char *argv[])
{
	double **mat1, *mat2;
	FILE *fp;
	int i, j, N;

	if(argc != 2)
	{
		printf("コマンドライン引数に過不足が生じています。\n");
		exit(1);
	}
	else
	{
	}

	fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		/* open file */
		printf("cannot open %s\n", argv[1]);
		exit(1);
	}
	else
	{
	}

	fscanf(fp, "%d", &N);	/* 次数読み込み */

	mat1 = (double **)malloc((N+1) * sizeof(double *));

	if(mat1 == NULL)
	{
		printf("memory allocation is failed...\n");
		exit(1);
	}
	else
	{
	}

	for (i = 0; i < N+1; i++)
	{
		mat1[i] = (double *)malloc((N+1) * sizeof(double));

		if(mat1[i] == NULL)
		{
			printf("memory allocation is failed...\n");
			exit(1);
		}
		else
		{
		}
	}

	/* 行列のメモリ確保とファイルからのデータの読み込み */

	for (i = 1; i < N+1; i++)
	{
		for(j = 1; j < N+1; j++)
		{
			if(i == 0)
			{
				mat1[i][j] = 0.0;
			}
			else if(j == 0)
			{
				mat1[i][j] = 0.0;
				}

			/* 0 の含まれる成分は 0.0 で初期化 */

			else
			{
				fscanf(fp, "%lf", &mat1[i][j]);	/* 数値読み込み */
			}
		}
	}

	mat2 = (double *)malloc((N+1) * sizeof(double));

	for (i = 1; i < N+1; i++)
	{
		if(i == 0)
		{
			mat2[i] = 0.0;
		}
		else
		{
			fscanf(fp, "%lf", &mat2[i]);	/* 数値読み込み */
		}
	}

	gauss(mat1, mat2, N);

	printf("\nAnswer:\n");	/* 解の表示 */
	for (i = 1; i <= N; i++)
	{
		printf("%f ", mat2[i]);
	}

	printf("\n");

	for (i = 0; i < N+1; i++)
	{
		free(mat1[i]);
	}
	free(mat1);
	free(mat2);

	fclose(fp);

	return 0;
}


void gauss(double **a, double *b, int N)
{
	int i,j,k;
	double alpha;
	/* 以下を完成させる */

		/* 前進消去 */

		for(k = 1; k <= N; k++)
		{
			for (i = k + 1; i <= N; i++)
			{
				if(a[k][k] == 0)
				{
					break;
				}
				else
				{
					alpha = a[i][k] / a[k][k];
					b[i] -= b[k] * alpha;
					for(j = 1; j <= N; j++)
					{
						a[i][j] -= a[k][j] * alpha;
					}
				}
			}
		}

		/* 後退代入 */

		for(j = 0; j < N; j++)
		{
			b[N - j] /= a[N - j][N - j];
			for(i = 1; i < N - j; i++)
			{
				b[i] -= a[i][N - j] * b[N - j];
			}
		}
}
