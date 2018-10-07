#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=15,MAXM=120,INF=100000;
int n,f[1<<MAXN],c[MAXN],u[MAXM],v[MAXM];
bool h[1<<MAXN],g[MAXN][MAXN];
char a[MAXN];
void color(int s,int r){
	if(h[s]){
		for(int i=0;i<n;i++)
			if(s&(1<<i))
				c[i]=r;
	}else
		for(int i=s;i;i=(i-1)&s)
			if(h[i]&&f[s-i]+1==f[s]){
				for(int j=0;j<n;j++)
					if(i&(1<<j))
						c[j]=r;
				color(s-i,r+1);
				return;
			}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int m;
	while(scanf("%d",&m)!=EOF){
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		n=0;
		for(int i=0;i<m;i++){
			char c1,c2;
			scanf(" %c %c",&c1,&c2);
			if(find(a,a+n,c1)==a+n)
				a[n++]=c1;
			if(find(a,a+n,c2)==a+n)
				a[n++]=c2;
			u[i]=find(a,a+n,c1)-a;
			v[i]=find(a,a+n,c2)-a;
			g[u[i]][v[i]]=g[v[i]][u[i]]=true;
		}
		memset(h,0,sizeof(h));
		for(int i=0;i<n;i++) h[1<<i]=true;
		for(int i=1;i<(1<<n);i++)
			if(h[i])
				for(int j=0;j<n;j++)
					if(!(i&(1<<j))){
						bool ok=true;
						for(int k=0;k<n;k++)
							if((i&(1<<k))&&g[j][k]){
								ok=false;
								break;
							}
						if(ok) h[i|(1<<j)]=true;
					}
		for(int i=1;i<(1<<n);i++){
			f[i]=h[i]?1:INF;
			for(int j=i;j;j=(j-1)&i)
				if(h[j]&&f[i-j]+1<f[i])
					f[i]=f[i-j]+1;
		}
		memset(c,0,sizeof(c));
		color((1<<n)-1,1);
		printf("%d\n",f[(1<<n)-1]-2);
		for(int i=0;i<m;i++)
			if(c[u[i]]>c[v[i]])
				printf("%c %c\n",a[u[i]],a[v[i]]);
			else
				printf("%c %c\n",a[v[i]],a[u[i]]);
	}
	return 0;
}
