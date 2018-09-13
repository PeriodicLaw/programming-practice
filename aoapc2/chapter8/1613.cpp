#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=10010,MAXM=200100;
struct edge{
	int v,next;
}edges[MAXM];
int n,m,k;
int graph[MAXN],degree[MAXN],color[MAXN];
bool visit[MAXN],possible[MAXN];
void add_edge(int i){
	int u,v;
    scanf("%d%d",&u,&v);
    edges[i].v=v,edges[i].next=graph[u],graph[u]=i;
    edges[m+i].v=u,edges[m+i].next=graph[v],graph[v]=m+i;
    ++degree[u],++degree[v];
}
void paint(int x){
	for(int i=1;i<=k;i++) possible[i]=true;
	for(int i=graph[x];i;i=edges[i].next)
		possible[color[edges[i].v]]=false;
	for(int i=1;i<=k;i++)
		if(possible[i]){
			color[x]=i;
			break;
		}
	for(int i=graph[x];i;i=edges[i].next)
		if(!color[edges[i].v])
			paint(edges[i].v);
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	bool flag=false;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(flag) printf("\n"); else flag=true;
		memset(graph,0,sizeof(graph));
		memset(degree,0,sizeof(degree));
		for(int i=1;i<=m;i++) add_edge(i);
		m*=2;
		k=0;
		for(int i=1;i<=n;i++) if(degree[i]>k) k=degree[i];
		if(k%2==0) ++k;
		memset(color,0,sizeof(color));
		paint(1);
		printf("%d\n",k);
		for(int i=1;i<=n;i++)
			printf("%d\n",color[i]);
	}
	return 0;
}

