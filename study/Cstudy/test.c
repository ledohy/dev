#include <stdio.h>

int main()
{
    int a, b = 10;

    scanf("%d %d", &a, &b);
    
    printf("%d %d %d %d", a+b, a-b, a*b, a/b);
}