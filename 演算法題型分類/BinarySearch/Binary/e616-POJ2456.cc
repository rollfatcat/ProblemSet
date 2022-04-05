/* 給定Ｎ個點代表牛可以放養的地點和Ｃ隻牛，輸出牛的相距間隔最大是多少？
 * 和基地台問題的差異：這題要求最大化間隔距離 而基地台在於最小化覆蓋範圍。
 * 解題關鍵：二分法
 * 單調性證明：間隔距離越小，可以放養的牛越多，反之間隔越大能放養的牛越少。
 *      函數：Ｃ提早用完時代表隔間距離太小，可以往大範圍挑戰。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxP=1e9;
int N, C;
int pos[MaxN];

/* 假設在目前間隔距離是 nR 的情況下，依照位置擺放Ｃ隻牛 
 * 起點一定先放一隻所以還有Ｃ-1隻牛需要配置
 * 當枚舉的點和前一個紀錄的位置( pos[pre] )相距大於等於testR時，代表這個位置可以再放一隻牛
 * 當分配的Ｃ隻牛都已經發完＝挑戰成功，反之失敗。
 */
inline bool challenge(int testR){
	int pre=0, cnt=C-1;
	for(int now=1;now<N;now++)
		if(pos[now]-pos[pre]>=testR){
			cnt--;
			pre=now;
			/* Ｃ隻牛都已經分配完，代表挑戰成功 */
			if(cnt==0)
				return true;
		}
	
	return false;
}
int main(){
	scanf("%d %d\n",&N,&C);
	for(int i=0;i<N;i++)
		scanf("%d",&pos[i]);
	sort(pos,pos+N);
	/* 左邊界＝最小間距，右邊界＝兩個極端位置的差距 */
	int nL=pos[1]]-pos[0];
	for(int i=2;i<N;i++)
		nL=min(nL,pos[i]-pos[i-1]);
	int nR=pos[N-1]-pos[0];
	int ans;	
	while(nL<=nR){
		int nM=nL+nR>>1;
		if( challenge(nM) )
			nL=nM+1, ans=nM;
		else
			nR=nM-1;
	}
	printf("%d\n",ans);
}