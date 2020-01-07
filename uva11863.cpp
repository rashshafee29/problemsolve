#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

    //freopen("outputUva11386.txt","w+",stdout);
    int a,c;
    while (1)
    {
        cin>>a>>c;
        if(a==0 || c==0){
            // cout<<endl;
            break;
        }
        int val[c];
        for(int i=0;i<c;i++){
            cin>>val[i];
        }
        int ans = a-val[0];
        for(int i=1;i<c;i++){
            if(val[i]>val[i-1]){
                continue;
            }
            ans = ans + val[i-1]-val[i];
        }
        cout<<ans<<endl;
    }
    return 0;
    
}