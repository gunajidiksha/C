// #include<stdio.h>
// int main()
// {
//     printf("Hello World!");
//     return 0;
// }


// int main()
// {
//     int a, b;
//     int *p;
//     a = 15;
//     p = &a;
//     b = *p;
//     printf("Value of a is %d and address is %p\n", a, &a);
//     printf("Value of a is %d and address is %u\n", *&a, &a);
//     printf("Value of a is %d and address is %u\n", *p, p);
//     printf("%d is the address pointed to by %u\n", p, &p);
//     printf("Value of b is %d and address is %u\n", b, &b);
//     *p = 25;
//     printf("Now the value of a is %d", a);
// int main()

    // int a[100];
    // int *p, i, sum;
    // printf("Enter numbers : ");
    // for(i=0;i<=100 ; i++)
    // {
    //     if(i=="stop")
    //     {
    //         break;
    //     }
    //     else{
    //         scanf("%d " , &a[i]);
    //     }
        
    // }
    
    // p = a;
    // sum = 0;
    // for(i=0; i<6; i++)
    // {
    //     sum = sum + *p;
    //     p++;
    // }
    // printf("Sum is %d", sum);



//     int age = 22;
//     int *ptr = &age;
//     // int _age = *ptr; 
//     printf("%u ", *ptr);    
//     printf("%u ", &age);    
//     printf("%u ", ptr);    //ptr == &age
//     printf("%u ", &ptr);    
// }


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// char stack[MAX_SIZE];
// int top = -1;

// void push(char c) {
//     if (top == MAX_SIZE - 1) {
//         printf("Stack Overflow\n");
//         exit(1);
//     }
//     stack[++top] = c;
// }

// char pop() {
//     if (top == -1) {
//         printf("Stack Underflow\n");
//         exit(1);
//     }
//     return stack[top--];
// }

// int priority(char operator) {
//     if (operator == '*' || operator == '/')
//         return 2;
//     else if (operator == '+' || operator == '-')
//         return 1;
//     else
//         return 0;
// }

// int main() {
//     char infix[50];
//     char postfix[50];
//     int i, j = 0;

//     printf("Enter an infix expression: ");
//     scanf("%s", infix);

//     for (i = 0; infix[i] != '\0'; i++) {
//         if (infix[i] >= 'a' && infix[i] <= 'z')
//             postfix[j++] = infix[i];
//         else if (infix[i] == '(')
//             push(infix[i]);
//         else if (infix[i] == ')') {
//             while (stack[top] != '(')
//                 postfix[j++] = pop();
//             pop();
//         }
//         else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
//             while (top != -1 && priority(stack[top]) >= priority(infix[i]))
//                 postfix[j++] = pop();
//             push(infix[i]);
//         }
//     }

//     while (top != -1)
//         postfix[j++] = pop();

//     postfix[j] = '\0';

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }


// (1*2/7)-2+3/8+4

// #include <stdio.h>
// #include <stdlib.h>
// #include<ctype.h>
// int top=-1;
// char stack[100];
// void push(char x){
//     stack[++top]=x;
// }
//     char pop(){
//     if(top==-1)
//         return -1;
//     else
//         return stack[top--];
// }
// int priority(char x){
//     if(x=='(')
//         return 0;
//     if(x=='+'|| x=='-')
//         return 1;
//     if(x=='*'|| x=='/')
//         return 2;
//     return 0;
// }
// void display(){
//     while(top!=-1)
//         printf("%c",pop());
//     printf("\n\n");
// }
// int main()
// {
//     char ep[100],x;
//     char *p;
//     printf("Enter the expression: ");
//     gets(ep);
//     printf("\n");
//     p=ep;
//     printf("The postfix expression is given below: \n\n ");
//     while(*p!='\0'){
//         if(isalnum(*p))
//             printf("%c",*p);
//         else if(*p=='(')
//             push(*p);
//         else if(*p==')'){
//             while((x=pop())!='(')
//                 printf("%c",x);
//         }
//         else{
//             while(priority(stack[top])>=priority(*p))
//                printf("%c",pop());
//             push(*p);
//         }
//         p++;
//     }
//     display();
//     return 0;
// }

// #include<stdio.h>

// int Nodes(int graph[][n] , int n1 , int n2)  {
//     if (graph[n1][n2]==1 || graph[n2][n1]==1) 
//         return 1;
//     else 
//         return 0;
// }

// int main()
// {
//     int n;
//     printf("Enter no. of nodes in graphs : ");
//     scanf("%d" , &n);
    
//     for(int i=0 ; i<n ; i++){
//         for(int j=i ; j<i ; j++){
//             int graph[i][j];
//             scanf("%d" , graph[i][j]); 
//         }
//     }

//     // int graph[][n];
//     // scanf("%d" , graph[][n]);

//     int n1 = 0;
//     int n2 = 1;

//     if(Nodes(graph[][] , n1 , n2)){
//         printf("%d and %d nodes are directly connected." , n1 , n2);
//     }else{
//         printf("%d and %d nodes are not directly connected." , n1 , n2);
//     }

//     return 0;
// }

#include <stdio.h>

int Nodes(int graph[][4], int node1, int node2) {
    if (graph[node1][node2] == 1 || graph[node2][node1] == 1) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int n = 4 , n1 , n2; 
    int graph[][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}
    };

    printf("Enter node 1 : ");
    scanf("%d" , &n1);
    printf("Enter node 2 : ");
    scanf("%d" , &n2);
    
    if (Nodes(graph, n1, n2)) {
        printf("Node %d and Node %d are directly connected.\n", n1, n2);
    } else {
        printf("Node %d and Node %d are not directly connected.\n", n1, n2);
    }
    
    return 0;
}