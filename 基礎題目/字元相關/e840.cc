#include <bits/stdc++.h>
using namespace std;

const int MaxL=20;
char pass[MaxL+2];
int L, cnt[3];

int main(){
	while(scanf("%s\n",pass)!=EOF){
		L=strlen(pass);
		cnt[0]= pass[0]<='9';
		cnt[1]= 1-cnt[0];
		cnt[2]=0;
		for(int i=1;pass[i]!='\0';i++)
			if(pass[i]<='9'){
				cnt[0]++;
				cnt[2]+=pass[i-1]<='9';
			}else
				cnt[1]++;
		
		printf("%d\n",3*(L+cnt[1])+2*(cnt[0]-cnt[2])-((cnt[0]==0 or cnt[1]==0))*L+ ((L>=8 and cnt[0] and cnt[1])?10:-5) );
	}
}