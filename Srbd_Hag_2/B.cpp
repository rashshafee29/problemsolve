#include<stdio.h>
#include<iostream>
using namespace std;
int cStr[4];
int ans = 1e9;

int minTwo(int a, int b) {
    if(a<b){
        return a;
    } else{
        return b;
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

void insertTrie(char* s, int len) {
    int sum = 0;
    for(int i=0;i<len;i++){
        int id = s[i] - 'A';
        int aa,bb;
        // cout<<id<<"-"<<cStr[i]<<endl;
        if(id==cStr[i]){
            continue;
        }
        if(id>cStr[i]) {
            aa = id-cStr[i];
            bb = 26+(cStr[i]-id);
        } else {
            aa = cStr[i]-id;
            bb = 26+(id-cStr[i]);
        }
        // cout<<aa<<" "<<bb<<endl;
        sum = sum + minTwo(aa,bb);
    }
    // cout<<sum<<endl;
    ans = minTwo(ans,sum);
}

void findAllSubStr(char* sStr){
    for(int i=0;i<stringLength(sStr);i++){
        int k=0;
        char* dStr = new char[4];
        for(int j=i;j<stringLength(sStr);j++){
            dStr[k]=sStr[j];
            k++;
            if(k==4){
                // cout<<dStr<<endl;
                insertTrie(dStr, 4);
                break;
            }
        }
    }
}

int main()
{
    cStr[0]='A'-'A';
    cStr[1]='C'-'A';
    cStr[2]='T'-'A';
    cStr[3]='G'-'A';
    int sLen;
    cin>>sLen;
    char* gStr = new char[sLen];
    cin>>gStr;
    findAllSubStr(gStr);
    cout<<ans<<endl;
    return 0;
}