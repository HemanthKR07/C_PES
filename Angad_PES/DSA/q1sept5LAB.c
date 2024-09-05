#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 30

void push(int s, int* top, int stack[MAX]);
int pop(int stack[MAX], int* top);
void eval(int stack[MAX], int* top, char postfix[MAX]);
void disp(int stack[MAX],int* top);

int main()
{
    int stack[MAX];
    int top = -1;
    char postfix[30];
    scanf("%s", postfix);
    eval(stack, &top, postfix);
    disp(stack,&top);
    return 0;
}

void push(int s, int* top, int stack[MAX])
{
    if (*top == MAX - 1) {
        printf("Stack is full\n");
        exit(0);
    }
    stack[++(*top)] = s;
}

int pop(int stack[MAX], int* top)
{
    if (*top == -1) {
        printf("Stack is empty\n");
        exit(0);
    }
    return stack[(*top)--];
}

void eval(int stack[MAX], int* top, char postfix[MAX])
{
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0', top, stack);
        } else {
            int operand2 = pop(stack, top);
            int operand1 = pop(stack, top);
            switch (postfix[i]) {
                case '+':
                    push(operand1 + operand2, top, stack);
                    break;
                case '-':
                    push(operand1 - operand2, top, stack);
                    break;
                case '*':
                    push(operand1 * operand2, top, stack);
                    break;
                case '/':
                    push(operand1 / operand2, top, stack);
                    break;
            }
        }
        i++;
    }
}

void disp(int stack[MAX],int* top)
{
    printf("%d\n", stack[*top]);
}