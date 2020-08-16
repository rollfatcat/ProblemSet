/* 給定涵蓋範圍最大值Ｍ和Ｔ組線段，輸出能覆蓋植物植披的最大範圍？
 * 對於每組線段只能選或不選，該線段的覆蓋範圍＝尾端-起點。
 * 解題關鍵：動態規劃(線段排序)＋BIT(實現㏒Ｎ查詢)
 * 更新某個線段時必須保證小於等於該線段的其他線段已經完成更新＝線段需要經過排序，依照起點再依照尾端。
 * BIT查詢：１到目前線段起點間最大的覆蓋範圍＋該線段的覆蓋範圍 試圖更新目前尾端的最大覆蓋範圍值。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=1e4;
const int MaxT=1e4;
int M, T;
int pos[MaxT][2];
int ord[MaxT];
int val[MaxT+1]={};
int BIT[MaxT+1]={};

bool compare(int a,int b){ return (pos[a][0]==pos[b][0])? pos[a][1]<pos[b][1]: pos[a][0]<pos[b][0]; }

inline int Query(int end,int out=0){
	for(int now=end; now>0; now^=now&-now)
		out=max(out,BIT[now]);
	return out;
}
inline void Update(int end,int v){
	for(int now=end; now<=M and BIT[now]<v; now+=now&-now)
		BIT[now]=v;
}
int main(){
 
  scanf("%d %d\n",&M,&T);
  for(int i=0;i<T;i++)
		scanf("%d %d\n",&pos[i][0],&pos[i][1]), ord[i]=i;
	sort(ord,ord+T,compare);
	
	int v, ans=0;
	for(int i=0;i<T;i++){
		v=Query(pos[ ord[i] ][0]);
		if(v+pos[ord[i]][1]-pos[ord[i]][0]>val[pos[ord[i]][1]]){
			val[pos[ord[i]][1]]=v+pos[ord[i]][1]-pos[ord[i]][0];
			ans=max(ans,val[pos[ord[i]][1]]);
			Update(pos[ord[i]][1],val[pos[ord[i]][1]]);
		}
	}
	printf("%d\n",ans);
}


