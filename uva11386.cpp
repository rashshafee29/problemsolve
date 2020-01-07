#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("outputUva11386.txt","w+",stdout);
    int a,c;
    while (1)
    {
        cin>>a>>c;
        if(a==0 || c==0){
            break;
        }
        int val[c];
        for(int i=0;i<c;i++){
            cin>>val[i];
        }
        int arr[a][c];

        for(int i=0;i<a;i++){
            for(int j=0;j<c;j++){
                arr[i][j]=0;
            }
        }

        for(int j=c-1;j>=0;j--){
            for(int i=a-1;i>=a-val[j];i--){
                arr[i][j]=1;
            }
        }

        // cout<<endl;
        // for(int i=0;i<a;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        bool foundOne = false;
        for(int i=0;i<a;i++){
            int sum = 0;
            foundOne = true;
            for(int j=0;j<c;j++){
                if(arr[i][j]==0 && foundOne){
                    foundOne = false;
                }
                if(arr[i][j]==1 && !foundOne){
                    foundOne = true;
                    sum++;
                }
            }
            if(!foundOne){
                sum++;
            }
            ans = ans + sum;
            // cout<<i<<"->"<<sum<<endl;
        }
        cout<<ans<<endl;
    }
    // cout<<endl;
    return 0;
    
}