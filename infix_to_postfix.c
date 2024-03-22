//Author: Sanskriti Gupta
//Aim: Convert infox to postfix expression using stck and array
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char item);
char pop();
int is_operator(char symbol); //this function checks if whether the symbol is an operator or not
int precedence(char symbol); //this function helps us to assign the precedence to the various operators
void infix_to_postfix(char infix_exp[], char postfix_exp[]);
void main()
{
    char infix[SIZE],postfix[SIZE];
    printf("\nEnter the infix expression: ");
    gets(infix);
    infix_to_postfix(infix, postfix);
    printf("\nPostfix Expression: ");
    puts(postfix);
    printf("\n");
}
void push(char item)
{
    if(top>=SIZE-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        char item=stack[top];
        top--;
        return item;
    }
}
int is_operator(char symbol)
{
    if(symbol=='+'|| symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char symbol)
{
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol=='*' || symbol=='/')
    {
        return 2;
    }
    else if(symbol=='+' || symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infix_to_postfix(char infix_exp[], char postfix_exp[])
{
    int i=0,j=0;
    char item,x;
    push('(');
    strcat(infix_exp,")");
    item=infix_exp[i];
    while(item!='\0')
    {
        if(item=='(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix_exp[j]=item;
            j++;
        }
        else if(is_operator(item)==1) //this condition checks whether the symbol is an operator or not
        {
            x=pop();
            while(is_operator(x)==1 && precedence(x)>=precedence(item))
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
        }
        else
        {
            printf("\nInvalid infix expression");
        }
        i++;
        item=infix_exp[i];
    }
    if(top>0)
    {
        printf("\nInvalid infix expression");
    }
    postfix_exp[j]='\0';
}