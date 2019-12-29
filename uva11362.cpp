#include<iostream>
#include<cstdio>
#include<malloc.h>
#define nool NULL
using namespace std;

bool isOkay;

int stringLength(char* s)
{
    int i = 0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

struct node
{
    bool isEnd;
    node* next[10+1];
    node()
    {
        isEnd = false;
        for(int i=0; i<10; i++)
        {
            next[i] = nool;
        }
    }
} * root;

void insertTrie(char* s, int len)
{
    isOkay = true;
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id = s[i] - '0';
        if (curr->next[id] == nool)
        {
            curr->next[id] = new node();
            isOkay = false;
        }
        else
        {
            if (curr->next[id]->isEnd == true)
            {
                if (len == 1)
                {
                    isOkay = true;
                    return;
                }
                if (i < len-1)
                {
                    isOkay = true;
                    return;
                }
            }
        }
        curr = curr->next[id];
    }
    curr->isEnd = true;
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

int main()
{
    //freopen("11362out.txt","w+",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        root = new node();
        int n;
        cin>>n;
        bool ans = true;
        while(n--)
        {
            char* s = new char[10];
            cin>>s;
            insertTrie(s, stringLength(s));
            if (isOkay)
            {
                ans = false;
            }
        }
        if (ans)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        del(root);
    }
    return 0;
}
