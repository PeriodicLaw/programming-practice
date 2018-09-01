#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int puzzle[8];//-2:block,-1:puzzle,0~9:number
inline void readpuzzle(char *s,int x){
	int l=strlen(s);
	for(int i=0;i<l;i++)
		puzzle[x-1-i]=(s[l-1-i]=='*')?-1:s[l-1-i]-'0';
}
int maxd,count,num[8];
void unique(int d){
	if(d==4){
		if(num[0]==0||(num[0]<0&&num[1]==0)) return;
		if(num[2]==0||(num[2]<0&&num[3]==0)) return; //HERE WA
		int num1=(num[0]<0?0:num[0])*10+(num[1]<0?0:num[1]),num2=(num[2]<0?0:num[2])*10+(num[3]<0?0:num[3]),
			num3=num1*num2;
		if(num3>=10000) return;
		for(int i=7;i>=4;i--)
			if(num3&&puzzle[i]!=num3%10&&puzzle[i]!=-1)
				return;
			else if(!num3&&puzzle[i]>=-1) //HERE WA
				return;
			else num3/=10;
		++count;
		return;
	}
	if(puzzle[d]==-1)
		for(int i=0;i<=9;i++){
			num[d]=i;
			unique(d+1);
			if(count>1) return;
		}
	else
		num[d]=puzzle[d],unique(d+1);
}
bool dfs(int d,int x){
	if(d==maxd){
		count=0;
		unique(0);
		return count==1;
	}
	if(x>=8) return false;
	if(puzzle[x]==-2) return dfs(d,x+1);
	int t=puzzle[x];
	for(int i=-1;i<=9;i++){
		puzzle[x]=i; //HERE WA
		if(i==t){
			if(dfs(d,x+1)) return true;
		}else
			if(dfs(d+1,x+1)) return true;
	}
	puzzle[x]=t;
	return false;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    char s[100];int count=0;
	while(scanf(" %s",s)&&strcmp(s,"0")){
		for(int i=0;i<8;i++) puzzle[i]=-2;
		readpuzzle(s,2);
		scanf(" %s",s);readpuzzle(s,4);
		scanf(" %s",s);readpuzzle(s,8);
		for(maxd=0;;++maxd)
			if(dfs(0,0)){
				printf("Case %d: ",++count);
				for(int i=0;i<8;i++){
					if(i==2||i==4) printf(" ");
					if(puzzle[i]>=-1) printf("%c",puzzle[i]==-1?'*':'0'+puzzle[i]);
				}
				printf("\n");
				break;
			}
	}
	return 0;
}
