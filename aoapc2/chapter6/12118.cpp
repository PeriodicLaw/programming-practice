#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXV=1010,INF=10000000;
int deg[MAXV];
bool edge[MAXV][MAXV],visit[MAXV];
int v,e,nodd;
void dfs(int x){
	visit[x]=true;
	nodd+=deg[x]%2;
	for(int i=0;i<v;i++)
		if(edge[x][i]&&!visit[i])
			dfs(i);
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int t,count=0;
    while(scanf("%d%d%d",&v,&e,&t)==3&&v){
    	memset(deg,0,sizeof(deg));
    	memset(edge,0,sizeof(edge));
    	for(int i=0;i<e;i++){
    		int a,b;scanf("%d%d",&a,&b);
    		--a,--b;
    		edge[a][b]=edge[b][a]=true;
    		++deg[a],++deg[b];
		}
		memset(visit,0,sizeof(visit));
		int ans=e;
		for(int i=0;i<v;i++)
			if(!visit[i]&&deg[i]){
				nodd=0;
				dfs(i);
				ans++;
				if(nodd>2) ans+=nodd/2-1;
			}
		if(e==0) ans=1;
		printf("Case %d: %d\n",++count,t*(ans-1));
	}
	return 0;
}

