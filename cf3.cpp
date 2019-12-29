#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> numbers;
vector<ll> v;
ll n;
int findValue(int k) {
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<numbers[i]<<" "<<k;
        if(numbers[i] || i==k){
            continue;
        }
        if (v[i-1] == 0) {
            continue;
        }
        numbers[i]=1;
        //cout<<"=>"<<i<<endl;
        return i;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        numbers[a]=1;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]==0) {
            v[i] = findValue(i+1);
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
