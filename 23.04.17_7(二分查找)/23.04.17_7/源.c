#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	printf("��������Ҫ���ҵ�����");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ԫ�ظ���
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;//��������������
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��ˣ��±���:%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("�Ҳ���\n");
	return 0;
}