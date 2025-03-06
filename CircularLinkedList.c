#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *tail = NULL;

bool isEmpty() {

    return head == NULL;
}

int length() {

    int length = 0;

    //if list is empty
    if(isEmpty()) {
        return 0;
    }

    current = head->next;

    while(current != head) {
        length++;
        current = current->next;
    }
    return length + 1;
}

//insert link at the first location
void insertFirst(int key, int data) {
    //create link
    struct node *el = (struct node*)malloc(sizeof(struct node));
    el->key = key;
    el->data = data;

    //if list is empty
    if(isEmpty()) {
        head = el;
        tail = el;
        el->next = head;
    } else {
        el->next = head;
        head = el;
        tail->next = el;
    }
}

struct node* deleteFirst() {

    struct node *temp = head;
    
    if(head->next == head) {
        head = NULL;
        tail = NULL;
        return temp;
    }

    head = head->next;
    tail->next = head;

    return temp;
}

void printList() {
    
    struct node *ptr = head;

    printf("\n[ ");

    if(!isEmpty()) {
        for(int i = 0; i < length(); i++) {
            printf(" (%d,%d) ", ptr->key, ptr->data);
            ptr = ptr->next;
        }
    }
    printf(" ]");
}

int main() {
    
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 40);
    insertFirst(5, 50);
    insertFirst(6, 60);

    printList();

    printf("list after deleting item: ");

    deleteFirst();
    printList();

    return 0;
}