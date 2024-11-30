

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll a[n];

        set<ll> s;
        s.insert(0);
        ll sum = 0;
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)

                a[i] *= -1;
                sum += a[i];
                if (s.find(sum) != s.end())

                    f = true;


                s.insert(sum);
            }


        if (f)

            cout << "YES" << endl;

        else

            cout << "NO" << endl;




}
}
