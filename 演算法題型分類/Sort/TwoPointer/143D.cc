#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e3;
const int MaxL=1e3;
int num[MaxN];

int main(){
	int N;
	
	scanf("%d",&N);
	for(int n=0; n<N; n+=1)
		scanf("%d",&num[n]);
	sort(num,num+N);
	int ans=0;
	for(int b=1; b<N; b+=1){
		int c=b+1;
		for(int a=0; a<b; a+=1){
			while(c<N and num[a]+num[b]>num[c])
				c+=1;
			ans+= c-b-1;
		}
	}
	printf("%d",ans);
}