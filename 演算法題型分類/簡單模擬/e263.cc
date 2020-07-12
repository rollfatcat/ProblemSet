/* 給定Ｎ位玩家、Ｍ張牌和九九的遊戲規則，模擬過程。
 * 若過程中並未違反規則則輸出最後的點數，反之輸出第一位違反規則的玩家。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e2;
const int MaxM=1e3;
char ss[10];
 
int main(){
 
	int N, M;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		int point=0;
		int player=1;
		int addv=1;
		while(M-->0){
			scanf("%s",ss);
			if(ss[0]=='A') point=0;
			if(ss[0]=='K') point=99;
			if(ss[0]=='Q') point+= (ss[1]=='+')? 20:-20;
			if(ss[0]=='1') point+= (ss[2]=='+')? 10:-10;
			if(ss[0]=='4') addv=-addv;
			if(ss[0]=='5'){ 
				player=ss[2]-'0';
				for(int i=3;ss[i]!=')';i++)
					player=(player<<3)+(player<<1)+ss[i]-'0';
				continue;
			}
			if(ss[0]=='2' or ss[0]=='3' or ss[0]=='6' or ss[0]=='7' or ss[0]=='8' or ss[0]=='9') point+=ss[0]-'0';
 
			if(point>99){ printf("%d cheated!\n",player); break; }
			if(point<0) point=0;
 
			player+=addv;
			if(player==0)   player=N;
			if(player==N+1) player=1;
		}
		if(M==-1) printf("The sum is %d\n",point);
		while(M-->0)
			scanf("%s",ss);
	}
}