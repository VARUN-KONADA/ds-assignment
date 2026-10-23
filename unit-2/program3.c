/*An expression-processing application receives an arithmetic expression in infix form. Write a C 
program using a stack to convert it to postfix form while correctly handling parentheses and 
operator precedence for +, -, *, / and ^. Test the program using an expression containing multiple 
operators and parentheses.*/

// take input expression 
// read each char and push it stack or output using precedency
// pop all elements if left

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 26
int top = -1;
char infix[MAX];
char stack[MAX/2];

int prec(char c);
void push(char c);

int main()
{
    printf("enter the infix expression: ");
    scanf("%s",infix);

    for(int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if(isalnum(c))
            printf("%c",infix[i]);

        else if(c == '^' || c == '*' || c == '/' || c == '-' || c == '+')
            push(c);

        else if(c == '(')
            stack[++top] = c;
        else if(c == ')')
        {
            while(stack[top] != '(')
            {
                printf("%c",stack[top--]);
            }
            top--;
        }
        else
        {
            printf("invalid symbol used !");
            return 1;
        }
    }
    while(top != -1)
        printf("%c",stack[top--]);

    return 0;
}

int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void push(char c)
{
    if(prec(c) > prec(stack[top]))
        stack[++top] = c;
    else
    {
        while(prec(c) <= prec(stack[top]) && top != -1)
            printf("%c",stack[top--]);
                
        stack[++top] = c;
    }
}