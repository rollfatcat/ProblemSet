/* 給定編號１到Ｎ的群體和３種類型的操作方式如下，輸出對應的答案？
 * (1) １ Ｐ Ｑ：將Ｐ屬於的 set 和Ｑ屬於的 set 合併
 * (2) ２ Ｐ Ｑ：將Ｐ加入Ｑ屬於的 set。
 * (3) ３ Ｐ   : 輸出Ｐ屬於的 set 的組員人數和號碼總和。
 * 解題關鍵：DisjointSet-Union twist
 * 解題盲點：自己不一定會屬於自己編號的群體，如何實現操作２的"移除"。 
 * 操作１和３都是 DisjointSetUnion 會提供的功能。
 * 操作２：將Ｐ從原本所屬 set "移除"，"加入"Ｑ屬於的 set，如果Ｐ是根節點會出問題。
 *        將號碼Ｐ映射到屬於的 set，找到該 set 的代表：Ｐ -> team[P] -> FindRoot()。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
const int MaxM=1e5;
int team[MaxN+1]; // team[A]=編號Ａ成員屬於的群體
int root[MaxN+1]; // root[A]=編號Ａ群體的代表號碼
int size[MaxN+1]; // size[A]=編號Ａ群體的成員人數
int sumv[MaxN+1]; // sumv[A]=編號Ａ群體的號碼總和
 
int FindRoot(int x){ 
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
int main(){
	int N, M, opt, A, B;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		/* 初始化：成員Ａ屬於編號Ａ的群體且每個群體的成員人數＝１、號碼和＝自己編號 */
        for(int i=1;i<=N;i++)
			root[i]=team[i]=sumv[i]=i, size[i]=1;
		int root_A, root_B;
		while(M-->0){
			scanf("%d",&opt);
			switch(opt){
				case 1:
					scanf("%d %d\n",&A,&B);
					root_A=FindRoot(team[A]);
					root_B=FindRoot(team[B]);
					if(root_A==root_B) continue;
					if(size[root_A]<size[root_B])
						swap(root_A,root_B);
					root[root_B]=root_A;
					size[root_A]+=size[root_B];
					sumv[root_A]+=sumv[root_B];
					break;
				case 2:
					scanf("%d %d\n",&A,&B);
					root_A=FindRoot(team[A]);
					root_B=FindRoot(team[B]);
					if(root_A==root_B) continue;
					team[A]=root_B;
					size[root_A]--; sumv[root_A]-=A;
					size[root_B]++; sumv[root_B]+=A;
					break;
				case 3:
					scanf("%d\n",&A);
					root_A=FindRoot(team[A]);
					printf("%d %d\n",size[root_A],sumv[root_A]);
			}
		}
	}
}