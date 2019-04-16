#include <stdio.h>
#include <string.h>

#define N 4

void gauss(double a[][N+1], double b[]);

double mat1[N+1][N+1]=
{
	{0.0, 0.0, 0.0, 0.0, 0.0},
	{0.0, 1.0, 2.0, 1.0, 1.0},
	{0.0, 4.0, 5.0, -2.0, 4.0},
	{0.0, 4.0, 3.0, -3.0, 1.0},
	{0.0, 2.0, 1.0, 1.0, 3.0}
};
double mat2[N+1]={0.0, -1.0, -7.0, -12.0, 2.0}; 

int main(void)
{
	int i;

	gauss(mat1, mat2);

	printf("\nAnswer:\n"); /* 解の表示 */
	for (i=1; i<=N; i++)
	{
		printf("%f ", mat2[i]);
	}

	printf("\n");
	return 0;
}

void gauss(double a[][N+1], double b[])
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
