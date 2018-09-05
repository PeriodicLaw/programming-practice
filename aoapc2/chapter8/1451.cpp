#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<utility>
using namespace std;
const int MAXN=100010;
int s[MAXN],mq[MAXN],qf,qb,n,l;
typedef pair<int,int> rat;
inline bool operator<(const rat &x,const rat &y){
	return x.first*y.second<x.second*y.first;
}
inline bool operator==(const rat &x,const rat &y){
	return x.first*y.second==x.second*y.first;
}
inline bool operator<=(const rat &x,const rat &y){
	return x.first*y.second<=x.second*y.first;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d ",&n,&l);
		s[0]=0;qf=qb=0;
		rat kans=make_pair(-1,1);int lans=-1,rans=-1;
		for(int i=1;i<=n;i++){
			char c=getchar();
			s[i]=s[i-1]+(c=='1');
			if(i>=l){
				int j=i-l;
				rat k=make_pair(s[j]-s[mq[qb-1]],j-mq[qb-1]);
				for(;qf<qb-1;){
					rat k1=make_pair(s[j]-s[mq[qb-2]],j-mq[qb-2]);
					if(k<k1)
						k=k1,qb--;
					else
						break;
				}
				mq[qb++]=j;
			}
			if(qf<qb){
				rat k=make_pair(s[i]-s[mq[qf]],i-mq[qf]);
				for(;qf+1<qb;){
					rat k1=make_pair(s[i]-s[mq[qf+1]],i-mq[qf+1]);
					if(k<=k1)
						k=k1,qf++;
					else
						break;
				}
				if(kans<k||(kans==k&&(i-mq[qf]-1)<(rans-lans))){
					kans=k;
					lans=mq[qf]+1;
					rans=i;
				}
			}
		}
		printf("%d %d\n",lans,rans);
	}
	return 0;
}
