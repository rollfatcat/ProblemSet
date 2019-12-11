/* 經典 Nim 問題
 * 拿到最後一顆石頭＝winner, Stan 先手
 * 雙方只能從集合中選出的數字作為移動步數( 且集合必定包含{1} )
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1000000;
const int MaxM=10;
int  num[MaxM];
bool win[MaxN+1]={};

int main(){
	int N, M;
	char ch;
	while(scanf("%d",&N)!=EOF){
		scanf("%c%d%c",&ch,&M,&ch);
		for(int i=0;i<M;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<=N;i++){
			win[i]=0;
			for(int j=0;j<M;j++)
				if(i-num[j]>=0)
					win[i]|=!(win[i-num[j]]);
		}
		puts((win[N])? "Stan wins":"Ollie wins");
	}	
}