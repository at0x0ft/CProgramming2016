#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 7

typedef struct
{
	int id;
	char name[30];
} BOOK;

int comp_id(const void *a, const void *b)
{
	/* この中を完成させる */
	BOOK BOOK1 = *(BOOK *)a;
	BOOK BOOK2 = *(BOOK *)b;

	return (BOOK1.id - BOOK2.id);
}

int comp_str(const void *a, const void *b)
{
	/* この中を完成させる */
	BOOK BOOK1 = *(BOOK *)a;
	BOOK BOOK2 = *(BOOK *)b;

	/* 小文字があった場合は大文字にする */
	if(BOOK1.name[0] >= 'a' || BOOK1.name[0] <= 'z')
	{
		BOOK1.name[0] = toupper(BOOK1.name[0]);
	}
	if(BOOK2.name[0] >= 'a' || BOOK2.name[0] <= 'z')
	{
		BOOK2.name[0] = toupper(BOOK2.name[0]);
	}

	return strcmp(BOOK1.name, BOOK2.name);
}

int main(void)
{
	int i;
	BOOK item[N] =
	{
		{120, "book1"}, {42, "C Prog."}, {53, "Perl Prog."}, {236, "C++ Prog."}, {8, "Pascal Prog."}, {189, "Lisp Prog."}, {35, "JAVA Prog."}
	};

	qsort(item, N, sizeof(BOOK), comp_id);
	for(i = 0; i < N; i++)
	{
		printf("id=%d, name=%s\n", item[i].id, item[i].name);
	}
	printf("\n");

	qsort(item, N, sizeof(BOOK), comp_str);
	for(i = 0; i < N; i++)
	{
		printf("id=%d, name=%s\n", item[i].id, item[i].name);
	}

	return 0;
}
