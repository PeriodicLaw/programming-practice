#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
const int MAXN=300,MAXL=100;
vector<int> graph[MAXN];
int r,c,n,visit[MAXN],in[MAXN],data[MAXN];
char str[MAXN][MAXL];
bool havecycle,cycle[MAXN];
void analyze(int x){
	char *s=str[x];
	int i=0;
	while(s[i])
		if(s[i]=='+'||s[i]=='-')
			++i;
		else if(s[i]>='0'&&s[i]<='9')
			while(s[i]>='0'&&s[i]<='9') ++i;
		else{
			int y=(s[i]-'A')*c+s[i+1]-'0';i+=2;
			graph[y].push_back(x);
			++in[x];
		}
}
void dfs(int x,bool cyclic){
	if(cyclic){
		havecycle=true;
		cycle[x]=true;
		for(int y:graph[x])
			if(!cycle[y])
				dfs(y,true);
	}else{
		visit[x]=2;
		for(int y:graph[x])
			if(visit[y]==0)
				dfs(y,false);
			else if(visit[y]==2)
				dfs(y,true);
		visit[x]=1;
	}
}
void calculate(int x){
	char *s=str[x];
	int i=0,sign=1;
	data[x]=0;
	while(s[i])
		if(s[i]=='+'||s[i]=='-')
			sign=(s[i]=='+')?1:-1,++i;
		else if(s[i]>='0'&&s[i]<='9'){
			int n=0;
			while(s[i]>='0'&&s[i]<='9') n=n*10+s[i]-'0',++i;
			data[x]+=sign*n;
		}
		else{
			int y=(s[i]-'A')*c+s[i+1]-'0';i+=2;
			data[x]+=sign*data[y];
		}
	for(int j:graph[x])
		calculate(j);
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    while(scanf("%d%d",&r,&c)==2&&r&&c){
    	n=r*c;
    	for(int i=0;i<n;i++) graph[i].clear();
    	memset(in,0,sizeof(in));
    	for(int i=0;i<r;i++)
    		for(int j=0;j<c;j++){
    			scanf(" %s",str[i*c+j]);
    			analyze(i*c+j);
			}
		memset(visit,0,sizeof(visit));
		memset(cycle,0,sizeof(cycle));
		havecycle=false;
		for(int i=0;i<n;i++)
			if(!visit[i])
				dfs(i,false);
		if(havecycle){
			for(int i=0;i<n;i++)
				if(cycle[i])
					printf("%c%d: %s\n",'A'+i/c,i%c,str[i]);
		}else{
			for(int i=0;i<n;i++)
				if(!in[i])
					calculate(i);
			printf(" ");for(int i=0;i<c;i++) printf("%6d",i);printf("\n");
			for(int i=0;i<r;i++){
				printf("%c",'A'+i);
				for(int j=0;j<c;j++)
					printf("%6d",data[i*c+j]);
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
