#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 10
struct node {
    int data;
    struct node *next;
};

struct node *hashTable[MAX];

void insertHash(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int a;
        cin>>a;
    }
    
}
