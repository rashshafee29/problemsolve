#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    bool isEnd;
    int count;
    node* next[10];
    node()
    {
        isEnd = false;
        count = 0;
        for(int i=0; i<10; i++)
        {
            next[i] = NULL;
        }
    }
};
node* root;
void insertTrie(node* root, char* str, int len)
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
    curr->count = curr->count + 1;
}

int searchTrie(node* root, char* str, int len)
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
    return curr->count;
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

int minTwo(int a, int b) {
    if(a<b){
        return a;
    } else{
        return b;
    }
}

int main()
{
    root = new node();
    int nn,cc=0;
    int ans = 1e9;
    cin>>nn;
    int valN[nn+1];
    for(int i=0;i<nn;i++){
        int val;
        cin>>val;
        valN[i]=val;
        if(!searchTrie(root, convertToString(val), 9)){
            cc++;
            insertTrie(root, convertToString(val),9);
        }
    }
    if (nn==cc){
        cout<<"0\n";
        return 0;
    }
    del(root);
    for(int i=0;i<nn;i++){
        node* mp = new node();
        int ccc = 0;
        for(int j=i;j<nn;j++){
            if((searchTrie(mp,convertToString(valN[j]), 9)) + 1 == searchTrie(root, convertToString(valN[j]),9)){
                ccc++;
            }
            insertTrie(mp, convertToString(valN[j]),9);
            if (i + nn - j - 1 == cc - ccc) {
                ans = min(ans, j - i + 1);
            }
        }
        del(mp);
    }
    cout<<ans<<endl;
    return 0;
}