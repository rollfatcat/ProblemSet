// 精準覆蓋問題(NP-Problem)，解法：Dancing Link(源於Ｘ演算法的基於稀疏矩陣的改良)
// 陣列只紀錄"1"，點數最多是1000x100
// 教學說明：http://www.cnblogs.com/grenet/p/3145800.html
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30

struct NODE{
  int L,R,U,D;
  int ch,rh;
} node[100001+1001]; // 多出來的部分是『輔助元素』
int cnt[1001];
// int rec[1001]; // 紀錄選取第 N Row
int R, C, head, size, minv;

inline void Remove(int col){ // 移除時只是改動連結位置，但移除節點的資訊並未消失
  node[ node[col].R ].L=node[col].L,
  node[ node[col].L ].R=node[col].R;
  for(int nowr=node[col].D; nowr!=col; nowr=node[nowr].D) // 固定同一個col
    for(int nowc=node[nowr].R; nowc!=nowr; nowc=node[nowc].R) // 固定同一個row
      node[ node[nowc].D ].U=node[nowc].U,
      node[ node[nowc].U ].D=node[nowc].D,
      cnt[ node[nowc].ch ]--;
}
inline void Resume(int col){
  for(int nowr=node[col].D; nowr!=col; nowr=node[nowr].D)
    for(int nowc=node[nowr].R; nowc!=nowr; nowc=node[nowc].R)
      node[ node[nowc].D ].U=nowc,
      node[ node[nowc].U ].D=nowc,
      cnt[ node[nowc].ch ]++;
  node[ node[col].R ].L=col,
  node[ node[col].L ].R=col;
}
void DancingLink(int num){
  if(num>minv){ return; }
  if(node[head].L==head){ minv=min(minv,num); return; }
  // 選擇『目前#元素最少』的Column展開
  int min_cnt=INF, min_col;
  for(int nowc=node[head].R; nowc!=head; nowc=node[nowc].R)
    if(min_cnt>cnt[nowc])
      min_cnt=cnt[nowc],
      min_col=nowc;
  Remove(min_col);
  for(int nowr=node[min_col].D; nowr!=min_col; nowr=node[nowr].D){ // 枚舉有這Column有1的每個Row
    // rec[num]=nowr; // 固定Column後紀錄選取的Row
    for(int nowc=node[nowr].R; nowc!=nowr; nowc=node[nowc].R) // 移除
      Remove( node[nowc].ch );
    DancingLink(num+1);
    for(int nowc=node[nowr].R; nowc!=nowr; nowc=node[nowc].R)
      Resume( node[nowc].ch );
  }
  Resume(min_col);
}
int main(){
  while(scanf("%d%d",&R,&C)==2){
    // init(); <- 產生根元素(head)和輔助元素(Column)
    head=size=0;
    for(int i=0;i<=C;i++)
      node[size+i].L=i-1,
      node[size+i].R=i+1,
      node[size+i].U=i,
      node[size+i].D=i,
      cnt[size+i]=0; //每一Column底下的#元素=0
    node[0].L=C,
    node[C].R=0;
    size+=C;
    // 根據輸入建構二維的雙向鏈結
    for(int N,i=1;i<=R;i++){
      scanf("%d",&N);
      for(int x,j=1;j<=N;j++)
        scanf("%d",&x),
        cnt[x]++,
        node[size+j].rh=i,
        node[size+j].ch=x,
        node[size+j].L=size+j-1,
        node[size+j].R=size+j+1,
        node[size+j].U=node[x].U,
        node[size+j].D=x,
        node[x].U=node[ node[x].U ].D=size+j;

      node[size+1].L=size+N,
      node[size+N].R=size+1;
      size+=N;
    }
    // Dancing Link
    minv=INF;
    DancingLink(0);
    // 輸出最少個數
    if(minv==INF) puts("No");
    else printf("%d\n",minv);
  }
}

/*
6 7
3 3 5 6
3 1 4 7
3 2 3 6
2 1 4
2 2 7
3 4 5 7

0 0 1 0 1 1 0
1 0 0 1 0 0 1
0 1 1 0 0 1 0
1 0 0 1 0 0 0
0 1 0 0 0 0 1
0 0 0 1 1 0 1

0  1  2  3  4  5  6  7
   0  0  8  0  9 10  0
  11  0  0 12  0  0 13
   0 14 15  0  0 16  0
  17  0  0 18  0  0  0
   0 19  0  0  0  0 20
   0  0  0 21 22  0 23

*/