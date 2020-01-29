#include<stdio.h>
#include<iostream>
using namespace std;
int main() {

    int n;
    while (cin>>n)
    {
        int arr[n],ans = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    ans++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<ans<<endl;
    }    
    return 0;
}