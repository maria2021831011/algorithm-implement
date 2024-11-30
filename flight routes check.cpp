

#include <bits/stdc++.h>
using namespace std;
const int ma = 2e5+1;
int n, m, a, b;
bool vis1[ma], vis2[ma];
vector<int> g1[ma], g2[ma];
void dfs1(int u, int p ){
    vis1[u] = true;
    for(int v : g1[u])
        if(v != p && !vis1[v])
            dfs1(v, u);
}
void dfs2(int u , int p ){
    vis2[u] = true;
    for(int v : g2[u])
        if(v != p && !vis2[v])
            dfs2(v, u);
}
int main(){
    cin >> n>> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i = 1; i <= n; i++){
        if(!vis1[i] || !vis2[i]){
            cout << "NO" << endl;
            if(!vis1[i])    cout << "1 " << i << endl;
            else            cout << i << " 1" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
