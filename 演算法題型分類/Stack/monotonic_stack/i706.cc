/* 給定Ｎ個數字，輸出每個數字往左側搜尋時第一個碰到比自己小的值，對應的位置？
 * 解題關鍵： Monotonic Stack
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxH=1e9;
int s[MaxN];
int h[MaxN];

int main(){
	int N, cnt=0;
	
	scanf("%d",&N);
	for(int n=0; n<N; n++){
		scanf("%d",&h[n]);
		while(0<cnt and h[s[cnt-1]]>=h[n])
			cnt-=1;
		printf("%d ",(cnt==0)? 0: s[cnt-1]+1);
		s[cnt++]=n;
	}
}

