#include <bits/stdc++.h>
using namespace std;
map<string, int> adj;
double v[200][200];
int n,m;
int main ()
{
  string a,b,c;
	int i,j;
	double k;
	int t=1;
	while(1){
		cin >> n;
		if(n==0)
			break;
		for(i=0;i<n;i++){
			cin >> a;
			adj[a]=i;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				v[i][j]=0.0;
			}
		cin >> m;

		for(int z=0;z<m;z++){
			cin >> a >> k >> b;
			i=adj.find(a)->second;
			j=adj.find(b)->second;
			v[i][j]=k;
		}
		for(int x=0;x<n;x++)
			for(int y=0;y<n;y++)
				for(int z=0;z<n;z++)
						if(v[y][z] < v[y][x]*v[x][z])
							v[y][z] = v[y][x]*v[x][z];
		for(i=0;i<n;i++)
			if(v[i][i]>1.0)
				break;
		cout << "Case " << t << ": ";
		if(i==n)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		t++;
	}
	return 0;
}

