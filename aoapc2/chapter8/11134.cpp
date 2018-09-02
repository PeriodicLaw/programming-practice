#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=5010;
struct data{
	int l,r,id;
}a[2][MAXN];
int n,x[2][MAXN];
bool cmp(const data &x,const data &y){
	if(x.r==y.r)
		return x.l<y.l;
	else
		return x.r<y.r;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d",&n)==1&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&a[0][i].l,&a[1][i].l,&a[0][i].r,&a[1][i].r);
			a[0][i].id=a[1][i].id=i;
		}
		memset(x,0,sizeof(x));
		bool nosol=false;
		for(int t=0;t<=1;t++){
			sort(a[t],a[t]+n,cmp);
			for(int i=0;i<n;i++){
				int j;
				for(j=0;j<n;j++)
					if(!x[t][a[t][j].id]&&a[t][j].l<=i+1)
						break;
				if(j>=n||a[t][j].r<=i){
					nosol=true;
					break;
				}else
					x[t][a[t][j].id]=i+1;
			}
			if(nosol)break;
		}
		if(nosol)
			printf("IMPOSSIBLE\n");
		else
			for(int i=0;i<n;i++)
				printf("%d %d\n",x[0][i],x[1][i]);
	}
	return 0;
}

