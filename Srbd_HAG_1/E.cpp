#include<iostream>
#include<stdio.h>
#define mx 100
using namespace std;
int main()
{
    int a[11];
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int val = ((n-1)/(10-1)) * (mx-1) + 1; //(X-A)/(B-A) * (D-C) + C
        cout<<val<<endl;
    }
    
}