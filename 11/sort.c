void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectsort(int *a, int n)
{
	/* a[0]..a[n-1] のソート */

	/* この中を完成させる */
	int tmp, i, j;

	for(j = 2; j < n; j++)
	{
		tmp = j - 1;
		for(i = j; i < n; i++)
		{
			if(a[tmp] > a[i])
			{
				tmp = i;
			}
		}

		if(a[j - 2] > a[tmp])
		{
			swap(&a[j - 2], &a[tmp]);
		}
	}

}

void quick_sort(int *a, int left, int right)
{
	/* a[left]..a[right] のソート */

	/* この中を完成させる */
	int key = a[(left + right) / 2], i = left, j = right;

	// 要素数 >= 2なら実行(初回呼び出し時の例外処理もここでまとめて行う)
	if(right - left + 1 >= 2)
	{

		while(i < j)
		{
			while(key > a[i])
			{
				i++;
			}

			while(key < a[j])
			{
				j--;
			}

			if(i >= j)
			{
				break;
			}

			swap(&a[i], &a[j]);
			i++;
			j--;
		}

			quick_sort(a, left, i - 1);
			quick_sort(a, j + 1, right);

	}
}
