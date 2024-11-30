#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        map<ll ,ll>m;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
        }
        sort(v.begin(),v.end());
        ll tt=0;
        for(auto it:m)
        {
            ll l=it.second;
            tt+=l*(l-1)*(l-2)/6;
            ll in=lower_bound(v.begin(),v.end(),it.first)-v.begin();
            tt+=l*(l-1)*in/2;

        }
        cout<<tt<<endl;
    }
}

