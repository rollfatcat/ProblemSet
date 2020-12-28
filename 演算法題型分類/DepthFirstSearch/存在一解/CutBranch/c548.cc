// 理論上惡意測資是無法通過，但這題只需要簡單剪枝即可
// 剪枝：將餘數由小到大排序，暴力法DFS枚舉所有可能，只要找到答案就停止搜索
// 正解：鴿籠原理，題目提到 2 ≦ K ≦ N，請見數論的鴿籠原理解法

#include<bits/stdc++.h>
using namespace std;

struct PG{
  int n, ID;
  PG(int rem=0,int ID=0):n(rem),ID(ID){}
  bool operator<(const PG &rhs)const{ return n<rhs.n; }
}pg[100001];
int N, K, bag[100001];
bool hasANS=0;

void DFS(int st,int bag_num,int sumn){
  if(sumn%K==0){
    hasANS=1;
    printf("%d\n",bag_num);
    for(int i=0;i<bag_num;i++)
      printf("%d ",bag[i]);
    putchar('\n');
    return;
  }
  for(int i=st;i<N and hasANS==0;i++)
    bag[bag_num]=pg[i].ID,
    DFS(i+1, bag_num+1, (sumn+pg[i].n)%K);
}
int main(){
  scanf("%d %d",&N,&K);
  for(int x,i=0;i<N;i++)
    scanf("%d",&x),
    pg[i]=PG(x%K,i+1);
  sort(pg,pg+N);
  for(int i=0;i<N;i++){
    bag[0]=pg[i].ID,
    DFS(i+1,1,pg[i].n);
    if(hasANS) break;
  }
  if(hasANS==0) puts("0");
}