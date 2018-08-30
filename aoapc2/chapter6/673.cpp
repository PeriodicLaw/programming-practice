#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXL=300;
int s[MAXL];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    char s[300];gets(s);
    int n;sscanf(s,"%d",&n);
    while(n--){
    	gets(s);
    	int l=strlen(s),m=0;
    	bool ok=true;
    	for(int i=0;i<l;i++)
    		if(s[i]=='(') s[m++]=1;
    		else if(s[i]=='[') s[m++]=2;
    		else if(s[i]==')'){
    			if(s[m-1]==1) m--;
    			else{ok=false;break;}
			}else if(s[i]==']'){
				if(s[m-1]==2) m--;
				else{ok=false;break;}
			}
		if(m>0) ok=false;
		printf(ok?"Yes\n":"No\n");
	}
	return 0;
}

