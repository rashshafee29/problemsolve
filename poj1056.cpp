#include<stdio.h>
#include<iostream>
using namespace std;
bool okay;
struct node {
    bool isEnd;
    node* next[2];
    int count;
    node(){
        isEnd = false;
        count = 0;
        for(int i=0;i<2;i++){
            next[i]=NULL;
        }
    }
} * root;

void insertTrie(char *s, int len) {
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = s[i]-'0';
        if(curr->next[id]==NULL){
            curr->next[id] = new node();
        }
        curr->count +=1;
        curr = curr->next[id];
    }
    curr->isEnd = true;
    curr->count = curr->count + 1;
}
bool isOkay(node* rootNode, int level){
    for(int i=0; i<2; i++)
    {
        if(rootNode->next[i])
        {
            if(rootNode->count>1 && rootNode->isEnd) {
                okay = false;
            }
            isOkay(rootNode->next[i], level+1);
        }
    }
    return okay;
}

int stringLength(char* s)
{
    int i = 0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}
int main()
{
    int c = 1;
    root = new node();
    char* s = new char[10];
    while (cin>>s)
    {
        if(s[0]=='9'){
            okay = true;
            char* sr = new char[10];
            if(isOkay(root, 0) == true){
                cout<<"Set "<<c<<" is immediately decodable\n";
            } else {
                cout<<"Set "<<c<<" is not immediately decodable\n";
            }
            c++;
            // cout<<isOkay(root, 0);
            // displayTrie(root, 0, sr);
            root = new node();
            continue;
        }
        insertTrie(s, stringLength(s));
    }
    
    return 0;
}