/* 給定涵蓋範圍最大值Ｍ和Ｔ組線段，輸出能覆蓋植物植披的最大範圍？
 * 對於每組線段只能選或不選，該線段的覆蓋範圍＝尾端-起點。
 * 解題關鍵：動態規劃(線段排序)
 * 更新某個線段時必須保證小於等於該線段的其他線段已經完成更新＝線段需要經過排序，依照起點再依照尾端。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=1e4;
const int MaxT=1e4;
int S[MaxT];
int E[MaxT];
int ord[MaxT];
int dpv[MaxM+1];

bool compare(int a,int b){ return S[a]==S[b]? E[a]<E[b]: S[a]<S[b]; }
/* 線性搜尋：從１到目前線段起始間 最大的覆蓋數，可用 RMQ 加速 */
int FindMaxDP(int start,int out=0){
	for(int i=1;i<=start;i++)
		out=max(out,dpv[i]);
	return out;
}
int main(){
	int M, T, v, ans;
	scanf("%d %d\n",&M,&T);
	for(int i=0;i<T;i++)
		scanf("%d %d\n",&S[i],&E[i]), ord[i]=i;
	sort(ord,ord+T,compare);
	fill(dpv+1,dpv+M+1,0);
	
	ans=dpv[ E[ord[0]] ]=E[ord[0]]-S[ord[0]];
	for(int ID,i=1;i<T;i++){
		ID=ord[i];
		v=FindMaxDP( S[ID] )+E[ID]-S[ID];
		dpv[ E[ID] ]=max(dpv[ E[ID] ],v);
		ans=max(ans,v);
	}
	printf("%d\n",ans);
}