/* 給定Ｎ集動畫的硬碟編號和支援Ｍ個插槽，輸出最少化更換硬碟的次數？
 * 解題關鍵：Inverse-Mapping + Greedy + set
 * Inverse-Mapping : 需要紀錄"使用到同一個硬碟"的下一次時機 ... 陣列紀錄"這個硬碟編號"上次使用的時機
 * Greedy : 當插槽滿的時候移除"下次更換時間最遠的硬碟"，並加入現在這個硬碟
 * set : 維護插槽中使用的硬碟編號和下次時機，根據下次時機排序
 *       需要支援 找到最大值 /刪除硬碟編號 /加入硬碟編號
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxM=1e4;
const int MaxA=1e5;//  0 ≤ 硬碟編號 ≤ 1e5
const int MaxcaseT=10;

int dsk[MaxA+1];
int esp[MaxN];
int nxt[MaxN];
int main(){
	int caseT, N, M, v;
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%d %d",&N,&M);
		// 初始化 : 每個硬碟編號"上次使用時機"為 -1
		fill(dsk,dsk+MaxA+1,-1);
		// 依順序讀取硬碟編號，並同步紀錄下次使用的時機
		for(int i=0;i<N;i+=1){
			scanf("%d",&v);
			if(dsk[v]>=0)
				nxt[ dsk[v] ]=i;
			dsk[v]=i;
			esp[i]=v;
			nxt[i]=N;
		}
		// 初始化 : 每個硬碟是否已經處於插槽，值＝０代表不存在
		int *InS=dsk;
		fill(InS,InS+MaxA+1,0);
		set< vector<int> > memo;
		int cnt=0;
		for(int i=0;i<N;i+=1){
			// 硬碟已經接在插槽 : update = remove + insert
			if( InS[ esp[i] ]<0 ){ 
				memo.erase(memo.find( {InS[esp[i]],esp[i]} ));
			}else if(memo.size()==M){ // 硬碟不在插槽且插槽已滿 : 移除"下次更換時間最遠的硬碟"
				cnt+=1;
				vector<int> out= *memo.begin();
				memo.erase(memo.begin());
				InS[ out[1] ]=0;
			}
			// 更新這個硬碟加入插槽的時機
			InS[ esp[i] ]=-nxt[i];
			memo.insert({-nxt[i],esp[i]});
		}
		printf("%d\n",cnt);
	}
}