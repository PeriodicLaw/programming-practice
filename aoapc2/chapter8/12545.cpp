#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int solve(int n0,int n1,int nq0,int nq1){
	if(n0==n1)
		return n0+nq0+nq1;
	if(n0<n1)
		if(n1-n0<=nq1)
			return n0+(n1-n0)+nq0+nq1;
		else
			return -1;
	if(n0>n1)
		return n1+(n0-n1)+nq0+nq1;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int c;scanf("%d ",&c);
	for(int i=1;i<=c;i++){
		char s1[200],s2[200];
		gets(s1);gets(s2);
		int n0=0,n1=0,nq0=0,nq1=0;
		for(int j=0;j<strlen(s1);j++)
			if(s1[j]!=s2[j])
				if(s1[j]=='0') n0++;
				else if(s1[j]=='1') n1++;
				else if(s2[j]=='0') nq0++;
				else nq1++;
		printf("Case %d: %d\n",i,solve(n0,n1,nq0,nq1));
	}
	return 0;
}

