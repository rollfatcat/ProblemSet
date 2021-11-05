/* 給定Ｎ個蘋果派的分數，去除掉最高分和最低分後的Ｎ-2個平均值是否大於等於Ｔ？
 * 解題關鍵：迴圈搜尋極值
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;

int main(){
	int N, K, T, v;
	scanf("%d %d %d",&N,&K,&T);
	
	T=T*(K-2);
	bool has_ans=0;
	for(int p=0; p<N; p+=1){
		scanf("%d",&v);
		int min_v=v;
		int max_v=v;
		int prS_v=v;
		for(int i=1;i<K;i+=1){
			scanf("%d",&v);
			min_v=min(min_v,v);
			max_v=max(max_v,v);
			prS_v+=v;
		}
		prS_v=prS_v-min_v-max_v;
		if(prS_v>=T){ 
			printf("%d\n",p);
			has_ans=1;
		}
	}
	if(has_ans==0)
		puts("A is for apple.");
}

