#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList() {
    struct node *ptr = head;
    while (ptr!=NULL)
    {
        cout<<ptr->key<<" "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    
}
void inserNode(int key, int val) {
    struct node *now, *temp;
    now = (struct node*)malloc(sizeof(struct node));

    now->key = key;
    now->data = val;
    now->next = head;

    head = now;
}

node* find(int key) {
    node* current = head;
    if(head == NULL){
        return NULL;
    }

    while (current->key != key)
    {
        if(current->next == NULL){
            return NULL;
        } else {
            current = current->next;
        }
    }

    return current;
    
}

node* deleteNode(int key) {
    node* current = head;
    node* previous = NULL;

    if(head == NULL){
        return NULL;
    }

    while (current->key != key)
    {
        if(current->next == NULL){
            return NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }
    if(current == head){
        head = head->next;
    } else {
        previous->next = current->next;
    }
    
    return current;
}
int main()
{
    int n = 10;
    while (n--)
    {
        inserNode(n,n*n);
    }
    printList();
    deleteNode(6);

    printList();
    return 0; 
}