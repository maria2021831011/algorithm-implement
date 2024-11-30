#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<ll> r(n);
        r[0] = 0;
        r[1] = 1;
        for(int i = 2; i < n; i++)
        {
            if(v[i] - v[i-1] < v[i-1] - v[i-2])
            {
                r[i] = r[i-1] + 1;
            }
            else
            {
                r[i] = r[i-1] + v[i] - v[i-1];
            }
        }

        vector<ll> l(n);
        l[n-1] = 0;
        l[n-2] = 1;
        for(int i = n-3; i >= 0; i--)
        {
            if(v[i+1] - v[i] < v[i+2] - v[i+1])
            {
                l[i] = l[i+1] + 1;
            }
            else
            {
                l[i] = l[i+1] + v[i+1] - v[i];
            }
        }

        ll q;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            x = x - 1;
            y = y - 1;
            if(x < y)
            {
                cout << r[y] - r[x] << endl;
            }
            else
            {
                cout << l[y] - l[x] << endl;
            }
        }
    }
}

