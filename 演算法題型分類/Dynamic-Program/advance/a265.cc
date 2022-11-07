/* 給定Ｎ個點和Ｎ-1條邊構成該二元樹，輸入的邊由兩個數字組成(值介於[-100,100])代表父節點和子節點。
 * 核心關鍵：離散化＋中序走訪＋樹型動態規劃
 * 若該二元樹是合法的，輸出該樹可以形成"紅黑樹"的方法數。
 * (1) 判斷是否為合法的二元樹：
 *      將數字有負的且題目保證整棵樹的點數＜32，因此可以作離散化
 *      透過InOrder(左中右)的順序檢查數字是否由小到大
 *      走訪時需要從根節點(Root)開始，判斷Root＝沒有被指到的節點
 * (2) Merge時計算合法的紅黑樹方法數(動態規劃)
 *      所有狀態：需要紀錄該點的狀態是 RED/BLACK 和 以此為根節點時抵達葉節點的"黑點個數"
 *              dp[ 這個節點的號碼 ][ RED/BLACK ][ 從目前節點延伸出去的黑色節點個數 ]
 *      初始化：葉節點(數字31代表), dp[31][BLACK][1]=1, others=0
 *      狀態轉移：計算方法數時方法數為 #左×#右 (乘積)
 *              當該點為紅色時，左右兩個子節點必為黑色(紅黑樹定義)且長度不變
 *              當該點為黑色時，左右兩個子節點顏色任選但長度-1
 *      優化：觀察可以發現"從目前節點延升出去的黑色節點個數"和這個節點的高度有關
 *           且考慮到最高化的情況：在"平衡樹"時的架構下高度為＝５
 *  輸出的答案＝根節點(Root)為黑色時 所有的"從目前節點延伸出去的黑色節點個數"
 */
#include<bits/stdc++.h>
using namespace std;
#define BLK 0
#define RED 1
 
const int MaxN=32;
const int MaxP=1e2;
 
int org[MaxN<<1];
int srt[MaxN<<1];
int Lson[MaxN];
int Rson[MaxN];
int hgt[MaxN];
bool NotRt[MaxN];
 
int pivot;
int dp[MaxN][2][5+2];
 
inline int GetRoot(int NodeCnt,int now=0){
	for(;now<NodeCnt; now++)
		if(NotRt[now]==0)
			return now;
	return now;
}
 
inline bool InOrder(int now,bool flag=1){
	int Ls=Lson[now], Rs=Rson[now];
 
	if(Ls<31) flag&=InOrder(Ls);
	flag&= now==pivot++ ;
	if(Rs<31) flag&=InOrder(Rs);
	hgt[now]=min(hgt[ Ls ],hgt[ Rs ])+1;
	for(int h=hgt[now];h>0;h--){
		dp[now][RED][h]=dp[Ls][BLK][h]*dp[Rs][BLK][h];
		dp[now][BLK][h]=(dp[Ls][BLK][h-1]+dp[Ls][RED][h-1])*(dp[Rs][BLK][h-1]+dp[Rs][RED][h-1]);
	}
	return flag;
}
int main(){
 
	int NodeCnt;
	for(int caseI=1;scanf("%d\n",&NodeCnt)!=EOF;caseI++){
		if(NodeCnt==1){ printf("Case %d:1\n",caseI); continue; }
 
		for(int i=0;i<NodeCnt-1;i++){
			scanf("%d %d\n",&org[i<<1],&org[i<<1|1]);
			srt[ i<<1 ]=org[ i<<1 ];
			srt[i<<1|1]=org[i<<1|1];
		}
		sort(srt,srt+(NodeCnt-1<<1));
		unique(srt,srt+(NodeCnt-1<<1));
 
		fill(Lson,Lson+MaxN,31);
		fill(Rson,Rson+MaxN,31);
		fill(NotRt,NotRt+MaxN,0);
		for(int i=0;i<NodeCnt-1;i++){
			int prt=lower_bound(srt,srt+NodeCnt,org[ i<<1 ])-srt;
			int chd=lower_bound(srt,srt+NodeCnt,org[i<<1|1])-srt;
			NotRt[chd]=1;
			(prt>chd)? Lson[prt]=chd: Rson[prt]=chd;
		}
		int root=GetRoot(NodeCnt);
		memset(dp,0,sizeof(dp));
		hgt[31]=dp[31][BLK][1]=1;
		pivot=0;
		bool flag=InOrder(root);
 
		int cnt=0;
		for(int h=hgt[root];h>0;h--)
			cnt+=dp[root][BLK][h];
		printf("Case %d:%d\n",caseI,(flag)? cnt: 0);
	}
}