#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string p;
        if (s == p)
        {
            cout << "0" << endl;
            continue;
        }

        string lax;
        vector<int> v;
        char c = s[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] >= c)
            {
                v.push_back(i);
                lax += s[i];
                c = s[i];
            }
        }

        int count = 0;
        for (int i = lax.size() - 1; i >= 0; i--)
        {
            if (lax[i] == lax.back())
            {
                count++;
            }
            else
            {
                break;
            }
        }

        reverse(lax.begin(), lax.end());
        for (int i = 0; i < lax.size(); i++)
        {
            s[v[i]] = lax[i];
        }

        int ans = lax.size();
        if (is_sorted(s.begin(), s.end()))
        {
            cout << ans - count << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}

