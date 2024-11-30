
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {int n;
    cin>>n;

        string s1,s2,s3;
        cin>>s1;
        cin>>s2;
        cin>>s3;
        bool k=false;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s3[i] && s2[i]!=s3[i])
            {
                k=true;
                break;
            }
        }
        if(k)
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }

    }
}
