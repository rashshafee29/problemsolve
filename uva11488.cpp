#include<iostream>
#include<cstdio>
#define N 2
using namespace std;
int ans = -1;
struct node
{
    bool isEnd;
    int cn;
    node* next[N];
    node()
    {
        cn=0;
        isEnd = false;
        for(int i=0; i<N; i++)
        {
            next[i] = NULL;
        }
    }
} * root;

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
        curr->cn = curr->cn + 1;
        if (curr->cn*(i+1)>ans) {
            //cout<<"i: "<<i<<"-"<<ans<<"<->"<<curr->cn<<endl;
            ans = curr->cn*(i+1);
        }
    }
    curr->isEnd = true;
}

void displayTrie(node* rootNode, int level, char* str)
{
    if(rootNode->isEnd)
    {
        str[level] = '\0';
        puts(str);
        return;
    }

    for(int i=0; i<N; i++)
    {
        if(rootNode->next[i])
        {
            str[level] = i + '0';
            //cout<<"cn"<<rootNode->cn<<endl;
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
    int t;
    cin>>t;
    while(t--)
    {
        root = new node();
        int n;
        cin>>n;
        ans = -1;
        while(n--)
        {
            char* s = new char[205];
            scanf("%s", s);
            insertTrie(s, stringLength(s));
        }
        cout<<ans<<endl;
    }
    return 0;
}
