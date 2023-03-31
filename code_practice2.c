#include<stdio.h>
int main(){
    int a=0;
    switch (a)
    {
    case 1:
        printf("value of a is 1 \n");
        break;
    case 2:
        printf("value of a is 2 \n");
        break;
    case 3:
        printf("value of a is 3 \n");
        break;
    default:
        printf("value of a is not between 1 to 3 \n");
        break;
    }
    int b=1;
    printf("%d",a>b?a:b);
    return 0;
}