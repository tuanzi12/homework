#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	printf("�������������������������Ľ���");
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
	printf("%d %d", num1, num2);
}