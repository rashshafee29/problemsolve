
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        ll p = n/k;
        if (n%k==0) {
            cout<<n<<endl;
            continue;
        }
        ll p1 = k/2;
        ll sum = 0;
        k = k - p1;
        while(p1--) {
            sum = sum + p + 1;
        }

        ll rem = n - sum;

        rem = (rem/k)*k;
        cout<<rem+sum<<endl;
    }
    return 0;
}
