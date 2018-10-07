#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=210;
vector<pair<int,int>> graph[MAXN];
int n,k;
bool f[MAXN][MAXN],s[MAXN],temp[MAXN];
int findk(int v){
	s[v]=true;
	int ans=0;
	for(auto i:graph[v])
		if(!s[i.first]&&i.second==1)
			ans=max(ans,findk(i.first));
	return ans+1;
}
void dp(int v){
	s[v]=true;
	for(int i=1;i<=k;i++)
		f[v][i]=true;
	for(auto i:graph[v])
		if(!s[i.first]){
			dp(i.first);
			if(i.second==1){
				bool g=false;
				for(int j=k;j>=1;j--){
					f[v][j]&=g;
					g|=f[i.first][j];
				}
			}else if(i.second==-1){
				bool g=false;
				for(int j=1;j<=k;j++){
					f[v][j]&=g;
					g|=f[i.first][j];
				}
			}else{
				bool g=false;
				for(int j=1;j<=k;j++){
					temp[j]=g;
					g|=f[i.first][j];
				}
				g=false;
				for(int j=k;j>=1;j--){
					temp[j]|=g;
					g|=f[i.first][j];
				}
				for(int j=1;j<=k;j++)
					f[v][j]&=temp[j];
			}
		}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(true){
		for(int i=0;i<MAXN;i++) graph[i].clear();
		n=0;
		while(true){
			int u;
			scanf("%d",&u);
			if(u==0) break;
			if(u>n) n=u;
			while(true){
				char s[10];scanf(" %s",s);int e=0;
				if(s[strlen(s)-1]=='d'||s[strlen(s)-1]=='u')
					e=s[strlen(s)-1]=='d'?1:-1,s[strlen(s)-1]='\0';
				int v;sscanf(s,"%d",&v);
				if(v==0) break;
				if(v>n) n=v;
				graph[u].emplace_back(v,e);
				graph[v].emplace_back(u,-e);
			}
		}
		if(n==0) break;
		k=0;
		for(int i=1;i<=n;i++){
			memset(s,0,sizeof(s));
			k=max(k,findk(i));
		}
		memset(s,0,sizeof(s));
		dp(1);
		bool ok=false;
		for(int i=1;i<=k;i++)
			ok|=f[1][i];
		if(ok) printf("%d\n",k);
		else printf("%d\n",k+1);
	}
	return 0;
}
