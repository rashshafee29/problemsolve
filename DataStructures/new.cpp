#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
    int data;
    int data2;
};

struct node *start = NULL;
node* inserNode(int val) {
    struct node *now, *temp;
    now = (struct node*)malloc(sizeof(struct node));
    now->data = 2;
    now->data2 = 4;
    return now;
}
void printNode(node *ne){
    cout<<ne->data;
    cout<<"\n"<<ne->data2;
}


int main()
{
    printNode(inserNode(2));
    return 0; 
}