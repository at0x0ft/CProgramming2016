#include <stdio.h>

int bin_search(int ary[], int n, int key)
{
	int left, right, mid;

	left = 0;
	right = n - 1;

	while(left <= right)
	{
		if(right - left % 2 == 0)	/* right - left の偶奇でmidの計算式を変え、値を正確な整数にする */
		{
			mid = (left + right) / 2;
		}
		else
		{
			mid = (left + right + 1) / 2;
		}

		/*
		 見つかったら，そのindexを返す

		 ここを完成させる
		*/

		if(ary[mid] == key)	/* 配列の要素とkeyが一致した場合、 midを返す */
		{
			return mid;
		}
		else if(ary[mid] > key)	/* 配列の要素よりもkeyが小さい場合、 rightをmidとして再計算 */
		{
			right = mid;
		}
		else	/* 配列の要素よりもkeyが小さい場合、 leftをmidとして再計算 */
		{
			left = mid;
		}
	}

	return -1;	/* 見つからなかったら-1を返す */
}

int main(void)
{
	int key;
	int data[14] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};

	for(key = 10; key <= 70; key += 10)
	{
		printf("data=%d ret=%d\n", key, bin_search(data, 14, key));
	}

	return 0;
}
