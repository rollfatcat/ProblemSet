/* 給定Ｎ個數字，輸出數列當中數字差的中位數？
 * 問題點：如何將中位數轉換為單調性的問題？"贏過"的數量＝全部組合數(任選２個做大減小)的一半
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
	int front=0, back=0;
	for(long bound; back<N; front++){
		/* 從上一次的指標繼續往下移動直到目前作為終點的數字和起點差值 ≦ Ｒ */
    for(bound=num[front]+R;back<N and num[back]<bound; back++);
		/* 檢查差距Ｒ是否存在？每次執行前要歸零 */
    Found_R|= (num[back]-num[front])==R;
    /* 只紀錄個數是小於差距內的組合數量 */
		cnt+=back-1-front;
	}
  /* 剩餘的組合＝目前起點到最後一個點之間可以形成的組合數量 */
	long rem=N-front;
	return cnt+(rem*(rem-1)>>1);
}


int main(){
	
	while(scanf("%ld\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		/* 排列的目的：為了用 TwoPointer 查詢當差距是否存在？ */
    sort(num,num+N);
		/* 中位數＝贏過全部組合的一半 
     * 全部組合=３＝中位數是第２大＝要贏過１個
     * 全部組合=４＝中位數是第２大＝要贏過１個
     */
		K=N*(N-1)>>1;
		K=K-1>>1;
		
    
		int nL=1;
		int nR=MaxA;
		int ans=0;
		while(nL<=nR){
			/* 當差距是 nM 時贏過的差距組合數量，count 和Ｋ的關係？ 
       * 當(贏過的數量) count > Ｋ時，差距猜的太大需要縮小(右邊界左移)
       * 當(贏過的數量) count ≦ Ｋ時，差距猜的太小需要放大(左邊界右移)
       * 更新答案的條件：count ≦ Ｋ 並且 差距存在 的前提下猜測差距越大越好
       */
      int nM=nL+nR>>1;
			long count=TwoPointer(nM);
			if(count>K)
				nR=nM-1;
			else{
				nL=nM+1;
				/* 查詢猜測的差距是否真的存在，如果確實存在才能更新 */
        if(Found_R)
					ans=nM;
			}
		}
		printf("%d\n",ans);
		
	}
}
