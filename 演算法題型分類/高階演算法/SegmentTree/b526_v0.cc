// 離散化+線段樹：http://cs.cysh.cy.edu.tw/php_system/acm_statistics/code.php?id=7005
// 線段樹離散化時需要注意重疊問題：
/* 题意：在墙上贴海报，海报之间可以相互重叠，问最后能看到几张海报。
 * 思路：海报的区间范围很大，但是海报总数不大，如果之间用海报的区间范围会超时，
 * 超内存，所以进行离散化。离散化的时候要注意：
 * 由于给定的是线段而不是点，因而需要注意重叠部分，普通的离散化会有问题：
 * 例子1：[1,10],[1,4],[6,10]
 * 例子2：[1,10],[1,4],[5,10]
 * 例子1,2的离散化都为[1,4],[1,2],[3,4]，但是，例子1中线段1不会被完全覆盖，例子2中线段1被完全覆盖
 * ，两者结果是不一样的，所以要对离散化进行调整。在相邻两个数间距大于1时添加一个数。
 * 例如[1,2,6,10],调整成[1,2,5,6,9,10]。然后再用线段树进行处理。这里线段树的区间只要保存最近更新的数是多少就好了。
 */
#include<bits/stdc++.h>
using namespace std;
int line_L[100005], line_R[100005];
int qL, qR, status;
bool segtr[800040]={}; // <- worstCase=4x(100000+100000)=800000
vector<int> node;
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void update(int nL,int nR,int pt){
  // lazy_update：不會更新到最底層的節點而是只要現在的範圍落在Query的範圍內即可
  if(nL>=qL and nR<=qR){  segtr[pt]^=1; return;  }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qL<=mid) update(   nL,mid,Lson);
  if(mid<qR)  update(mid+1, nR,Lson+1);
}
void Range_Check(int nL,int nR,int pt){
  if(segtr[pt]) status^=1;
  if(nL==nR) return; // 走到最底層的點時就回傳
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qL<=mid)
    return Range_Check(   nL,mid,Lson);
  return Range_Check(mid+1, nR,Lson+1);
}
int main(){
  int n, m;
  scanInt(n), scanInt(m);
  for(int i=0;i<m;i++)
    scanInt(line_L[i]),
    scanInt(line_R[i]),
    node.push_back(line_L[i]-1),
    node.push_back(line_R[i]);
  sort(node.begin(),node.end());
  node.push_back(n);
  // unique()：會讓重複的元素放到後面並回傳排序好不重複最後一個的元素位置
  // resize()：把重複的部分刪除
  node.resize( unique(node.begin(),node.end())-node.begin() );

  /* 以下的目的是離散化，不可能查表所以是二分法查值(也可用multiset實現)
   * 這邊是用內建二分法的 lower_bound() 達成
   */
  // 範例：https://blog.csdn.net/Quack_quack/article/details/48447293
  for(int i=0;i<m;i++)
    // BinarySearch，在升序排列的a数组内二分查找[l,r)区间内的值为m的元素
    // 1.如果m在区间中没有出现过，那么返回第一个比m大的数的下标。
    // 2.如果m比所有区间内的数都大，那么返回r。这个时候会越界，小心。
    // 3.如果区间内有多个相同的m，返回第一个m的下标。
    qL=lower_bound(node.begin(),node.end(),line_L[i])-node.begin(),
    qR=lower_bound(node.begin(),node.end(),line_R[i])-node.begin(),
    update(0,node.size()-1,1);

    int sit_pe=0;
    for(int i=1;i<node.size();i++){
      // 點對於區間的代表，所有的區間都被分割成(node[i-1], node[i]]
      status=0, qL=i;
      Range_Check(0,node.size()-1,1);
      if(status)
        sit_pe+=(node[i]-node[i-1]);
    }
    printf("%d\n",n-sit_pe);
}
/*
10 4
2 8
3 4
5 7
6 9
*/
// 1 2 4 5 7 8 9 10
// 0 1 0 0 1 0 1 0