#include<stdio.h>
#include<stdlib.h>
int main(){
    /*int i;
    char j;
    scanf("%d",&i);
    scanf("%d",&j);
    // printf("the value is: %d%s",(9>10)?9:10,"kg");
    printf("%d   %c",i,j); */

// FULL PYRAMID OF ALPHABETS GIVEN BELOW:-
/*
_   _   _   _   A   _   _   _   _
_   _   _   A   B   C   _   _   _
_   _   A   B   C   D   E   _   _
_   A   B   C   D   E   F   G   _
A   B   C   D   E   F   G   H   I
*/
/*
    int n;
    printf("enter the number of rows you want: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for(int j=n-1;j>i;j--){
            printf(" \t");
        }
        for(int k=0;k<2*i+1;k++){
            printf("%c %s",k+'A',"\t");
        }
        printf("\n");
    }    
*/

// HALF PYRAMID OF ALPHABETS GIVEN BELOW:-
/* A    B   C   D   E
   _    A   B   C   D
   _    _   A   B   C
   _    _   _   A   B
   _    _   _   _   A
*/

/*
    int n;
    printf("enter the number of rows you want: ");
    scanf("%d",&n);
    int l=0;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<i;j++){
            printf(" \t");
        }
        
        for(int k=5;k>i;k--){
            printf("%c %s",l+'A',"\t");
            l++;
        }
        printf("\n");
    } 
*/

    FILE *ptr1;
    ptr1=fopen("random.txt","a");

    int* arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("enter the element a%d%d",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    int* arr1[3][1];
    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            printf("enter the element a%d%d  ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }

    int* arr2[3][1];
    for(int l=0;l<3;l++){
        int m=0;
        arr2[l][m]=NULL;
        for(m=0;m<3;m++){
            if(arr[l][m] || arr1[m][l]==NULL){
                continue;
            }
            int a=arr[l][m];
            int b=arr1[m][l];
            arr2[l][m] += a*b;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            fprintf(ptr1,"%d%s",arr[i][j],"\t");
        }
        fprintf(ptr1,"\n");
    }
    fclose(ptr1);
   
    FILE* ptr2;
    ptr2=fopen("random2.txt","w");

    FILE* ptr;
    ptr=fopen("random.txt","r");
    int num;
    // fscanf(ptr,"%d",&num);

    // printf("%d",num);
    char s;
    
    while(1){
        s=fgetc(ptr);
        if(s==EOF){
            break;
        }
        fprintf(ptr2,"%c",s);
    }
    fclose(ptr);
    fclose(ptr2);

    return 0;
}