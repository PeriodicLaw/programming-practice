#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int edge[26][26],in[26],out[26];
bool use[26],visit[26];
void dfs(int x){
	visit[x]=true;
	for(int i=0;i<26;i++)
		if(!visit[i]&&(edge[x][i]||edge[i][x]))
			dfs(i);
	return;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--){
    	memset(edge,0,sizeof(edge));
    	memset(in,0,sizeof(in));
    	memset(out,0,sizeof(out));
    	memset(use,0,sizeof(use));
    	memset(visit,0,sizeof(visit));
    	int n;scanf("%d",&n);
    	for(int i=0;i<n;i++){
    		char s[1020];
    		scanf(" %s",s);
    		int x=s[0]-'a',y=s[strlen(s)-1]-'a';
    		use[x]=use[y]=true;
    		edge[x][y]++;
    		out[x]++;
    		in[y]++;
		}
		for(int i=0;i<26;i++)
			if(use[i]){
				dfs(i);
				break;
			}
		bool flag=true;
		for(int i=0;i<26;i++)
			if(use[i]&&!visit[i]){
				flag=false;
				break;
			}
		int c1=0,c2=0;
		for(int i=0;i<26;i++)
			if(use[i]){
				if(in[i]-out[i]==1)
					c1++;
				else if(out[i]-in[i]==1)
					c2++;
				else if(in[i]!=out[i]){
					flag=false;
					break;
				}
			}
		if(flag)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}
 
