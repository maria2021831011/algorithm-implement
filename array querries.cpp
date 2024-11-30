
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> seg_tree;

void build(int node, int begin, int end)
{
    if(begin == end)
    {
        seg_tree[node] = arr[begin];
        return;
    }

    int left, right, mid;
    left = node*2;
    right = (node*2)+1;
    mid = begin + ((end - begin) / 2);
    build(left, begin, mid);
    build(right, mid + 1, end);
    seg_tree[node] = min(seg_tree[left], seg_tree[right]);
}

int query(int node, int begin, int end, int i, int j)
{
    if(end < i || j < begin)
        return INT_MAX;

    if(i <= begin && end <= j)
        return seg_tree[node];

    int left, right, mid, q1, q2;
    left = node*2;
    right = (node*2)+1;
    mid = begin + ((end - begin) / 2);
    q1 = query(left, begin, mid, i, j);
    q2 = query(right, mid + 1, end, i, j);
    return min(q1, q2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int cs = 1; cs <= t; cs++)
    {
        int n, q;
        cin >> n >> q;
        arr.assign(n + 2, 0);
        seg_tree.assign((4 * n) + 2, 0);

        for(int i = 1; i <= n; i++)
            cin >> arr[i];

        build(1, 1, n);
        cout << "Case " << cs << ":" << "\n";

        for(int i = 1; i <= q; i++)
        {
            int I, J;
            cin >> I >> J;
            cout << query(1, 1, n, I, J) << "\n";
        }
    }

    return 0;
}
