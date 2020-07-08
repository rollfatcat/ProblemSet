/* N2 排序
 * 依據各別字串的#反轉由小到大排列
 * #反轉＝字元大出現在字元小的前面。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=50;
const int MaxM=100;
char ss[MaxM][MaxN+2];
int ord[MaxM];
int cnt[MaxM];

int main(){
	int caseT, N, M;
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%d %d",&N,&M);
		for(int i=0;i<M;i++)
			ord[i]=i, scanf("%s",ss[i]);
		// 計算每個字串的逆數對(字母大的在前面的位置)
		for(int i=0;i<M;i++){
			cnt[i]=0;
			for(int j=0;j<N;j++)
				for(int k=j+1;k<N;k++)
					if(ss[i][j]>ss[i][k])
						cnt[i]++;
		}
		for(int i=1;i<M;i++)
			for(int j=i;j>0 and cnt[ord[j]]<cnt[ord[j-1]];j--)
					swap(ord[j-1],ord[j]);
		for(int i=0;i<M;i++)
			printf("%s\n",ss[ord[i]]);
	}
}