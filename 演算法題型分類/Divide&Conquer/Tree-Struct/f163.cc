/* 給定Ｎ個系統貨櫃和Ｍ個依序放入系統中的物品重量，輸出Ｍ個物品抵達的底層貨櫃編號？
 * 第二行代表底層貨櫃編號 Ｎ - 2Ｎ-1 的貨櫃(leaf)初始時已裝有的物重
 * 第三行代表Ｍ個物品依序放入系統中(必定是先放入編號１的系統貨櫃)，並依照下述規則分裝。
 * 分裝規則：物品會選擇左右分支(若存在)選擇總重量較輕的一邊(編號小的)直到底層貨櫃。
 * 解題關鍵：Divide & Conquer(divide only) + TreeStruction
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxM=1e4;
const int MaxSumW=1e9;
 
int Lson[MaxN<<1]={};
int Rson[MaxN<<1]={};
int sum_w[MaxN<<1];
int obj_w[MaxM];
 
void Build_Tree(int now){
	if(Lson[now]==0 and Rson[now]==0) 
        return;
	if(Lson[now]){ 
		Build_Tree(Lson[now]);
		sum_w[now]+=sum_w[Lson[now]];
	}
	if(Rson[now]){ 
		Build_Tree(Rson[now]);
		sum_w[now]+=sum_w[Rson[now]];
	}
}
void Query_Tree(int now,int& qw){
	sum_w[now]+=qw;
	if(Lson[now]==0 and Rson[now]==0){
		printf("%d ",now);
		return;
	}
	(sum_w[Lson[now]]<=sum_w[Rson[now]])? Query_Tree(Lson[now],qw): Query_Tree(Rson[now],qw);
}
 
int main(){
	int N, M, a, b, c;
 
	scanf("%d %d\n",&N,&M);
	for(int i=N;i<(N<<1);i++)
		scanf("%d",&sum_w[i]);
	for(int i=0;i<M;i++)
		scanf("%d",&obj_w[i]);
	for(int i=1;i<N;i++){
		scanf("%d",&a);
		scanf("%d %d\n",&Lson[a],&Rson[a]);
	}
	Build_Tree(1);
	for(int i=0;i<M;i++)
		Query_Tree(1,obj_w[i]);
}