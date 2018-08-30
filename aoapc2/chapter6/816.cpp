#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=10;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool able[MAXN][MAXN][4][4],visit[MAXN][MAXN][4];
struct node{
	int x,y,dir,father;
}q[100000];
int ans[100000];
inline int getdir(char c){
	switch(c){
		case 'N':return 0;
		case 'S':return 2;
		case 'E':return 3;
		case 'W':return 1;
	}
	return -1;
}
inline int turn(int dir,char c){
	switch(c){
		case 'L':return (dir+1)%4;
		case 'F':return dir;
		case 'R':return (dir+3)%4;
	}
	return -1;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    char s[100];scanf(" %s",s);
    while(strcmp(s,"END")){
    	memset(able,0,sizeof(able));
    	memset(visit,0,sizeof(visit));
    	printf("%s\n",s);
    	
    	int sx,sy,gx,gy,sdir;char c;
    	scanf("%d%d %c%d%d",&sx,&sy,&c,&gx,&gy);
    	sx--,sy--,gx--,gy--;sdir=getdir(c);
    	int t;scanf("%d",&t);
    	while(t){
    		int x=t,y;scanf("%d",&y);
    		x--,y--;
			while(scanf(" %s",s)==1&&strcmp(s,"*")){
				int dir=getdir(s[0]);
				for(int i=1;i<strlen(s);i++)
					able[x][y][dir][turn(dir,s[i])]=true;
			}
			scanf("%d",&t);
		}
    	int qf=0,qb=1;
    	q[0].x=sx+dx[sdir],q[0].y=sy+dy[sdir],q[0].dir=sdir,q[0].father=-1;
    	bool nosol=true;
    	while(qf<qb){
    		int x=q[qf].x,y=q[qf].y,dir=q[qf].dir;
    		visit[x][y][dir]=true;
    		if(x==gx&&y==gy){
    			nosol=false;
    			break;
			}
			for(int d=0;d<4;d++)
				if(able[x][y][dir][d]){
					q[qb].x=x+dx[d];
					q[qb].y=y+dy[d];
					if(q[qb].x<0||q[qb].x>=9||q[qb].y<0||q[qb].y>=9) continue; //HERE RE
					if(visit[q[qb].x][q[qb].y][d]) continue;
					q[qb].dir=d;
					q[qb].father=qf;
					qb++;
				}
    		qf++;
		}
		
		if(nosol)
			printf("  No Solution Possible\n");
		else{
			printf("  (%d,%d)",sx+1,sy+1);
			int m=0;
			for(int i=qf;i>=0;i=q[i].father)
				ans[m++]=i;
			for(int i=0;i<m;i++){
				if(i%10==9) printf("\n ");
				printf(" (%d,%d)",q[ans[m-i-1]].x+1,q[ans[m-i-1]].y+1);
			}
			printf("\n");
		}
		
    	scanf(" %s",s);
	}
	return 0;
}

