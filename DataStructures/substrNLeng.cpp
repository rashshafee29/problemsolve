#include<stdio.h>
#include<iostream>
using namespace std;
int stringLength(char* s)
{
    int i = 0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}
void substr(int n, char* sStr, char* dStr) {
    if(n<=0){
        cout<<dStr<<endl;
    } else {
        for(int i=0;i<stringLength(sStr);i++){
            dStr[n-1] = sStr[i];
            substr(n-1, sStr, dStr);
        }
    }
}
int main()
{
    int sLen;
    cin>>sLen;
    char* gStr = new char[sLen];
    char* dStr = new char[4];
    cin>>gStr;
    substr(4,gStr,dStr);
}