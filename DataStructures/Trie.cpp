#include <iostream>
#include<malloc.h>
#include<cstdio>
using namespace std;
struct node
{
    bool isEnd;
    node* next[26+1];
    node()
    {
        isEnd = false;
        for(int i=0; i<26; i++)
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
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->isEnd = true;
}

bool searchTrie(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
        {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->isEnd;
}

void del(node* delNode)
{
    for(int i=0; i<26; i++)
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

    for(int i=0; i<26; i++)
    {
        if(rootNode->next[i])
        {
            str[level] = i + 'a';
            displayTrie(rootNode->next[i], level+1, str);
        }
    }
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
    root = new node();
    int n;
    cin>>n;
    while(n--)
    {
        char* s = new char[26];
        scanf("%s", s);
        insertTrie(s, stringLength(s));
    }
    char* dis = new char[26];
    displayTrie(root, 0, dis);

    // cout<<searchTrie("shafee", stringLength("shafee"));

    // cout<<searchTrie("shaf", stringLength("shaf"));

    // cout<<searchTrie("shafey", stringLength("shafey"));
    return 0;
}
