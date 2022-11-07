/* 給定Ｎ個飲料塔高度、每瓶飲料的單位高度、容許的落差高度值，保證相鄰的高度差在容許值內輸出最少要移除的飲料罐數？
 * 解題關鍵：更新順序
 * 根據題目的移除規則，高度最低的飲料塔不可能被更動，所以優先更新該飲料塔"周圍"。
 * 同樣的邏輯，最低飲料塔的狀態確保成立後再接著處理第二低的...，因此更新順序是依據高度低到高排序。
 * 成本均攤：每個飲料塔最多被更新２次(左右各一次)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxH=1e6;
int hgt[MaxN];
int ord[MaxN];
bool vis[MaxN]={};
int main(){
	int N, U, C;
	// input
	scanf("%d %d %d",&N,&U,&C);
	for(int n=0; n<N; n++)
		scanf("%d",&hgt[n]);
	iota(ord,ord+N,0);
	sort(ord,ord+N,[&](int lhs,int rhs){
		return hgt[lhs]<hgt[rhs]; });
	int tmp;
	long ans=0;
	for(int n=0; n<N; n++){
		if( vis[ord[n]] ) continue;
		vis[ ord[n] ]=1;
		for(int R=ord[n]; R+1<N and hgt[R]+C<=hgt[R+1]; R++){
			tmp =hgt[R+1]-hgt[R]-C; 
			tmp =tmp/U+(tmp%U>0)+(tmp==0); // 避免相同時多加一
			ans+=tmp;
			hgt[R+1]-=U*tmp;
			vis[R+1]=1;
		}
		for(int L=ord[n]; 0<=L-1 and hgt[L-1]>=hgt[L]+C; L--){
			tmp =hgt[L-1]-hgt[L]-C; 
			tmp =tmp/U+(tmp%U>0)+(tmp==0); // 避免相同時多加一
			ans+=tmp;
			hgt[L-1]-=U*tmp;
			vis[L-1]=1;
		}
	}
	printf("%ld",ans);
}