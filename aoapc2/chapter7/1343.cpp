#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=24;
const int dest[8]={6,7,8,11,12,15,16,17};
const int opers[8][7]={
0,2,6,11,15,20,22,
1,3,8,12,17,21,23,
10,9,8,7,6,5,4,
19,18,17,16,15,14,13,
23,21,17,12,8,3,1,
22,20,15,11,6,2,0,
13,14,15,16,17,18,19,
4,5,6,7,8,9,10};
int state[N];
char oper[100];
int maxd;
/*void printstate(){
	printf("  %d %d  \n  %d %d  \n",state[0],state[1],state[2],state[3]);
	for(int i=4;i<11;i++) printf("%d",state[i]);
	printf("\n  %d %d  \n",state[11],state[12]);
	for(int i=13;i<20;i++) printf("%d",state[i]);
	printf("\n  %d %d  \n  %d %d  \n",state[20],state[21],state[22],state[23]);
}*/
bool correct(){
	for(int i=1;i<8;i++)
		if(state[dest[i]]!=state[dest[0]]) return false;
	return true;
}
int mind(){
	int m=10;
	for(int x=1;x<=3;x++){
		int t=0;
		for(int i=0;i<8;i++) t+=(state[dest[i]]==x)?0:1;
		if(t<m) m=t;
	}
	return m;
}
bool dfs(int d){
	if(correct()){
		if(strlen(oper)==0) printf("No moves needed"); else printf("%s",oper);
		printf("\n%d\n",state[dest[0]]);
		return true;
	}
	if(d+mind()>maxd) return false;
	for(int i=0;i<8;i++){
		int temp[N];memcpy(temp,state,sizeof(state));
		int t=state[opers[i][0]];
		for(int j=0;j<6;j++) state[opers[i][j]]=state[opers[i][j+1]];
		state[opers[i][6]]=t;
		oper[d]='A'+i;oper[d+1]='\0';
		if(dfs(d+1)) return true;
		memcpy(state,temp,sizeof(state));
	}
	return false;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int t;
    while(scanf("%d",&t)==1&&t){
    	state[0]=t;
    	for(int i=1;i<N;i++) scanf("%d",&state[i]);
    	oper[0]='\0';
    	for(maxd=0;;++maxd)
    		if(dfs(0))
    			break;
	}
	return 0;
}
