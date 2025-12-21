#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix[25],postfix[25];
int stack[25];
int top=-1;
int j=0;

void push(int ele) {
    stack[++top]=ele;
}

char pop() {
    return stack[top--];
}
int rank(char ch) {
    if (ch=='+'||ch=='-') return 1;
    else if (ch=='/'||ch=='*'||ch=='%') return 2;
    else if (ch=='^') return 3;
    else return 0;
}

void infixPostfix(char arr[]) {
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for (int i=0; arr[i]!='\0'; i++) {
        if (arr[i]=='(') cnt1++;
        else if (arr[i]==')') cnt2++;
        else if (arr[i]=='+' || arr[i]=='-' || arr[i]=='/' || arr[i]=='%' || arr[i]=='*' || arr[i]=='^') cnt3++;
        else cnt4++;
    }
    if ((cnt1==cnt2)&&(cnt4-1==cnt3)) {
        printf("Valid Expression");
        for (int i=0; arr[i]!='\0'; i++) {
        if (arr[i]=='(') {
            push(arr[i]);
        }
        else if (arr[i]==')') {
            while (stack[top]!='(') {
                postfix[j++]=pop();
            }
            pop();
        }
        else if (arr[i]=='+' || arr[i]=='-' || arr[i]=='/' || arr[i]=='%' || arr[i]=='*' || arr[i]=='^') {
            if (arr[i]=='^') {
                while(rank(stack[top])>rank(arr[i]) && top!=1) postfix[j++]=pop();
                push(arr[i]);
            }
            else {
                while(rank(stack[top])>=rank(arr[i]) && top!=1) postfix[j++]=pop();
                push(arr[i]);
            }
        }
        else postfix[j++]=arr[i];
        }
        while (top!=-1) {
            postfix[j++]=pop();
        }
        postfix[j]='\0';
    }
    else {
        printf("Invalid Expression.");
        return;
    }
}

int main () {
    printf("Enter infix expression: ");
    scanf("%s",infix);
    infixPostfix(infix);
    printf("%s",postfix);
    return 0;
}