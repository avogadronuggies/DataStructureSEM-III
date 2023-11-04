#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define size 10

char a[size];
int top = -1;
void push(char p)
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        a[top] = p;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int val = a[top];
        top--;
        return val;
    }
}

int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 2;
        break;
    case '/':
        return 3;
        break;
    case '*':
        return 4;
        break;
    }
}
int evalutePostfix(char postfix[])
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0'); // Convert character digit into Integar
        }
        else if (isOperator(ch))
        {
            int op1 = pop();
            int op2 = pop();
            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            }
        }
        i++;
    }
    return pop();
}

int main()
{
    char postfix[size];
    printf("Enter the Postfix Expression:\n");
    scanf("%s", postfix);

    if (top == -1)
    {
        printf("Value of Postfix Expresssion= %d", evalutePostfix(postfix));
    }
    else
    {
        printf("ERROR!");
    }
}