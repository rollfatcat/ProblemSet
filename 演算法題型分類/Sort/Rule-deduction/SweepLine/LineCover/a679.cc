#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=3e4;

vector<vector<int>> line(MaxN,vector<int>(2));
int ord[MaxN];

bool compare(int lhs,int rhs){ 
	return line[lhs][1]<line[rhs][1]; }

int main(){
	int N, p, ans;
	
	for(int caseI=1; scanf("%d",&N)!=EOF; caseI+=1){
		for(int n=0; n<N; n+=1)
			scanf("%d %d",&line[n][0],&line[n][1]);
		sort(line.begin(),line.begin()+N);
		iota(ord,ord+N,0);
		sort(ord,ord+N,compare);

		ans=N*(N-1);
		p=0;
		for(int n=0; n<N; n+=1){
			while(p<N and line[p][0]<line[ord[n]][1])
				p+=1;
			ans-=N-p;
		}
		p=0;
		for(int n=0; n<N; n+=1){
			while(p<N and line[ord[p]][1]<=line[n][0])
				p+=1;
			ans-=p;
		}
		printf("Case %d: %d\n",caseI,ans>>1);
	}
}