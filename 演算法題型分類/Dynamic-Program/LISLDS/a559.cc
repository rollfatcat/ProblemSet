/* 給定Ｋ個集合，每個集合中包含Ｎ個數字，輸出在"覆蓋限制下"能形成 #Col＝Ｎ時 #Row 最多的矩陣
 * "覆蓋限制"：第ｉ個 Row 當中的第ｊ個數字都大於[０,ｉ-1]個 Row 的第ｊ個數字。
 * 解題關鍵：排序＋(動態規劃)LIS
 * 		集合中的每個數字都要使用：可以對每個集合內的數字排序(小到大)
 * 			目的：形成最多的"覆蓋關係"
 * 		動態規劃處理前需要注意更新順序:必須把該集合可以覆蓋的所有集合都完成更新才處理該集合，
 * 			依照"字典序"排序(已經完成內部排序)每個集合
 * 			原因：覆蓋限制必定遵守字典序(反之不然)，所以至少要遵守字典序才有機會符合覆蓋限制
 * 		最多的 #Row ＝ LIS
 * 		狀態定義：從第０個 Row 到第ｉ個 Row 時可以形成的最長嚴格遞增子序列長度
 */
#include<bits/stdc++.h> 
using namespace std;

const int MaxN=20;
const int MaxK=2500;
int N, K;
int  LIS[MaxK];
int  ord[MaxK];
int data[MaxK][MaxN];
/* 字典序 */
bool compare(int a,int b){
	for(int i=0;i<N;i++)
		if(data[a][i]!=data[b][i])
			return data[a][i]<data[b][i];
	return true;
}
/* 覆蓋限制：檢測第ａ列的每個數字都大於第ｂ列的每個數字 */
bool cover(int a,int b){
	for(int i=0;i<N;i++)
		if(data[a][i]>=data[b][i])
			return false;
	return true;
}
int main(){
	int caseT;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&K,&N);
		for(int i=0;i<K;i++){
			ord[i]=i;
			for(int j=0;j<N;j++)
				scanf("%d",&data[i][j]);
			sort(data[i],data[i]+N);
		}
		/* 至少要符合"字典序"才會符合覆蓋限制 */
		sort(ord,ord+K,compare);
		/* Ｎ^2的 LIS 的更新方式，只要遵守"覆蓋限制"的集合就能夠做動態規劃的狀態轉移 */
		int ans=0;
		for(int i=0;i<K;i++){
			LIS[i]=0;
			for(int j=i-1;j>=0;j--)
				if(cover(ord[j],ord[i]))
					LIS[i]=max(LIS[i],LIS[j]);
			LIS[i]++;
			ans=max(ans,LIS[i]);
		}
		printf("%d\n",ans);
	}
}