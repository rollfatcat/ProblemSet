/* 給定２個遞增數列包含Ｎ個，在已知Ｘ店的出戰名單的順序(該遞增數列)時Ｙ店可以獲得最多勝場？
 * 解題關鍵：利用遞增的特性，雙指標實作貪婪
 * 枚舉Ｙ數列中由高到低的數字，對應Ｘ數列中挑出低於目前 Ay 時最大的 Ax，
 * 下一個 Ay 需要搜尋時可以從上次的位置再往更小的 Ax 找，整體時間為 O(N)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
int num[2][MaxN];
int main(){
	int N;
	
	scanf("%d",&N);
	for(int i=0;i<N;i+=1)
		scanf("%d",&num[0][i]);
	for(int i=0;i<N;i+=1)
		scanf("%d",&num[1][i]);

	int ans=0;
	for(int p0=N-1,p1=N-1; p1>=0; p1-=1){
		while(0<=p0 and num[0][p0]>=num[1][p1])
			p0-=1;
		if(p0==-1) break;
		ans+=1;
		p0-=1;
	}
	printf("%d\n",ans);
}

