#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
bool edge[52][52],use[26];
int visit[52];
inline int getnum(const char *s){
	if(s[0]=='0') return -1;
	if(s[1]=='+') return s[0]-'A';
	else return s[0]+26-'A';
}
inline int reverse(int x){
	if(x<26) return x+26;
	else return x-26;
}
bool dfs(int x){
	visit[x]=1;
	for(int i=0;i<52;i++)
		if(use[i%26]&&edge[x][i]){ //HERE RE
			if(visit[i]==1) return false;
			if(!visit[i]&&!dfs(i)) return false;
		}
	visit[x]=2;
	return true;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
    	memset(visit,0,sizeof(visit));
    	memset(edge,0,sizeof(edge));
    	for(int i=0;i<n;i++){
    		char s[20];
    		scanf(" %s",s);
    		int a[4];
			for(int j=0;j<4;j++){
				a[j]=getnum(s+j*2);
				if(a[j]>=0) use[a[j]%26]=true;
			}
    		for(int j=0;j<4;j++) if(a[j]>=0)
    			for(int k=0;k<4;k++) if(a[k]>=0&&j!=k){
    				edge[reverse(a[j])][a[k]]=true;
    				edge[reverse(a[k])][a[j]]=true;
    			}
		}
		bool cycle=false;
		for(int i=0;i<52;i++)
			if(use[i%26]&&!dfs(i)){
				cycle=true;
				break;
			}
		printf(cycle?"unbounded\n":"bounded\n");
	}
	return 0;
}

