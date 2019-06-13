// 題解：https://www.pttdata.com/ResponesPage.php?u=/bbs/C_and_CPP/M.1424084048.A.7F3.html
/* 標準解是 Cartesian Tree，以下是另一種解法：https://ideone.com/dwEeRp
 * 利用排序取得中序尋訪，再利用輸入順序來解出 preorder
 * RMQ且不需要修改，只需要支援區間查詢找 Root => SparseTable( 84ms/10.1MB )
 */
#include<bits/stdc++.h>
using namespace std;

const int maxN=131072;
int N, ST[18][maxN];
struct nn{
  int order,num;
  bool operator<(const nn &other)const{ return num<other.num; }
}node[maxN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
void fake_preorder(int qL,int qR){ //---輸出順序：中左右---
  int h=__lg(qR-qL+1);
  int IL=ST[h][qL], IR=ST[h][qR-(1<<h)+1];
  int root_pos=(node[IL].order<=node[IR].order)?IL:IR; // 查詢 root_pos
  printf("%d ",node[root_pos].num);
  if(qL<root_pos) fake_preorder(qL,root_pos-1); // 左子樹存在
  if(qR>root_pos) fake_preorder(root_pos+1,qR); // 右子樹存在
}
int main(){
  while(scanInt(N)){
    for(int i=0;i<N;i++)
      node[i].order=i, scanInt(node[i].num);
    sort(node,node+N);
    // 這篇的重點技巧：---根據輸入順序作為判斷的依據建樹---
    for(int i=0;i<N;i++)
      ST[0][i]=i;
    for(int h=0; (1<<h)<N; h++) // h<㏒N
      for(int st=0; st+(1<<h)<=N; st++) // 有st但不保證ed會落在N以內(更新時會出問題)
        ST[h+1][st]=(node[ST[h][st]].order<=node[ST[h][st+(1<<h)]].order)? ST[h][st]: ST[h][st+(1<<h)];
    // ---區間查詢找區間查詢找到Root---
    fake_preorder(0,N-1);
    puts("");
  }
}