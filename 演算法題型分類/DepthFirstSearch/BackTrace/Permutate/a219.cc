/* 給定Ｎ個人(編號為Ａ-Ｏ)以及Ｎ行代表每個人不想排的位置，依照字典序輸出所有的排列(只要輸出同個位置卻不同字元的部分)
 * 解題關鍵：Permutate + mask( maintain the pos can't be put. )
 * 只要輸出和「上一個字串」不同部分 ... 需要紀錄上一個字串的內容
 * 二維陣列紀錄哪個位置不能放置
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=15;
int N;
bool mask[MaxN][MaxN];
bool use[MaxN];
char pre[MaxN];
char ans[MaxN];
 
void Permutate(int depth){
	if(depth==N){ 
		for(int i=0;i<N;i++)
			if(ans[i]!=pre[i]){
				putchar(ans[i]);
				pre[i]=ans[i];
      }
		putchar('\n');
		return;
	}
	for(int i=0;i<N;i++)
		if(use[i]==0 and mask[i][depth]==0){
			use[i]=1;
			ans[depth]=i+'A';
			Permutate(depth+1);
			use[i]=0;
		}
}
 
int main(){
	while(scanf("%d\n",&N)!=EOF){
		/* set mask */
		for(int v,i=0;i<N;i++){
			pre[i]=use[i]=0;
			fill(mask[i],mask[i]+N,0);
			while(scanf("%d",&v) and v>0)
				mask[i][v-1]=1;
		}
		Permutate(0);
		putchar('\n');
	}
}