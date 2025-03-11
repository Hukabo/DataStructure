#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[25];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

//return precedence of operators
int precedence(char symbol) {

    switch(symbol) {
        case '+':
        case '-':
            return 2;
            break;
        case '*':
        case '/':
            return 3;
            break;
        case '^':
            return 4;
            break;
        case '(':
        case ')':
        case '#':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

//check whether the symbol is operator?
int isOperator(char symbol) {

    switch(symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
            break;

        default:
            return 0;
    }
}

//convert infix expression to postfix
void convert(char infix[], char postfix[]) {
    int i, symbol, j = 0;
    stack[++top] = '#';

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if(isOperator(symbol) == 0) { // if symbol is not an operator
            postfix[j++] = symbol;
        } else { // if symbol is an operator
            if(symbol == '(') {
                push(symbol);
            } else {
                if(symbol == ')') {

                    while(stack[top] != '(') {
                        postfix[j++] = pop();
                    }
                    pop(); // remove '(' from stack
                } else { // if symbol is an operator other than '(' and ')'
                
                    if(precedence(symbol) > precedence(stack[top])) {
                        push(symbol);
                    } else { // precedence(symbol) <= precedence(stack[top])

                        while(precedence(symbol) <= precedence(stack[top])) {
                            postfix[j++] = pop();
                        }

                        push(symbol);
                    }
                }
            }
        }
    }

    while(stack[top] != '#') {
        postfix[j++] = pop();
    }
    pop(); // remove '#' from stack
    postfix[j] = '\0'; //null terminate string
}

//int stack
int stack_int[25];
int top_int = -1;

void push_int(int item) {
    stack_int[++top_int] = item;
}

int pop_int() {
    return stack_int[top_int--];
}

int evaluate(char postfix[]) {

    char ch;
    int i = 0, operand1, operand2;

    while( (ch = postfix[i++]) != '\0') {

        if(isdigit(ch)) {
            push_int(ch-'0');
        } else {
            operand2 = pop_int();
            operand1 = pop_int();

            switch(ch) {
                case '+':
                    push_int(operand1 + operand2);
                    break;
                case '-':
                    push_int(operand1 - operand2);
                    break;
                case '*':
                    push_int(operand1 * operand2);
                    break;
                case '/':
                    push_int(operand1 / operand2);
                    break;
            }
        }
    }

    return stack_int[top_int];
}

int main() {
    char infix[25] = "1+2+3";
    char postfix[25];
    convert(infix, postfix);

    printf("Infix expression is: %s\n", infix);
    printf("Postfix expression is: %s\n", postfix);
    printf("top's value is : %d\n", top);
    printf("Evaluated expression is: %d\n", evaluate(postfix));



    char infix2[25] = "1+2*3+(9-3)";
    char postfix2[25];
    convert(infix2, postfix2);

    printf("Infix expression is: %s\n", infix2);
    printf("Postfix expression is: %s\n", postfix2);
    printf("Evaluated expression is: %d\n", evaluate(postfix2));

    printf("stack_int : %d\n", stack_int[top_int]);
    return 0;
}