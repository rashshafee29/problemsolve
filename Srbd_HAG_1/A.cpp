#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,lC=0,lR=9;
    int prvL=0,prvR=0;
    cin>>n;
    char* str = new char[n+5];
    cin>>str;
    int hRoom[10]={0};
    for(int i=0;i<n;i++){
        if(str[i]=='L'){
            hRoom[lC]=1;
            if(hRoom[lC+1]){
                lC=prvL;
            } else {
                lC++;
            }
            continue;
        }

        if(str[i]=='R'){
            hRoom[lR]=1;
            if(hRoom[lR-1]){
                lR=prvR;
            } else {
                lR--;
            }
            continue;
        }

        int loc=str[i]-'0';
        if(loc-0<9-loc){
            hRoom[loc]=0;
            if(loc<lC){
                prvL=lC;
                lC=loc;
            }
        } else {
            hRoom[loc]=0;
            if(loc>lR){
                prvR=lR;
                lR=loc;
            }
        }
    }

    for(int i=0;i<=9;i++){
        cout<<hRoom[i];
    }
    cout<<"\n";
}
