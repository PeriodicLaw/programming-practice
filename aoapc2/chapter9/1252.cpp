#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=150,MAXM=11;
int n,m,f[1<<MAXM][1<<MAXM],c[1<<MAXM][1<<MAXM],s[MAXN];
int dp(int s,int a){
	if(f[s][a]!=-2) return f[s][a];
	if(c[s][a]==1) return f[s][a]=0;
	f[s][a]=-1;
	for(int i=0;i<m;i++)
		if(!(s&(1<<i))){
			int x=dp(s+(1<<i),a+(1<<i)),y=dp(s+(1<<i),a),
				z=(x<y)?y:x;
			if(z!=-1&&(f[s][a]==-1||z+1<f[s][a]))
				f[s][a]=z+1;
		}
	return f[s][a];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d%d",&m,&n)==2&&m&&n){
		for(int i=0;i<n;i++){
			scanf(" ");
			s[i]=0;
			for(int j=0;j<m;j++)
				s[i]=s[i]*2+(getchar()=='1');
		}
		for(int i=0;i<(1<<m);i++){
			f[i][0]=-2,c[i][0]=0;
			for(int j=i;j;j=(j-1)&i)
				f[i][j]=-2,c[i][j]=0;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<(1<<m);j++)
				c[j][s[i]&j]++;
		int ans=0;
		for(int i=0;i<(1<<m);i++){
			int x=dp(i,0);if(x>ans) ans=x;
			for(int j=i;j;j=(j-1)&i){
				x=dp(i,j);
				if(x>ans)
					ans=x;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}

