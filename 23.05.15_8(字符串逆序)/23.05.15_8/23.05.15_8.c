#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    long n = 0, k = 0;
    scanf("%ld %ld", &n, &k);
    if (k == 0)
    {
        printf("%ld", n * n);
        
    }
    long count = 0;
    for (long y = k + 1; y <= n; y++)
    {
        long ret = n % y < k ? 0 : n % y - (k - 1);
        count += (y - k) * (n / y) + (ret);
    }
    printf("%ld\n", count);
    return 0;
}