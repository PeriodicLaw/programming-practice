#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue> 
#include<utility>
using namespace std;
const int MAXN=23;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
struct node{
	int x,y,r,s;
	node(int x,int y,int r,int s):x(x),y(y),r(r),s(s){}
};
queue<node> q;
bool visit[MAXN][MAXN][MAXN],map[MAXN][MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int m,n,k,count;scanf("%d",&count);
    while(count--){
    	memset(visit,0,sizeof(visit));
    	scanf("%d%d%d",&m,&n,&k);
    	for(int i=0;i<m;i++)
    		for(int j=0;j<n;j++){
    			int t;scanf("%d",&t);
    			map[i][j]=t?true:0;
			}
		q=queue<node>();
		node temp(0,0,0,0);q.push(temp);visit[0][0][0]=true;
		bool ok=false;
		while(!q.empty()){
			node cur=q.front();q.pop();
			if(cur.x==m-1&&cur.y==n-1){
				printf("%d\n",cur.s);
				ok=true;
				break;
			}
			for(int i=0;i<4;i++){
				int x=cur.x+dx[i],y=cur.y+dy[i],r;
				if(x<0||x>=m||y<0||y>=n) continue;
				if(map[x][y]) r=cur.r+1; else r=0;
				if(r<=k&&!visit[x][y][r]){
					visit[x][y][r]=true;
					node nxt(x,y,r,cur.s+1);
					q.push(nxt);
				}
			}
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}

