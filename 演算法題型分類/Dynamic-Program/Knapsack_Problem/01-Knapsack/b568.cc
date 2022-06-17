#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
const int MaxA=7e5+1;
bool on[2][MaxA]={{1}};
int main(){
	int N, A;
	bool now=0, pre=1;
	
	scanf("%d",&N);
	for(int n=0; n<N; n++){
		scanf("%d",&A);
		swap(pre,now);
    // 這邊容易以為取模
		for(int v=0; v<A; v++)
			on[now][v]=on[pre][v]|on[pre][v-A+MaxA-1];
		for(int v=A; v<MaxA; v++)
			on[now][v]=on[pre][v]|on[pre][v-A];
	}
	for(A=MaxA-1; on[now][A]==0; A--);
	printf("%d",A);
}
