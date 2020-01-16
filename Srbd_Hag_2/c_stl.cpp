#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n+5];
    map<int, int> mp1,mp2;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 1e9;
    for(int l=0;l<n;l++){
        int pR;
        mp1[arr[l]]++;
        if(mp1[arr[l]]==2){
            ans--;
            break;
        }
        for(int r=n-1;r>=l;r--){
            pR = r;
            if(l==r){
                break;
            }
            mp2[arr[r]]++;
            if(mp2[arr[r]]==2){
                ans = min(ans, r-l+1);
                break;
            }
        }
        mp2.clear();
    }
    cout<<ans<<endl;
    return 0;
}