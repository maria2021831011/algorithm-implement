
#include<bits/stdc++.h>
#define ll long long
#define for0(i,n) for(ll i=0;i<n;i++)
using namespace std;
void dfs(ll node,vector<ll> a[],ll *s,ll c,ll par)
{
for0(i,a[node].size())
{
ll x=a[node][i];
if(par!=x)
dfs(x,a,s,c+1,node);
else
*s=max(*s,c);
}
}
int main() {
ifstream cin("input.txt");
ofstream cout("output.txt");
ll n,ans=0;cin>>n;
while(n--)
{
ll m,l=0,s=0,v,u;cin>>m;
vector<ll> a[m+1]={};
for0(i,m-1)
{
cin>>v>>u;
a[v].push_back(u);
a[u].push_back(v);
}
for0(i,m)
dfs(i+1,a,&s,0,-1);
ans+=s;
}
cout<<ans;
}
