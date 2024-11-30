
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack<int>small,capital;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' &&s[i]<='Z' &&s[i]!='B')
                capital.push(i);
            if(s[i]>='a' &&s[i]<='z'&&s[i]!='b')
                small.push(i);
                if(s[i]=='B' && !capital.empty())
                {
                    s[capital.top()]='9';
                    capital.pop();
                }
                if(s[i]=='b' && !small.empty())
                {
                    s[small.top()]='9';
                    small.pop();
                }
        }
        for(int i=0;i<s.size();i++)

{
    if(s[i]!='B' & s[i]!='b'&s[i]!='9')
    {cout<<s[i];

}} cout<<endl;
}

}
