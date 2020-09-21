/* 給定Ｎ個數字和Ｋ，輸出數列當中第Ｋ大的數字差？
 * 問題點：如何將第Ｋ大轉換為單調性的問題？"贏過"的數量＝全部組合數(任選２個做大減小)−Ｋ
 * 解題關鍵：二分法＋TwoPointer
 * 因為題目要從任兩點的數字差值中找到第Ｋ大，但Ｎ＝1e10 時組合數量＝5e9 個可能，在排序一定 TLE。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxA=1e9;
long N, K;
int num[MaxN];
bool Found_R;
/* TwoPointers(爬行法)：回傳在差距是Ｒ的情況下能夠贏過的其他組合數量 */
inline long TwoPointer(long R,long cnt=0){
	/* 初始設定：不存在差距Ｒ，因為已經需要回傳其他數值，所以將"是否存在差距Ｒ"設定為全域變數 */
	Found_R=false;
	int front=0;
	for(int back=1; back<N; back++){
		/* 區間差值大於等於Ｒ時，起點不斷右移 */
		while( num[back]-num[front]>=R ) 
			front++;
		/* 檢查差距Ｒ是否存在：存在front前一個且差值＝Ｒ */
		Found_R|= (front>0 and num[back]-num[front-1]==R);
		/* 只紀錄個數是小於差距內的組合數量 */
		cnt+=back-front;
	}
	return cnt;
}

int main(){
	
	while(scanf("%ld %ld\n",&N,&K)!=EOF){
		/* 第Ｋ大＝贏過全部組合數−Ｋ＋１
		 * EX：第５大 代表贏過１個的前提下數字越大越好。
		 */
		K= (N*(N-1)>>1) -K;
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		/* 排列的目的：為了用 TwoPointer 查詢當差距是否存在？ */
		sort(num,num+N);
		
		int nL=0;
		int nR=MaxK;
		int ans=0;
		while(nL<=nR){
			/* 當差距是 nM 時贏過的差距組合數量，count 和Ｋ的關係？ 
			 * 當(贏過的數量) count > Ｋ時，差距猜的太大需要縮小(右邊界左移)
		 	 * 當(贏過的數量) count ≦ Ｋ時，差距猜的太小需要放大(左邊界右移)
			 * 更新答案的條件：count ≦ Ｋ 並且 差距存在 的前提下猜測差距越大越好
			 */
			int nM=nL+nR>>1;
			long count=TwoPointer(nM);
			if(count<=K){
				/* 查詢猜測的差距是否真的存在，如果確實存在才能更新 */
				if(Found_R)
					ans=nM;
				nL=nM+1;
			}else
				nR=nM-1;
		}
		printf("%d\n",ans);
	}
}