#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int r,c,spaces,map[30][30],len,ans[50],cur[50];
inline int compare(int l){
	for(int i=0;i<l;i++)
		if(ans[i]!=cur[i])
			return cur[i]>ans[i]?1:-1;
	return 0;
}
void dfs(int d,int x,int y){
	cur[d-1]=map[x][y];
	int t=compare(d<len?d:len);
	if(d>len||(d==len&&t==1)){
		len=d;
		for(int i=0;i<len;i++)
			ans[i]=cur[i];
	}else if(len==spaces&&t==-1) return;
	map[x][y]=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(map[nx][ny])
			dfs(d+1,nx,ny);
	}
	map[x][y]=cur[d-1];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d%d",&r,&c)==2&&r){
		memset(map,0,sizeof(map));
		spaces=0;
		for(int i=1;i<=r;i++){
			scanf(" ");
			for(int j=1;j<=c;j++){
				char c=getchar();
				if(c!='#') map[i][j]=c-'0',++spaces;
			}
		}
		memset(ans,0,sizeof(ans));len=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(map[i][j])
					dfs(1,i,j);
		for(int i=0;i<len;i++) printf("%d",ans[i]);printf("\n");
	}
	return 0;
}
