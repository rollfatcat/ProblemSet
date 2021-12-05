/* 存在Ｎ種口味的冰棒各一支和Ｋ位學生偏好的２種口味，輸出最少有幾位學生吃不到冰棒？
 * 可以自由調整學生拿取的順序但只要該口味還有就會(全數)拿走，目的是最小化吃不到冰棒的學生人數
 * 解題關鍵：DSU(查並集)
 * Ｎ種口味＝vertex 編號(1:Ｎ)，學生偏好的２種口味＝連接著２個 vertex 的 edge
 * 吃不到冰棒的學生＝這條 edge 加入集合後會形成環(cycle)，題目等於在問會造成 cycle 的邊數量？
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
const int MaxK=1e5;
int root[MaxN+1];
int FindRoot(int x){
	return root[x]==x ? x: root[x]=FindRoot(root[x]); }
bool Union(int a,int b){
	int Ra=FindRoot(a);
	int Rb=FindRoot(b);
	if(Ra==Rb) return true; // 合併失敗
	root[Rb]=Ra; return false; // 合併成功
}
int main(){
	int N, K, A, B;
	int ans=0;
	
	scanf("%d %d",&N,&K);
	iota(root,root+N+1,0);
	while(K-->0){
		scanf("%d %d",&A,&B);
		ans+=Union(A,B);
	}
	printf("%d",ans);
}