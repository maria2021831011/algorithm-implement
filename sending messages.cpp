
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<int>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        ll pre=0,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(b,abs(pre-p[i])*a);
            f-=mini;
            pre=p[i];
        }
        if(f>0)
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }

    }






}
