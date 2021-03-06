#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
#define MAX 10
struct node {
    int data;
    struct node *next;
};

struct node *hashTable[MAX];

void init()
{
    int i;
    for(i = 0; i < MAX; i++)
        hashTable[i] = NULL;
}

void insertHash(int val) {

    node *newNode = (struct node *)malloc(sizeof(struct node));;
    newNode->data = val;
    newNode->next = NULL;

    int key = val % MAX;
    if(hashTable[key] == NULL) {
        hashTable[key] = newNode;
    } else {
        struct node *temp = hashTable[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool searchHash(int val) {
    int key = val % MAX;
    struct node *temp = hashTable[key];
    while (temp)
    {
        if(temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteHash(int val) {
    int key = val % MAX;
    struct node *temp = hashTable[key], *delLoc;
    if(temp != NULL) {
        if(temp->data == val) {
            delLoc = temp;
            temp = temp->next;
            free(delLoc);
            return;
        } else {
            while (temp->next)
            {
                if(temp->next->data == val) {
                    delLoc = temp->next;
                    temp->next = temp->next->next;
                    free(delLoc);
                    return;
                }
                temp = temp->next;
            }
            
        }
    }
       
}

void printHashTable() {
    for(int i=0;i<MAX;i++){
        struct node *temp = hashTable[i];
        while (temp)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

int main()
{
    init();
    int n;
    cin>>n;
    while (n--)
    {
        int a;
        cin>>a;
        insertHash(a);
    }

    printHashTable();

    cout<<searchHash(5);
    // cout<<search(15);
    // cout<<search(25);
    // cout<<search(6);

    deleteHash(15);
    printHashTable();
    return 0;
}
