#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=17000;
const double INF=100000;
int p[MAXN];
double a[MAXN],b[MAXN],c[MAXN],s[MAXN][8];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n,count=0;
	while(scanf("%d",&n)==1&&n){
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
			s[i][0]=0;
			s[i][1]=a[i];
			s[i][2]=b[i];
			s[i][3]=c[i];
			s[i][4]=a[i]+b[i];
			s[i][5]=a[i]+c[i];
			s[i][6]=b[i]+c[i];
			s[i][7]=a[i]+b[i]+c[i];
		}
		double last=INF;
		int lastp=-1;
		bool nosol=false;
		for(int i=0;i<n;i++){
			int p;scanf("%d",&p);
			p--;
			if(nosol) continue;
			double max=-1,m=-1;
			for(int j=0;j<8;j++)
				if((p<lastp&&s[p][j]<last-1e-6)||(p>lastp&&s[p][j]<last+1e-6))
					if(s[p][j]>max)
						max=s[p][j],m=j;
			if(m==-1) nosol=true;
			last=max,lastp=p;
		}
		printf("Case %d: ",++count);
		if(nosol)
			printf("No solution\n");
		else
			printf("%.2lf\n",last);
	}
	return 0;
}
