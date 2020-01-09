#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
int MAX,k;
int *queue_;
int front_=-1;
int rear=-1;
struct node {
    int data;
    struct node *next;
};

void init(node *hashTable[])
{
    int i;
    for(i = 0; i < MAX; i++)
        hashTable[i] = NULL;
}

void insertHash(node *hashTable[], int val) {

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

bool searchHash(node *hashTable[], int val) {
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

void deleteHash(node *hashTable[], int val) {
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

void qPush(node *hashTable[], int val)
{
    //cout<<val<<endl;
    if(front_==-1)
    {
        front_=0;
    }
    rear=rear+1;
    if(rear-front_== k){
        deleteHash(hashTable,queue_[front_]);
        front_ = front_+1;
    }
    queue_[rear]=val;
}
void qDisplay()
{
    cout<<rear-front_+1<<endl;
    for(int i=rear; i>=front_; i--)
    {
        printf("%d ", queue_[i]);
    }
    printf("\n");
}

int main()
{
    cin>>MAX>>k;
    node *hashTable[MAX];
    init(hashTable);
    queue_ = new int[MAX+5];
    for(int i=0;i<MAX;i++) {
        int aa;
        cin>>aa;
        if(!searchHash(hashTable,aa)) {
            qPush(hashTable,aa);
            insertHash(hashTable,aa);
        }
    }

    qDisplay();
    return 0;
}
