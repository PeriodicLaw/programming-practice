#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef unsigned char state[9];
const int HASHMOD=1000003,SIZE=sizeof(state);
inline int hashcode(const state &x){
	int h=0;
	for(int i=0;i<9;i++) h=h*10+(int)x[i];
	return h%HASHMOD;
}
inline bool findhash_add(int hash[],int next[],const state states[],int x){
	int h=hashcode(states[x]);
	for(int p=hash[h];p;p=next[p])
		if(!memcmp(states[p-1],states[x],SIZE))
			return true;
	next[x]=hash[h],hash[h]=x+1;
	return false;
}
inline int gethash(const int hash[],const int next[],const state states[],const state &s){
	int h=hashcode(s);
	for(int p=hash[h];p;p=next[p])
		if(!memcmp(states[p-1],s,SIZE))
			return p-1;
	return -1;
}
const int MAXQ=5000000,dpos[4]={-3,1,3,-1},dstate[6][2]={4,5,5,3,3,4,2,1,0,2,1,0};
const bool candpos[9][4]={0,1,1,0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,0,0,1};
state states[MAXQ],rev_states[MAXQ];
int hash[HASHMOD],next[MAXQ],rev_hash[HASHMOD],rev_next[MAXQ];
int pos[MAXQ],rev_pos[MAXQ],step[MAXQ],rev_step[MAXQ];
int front,back,rev_front,rev_back;
int bfs(int steps){
	int f,b;
	for(f=front,b=back;f<back;f++)
		for(int i=0;i<4;i++)
			if(candpos[pos[f]][i]){
				int nextpos=pos[f]+dpos[i];
				memcpy(states[b],states[f],SIZE);
				states[b][pos[f]]=dstate[states[f][nextpos]][i%2];
				states[b][nextpos]=6;
				int t=gethash(rev_hash,rev_next,rev_states,states[b]);
				if(t>=0) return steps+rev_step[t];
				if(!findhash_add(hash,next,states,b)){
					pos[b]=nextpos;
					step[b]=step[f]+1;
					++b;
				}
			}
	front=back,back=b;
	return -1;
}
int rev_bfs(int steps){
	int f,b;
	for(f=rev_front,b=rev_back;f<rev_back;f++)
		for(int i=0;i<4;i++)
			if(candpos[rev_pos[f]][i]){
				int nextpos=rev_pos[f]+dpos[i];
				memcpy(rev_states[b],rev_states[f],SIZE);
				rev_states[b][rev_pos[f]]=dstate[rev_states[f][nextpos]][i%2];
				rev_states[b][nextpos]=6;
				int t=gethash(hash,next,states,rev_states[b]);
				if(t>=0) return steps+step[t];
				if(!findhash_add(rev_hash,rev_next,rev_states,b)){
					rev_pos[b]=nextpos;
					rev_step[b]=rev_step[front]+1;
					++b;
				}
			}
	rev_front=rev_back,rev_back=b;
	return -1;
}
int main(){
	int sx,sy;
	while(scanf("%d%d",&sx,&sy)&&sx){
		int startpos=sy*3+sx-4;
		memset(hash,0,sizeof(hash));
		front=0,back=1;
		memset(states[0],0,SIZE);states[0][startpos]=6;pos[0]=startpos;step[0]=0;
		findhash_add(hash,next,states,0);
		memset(rev_hash,0,sizeof(rev_hash));
    	state final;int finalpos;
    	for(int i=0;i<9;i++){
    		char x;scanf(" %c",&x);
    		switch(x){
    			case 'W':final[i]=0;break;
    			case 'R':final[i]=1;break;
    			case 'B':final[i]=2;break;
    			case 'E':final[i]=6;finalpos=i;break;
			}
		}
		rev_front=0,rev_back=1<<8;
		for(int i=0;i<(1<<8);i++){
			int t=i;
			for(int j=0;j<9;j++)
				if(j==finalpos)
					rev_states[i][j]=6;
				else
					rev_states[i][j]=final[j]+(t%2)*3,t/=2;
			rev_pos[i]=finalpos;
			rev_step[i]=0;
			findhash_add(rev_hash,rev_next,rev_states,i);
		}
		if(gethash(rev_hash,rev_next,rev_states,states[0])>=0){
			printf("0\n");
			continue;
		}
		bool nosol=true;
		for(int i=1;i<=21;i++){
			int t=bfs(i);
			if(t>=0){
				printf("%d\n",t);
				nosol=false;
				break;
			}
		}
		if(!nosol) continue;
		for(int i=1;i<=9;i++){
			int t=rev_bfs(i);
			if(t>=0){
				printf("%d\n",t);
				nosol=false;
				break;
			}
		}
		if(nosol) printf("-1\n");
	}
	return 0;
}
