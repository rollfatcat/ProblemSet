// 解法類似d555，但是與定義Dominate的方式不同
// 所以排序規則和偵測方式需要略微調整
#include<bits/stdc++.h>
using namespace std;

const int MAXN=20000;
struct NODE{
  int x, y, n;
  bool operator<(const NODE &rhs)const{ return(x==rhs.x)?(y>rhs.y):(x<rhs.x); }
}node[MAXN+1];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int caseT, Nnode, origin;
  scanInt(caseT);
  while(caseT--){
    scanInt(Nnode),
    scanInt(origin);
    for(int i=1;i<=Nnode;i++)
      scanInt(node[i].x),
      scanInt(node[i].y),
      node[i].n=i;
    int x=node[origin].x,
        y=node[origin].y;
    // 只保留兩個座標值都大於題目指定點的座標時才保留
    int tot=0;
    for(int i=1;i<=Nnode;i++)
      if(node[i].x>x and node[i].y>y)
        node[tot++]=node[i];
    // 依據Ｘ軸由小到大排序，但Ｙ軸是由大到小(當Ｘ值相同時，這些點都屬於可能的選項)
    sort(node,node+tot);
    // 從尾端掃回去，不斷更新水平線，相同時也屬於可能的選項
    int base=-1;
    vector<int> ans;
    for(int i=tot-1;i>=0;i--)
      if(node[i].y>=base)
        ans.push_back(node[i].n),
        base=node[i].y;
    // 當新座標軸將原點設在題目給的點時導致沒有任何點落在第一象限時...
    // 水梨不會傳給其他水貍，最後仍留在一開始的水貍手中
    if(ans.empty()){ printf("1\n%d\n",origin); continue; }
    sort(ans.begin(),ans.end());
    printf("%lu\n",ans.size());
    for(auto x:ans)
      printf("%d ",x);
    puts("");
  }
}
/*
2
4 2
1 3
1 1
2 2
3 3

4 1
1 1
2 3
3 2
3 3
*/