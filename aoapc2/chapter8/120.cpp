#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=50;
int n,a[MAXN],b[MAXN];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;
	do{
		n=0;
		do{
			cin>>a[n++];
			while(cin.peek()==' ') cin.get();
		}while(cin.peek()!='\n'&&cin.peek()!=EOF);
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",a[i]);
		}printf("\n");
		while(cin.peek()=='\n') cin.get();
		for(int l=0;l<n;l++){
			int max=0,m=-1;
			for(int i=0;i<n-l;i++) if(a[i]>max) max=a[i],m=i;
			if(m==n-l-1) continue;
			if(m){
				printf("%d ",n-m);
				for(int i=0;i<=m;i++)
					b[i]=a[m-i];
				for(int i=0;i<=m;i++) a[i]=b[i];
			}
			printf("%d ",l+1);
			for(int i=0;i<n-l;i++) b[i]=a[n-l-i-1];
			for(int i=0;i<n-l;i++) a[i]=b[i];
		}
		printf("0\n");
	}while(cin.peek()!=EOF);
	return 0;
}

