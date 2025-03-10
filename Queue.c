#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6
int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

int peek() {
    return queue[front];
}

bool isEmpty() {
    return count == 0;
}

bool isFull() {
    return count == MAX;
}

int size() {
    return count;
}

void insert(int data) {

    if(!isFull()) {
        queue[++rear] = data;
        count++;
        if(rear == MAX - 1) {
            rear = -1;
        }
    } else {
        printf("\ncan't insert the data(%d). because Queue is full.\n", data);
    }
}

int removeData() {

    if(isEmpty()) {
        printf("there is no data.\n");
        return 0;
    }

    int data = queue[front++];
    count--;

    if(front == MAX) {
        front = 0;
    }

    return data;
}

void print() {
    if (isEmpty()) {
        printf("Queue : [ ]\n");
        return;
    }

    int i = front;
    int items = 0;
    printf("Queue : [ ");
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
        items++;
    } while (items < count);
    printf("]\n");
}

int main() {
    insert(3);
    insert(5);
    insert(32);
    insert(343);
    insert(51);
    insert(73);
    print();

    removeData();
    print();
    removeData();
    print();
    removeData();
    print();
    removeData();
    print();
    removeData();
    print();
    removeData();
    print();
    removeData();
    print();

    return 0;
}