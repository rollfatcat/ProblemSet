/* 給定Ｎ顆寶石的顏色和Ｎ-1條路徑(樹架構)，若從節點０出發沿途蒐集寶石(但不能回頭)，最多可以蒐集到相同顏色的寶石個數？
 * 解題核心：
 *   寶石顏色號碼最大＝1e9但寶石最多 2e5顆 -> 離散化( map< ColorID, ColorCnt> )
 *   因為是樹的架構，走到葉節點時才需要判斷最多的寶石個數，但每走到一個節點時就可以更新 max_cnt
 *     max_cnt＝從根節點到目前節點時最多的數量
 *     回朔時要扣除該節點寶石顏色的數量
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
int org[MaxN];
int srt[MaxN];
vector<int> chd[MaxN];
int cnt[MaxN]={};
int ans=1;

void GoTree(int now,int max_cnt){
	cnt[ org[now] ]++;
	max_cnt=max(max_cnt,cnt[ org[now] ]);
	// 走到葉節點
	if(chd[now].size()==0) 
		ans=max(ans,max_cnt);
	for(int nxt:chd[now])
		GoTree(nxt,max_cnt);
	// 回朔時要扣除這個節點的寶石數量
	cnt[ org[now] ]--; 
}
int main(){
	int N, uN;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&org[i]), srt[i]=org[i];
	// 離散化
	sort(srt,srt+N);
	uN=unique(srt,srt+N)-srt;
	for(int i=0;i<N;i++)
		org[i]=lower_bound(srt,srt+uN,org[i])-srt;
	// 讀取整顆樹的架構
	for(int a,b,i=1;i<N;i++){
		scanf("%d %d\n",&a,&b);
		chd[a].push_back(b);
	}
	GoTree(0,0);
	printf("%d\n",ans);
}