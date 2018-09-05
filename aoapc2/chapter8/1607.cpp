#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXM=200100;
int n,m,gate[MAXM][2];
bool input[MAXM],output[MAXM];
bool get(){
	for(int i=1;i<=m;i++)
		output[i]=((gate[i][0]>0?output[gate[i][0]]:input[-gate[i][0]])&&
		(gate[i][1]>0?output[gate[i][1]]:input[-gate[i][1]]))?false:true;
	return output[m];
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int d;scanf("%d",&d);
	while(d--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&gate[i][0],&gate[i][1]);
		for(int i=1;i<=n;i++) input[i]=false;
		bool x0=get();
		for(int i=1;i<=n;i++) input[i]=true;
		bool x1=get();
		if(x0==x1){
			for(int i=1;i<=n;i++)
				printf("0");
			printf("\n");
			continue;
		}
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2;
			for(int i=1;i<=mid;i++) input[i]=true;
			for(int i=mid+1;i<=n;i++) input[i]=false;
			bool x=get();
			if(x==x0)
				l=mid+1;
			else if(x==x1)
				r=mid;
		}
		for(int i=1;i<l;i++) printf("1");
		printf("x");
		for(int i=l+1;i<=n;i++) printf("0");
		printf("\n");
	}
	return 0;
}

