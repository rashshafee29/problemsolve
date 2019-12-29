#include<iostream>
#include<cstdio>
#include<malloc.h>
#define nool NULL
#define N 128
using namespace std;
float sum=0;
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
    float countNode;
    node* next[N];
    node()
    {
        isEnd = false;
        countNode = 0;
        for(int i=0; i<N; i++)
        {
            next[i]=nool;
        }
    }
} * root;

void insertTrie(char* s, int len)
{
    node* curr = root;
    //cout<<"string: "<<s<<endl;
    for (int i=0; i<len; i++)
    {
        int id = s[i] - NULL;
        if(curr->next[id] == nool)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->isEnd = true;
    curr->countNode = curr->countNode + 1;
    sum = sum + 1;
}

void del(node* delNode)
{
    for(int i=0; i<N; i++)
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
        float val = rootNode->countNode;
        float ans = (val/sum)*100;
        cout<<str;
        printf(" %.4f\n",ans);
        return;
    }

    for(int i=0; i<N; i++)
    {
        if(rootNode->next[i])
        {
            str[level] = i + NULL;
            displayTrie(rootNode->next[i], level+1, str);
        }
    }
}

int main()
{

    //freopen("10226in.txt","r+",stdin);
    //freopen("10226Out.txt","w+",stdout);
    int t;
    cin>>t;
    getchar();
    getchar();
    for(int tt=1; tt<=t; tt++)
    {
        root = new node();
        sum = 0;
        while(1)
        {
            char *s = new char[30];
            gets(s);
            if (stringLength(s) == 0)
            {
                break;
            }
            insertTrie(s, stringLength(s));
        }
        char* str = new char[30];
        displayTrie(root, 0, str);
        del(root);
        if (tt!=t)
        {
            cout<<"\n";
        }
    }
    return 0;
}
