#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=500,MAXM=100000;
struct edge{
	int v;
	int next;
}edges[MAXM],redges[MAXM];
int n,m;
int graph[MAXN],rgraph[MAXN];
bool mgraph[MAXN][MAXN];
void add_edge(int i){
	int u,v;
	scanf("%d%d",&u,&v);
	edges[i].v=v,edges[i].next=graph[u],graph[u]=i;
	redges[i].v=u,redges[i].next=rgraph[v],rgraph[v]=i;
	mgraph[u][v]=true;
}
set<int> s1,s2;
bool v1[MAXN],v2[MAXN];
void search2(int v);
void search1(int u){
	s1.insert(u);
	for(int i=graph[u];i;i=edges[i].next)
		if(!v2[edges[i].v]){
			v2[edges[i].v]=true;
			search2(edges[i].v);
		}
}
void search2(int v){
	s2.insert(v);
	for(int i=rgraph[v];i;i=redges[i].next)
		if(!v1[redges[i].v]){
			v1[redges[i].v]=true;
			search1(redges[i].v);
		}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d%d",&n,&m);
		memset(graph,0,sizeof(graph));
		memset(rgraph,0,sizeof(rgraph));
		memset(mgraph,0,sizeof(mgraph));
		for(int i=1;i<=m;i++)
			add_edge(i);
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		for(int i=0;i<n;i++)
			if(!v1[i]){
				s1.clear();
				s2.clear();
				v1[i]=true;
				search1(i);
				for(auto u:s1)
					for(auto v:s2)
						if(!mgraph[u][v]){
							printf("Case #%d: No\n",tt);
							goto label;
						}
			}
		printf("Case #%d: Yes\n",tt);
		label:;
	}
	return 0;
}
