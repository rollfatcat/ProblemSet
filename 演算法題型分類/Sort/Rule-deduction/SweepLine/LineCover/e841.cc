/* 給定Ｎ個寶箱和Ｍ次的操作，所有操作是同時完成(無順序差異)，輸出金幣最多的寶箱編號和金幣數量(金幣相同時取編號小)？
 * 每次操作為(ＰＱＲＳ)代表第Ｐ號到第Ｑ號寶箱內的金幣 Ｒ=１時增加Ｓ個/ Ｒ=２時多出Ｓ倍
 * 解題關鍵：掃描線＋降維處理
 * 區間增值＝入點和出點的變化量
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxM=1e6;
int add[MaxN+2]={};
int mul[MaxN+2];
int dvd[MaxN+2];
int main(){
	int N, M, P, Q, R, S;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N+1; i+=1)
		mul[i]=dvd[i]=1;
	while(M-->0){
		scanf("%d %d %d %d",&P,&Q,&R,&S);
		if(R==1){
			add[P]+=S;
			add[Q+1]-=S;
		}else{
			mul[P]*=S;
			dvd[Q+1]*=S;
		}
	}
 
	long adds=0;
	long muls=1;
	int ans_v=0;
	int ans_p=-1;
	for(int i=1; i<=N; i+=1){
		adds+=add[i];
		muls=muls*mul[i]/dvd[i];
		if(adds*muls>ans_v){
			ans_v=adds*muls;
			ans_p=i;
		}
	}
	printf("%d %d\n",ans_p,ans_v);
}
