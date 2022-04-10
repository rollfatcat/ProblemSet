#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxA=1e5;
int A[MaxN];
int main(){
	int N, L, H;
	// input
	scanf("%d",&N);
	for(int n=0; n<N; n++)
		scanf("%d",&A[n]);
	// monotonic stack
	int ans=0;
	stack<int> s;
	for(int n=0; n<N; n++){
		while(!s.empty() and A[s.top()]>=A[n]){
			H=A[s.top()]; s.pop();
			L=(s.empty())? -1: s.top();
			ans=max(ans,(n-L-1)*H);
		}
		s.push(n);
	}
	while(!s.empty()){
		H=A[s.top()]; s.pop();
		L=(s.empty())? -1: s.top();
		ans=max(ans,(N-L-1)*H);
	}
	printf("%d",ans);	
}