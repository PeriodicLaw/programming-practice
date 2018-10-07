#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=15,MAXM=1020;
int m,ansm,a[MAXN],ansa[MAXN];
bool f[MAXN][MAXM];
bool cmp(){
	if(m==ansm){
		for(int i=m-1;i>=0;i--)
			if(a[i]!=ansa[i])
				return a[i]<ansa[i];
		return false;
	}else
		return m<ansm;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n,s;
	while(scanf("%d",&s)==1&&s){
		scanf("%d",&n);
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&m);
			for(int i=0;i<m;i++)
				scanf("%d",&a[i]);
			memset(f,0,sizeof(f));
			f[0][0]=true;
			for(int i=1;i<=s;i++)
				for(int j=0;j<=MAXM;j++){
					f[i][j]=f[i-1][j];
					for(int k=0;k<m;k++)
						if(j>=a[k]&&f[i-1][j-a[k]])
							f[i][j]=true;
				}
			int cur=0;
			while(f[s][cur+1]) cur++;
			if(cur>ans||(cur==ans&&cmp())){
				ans=cur;
				ansm=m;
				memcpy(ansa,a,sizeof(a));
			}
		}
		printf("max coverage = %3d :",ans);
		for(int i=0;i<ansm;i++)
			printf("%3d",ansa[i]);
		printf("\n");
	}
	return 0;
}

