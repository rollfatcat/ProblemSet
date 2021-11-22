/* 給定Ｎ位工作人員(只會屬於兩組中其一)和Ｍ段關係(Ａ和Ｂ必定屬於不同組別，保證不會矛盾)。
 * Ｐ位調查員紀錄有Ｋ段關係和已知的Ｍ段關係組合後是否會矛盾，輸出符合條件的調查員編號？
 * 解題關鍵：二分圖(DSU)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e4;
const int MaxM=2e4;
const int MaxP=1e4;
const int MaxK=20;

vector<int> root;
int FindRoot(int x){
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
bool Union(int a,int b,int N){
	int Ra=FindRoot( a );
	int Rb=FindRoot( b );
	int Ea=FindRoot(N+a);
	int Eb=FindRoot(N+b);
	if(Ra==Rb or Ea==Eb) return false;
	if(Ra!=Eb and Rb!=Ea){ 
		root[Eb]=Ra;
		root[Ea]=Rb;
	}
	return true;
}
int main(){
	int N, M, Q, K, a, b;
	scanf("%d %d",&N,&M);
	//
	for(int i=0; i<(N<<1); i+=1)
		root.push_back(i);
	while(M-->0){
		scanf("%d %d",&a,&b);
		Union(a,b,N);
	}
	vector<int> memo=root;
	scanf("%d %d",&Q,&K);
	for(int k,q=1; q<=Q; q+=1){
		bool troll=false;
		for(k=0; k<K; k+=1){
			scanf("%d %d",&a,&b);
			if(Union(a,b,N)==0){
				troll=true;
				break;
			}
		}
		if(troll){
			printf("%d\n",q);
			for(k+=1; k<K; k+=1)
				scanf("%d %d",&a,&b);
		}
		root=memo;
	}
}
 