
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int>m;
    for(auto it:v)
    {
        m[it]++;
    }
    vector<int>s;
    for(auto it:m)
    {
        if(it.second>=2)
        {
            s.push_back(it.first);
        }
    }if(s.size()<2)
    {
        cout<<-1<<endl;
    }else
    {bool ok1=false;bool ok2=false;
        vector<int>d;
        for(auto it:v)
        {
            if(it==s[0])
            {
                d.push_back(ok1?2:1);
                ok1=true;
            }else if(it==s[1])
            {
                d.push_back(ok2?3:1);
                ok2=true;
            }
            else
            {d.push_back(1);

            }
        }

    for(auto it:d)
    {
        if(it>0)
        {
            cout<<it<<" ";
        }
    }
    cout<<endl;
    }
    }
}
