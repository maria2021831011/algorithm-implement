

#include<bits/stdc++.h>
using namespace std;

int main() {
	string ne,h;
	int j=0,n,i,c;

	while(cin>>n>>ne>>h){
		if(ne.length()>h.length()){
			cout<<endl;
		}
		if(ne.length()==h.length()){
			if(h==ne){
				cout<<0<<endl;
			}

		}
		if(ne.length()<h.length()){
		for(int k=0;k<=(h.length()-ne.length());++k){
			i=k;
			c=0;
			for(j=0;j<ne.length();++j){
				if(h[i]==ne[j]){

					++i;
					++c;
					if(c==n){
						cout<<i-n<<endl;
					}
			}
			else{
				break;
			}
			}
		}
		}
	}

	return 0;
}
