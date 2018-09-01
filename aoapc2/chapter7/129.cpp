#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXL=100;
int n,l,c,len,s[MAXL];
bool check(int l){
	for(int ll=2;ll<=l+1;ll+=2){
		bool same=true;
		for(int i=l-ll+1;i<=l-ll/2;i++)
			if(s[i]!=s[i+ll/2]){
				same=false;
				break;
			}
		if(same) return false;
	}
	return true;
}
void search(int d){
	++c;
	//printf("search %d,already %d\n",d,c);
	//printf("now:");for(int i=0;i<d;i++) printf("%c",'A'+s[i]);printf("\n");
	if(c==n){
		len=d-1;
		return;
	}
	for(int i=0;i<l;i++){
		s[d]=i;
		if(check(d)) search(d+1);
		if(c==n) return;
	}
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    while(scanf("%d%d",&n,&l)==2&&n){
    	c=-1,len=0;
    	search(0);
    	for(int i=0;i<=len;i++){
    		if(i%4==0&&i)
    			if(i%64==0) printf("\n");
    			else printf(" ");
    		printf("%c",'A'+s[i]);
		}
		printf("\n%d\n",len+1);
	}
	return 0;
}

