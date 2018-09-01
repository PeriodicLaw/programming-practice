#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=20;
int n,maxd,deg0,deg1,degother;
bool edge[MAXN][MAXN],open[MAXN],visit[MAXN],history[100000];
void dfs2(int x){
	visit[x]=true;
	int deg=0;
	for(int i=0;i<n;i++)
		if(!open[i]&&edge[x][i]){
			if(!visit[i]) dfs2(i);
			deg++;
		}
	if(deg==0) deg0++;
	if(deg==1) deg1++;
	if(deg>=3) degother++;
}
bool dfs1(int d,int set){
	if(d==maxd){
		memset(visit,0,sizeof(visit));
		int m=0;
		for(int i=0;i<n;i++)
			if(!open[i]&&!visit[i]){
				deg0=deg1=degother=0;
				dfs2(i);
				if(deg0!=1&&(deg1!=2||degother)) return false; //HERE WA
				m++;
			}
		return d+1>=m;
	}
	if(history[set]) return false; else history[set]=true; //HERE TLE
	for(int i=0;i<n;i++)
		if(!open[i]){
			open[i]=true;
			if(dfs1(d+1,set+(1<<i))) return true;
			open[i]=false;
		}
	return false;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int count=0;
    while(scanf("%d",&n)==1&&n){
    	int i,j;
    	memset(edge,0,sizeof(edge));
    	while(scanf("%d%d",&i,&j)&&i!=-1) edge[i-1][j-1]=edge[j-1][i-1]=true;
    	memset(open,0,sizeof(open));
		for(maxd=0;;++maxd){
			memset(history,0,sizeof(history));
    		if(dfs1(0,0)){
    			printf("Set %d: Minimum links to open is %d\n",++count,maxd);
    			break;
			}
		}
	}
	return 0;
}
