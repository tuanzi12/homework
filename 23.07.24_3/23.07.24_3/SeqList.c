#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqLIst.h"

//检查容量
void CheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, ps->capacity * 2 * (sizeof(SLDateType)));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps -> a = tmp;
		ps->capacity *= 2;
	}
}

//创建表
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//头插
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头删
void SeqListPopFront(SeqList* ps)
{
	/*if (ps->size == 0)
		return;*/
	assert(ps->size >  0);
	int front = 0;
	while (front < ps->size)
	{
		ps->a[front] = ps->a[front + 1];
		front++;
	}
	ps->size--;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	/*if (ps->size == 0)
		return;
	ps->a[ps->size - 1] = 0;*/
	assert(ps->size>0);
		ps->size--;		
}

//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps->size > 0);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return 0;
}

//指定位置插入
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	CheckCapacity(ps);
	for (int i = ps->size; i >= pos; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;

}

//指定位置删除
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps->size > 0);
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;

}

//输出
void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//顺序表销毁
void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity=ps->size = 0;
}
