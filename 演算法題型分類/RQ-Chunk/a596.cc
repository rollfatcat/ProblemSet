/* 給定Ｎ個數字，任意選擇３個以上的數字形成一個數列，跟數列的相鄰數字繪製成折線圖後能形成「拐點」的方法數？
 * 解題關鍵：動態規劃
 *   狀態定義：若要選定這個數字時要考量和前一個選定數字的關係而且這個關係為遞推相關。
 *      第ｉ個數字 × 選完該數字後是上升或下降關係(０=上升，１=下降)，紀錄的是該狀態下的方法數
 *   狀態轉移：
 *      DP[now][0] += DP[i][1], ０≤ｉ≤ now and org[i]<org[now]
 *      DP[now][1] += DP[i][0], ０≤ｉ≤ now and org[i]>org[now]
 * 問題盲點：上述的動態規劃需要利用雙層迴圈，而測資數太多導致 1e3×1500×1500＝2e9＝TLE
 * 問題轉換：如何避開雙層迴圈？類似 CountingSort 統計不同數字對應到的方法數。
 *          當查詢大於/小於某個數字的方法數總和時做分塊處理，這題的數字範圍最大到 30000 但數字個數只有 1500，做離散化加速。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e3;
const int MaxN=1500;
const int MOD=12345;
const int MaxChunk_size=40; // sqrt(MaxN)=38
 
int chunk[2][MaxChunk_size];
int one[2][MaxN];
int ord[MaxN];
int org[MaxN];
int cnt[MaxN];
 
int main(){
	int N, uN, Csz, CN;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d",&org[i]),
			ord[i]=org[i];
        /* 離散化：數字範圍最大是 30000，但數字的個數最多只有 1500 個 */
		sort(ord,ord+N);
		uN=unique(ord,ord+N)-ord;
		/* 計算 區塊大小 和 區塊的數量 */
        Csz=sqrt(uN);
		CN=uN/Csz;
        /* 初始化：清空所有的陣列數值 */
		memset(cnt,0,sizeof(cnt));
		memset(one,0,sizeof(one));
		memset(chunk,0,sizeof(chunk));
 
		int ans_cnt=0, toup, down;
		for(int i=0;i<N;i++){
			int tag=lower_bound(ord,ord+uN,org[i])-ord;
			int tID=tag/Csz;
			/* Chunk_Query：計算「大於」目前數字的方法數總和 */
			down=0;
			for(int i=CN;i>tID;i--) down+=chunk[0][i];
			for(int i=(tID+1)*Csz-1;i>tag;i--) down+= one[0][i];
			/* Chunk_Query：計算「小於」目前數字的方法數總和*/
			toup=0;
			for(int i=0;i<tID;i++) toup+=chunk[1][i];
			for(int i=tID*Csz;i<tag;i++) toup+=one[1][i];
            /* 若以目前的數字為「結束」時的方法數，但根據題目要求要排除「只有兩個點形成的上升或是下降關係」
             * 「只有兩個點形成的上升或是下降關係」＝目前的點數－相同數值的數量(不同必定能形成兩者關係之一)
             */
			ans_cnt=(ans_cnt+down+toup-(i-cnt[tag]))%MOD; 
			/* 更新資訊：這個數字的個數+1 並做 Chunk_Update */
            cnt[tag]++;
			one[0][tag]=(one[0][tag]+toup+1)%MOD;
			one[1][tag]=(one[1][tag]+down+1)%MOD;
			chunk[0][tag/Csz]=(chunk[0][tag/Csz]+toup+1)%MOD;
			chunk[1][tag/Csz]=(chunk[1][tag/Csz]+down+1)%MOD;
		}
		printf("%d\n",ans_cnt);
	}
}