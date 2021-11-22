/* 給定Ｎ根木棍需要製作成Ｍ副筷子，最大化筷子長度時應該是多少？
 * 解題關鍵：二分法
 * 滿足Ｍ副筷子＝至少存在 2M 支長度相同的筷子，猜測筷子長度
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxM=1e5;
const int MaxV=1e9;

int N, M;
int len[MaxN];
bool check(int nM){
	int cnt=0;
	for(int n=0;n<N;n+=1)
		cnt+= len[n]/nM;
	return cnt>=(M<<1);
}
int main(){
	scanf("%d %d",&N,&M);
	for(int n=0; n<N; n+=1)
		scanf("%d",&len[n]);
	int ans;
	int nL=1;
	int nR=MaxV;
	while(nL<=nR){
		int nM=nL+nR>>1;
		if( check(nM) ){
			ans=nM;
			nL=nM+1;
		}else
			nR=nM-1;
	}
	printf("%d\n",ans);
}