#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("**************************\n");
	printf("**1.��ʼ��Ϸ      2.�˳�**\n");
	printf("**************************\n");
}

void game()
{
	int ret = rand() % 100 + 1;
	int guess = 0;
	int small = 0, max = 100;
	while (1)
	{
		printf("�������");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
			max = guess;
			printf("%d--%d������\n", small, max);
		}
		else if (guess < ret)
		{
			printf("��С��\n");
			small = guess;
			printf("%d--%d������\n", small , max );
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand(time(0));
	do
	{
		menu();
		printf("��ѡ��-->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:printf("��������Ϸ\n"); game(); break;
		case 2:printf("�˳���Ϸ\n"); break;
		default:printf("ѡ���������ѡ��\n");
		}
	} while (input != 2);
	return 0;
}
