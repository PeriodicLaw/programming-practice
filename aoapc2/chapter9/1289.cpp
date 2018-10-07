#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map> 
using namespace std;
typedef long long LL;
const int INF=1000000;
map<int,map<int,int>> a;
int n,f[10000][70];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int count=0;
	while(scanf("%d",&n)==1){
		a.clear();
		for(int i=0;i<n;i++){
			int m;scanf("%d",&m);
			for(int j=0;j<m;j++){
				int x;scanf("%d",&x);
				a[x][i]++;
			}
		}
		memset(f,0,sizeof(f));
		int i=0;
		for(auto x:a){
			i++;
			auto &y=x.second;
			int u=y.size();
			for(int j=0;j<n;j++){
				f[i][j]=INF;
				if(y.find(j)!=y.end()){
					for(int k=0;k<n;k++)
						if(k==j)
							if(u==1)
								f[i][j]=min(f[i][j],f[i-1][k]);
							else
								f[i][j]=min(f[i][j],f[i-1][k]+u);
						else
							if(y.find(k)==y.end())
								f[i][j]=min(f[i][j],f[i-1][k]+u);
							else
								f[i][j]=min(f[i][j],f[i-1][k]+u-1);
				}
			}
		}
		int ans=INF;
		for(int j=0;j<n;j++)
			if(f[i][j]<ans)
				ans=f[i][j];
		printf("Case %d: %d\n",++count,ans*2-n+1);
	}
	return 0;
}
