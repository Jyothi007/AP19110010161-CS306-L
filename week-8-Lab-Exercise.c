#include<stdio.h>
#include<stdlib.h>
void pop(),push(char),display();
char a[100]="\0", i[100], *ip;
int top=-1;
void push(char b)
{
    top++;
    a[top]=b;
}
void pop()
{
    a[top]='\0';
    top--;
}
void display()

{
    printf("\n%s\t%s\t",a,ip);
}
void main()
{
    printf("S->0S0\n");
    printf("S->1S1\n");
    printf("S->2\n");
    printf("Enter the input string followed by $ \n");
    scanf("%s",i);
    ip=i;
    push('$');
    printf("a\t BUFFER \t ACTION\n");
    printf("-----\t ------- \t ------\n");
    display();
    if(a[top]=='$' && *ip=='$'){
    printf("Null input");
    exit(0);
    }
    do
    {
    if((a[top]=='S' && a[top-1]=='$') && (*(ip)=='$'))
    {
    display();
    printf("\t Valid\n\n\n");
    break;
    }
    if(a[top]=='$')
    {
    push(*ip);
    ip++;
    printf("\tShift");
    }
    else if(a[top]=='2')
    {
    display();
    pop();
    push('S');
    printf("\tReduce S->2");
    }
    else if(a[top]=='0' && a[top-1]=='S' && a[top-2]=='0')
    {
    display();
    pop();
    pop();
    pop();
    push('S');
    printf("\tReduce S->0S0");
    }
    else if(a[top]=='1' && a[top-1]=='S' && a[top-2]=='1')
    {
    display();
    pop();
    pop();
    pop();
    push('S');
    printf("\tReduce S->1S1");
    }
    else if(*ip=='$')
    { printf("\tInvalid\n\n\n");
    break;
    }
    else
    {
    display();
    push(*ip);
    ip++;
    printf("\tshift");
    }
    }while(1);
}
