#include<bits/stdc++.h>
using namespace std;
int a[10005];int b[10005];
#define ll long long
int main()
{ll n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        int c=0;
        while(1)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]<=b[i])
                {
                    b[i]-=a[i];
                }else{
                    k-=(a[i]-b[i]);
                    b[i]=0;
                }
                }if(k>=0)
                c++;
                else
                    break;}
        cout<<c<<endl;
}

