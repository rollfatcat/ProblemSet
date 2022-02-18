/* 給定Ｎ個數字每次操作可以替換某個位置為任意的數字，目標是讓數列變為非嚴格遞減，輸出最少的操作次數？
 * 解題關鍵：找出數列中可以形成最長的非嚴格遞減，替換其他數字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxA=1e9;

int main(){
	int N, v;
	
	while(scanf("%d",&N)!=EOF){
		scanf("%d",&v);
		vector<int> s={v};
		for(int n=1; n<N; n+=1){
			scanf("%d",&v);
			if(s.back()<=v){
				s.push_back(v);
			}else{
				*upper_bound(s.begin(),s.end(),v)=v;
			}
		}
		printf("%d\n",N-s.size());
	}
}

