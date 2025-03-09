#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isFull() {

    if(top == MAXSIZE - 1) {
        return 1;
    }

    return 0;
}

int isEmpty() {
    if(top == -1) {
        return 1;
    }

    return 0;
}

void push(int data) {
    if(!isFull()) {
        top++;
        stack[top] = data;
    } else {
        printf("\nCould not insert data(= %d), Stack is full.\n", data);
    }
}

int pop() {
    int data;
    if(!isEmpty()) {
        data = stack[top];
        stack[top] = 0;
        top--;

        return data;
    } else {
        printf("\nCould not retrive data, Stack is empty.\n");

        return 0;
    }
}

int peek() {

    if(!isEmpty())
        return stack[top];
    else
        printf("\nStack is Empty.\n");

    return 0;
}

void printStack() {
    int i;

    printf("[ ");

    for(i = 0; i < MAXSIZE; i++) {
        printf("%d ", stack[i]);
    }

    printf("] ");

    return;
}

int main() {
    
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    push(15);
    push(15);
    push(15);

    push(99);

    printf("Stack Elements: \n");
    printStack();

    printf("\nElement at top of the stack : %d\n", peek());

    printf("\nElements popped: \n");

    for(int i = 0; i < MAXSIZE; i++) {
        printf(" %d ", pop());
    }

    printf("\nAfter popped: \n");
    printStack();

    if(isEmpty()) {
        printf("\nStack was successfully cleared.\n");
    }

    return 0;
}