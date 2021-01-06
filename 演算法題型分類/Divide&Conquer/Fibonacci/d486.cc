/* 給定第Ｎ項費波那契數字，輸出整個分解過程(依照深度順序印出，相同的印在同一行)
 * 解題關鍵：Iterative Deepening Depth-First Search (IDS or IDDFS)
 * 枚舉深度，輸出某一行時只有目前深度是枚舉的限制或是已經是葉節點時才停止
 */
#include<bits/stdc++.h>
using namespace std;
 
int N, Depth;
int FIB[16]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
void IDDFS(int num,int now){
	if(num<=1 or now==Depth){ 
		printf("f(%d) ",num); 
		return;
	}
	IDDFS(num-1,now+1);
	IDDFS(num-2,now+1);
}
int main(){
	while(scanf("%d\n",&N) and N>0){
		for(Depth=0; Depth<N; putchar('\n'),Depth++)
			IDDFS(N,0);
		printf("f(%d) = %d\n\n",N,FIB[N]);
	}
}