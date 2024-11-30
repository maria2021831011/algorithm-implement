#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n>>m;
        vector<ll> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(),v.end());
vector<ll>v1(m);
for(int i=0;i<m;i++)
{
    cin>>v1[i];
}
sort(v1.rbegin(),v1.rend());

ll i=0,r=n-1,j=m-1,p=0,ans=0;
while(i<=r)
{ll rr=abs(v[i]-v1[p]);
ll l=abs(v[r]-v1[j]);
ll a=max(rr,l);
ans+=a;
if(rr==a)
{
   i++;
   p++;
}else if(a==l)
{
    j--;
    r--;
}

}
cout<<ans<<endl;

}
}

