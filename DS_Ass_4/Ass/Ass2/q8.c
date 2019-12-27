#include<stdio.h>
extern int reverse(char *str);
int main()
{
    char str[100];
    scanf("%s",str);
    reverse(str);
    printf("%s",str);
    return 0;
}
