#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *head = NULL;
struct node *current = NULL;

void printList() {
    struct node* temp = head;
    
    printf("\n[");

    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("]");
}

void insertatbegin(int data) {

    struct node *lk = (struct node *) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;
    head = lk;
}

void insertatend(int data) {
    
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;

    struct node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = lk;
}

void insertafternode(struct node *list, int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = list->next;
    list->next = lk;
}

void deleteatbegin() {
    head = head->next;
}

void deleteatend() {
    struct node *temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    temp->next = NULL;
}

void deletenode(int key) {
    struct node *temp = head, *prev;
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
}

int searchlist(int key) {
    struct node *temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

void reverseList(struct node** head) {
    struct node *prev = NULL, *cur = *head, *temp;
    while(cur != NULL) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;
}

int main() {

    insertatbegin(12);
    insertatbegin(22);
    insertatbegin(32);
    insertatbegin(42);
    insertatend(11);
    insertafternode(head, 100);
    insertafternode(head->next, 200);

    printf("\nLinked List : ");
    printList();

    printf("\nLinked List After deleted : ");
    deleteatbegin();
    deleteatend();
    deletenode(22);
    printList();

    int ex = searchlist(12);

    if(ex) {
        printf("\nthe element is found");
    } else {
        printf("\nthe element is not found");
    }

    printf("\nLinked List After reverse : ");
    reverseList(&head);
    printList();
    
    return 0;
}