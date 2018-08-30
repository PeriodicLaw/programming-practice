#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
const int MAXN=300;
struct data{
	int n;
	char s[MAXN];
};
int n;
data tree[MAXN];
bool comp(const data &x,const data &y){
	if(strlen(x.s)==strlen(y.s))
		return strcmp(x.s,y.s)<0;
	else
		return strlen(x.s)<strlen(y.s);
}
set<string> dict;
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	bool flag=false;scanf(" ");
    while(!feof(stdin)){
    	n=0;char s[MAXN];
    	memset(tree,0,sizeof(tree));
    	while(scanf("%s ",s)==1&&strlen(s)!=2){
    		s[strlen(s)-1]=0;
    		sscanf(s+1,"%d,%s",&tree[n].n,tree[n].s);
    		n++;
		}
		bool complete=true;
		dict.clear();
		for(int i=0;i<n;i++){
			string s1(tree[i].s);
			if(dict.find(s1)!=dict.end()){
				complete=false;
				break;
			}
			dict.insert(s1);
		}
		if(!complete){
			printf("not complete\n");
			continue;
		}
		for(int i=0;i<n;i++) if(strlen(tree[i].s)){
			string s1(tree[i].s);
			s1.erase(s1.length()-1);
			if(dict.find(s1)==dict.end()){
				complete=false;
				break;
			}
		}
		if(!complete){
			printf("not complete\n");
			continue;
		}
		sort(tree,tree+n,comp);
		for(int i=0;i<n;i++){
			if(i) printf(" ");
			printf("%d",tree[i].n);
		}
		printf("\n");
	}
	return 0;
}

