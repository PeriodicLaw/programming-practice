#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
const int MAXD=16;
const long long power[MAXD]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
map<long long,int> dict;
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n;scanf("%d",&n);
    while(n--){
    	dict.clear();
    	int d=0,m=0;
    	scanf(" ");char c=getchar();
    	while(c!='\n'){
    		if(c=='[')
    			++d,c=getchar();
    		else if(c==']')
    			--d,c=getchar();
    		else if(c==',')
				c=getchar();
			else{
    			long long n=c-'0';
    			while((c=getchar())>='0'&&c<='9')
    				n=n*10+(c-'0');
    			++dict[n*power[d]];
    			++m;
			}
		}
		int max=0;
		for(auto it:dict)
			if(it.second>max)
				max=it.second;
		printf("%d\n",m-max);
	}
	return 0;
}

