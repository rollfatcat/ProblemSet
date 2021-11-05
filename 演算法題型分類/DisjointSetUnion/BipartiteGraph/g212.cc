/* 給定一個平面上的點所組成的集合Ｓ。這個集合有個特性假設：若 (x1,y1)、(x1,y2)、(x2,y1) 都在集合內，則 (x2,y2) 也會自動被插入集合內。
 * 共給定 n 次操作，每次會將一個座標放進集合裡，請在每次操作後輸出集合大小。
 * 請注意，有可能會放一個已經在集合內的座標，此情況下集合大小不變。
 * 解題關鍵：DSU - connect(連通概念)
 * 需要計算２個維度每個點的連通關係(從２個維度各挑一點的所有組合) = 判斷 1th 維度內點可以抵達 2th 維度內的哪些點？
 * 因為存在"新關係"讓２群的點做 Union 時要先扣除本來２群可以形成的組合數再加上合併後的新組合數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxP=2e5;
int root[MaxN+1<<1];
int  cnt[MaxN+1<<1][2];
int FindRoot(int x){
	return root[x]==x? x: root[x]=FindRoot(root[x]); }
void Union(int a,int b,long& ans){
	int Ra=FindRoot(a);
	int Rb=FindRoot(b);
	// ２個點已經"連通"
	if(Ra==Rb) return;
	// ２個點屬於"非連通"，而需要對２群建立"連通關係"時要先扣除本來的組合，再加上新的組合數
	ans-=(long)cnt[Ra][0]*cnt[Ra][1]+(long)cnt[Rb][0]*cnt[Rb][1];
	root[Rb]=Ra;
	cnt[Ra][0]+= cnt[Rb][0];
	cnt[Ra][1]+= cnt[Rb][1];
	ans+=(long)cnt[Ra][0]*cnt[Ra][1];
}
int main(){
	// init
	for(int i=1;i<=MaxN;i+=1){
		root[i]=i;  root[i+MaxN]=i+MaxN;
		cnt[i][0]=1; cnt[i+MaxN][0]=0;
		cnt[i][1]=0; cnt[i+MaxN][1]=1;
	}
	int N, x, y;
	long ans=0;
	scanf("%d",&N);
	for(int i=0;i<N;i+=1){
		scanf("%d %d",&x,&y);
		Union(x,y+MaxN,ans);
		printf("%ld\n",ans);
	}
}