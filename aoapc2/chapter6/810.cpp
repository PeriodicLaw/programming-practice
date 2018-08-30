#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=12,MAXQ=100000;
const int next[7][4]={0,0,0,0, 2,4,5,3, 1,3,6,4, 2,1,5,6, 1,2,6,5, 1,4,6,3, 2,3,5,4};
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int m,n,ans[MAXQ],map[MAXN][MAXN],visit[MAXN][MAXN][6][6];
struct node{
	int x,y,a,b,f;
}q[MAXQ];
inline int geta(int a,int b,int i){
	if(next[a][0]==b) return next[a][i];
	if(next[a][1]==b) return next[a][(i+1)%4];
	if(next[a][2]==b) return next[a][(i+2)%4];
	if(next[a][3]==b) return next[a][(i+3)%4];
	return 3/0;
}
inline int getb(int a,int b,int i){
	if(i==0) return 7-a;
	if(i==2) return a;
	return b;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    char s[40];
    while(scanf("%s",s)==1&&strcmp(s,"END")){
    	puts(s);
    	memset(visit,0,sizeof(visit));
    	int sx,sy,sa,sb;
    	scanf("%d%d%d%d%d%d",&m,&n,&sx,&sy,&sa,&sb);
    	--sx,--sy;
    	for(int i=0;i<m;i++)
    		for(int j=0;j<n;j++)
    			scanf("%d",&map[i][j]);
    	int qf=0,qb=1;bool nosol=true;
    	q[0].x=sx,q[0].y=sy,q[0].a=sa,q[0].b=sb,q[0].f=-1;
    	while(qf<qb){
    		int x=q[qf].x,y=q[qf].y,a=q[qf].a,b=q[qf].b;
    		if(x==sx&&y==sy&&qf){
    			nosol=false;
    			break;
			}
			for(int i=0;i<4;i++){
				int xx=x+dx[i],yy=y+dy[i];
				if(xx<0||xx>=m||yy<0||yy>=n) continue;
				int aa=geta(a,b,i),bb=getb(a,b,i);
				if(map[xx][yy]==-1||map[xx][yy]==a)
					if(!visit[xx][yy][aa][bb]){
						visit[xx][yy][aa][bb]=true;
						q[qb].x=xx,q[qb].y=yy,q[qb].a=aa,q[qb].b=bb,q[qb].f=qf;
						++qb;
					}
			}
			++qf;
		}
		if(nosol)
			printf("  No Solution Possible\n");
		else{
			int count=0;
			for(int i=qf;i>=0;i=q[i].f)
				ans[count++]=i;
			printf("  ");
			for(int i=1;i<=count;i++){
				if(i%9==1&&i>1) printf("\n  ");
				printf("(%d,%d)",q[ans[count-i]].x+1,q[ans[count-i]].y+1);
				if(i<count) printf(",");
			}
			printf("\n");
		}
	}
	return 0;
}

