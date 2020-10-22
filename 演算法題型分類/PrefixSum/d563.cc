/* 給定Ｎ個數字，輸出前綴和＝後綴和的數量？
 * 解題關鍵：TwoPointer
 * 比對"從開始到目前指標(front)的前綴和值" "從尾端到目前指標(back)的後綴和值"，
 * 相等時代表存在一組相同解，因為數字最少是１所以兩個指標一起"前進移動"。
 * 否則根據總和較少的一邊，指標移動一格。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int num[MaxN];
int main(){
	int N, ans=0;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);
	int PreS=0, front=0;
	int SufS=0, back=N-1;
	while(front<N and back>=0){
		if(PreS>SufS)
			SufS+=num[back--];
		else if(PreS<SufS)
			PreS+=num[front++];
		else{ // PreS==SufS
			PreS+=num[front++];
			SufS+=num[back--];
			ans++;
		}
	}
	printf("%d\n",ans);
}