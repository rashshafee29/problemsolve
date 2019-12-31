#include<iostream>
#include<stdio.h>
using namespace std;
int arr[3];
void custom_sort()
{
    for(int i=1;i<3;i++)
    {

        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key)
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int ans;
        cin>>arr[0]>>arr[1]>>arr[2];
        custom_sort();
        if (arr[2]<arr[0]+arr[1]){
            ans = arr[0]+arr[1]+arr[2];
            ans = ans/2;
        } else {
            ans = arr[1]+arr[0];
        }
        cout<<ans<<endl;
    }
    
    return 0;   
}