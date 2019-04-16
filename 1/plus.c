#include <stdio.h>
#define DIM 4
int mat1[DIM][DIM] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
int mat2[DIM][DIM] = {{17,18,19,20}, {21,22,23,24}, {25,26,27,28}, {29,30,31,32}};

/* 行列の和 */

void plus(int array1[][DIM], int array2[][DIM], int ans[][DIM])
{
	int i,j;

	for (i=0; i<DIM; i++)
		for (j=0; j<DIM; j++)
			ans[i][j]=array1[i][j]+array2[i][j];
}

/* 行列の表示 */

void print_matrix(int array[][DIM])
{
	int i,j;

	for (i=0; i<DIM; i++)
		{
			for (j=0; j<DIM; j++)
			{
				printf("%d ", array[i][j]);
			}
			printf("\n");
		}
}

int main(void)
{
	int i,j,ans[DIM][DIM];

	plus(mat1,mat2,ans);
	print_matrix(ans);

	return 0;
}
