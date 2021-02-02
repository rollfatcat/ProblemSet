/* 給定Ｎ個人(編號１~Ｎ)和Ｍ段朋友關係(兩人彼此的關係為相互)，Ｑ次查詢時輸出兩人是否為朋友？
 * 解題關鍵：DSU
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxM=1e4;
const int MaxQ=1e5;

int root[MaxN+1];
int FindRoot(int x){ 
	return(root[x]==x)?x:FindRoot(root[x]); }
int main(){
  int N, M, Q; 

  while(scanf("%d %d %d\n",&N,&M,&Q)!=EOF){
    for(int i=1;i<=N;i++)
      root[i]=i;
    for(int a,b; M--; ){
      scanf("%d %d\n",&a,&b);
      int rootA=FindRoot(a);
      int rootB=FindRoot(b);
      if(rootA==rootB) continue;
      root[rootB]=rootA;
    }
    
    for(int a,b; Q--; )
      scanf("%d %d\n",&a,&b), 
      puts( (FindRoot(a)==FindRoot(b))?":)":":(" );
  }
}