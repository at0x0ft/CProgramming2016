#include <stdio.h>
#include <string.h>

int str_len(char *a)
{
	int len, i;

	for(i = 0; a[i] != '\0' ; i++)
	{
		len = i;
	}

	++len;	/* lenは配列内の変数iをコピーしており、配列の要素は 0 から始まるため、調整のためにlenをインクリメントした */

	return len;
}

void str_cpy(char a[], char b[])
{
	int num_b = str_len(b);
	int i;

	for(i = 0; i <= num_b; ++i)	/* iをnum_bまで続けることで、終端文字'\0'までをコピーし、配列の長さの調整もする */
	{
		a[i] = b[i];
	}

}


int main(void)
{
	/* 確認用の部分 */

	/* テスト用文字列 */
	char str1[] = "ABCDEF";
	char str2[] = "123";
	char *p = "abcd";

	int num_1 = str_len(str1);
	printf("%d\n", num_1);

	int num_2 = str_len(str2);
	printf("%d\n", num_2);

	int num_p = str_len(p);
	printf("%d\n", num_p);

	str_cpy(str1, str2);
	printf("%s\n", str1);

	str_cpy(str1, p);
	printf("%s\n", str1);

	str_cpy(str1, "xyz");
	printf("%s\n", str1);

	return 0;
}
