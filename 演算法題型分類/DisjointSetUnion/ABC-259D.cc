/* 給定Ｎ個圓的座標和半徑和２個點ＳＴ的座標，判斷Ｓ能否透過Ｎ個圓周的軌跡移動到Ｔ？
 * 解題關鍵：點Ｓ能否透過Ｎ個圓抵達點Ｔ＝連通
 * 根據圓心和半徑判斷兩個圓是否有交點(除非外離和內離) ... |r1-r2| ≤ dis(O1,O2) ≤ r1+r2
  */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e3;
const int MaxP=1e9;
long x[MaxN+2];
long y[MaxN+2];
long r[MaxN+2];
int root[MaxN+2];
int FindRoot(int x){
	return root[x]==x ? x: root[x]=FindRoot(root[x]); }
bool overlap(int a,int b){
	long D=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
	return (r[a]-r[b])*(r[a]-r[b])<=D and D<=(r[a]+r[b])*(r[a]+r[b]);
}
int main(){
	int N;
	
	scanf("%d",&N);
	scanf("%ld %ld",&x[0],&y[0]); r[0]=0; root[0]=0;
	scanf("%ld %ld",&x[1],&y[1]); r[1]=0; root[1]=1;
	for(int n=2; n<N+2; n++){
		root[n]=n;
		scanf("%ld %ld %ld",&x[n],&y[n],&r[n]);
		for(int i=0; i<n; i++){
			if( overlap(i,n)==0 )
				continue;
			int Ri=FindRoot(i);
			int Rn=FindRoot(n);
			if(Ri==Rn) continue;
			root[Rn]=Ri;
		}
	}
	puts( FindRoot(0)==FindRoot(1)? "Yes":"No" );
}