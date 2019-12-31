#include<stdio.h>
#include<iostream>
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
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[0]=a;
        arr[1]=b;
        arr[2]=(a+b+c)/3;
        custom_sort();
        cout<<arr[0]<<endl;
    }
    return 0;
}