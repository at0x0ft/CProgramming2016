#include <stdio.h>
#include <stdlib.h>

#define QUESIZE 100

void que_enqueue(int);
int que_dequeue(void);
int que_size(void);
int que_free(void);
int que_empty(void);
void que_clear(void);

int que[QUESIZE];
int head = 0, tail = 0;


void que_enqueue(int n)	/* queueに格納 */
{
	/* ここを作成する */
	if(que_size() == QUESIZE - 1)	/* バッファが一杯の時はenqueueはしない */
	{
		printf("que overflow\n");
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

int main(void)
{
	int i;
	int num1 = 12, num2 = 345, num3 = 6789;
	char str[]="queue sample program";

	que_clear();

	que_enqueue(num1);
	que_enqueue(num2);
	que_enqueue(num3);
	printf("size=%d free=%d\n", que_size(), que_free());

	while(!que_empty())
	{
		printf("deque=%d \n", que_dequeue());
	}

	printf("\nenqueue.....");
	for(i = 0; str[i] != '\0'; i++)
	{
		printf("%c",str[i]);
		que_enqueue(str[i]);
	}

	printf("\ndequeue.....");
	while(!que_empty())
	{
		printf("%c", que_dequeue());
	}
	printf("\n");

	return 0;
}
