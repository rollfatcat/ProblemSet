/* 給定Ｎ個店家位置，選定一個最佳停車點使得往返所有店家的距離總和越小越好，輸出距離總和？
 * 題解關鍵：最小化曼哈頓距離
 * 答案為最遠兩個端點的距離兩倍。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e2;
const int MaxN=20;
 
int main(){
	int caseT, N, pos;
 
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N);
 
		int min_pos=100;
		int max_pos=-1;
		for(int i=0;i<N;i++){
			scanf("%d",&pos);
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
		}
		printf("%d\n",(max_pos-min_pos)<<1);
	}
}