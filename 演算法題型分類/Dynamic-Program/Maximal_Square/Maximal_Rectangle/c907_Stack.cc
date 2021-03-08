/* 給定Ｎ個寬度為1單位的長條圖，求長條圖可以形成的最大矩形面積？
 * 解題關鍵：Stack-classic( sweep-line view )
 * 新高度加入時為了維護左側遞增的高度需要先把 "Container" 內高度大於新高度的部分 pop() 後在推入新高度 ... Stack
 * 上述的行為代表新高度會受限於 Container 內高度小於新高度中離他最近的
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int hgt[MaxN];

int main(){
	for(int C;scanf("%d\n",&C)!=EOF;){
		for(int i=0;i<C;i++)
			scanf("%d",&hgt[i]);
		int maxRec=0, prev;
		stack<int> S;
		for(int j=0;j<C;j++){
			for(prev=j; S.empty()==0 and hgt[S.top()]>hgt[j]; S.pop()){
				prev=S.top(),
				maxRec=max(maxRec,hgt[S.top()]*(j-prev));
			}
			S.push(prev);
			hgt[prev]=hgt[j];
		}
		for( ;S.empty()==0 and hgt[S.top()]>0; S.pop())
			maxRec=max(maxRec,hgt[S.top()]*(C-S.top()));
		printf("%d\n",maxRec);
	}
}