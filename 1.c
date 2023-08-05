#include<stdio.h>
#include<string.h>
int main()
{
    char arr[1000],cnt=0,i;
    printf("Enter a string(max 1000 character): ");
    gets(arr);

    for(i=0;arr[i]!='\0';i++)
        cnt++;
    printf("String length: %d",cnt);

}