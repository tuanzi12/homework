#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqLIst.h"

//�������
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

//������
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

//ͷ��
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

//β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷɾ
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

//βɾ
void SeqListPopBack(SeqList* ps)
{
	/*if (ps->size == 0)
		return;
	ps->a[ps->size - 1] = 0;*/
	assert(ps->size>0);
		ps->size--;		
}

//˳������
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

//ָ��λ�ò���
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

//ָ��λ��ɾ��
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps->size > 0);
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;

}

//���
void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//˳�������
void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity=ps->size = 0;
}
