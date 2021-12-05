/* 給定Ｎ位報名者的交友關係，最大化入選人數(入選者彼此都不是朋友關係)？
 * 題目類比：圖論 - 相鄰的點不可同為黑色(但可以同為白色)，最大化可以塗黑的點數
 * 解題關鍵：深度優先搜尋 - DFS，枚舉每個點是否可以塗成黑色(不存在任一個檢查編號較小者和 ID 相連且已經塗黑)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=17;
bool link[MaxN][MaxN];
bool  use[MaxN]={};
int N, ans=0;

void DFS(int ID,int cnt){
	if(ID==N){ ans=max(ans,cnt); return; }
	bool use_friend=false;
	for(int n=0; n<ID; n+=1)
		use_friend|= link[ID][n]&use[n];
	
	if(use_friend==0){
		use[ID]=1;
		DFS(ID+1,cnt+1);
		use[ID]=0;
	}
	DFS(ID+1,cnt);
}
int main(){
	
	scanf("%d",&N);
	for(int r=0; r<N; r+=1)
		for(int c=0; c<N; c+=1)
			scanf("%d",&link[r][c]);
	DFS(0,0);
	printf("%d",ans);
}
