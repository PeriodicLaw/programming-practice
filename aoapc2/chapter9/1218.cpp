#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=10010;
const LL INF=10000000;
LL f[MAXN][3];
bool v[MAXN];
vector<int> g[MAXN];
void dp(int n){
	f[n][0]=1;f[n][1]=0;f[n][2]=INF;
	v[n]=true;
	vector<int> c;
	for(auto i:g[n])
		if(!v[i]){
			c.push_back(i);
			dp(i);
			f[n][0]+=f[i][0]<f[i][1]?f[i][0]:f[i][1];
			f[n][1]+=f[i][2];
		}
	for(auto i:c)
		if(f[n][1]+f[i][0]-f[i][2]<f[n][2])
			f[n][2]=f[n][1]+f[i][0]-f[i][2];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;bool flag=false;
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;i++) g[i].clear(),v[i]=false;
		int a,b;
		while(scanf("%d",&a)==1){
			if(a==-1) flag=true;
			if(a<=0) break;
			scanf("%d",&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dp(1);
		printf("%lld\n",f[1][0]<f[1][2]?f[1][0]:f[1][2]);
		if(flag) break;
	}
	return 0;
}
