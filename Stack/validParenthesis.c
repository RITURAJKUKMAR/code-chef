#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

void push(char ele){
    if(top <= MAX_SIZE - 1){
        a[++top] = ele;
    }
    else{
        printf("Stack is full. Cannot push: %c\n", ele);
    }
}

char pop(){
    if(top >= 0){
        char ele = a[top];
        top--;
        return ele;
    }
    else{
        printf("Stack is empty. Cannot pop.\n");
        return '\0'; // Use '\0' to indicate null character instead of '-1'
    }
}

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top >= MAX_SIZE - 1;
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')');
}

bool isBalanced(char expression[]) {
    // Write your code here
    bool ans=false;
    for(int i=0;i<strlen(expression);i++)
    {
        if(expression[i]=='(')
            push(expression[i]);
        else if(expression[i]==')')
        {
            if(expression[i]=='(')
            push(expression[i]);
            else if(expression[i]==')')
            {
                ans=isMatchingPair((pop()),expression[i]);
                if(ans==false){
                    break;
                }
            }
        }
    }
    if(!isEmpty())
        ans=false;
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        char str[MAX_SIZE];
        scanf("%s", str);
        printf("%s : ", str);
        bool ans = isBalanced(str);
        if(ans)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
