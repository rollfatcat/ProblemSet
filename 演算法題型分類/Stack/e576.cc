#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxP=5e4;
const int MaxM=5e3;

int pos[MaxN+1][3];
int ord[MaxN];

int main(){
	int caseT, N, M;
	
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%d",&M);
		for(N=0; scanf("%d %d",&pos[N][0],&pos[N][1]); N+=1)
			if(pos[N][0]==0 and pos[N][1]==0)
				break;
		iota(ord,ord+N,0);
		sort(ord,ord+N,[&](int lhs,int rhs){
			return (pos[lhs][1]==pos[rhs][1])? pos[lhs][0]>pos[rhs][0]: pos[lhs][1]<pos[rhs][1];
		});
		
		vector<int> s; // stack 
		for(int o=0; o<N; o+=1){
			int n=ord[o];
			if(pos[n][1]<=0) continue;
			if(M<=pos[n][0]) continue;
			while(!s.empty() and pos[n][0]<=pos[s.back()][2])
				s.pop_back();
			if(s.empty() or pos[n][0]<=pos[s.back()][1]){
				pos[n][2]=(s.empty())? 0:pos[s.back()][1];
				s.push_back(n);
			}
		}
		while(!s.empty() and M<=pos[s.back()][2])
			s.pop_back();
		if(s.empty() or 0<pos[s[0]][0] or pos[s.back()][1]<M)
			s.clear();
		printf("%d\n",s.size());
		for(int x: s)
			printf("%d %d\n",pos[x][0],pos[x][1]);
		if(caseT)
			putchar('\n');
	}
}