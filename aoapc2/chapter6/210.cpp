#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
const int MAXN=1000,MAXS=30;
deque<int> exec;
queue<int> block;
int n,qtime,prog[MAXN][MAXS][3],var[26],cur[MAXN],time[5];
bool lock;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
    int tc;scanf("%d",&tc);
    while(tc--){
    	memset(var,0,sizeof(var));
    	memset(cur,0,sizeof(cur));
    	lock=false;
    	scanf("%d%d%d%d%d%d%d",&n,&time[0],&time[1],&time[2],&time[3],&time[4],&qtime);
    	for(int i=0;i<n;i++){
    		int nstate=0;
    		while(true){
	    		char s[20];scanf(" %s",s);
	    		if(strlen(s)==1){
	    			prog[i][nstate][0]=0;
	    			prog[i][nstate][1]=s[0]-'a';
	    			scanf(" = %s",s); 
	    			prog[i][nstate][2]=atoi(s);
				}else if(!strcmp(s,"print")){
					prog[i][nstate][0]=1;
					scanf(" %s",s);
					prog[i][nstate][1]=s[0]-'a';
				}else if(!strcmp(s,"lock")){
					prog[i][nstate][0]=2;
				}else if(!strcmp(s,"unlock")){
					prog[i][nstate][0]=3;
				}else{
					prog[i][nstate][0]=4;
					break;
				}
				nstate++;
			}
			exec.push_back(i);
		}
    	while(!exec.empty()){
    		int run=exec.front();exec.pop_front();
    		int usetime=0;bool end=false;
    		while(usetime<qtime){
    			int *state=prog[run][cur[run]];
    			usetime+=time[state[0]];
    			if(state[0]==0)
					var[state[1]]=state[2];
    			else if(state[0]==1)
					printf("%d: %d\n",run+1,var[state[1]]);
    			else if(state[0]==2)
					if(lock){
						block.push(run);
						end=true;
						break;	
					}else{
						lock=true;
					}
				else if(state[0]==3){
					lock=false;
					if(!block.empty()){
						exec.push_front(block.front());
						block.pop();
					}
				}else{
					end=true;
					break;
				}
				cur[run]++; //HERE WA
			}
		if(!end) exec.push_back(run);
		}
		if(tc) printf("\n");
	}
	return 0;
}

