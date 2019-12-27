#include<stdio.h>
extern void reverse(char* str);
int main(){
    char str[10005];
    scanf("%s",str);
    reverse(str);
    printf("%d",str);
        return 0;
}