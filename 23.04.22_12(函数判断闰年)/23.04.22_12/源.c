#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int is_leap_year(int i)
{
    return  ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0));
}
int main()
{
    int i,year = 0;
    printf("������Ҫ�ж��Ƿ�Ϊ��������");
    scanf("%d", &year);
    if (is_leap_year(year) == 1)
        printf("%d������ ", year);
    else
        printf("%d��������", year);
return 0;
}