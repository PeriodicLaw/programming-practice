#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define MAXN 100100
#define MAXM 400100
#define INF 1000001000
struct edge{
	int v,c;
	int next;
}edges[MAXM];
int n,m;
int graph[MAXN],dist[MAXN],ans[MAXN];
bool visit[MAXN];
void add_edge(int i){
	int u,v,c;
    scanf("%d%d%d",&u,&v,&c);
    edges[i].v=v,edges[i].c=c,edges[i].next=graph[u],graph[u]=i;
    edges[m+i].v=u,edges[m+i].c=c,edges[m+i].next=graph[v],graph[v]=m+i;
}
void bfs1(){
	memset(visit,0,sizeof(visit));
	memset(dist,0,sizeof(dist));
	queue<int> q;q.push(n);
	visit[n]=true;dist[n]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=graph[u];i;i=edges[i].next)
			if(!visit[edges[i].v]){
				q.push(edges[i].v);
				dist[edges[i].v]=dist[u]+1;
				visit[edges[i].v]=true;
			}
	}
}
void bfs2(){
	memset(visit,0,sizeof(visit));
	vector<int> q;
	q.push_back(1);visit[1]=true;
	for(int i=0;i<dist[1];i++){
		ans[i]=INF;
		for(int j=0;j<q.size();j++){
			int u=q[j],d=dist[u]-1;
			for(int k=graph[u];k;k=edges[k].next)
				if(dist[edges[k].v]==d&&ans[i]>edges[k].c)
					ans[i]=edges[k].c;
		}
		vector<int> q2;
		for(int j=0;j<q.size();j++){
			int u=q[j],d=dist[u]-1;
			for(int k=graph[u];k;k=edges[k].next)
				if(!visit[edges[k].v]&&dist[edges[k].v]==d&&edges[k].c==ans[i]){
					q2.push_back(edges[k].v);
					visit[edges[k].v]=true;
				}
		}
		q=q2;
	}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    while(scanf("%d%d",&n,&m)==2){
    	memset(graph,0,sizeof(graph));
		for(int i=1;i<=m;i++) add_edge(i);
		bfs1();
		bfs2();
		printf("%d\n%d",dist[1],ans[0]);
		for(int i=1;i<dist[1];i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
}
