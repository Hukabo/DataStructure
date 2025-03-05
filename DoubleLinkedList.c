#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
    struct node *prev;
};

//this link always points to first node
struct node *head = NULL;

//this link alway points to last node
struct node *last = NULL;
struct node *current = NULL;

//check if it is empty or not
bool isEmpty() {
    return head == NULL;
}

//display the double linked list
void printList() {

    if(isEmpty()) {
        printf("\nLinked List is Empty\n");
    } else {
        struct node *ptr = head;
        
        printf("\nLinked List : \n");

        while(ptr != NULL) {
            printf(" (%d, %d) ", ptr->key, ptr->data);
            ptr = ptr->next;
        }
    }
}

//insert link at the first locstion
void insertFirst(int key, int data) {

    //create link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if(isEmpty()) {
        
        //make it the last link
        last = link;
    } else {
        
        //update first prev link
        head->prev = link;
    }

    //point it to lod first link
    link->next = head;

    //point first to new first link
    head = link;
}

void insertLast(int key, int data) {

    //create link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if(isEmpty()) {

        //make it the head link
        head = link;
    } else {
        last->next = link;

        link->prev = last;
    }

    last = link;
}

//delete first link
struct node* deleteFirst() {

    //save reference to first link
    struct node *temp = head;

    //if only one link
    if(head->next == NULL) {
        last = NULL;
    } else {
        head->next->prev = NULL;
    }

    head = head->next;

    //return the deleted link
    return temp;
}

//delete last link
struct node* deleteLast() {

    struct node *temp = last;

    //if only one link
    if(head->next == NULL) {
        head = NULL;
    } else {
        last->prev->next = NULL;
    }
    last = last->prev;

    return temp;
}

//delete a link with given key
struct node* delete(int key) {

    //start from the first link
    struct node* current = head;
    struct node* previous = NULL;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->key != key) {

        //if it is last node
        if(current->next == NULL) {
            return NULL;
        } else {

            //store reference to current link
            previous = current;

            //move to next link
            current = current->next;
        }
    }

    //fount a match, update the link
    if(current == head) {

        //change first to point to next link
        head = head->next;
    } else {

        //bypass the current link
        current->prev->next = current->next;
    }
    if(current == last) {

        //chage last to point to prev link
        last = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    return current;
}

bool insertAfter(int key, int newKey, int data) {

    //start from the first link
    struct node* current = head;

    //if list is empty
    if(head == NULL) {
        return false;
    }

    //navigate through list
    while(current->key != key) {

        //if it is last node
        if(current->next == NULL) {
            return false;
        } else {

            //move to next link
            current = current->next;
        }
    }

    //create a link
    struct node *newLink = (struct node*) malloc(sizeof(struct node));
    newLink->key = newKey;
    newLink->data = data;

    if(current == last) {
        newLink->next = NULL;
        last = newLink;
    } else {
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;

    return true;
}

int main() {
    insertLast(1, 10);
    insertLast(2, 20);
    insertFirst(3, 30);
    
    printList();

    delete(2);

    printf("\nAtfer deleting : \n");
    printList();

    insertAfter(1,2,20);
    insertAfter(3,9,90);
    printList();

    return 0;
}