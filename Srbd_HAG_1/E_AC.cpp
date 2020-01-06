
#include<iostream>
#include<stdio.h>
using namespace std;
int *queue_;
int front_=-1;
int rear=-1;
int mx;
int *values;
struct node
{
    bool isEnd;
    bool isPresent;
    node* next[10];
    node()
    {
        isEnd = false;
        isPresent = false;
        for(int i=0; i<10; i++)
        {
            next[i] = NULL;
        }
    }
} * root;

void insertTrie(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->isEnd = true;
    curr->isPresent = false;
}

bool searchTrie(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
        {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->isPresent;
}

void updateTrie(char* str, int len, bool val){
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
        {
            return;
        }
        curr = curr->next[id];
    }
    curr->isPresent = val;
}

void del(node* delNode)
{
    for(int i=0; i<10; i++)
    {
        if(delNode->next[i])
        {
            del(delNode->next[i]);
        }
    }
    delete(delNode);
}

void displayTrie(node* rootNode, int level, char* str)
{
    if(rootNode->isEnd)
    {
        str[level] = '\0';
        puts(str);
        cout<<"\n";
        return;
    }

    for(int i=0; i<10; i++)
    {
        if(rootNode->next[i])
        {
            str[level] = i + '0';
            displayTrie(rootNode->next[i], level+1, str);
        }
    }
}
char* convertToString(int n){
    char* str = new char[10];
    for(int i=0;i<9;i++){
        str[i]='0';
    }
    int l=8;
    while(n/10){
        str[l]=(n%10)+'0';
        n=n/10;
        l--;
    }
    str[l]=n+'0';
    return str;
}
void qPush(int val)
{
    //cout<<val<<endl;
    if(front_==-1)
    {
        front_=0;
    }
    rear=rear+1;
    if(rear-front_==mx){
        updateTrie(convertToString(queue_[front_]),9,false);
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
    root = new node();
    char* dis = new char[10];
    int n,k;
    cin>>n>>k;
    queue_ = new int[n+5];
    values = new int[n+5];
    mx = k;
    for(int i=0; i<n; i++)
    {
        cin>>values[i];
        insertTrie(convertToString(values[i]),9);
    }
    for(int i=0;i<n;i++){
        if(!searchTrie(convertToString(values[i]),9)){
            qPush(values[i]);
            updateTrie(convertToString(values[i]),9,true);
        }
    }
    //displayTrie(root,0,dis);
    qDisplay();
    del(root);
    return 0;
}
