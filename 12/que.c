#include <stdio.h>
#include <stdlib.h>

#define QUESIZE 100

static int que[QUESIZE];
static int head = 0, tail = 0;

int que_size(void)	/* 現在入っているデータ数 */
{
	if(head < tail)
	{
		return tail - head;
	}
	else
	{
		return tail - head + QUESIZE;
	}
}

int que_free(void)	/* 空き容量を返す */
{
	return QUESIZE - 1 - que_size();
}

int que_empty(void)	/* queueが空か？ */
{
	return head == tail;
}

void que_clear(void)
{
	head = tail = 0;
}

void que_enqueue(int n)	/* queueに格納 */
{
	/* ここを作成する */
	if(que_size() == QUESIZE - 1)	/* バッファが一杯の時はenqueueはしない */
	{
		printf("queue overflow\n");
	}
	else	/* enqueueする */
	{
		que[tail] = n;
		tail = (tail + 1) % QUESIZE;
	}
}

int que_dequeue(void)	/* queueから取り出す */
{
	/* ここを作成する */
	int tmp;

	if(que_empty())	/* バッファが空の時にはdequeueしない */
	{
		printf("que underflow\n");
		return 0;
	}
	else	/* dequeueする */
	{
		tmp = head;
		head = (head + 1) % QUESIZE;
		return que[tmp];
	}
}
