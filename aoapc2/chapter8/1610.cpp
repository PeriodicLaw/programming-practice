#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=1010;
string name[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(cin>>n&&n){
		for(int i=0;i<n;i++) cin>>name[i];
		sort(name,name+n);
		int t=-1;
		for(int i=0;i<name[n/2-1].length()-1;i++)
			if(name[n/2-1][i]<name[n/2][i])
				if(name[n/2-1][i]+1==name[n/2][i]&&i+1==name[n/2].length()){
					for(int j=i+1;j<name[n/2-1].length()-1;j++)
						if(name[n/2-1][j]!='Z'){
							t=j;
							break;
						}
				}else{
					t=i;
					break;
				}
		if(t==-1)
			cout<<name[n/2-1]<<endl;
		else{
			for(int i=0;i<t;i++) cout<<name[n/2-1][i];
			cout<<(char)(name[n/2-1][t]+1)<<endl;
		}
	}
	return 0;
}
