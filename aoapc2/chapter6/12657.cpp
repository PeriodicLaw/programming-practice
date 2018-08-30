#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=100100;
int n,m,l[MAXN],r[MAXN];
int op,x,y,lx,rx,ly,ry;
long long sum;
bool rev;
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int tot=0,i,j;
    while(scanf("%d%d",&n,&m)==2){
    	++tot;
    	r[0]=1,l[n+1]=n;
    	for(i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
    	rev=false;
    	for(i=0;i<m;i++){
    		int op;scanf("%d",&op);
    		if(op==4) rev=!rev;
    		else{
    			scanf("%d%d",&x,&y);
    			if(rev&&op<=2) op=3-op;
    			lx=l[x],rx=r[x],ly=l[y],ry=r[y];
    			if(op==1&&ly==x) continue;
    			if(op==2&&ry==x) continue;
    			if(op==1){
    				r[lx]=rx;l[rx]=lx;
    				r[ly]=x;l[x]=ly;
    				r[x]=y;l[y]=x;
				}else if(op==2){
					r[lx]=rx;l[rx]=lx;
					l[ry]=x;r[x]=ry;
					l[x]=y;r[y]=x;
				}else if(op==3&&rx==y){ //HERE TLE
					r[lx]=y;l[ry]=x;
					l[x]=y;r[x]=ry;
					l[y]=lx;r[y]=x;
				}else if(op==3&&lx==y){ //HERE TLE
					r[ly]=x;l[rx]=y;
					l[x]=ly;r[x]=y;
					l[y]=x;r[y]=rx;
				}else if(op==3){
					r[lx]=y,l[rx]=y;
					r[ly]=x,l[ry]=x;
					l[x]=ly;l[y]=lx;
					r[x]=ry;r[y]=rx;
				}
			}
		}
		sum=0;
		if(rev)
			for(j=1,i=l[n+1];i>0;i=l[i],j++){
				if(j&1) sum+=i;
				i;
			}
		else
			for(j=1,i=r[0];i<=n;i=r[i],j++){
				if(j&1) sum+=i;
				i;
			}
		printf("Case %d: %lld\n",tot,sum);
	}
	return 0;
}

