#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int top=-1;
char stack[100];

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'|| x=='-')
        return 1;
    if(x=='*'|| x=='/')
        return 2;
    return 0;
}

void display()
{
    while(top!=-1)
        printf("%c",pop());
    printf("\n");
}

int main()
{
    char ep[100],x;
    char *p;
    printf("Enter the expression: ");
    gets(ep);
    p=ep;
    printf("The postfix expression is given below: ");
    while(*p!='\0'){
        if(isalnum(*p))
            printf("%c",*p);
        else if(*p=='(')
            push(*p);
        else if(*p==')'){
            while((x=pop())!='(')
                printf("%c",x);
        }
        else{
            while(priority(stack[top])>=priority(*p))
               printf("%c",pop());
            push(*p);
        }
        p++;
    }
    display();
    return 0;
}
 
// (1*2/7)-2+3/8+4