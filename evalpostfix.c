#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int stack[25];
char postfix[25];
int top=-1;

void push(int ele) {
    stack[++top]=ele;
}

int pop() {
    return stack[top--];
}

int main() {
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    for (int i=0; postfix[i]!='\0'; i++) {
        if (isdigit(postfix[i])) push(postfix[i]-'0');
        else {
            int ch=postfix[i];
            int b=pop();
            int a=pop();
            int res;
            switch(ch) {
                case '+': 
                    res=a+b;
                    break;
                case '-': 
                    res=a-b;
                    break;
                case '*': 
                    res=a*b;
                    break;
                case '/': 
                    res=a/b;
                    break;
                case '^': 
                    res=(int)pow(a,b);
                    break;
            }
            push(res);
        }
    }
    printf("Result: %d",pop());
    return 0;
}