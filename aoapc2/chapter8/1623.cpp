#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=1000100;
struct node{
	int sunday,equal,next;
}list[MAXN];
int nlist,lastlist;
void init(){
	nlist=1;lastlist=0;
	list[0].sunday=-1;
	list[0].equal=-1;
	list[0].next=-1;
}
int newnode(int sunday){
	list[nlist].sunday=sunday;
	list[nlist].equal=-1;
	list[nlist].next=-1;
	list[lastlist].next=nlist;
	lastlist=nlist;
	nlist++;
	return nlist-1;
}
void merge(int a){
	int b=list[a].next;
	list[b].equal=a;
	list[a].next=list[b].next;
	if(lastlist==b) lastlist=a;
}
void del(int a){
	if(lastlist==list[a].next) lastlist=a;
	list[a].next=list[list[a].next].next;
}
int n,m,nsun,sunday[MAXN],prev[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++) prev[i]=0;
		nsun=0;
		bool nosol=false;
		for(int i=0;i<m;i++){
			int day;scanf("%d",&day);
			if(nosol) continue;
			if(day==0){
				newnode(nsun);
				sunday[nsun++]=0;
			}else{
				int p=prev[day];
				while(list[p].equal>=0)
				p=list[p].equal;
				while(list[p].next>=0&&list[list[p].next].sunday<0)
					merge(p);
				if(list[p].next<0){
					printf("NO\n");
					nosol=true;
					continue;
				}
				int s=list[list[p].next].sunday;
				sunday[s]=day;
				del(p);
				prev[day]=newnode(-1);
			}
		}
		if(nosol) continue;
		printf("YES\n");
		for(int i=0;i<nsun;i++){
			if(i) printf(" ");
			printf("%d",sunday[i]);
		}
		printf("\n");
	}
	return 0;
}