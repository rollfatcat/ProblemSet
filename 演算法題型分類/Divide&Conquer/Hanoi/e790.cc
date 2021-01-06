/* 河內塔Ｎ個盤子的第Ｔ步驟的移動方式？
 * 解題關鍵：分治法(遞迴查詢) 或是 BottomUp 簡化查詢範圍
 * 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=60;
void Hanoi(int ths,int st,int tmp,int ed,long T){
	long cut=(long)1<<ths-1;
	if(T<cut){ Hanoi(ths-1,st,ed,tmp,T); return; }
	if(T>cut){ Hanoi(ths-1,tmp,st,ed,T-cut); return; }
	printf("move %d from %d to %d\n",ths,st,ed);
}

int main(){
	int N;
	long T;
	while(scanf("%d %ld\n",&N,&T)!=EOF){
		for(int st=1,tmp=2,ed=3;T>0;N--){
			long cut=(long)1<<N-1;
			if(T==cut){ 
				printf("move %d from %d to %d\n",N,st,ed); break;
			}else if(T>cut)
				swap(st,tmp), T-=cut;
			else
				swap(tmp,ed);
		}
	}
}