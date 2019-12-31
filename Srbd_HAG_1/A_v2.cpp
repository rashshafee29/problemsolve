#include<iostream>
#include<stdio.h>
using namespace std;
int hRoom[10];
void bookRoom(bool iRev)
{
    if(!iRev)
    {
        for(int i=0; i<=9; i++)
        {
            if(hRoom[i]==0)
            {
                hRoom[i]=1;
                break;
            }
        }
    }
    else
    {
        for(int i=9; i>=0; i--)
        {
            if(hRoom[i]==0)
            {
                hRoom[i]=1;
                break;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    char* str = new char[n+5];
    cin>>str;
    hRoom[10]= {0};

    for(int i=0; i<n; i++)
    {
        if(str[i]=='L')
        {
            bookRoom(false);
            continue;
        }

        if(str[i]=='R')
        {
            bookRoom(true);
            continue;
        }

        int loc = str[i]-'0';
        hRoom[loc]=0;
    }
    for(int i=0; i<=9; i++)
    {
        cout<<hRoom[i];
    }
    cout<<"\n";
    return 0;
}
