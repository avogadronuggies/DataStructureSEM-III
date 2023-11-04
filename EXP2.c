#include <stdio.h>
#include <ctype.h>
#define size 10

char a[size];
int top = -1;
void push(char p)
{
    if (top >= size - 1)
    {
        printf("Stack OverFlow\n");
    }
    else
    {
        top++;
        a[top] = p;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        char ch = a[top];
        top--;
        return ch;
    }
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
    return -1;
}

void convert(char s[])
{
    int i = 0;
    int x;
    while (s[i] != '\0')
    {
        if (isalnum(s[i]))
        {
            printf("%c", s[i]);
        }
        else if (s[i] == '(')
        {
            push(s[i]);
        }
        else if (s[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (top != -1 && precedence(a[top])>=precedence(s[i]))
            {
                printf("%c",pop());
            }
            push(s[i]);
        }
        i++;
    }
    while (top!=-1)
    {
        printf("%c",pop());
    }
}
int main()
{
    char s[size];
    printf("Enter an Infix Expression:\n");
    scanf("%s",s);
    printf("Enter an Postfix Expression:\n");
    convert(s);
    //
    return 0;
}