/* (錯誤) 先排序Ｘ軸座標，
 *        用BIT順向更新，找出落於目前這個點左下方的點數
 *        用BIT反向更新，找出落於目前這個點右上方的點數
 *        枚舉兩點時將右上角點的左下點數＋左下角點的右上點數(但上述方法僅適用左下對右上)
 *        第二筆測資，當點對是(1,2)和(3,5)時就不是，因為(5,1)不會被算到
 * (正解)枚舉右側點，再枚舉左側點時將落在上方和下方的兩部份分開討論
 */

#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

struct NODE{
  unsigned short x,y;
  NODE(unsigned short a=0,unsigned short b=0):x(a),y(b){}
  bool operator<(const NODE &rhs)const{ return x<rhs.x; }
}node[20000];

inline void scanShort(unsigned short &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  unsigned short N, K, x, y, maxy=0;
  scanShort(N);
  scanShort(K);
  for(int i=0;i<N;i++)
    scanShort(x),
    scanShort(y),
    node[i]=NODE(x+1,y+1),
    maxy=max(maxy,node[i].y);
  sort(node,node+N);

  short ans=20001;
  for(int i=0;i<N and ans!=K;i++){ // 枚舉右側點
    short UpC[64002]={};
    short DoC[64002]={};
    short Ucnt=0, Dcnt=0;
    /* 根據左側點的Ｙ軸座標是分佈在現在這個點的上方或下方討論(更新方向是i到0)
     * 要分成上下區間計算是避開每次要查詢從0到現在座標點內的點數
     * (1) 上方：將紀錄在UpC這棵BIT
     * (2) 下方：將紀錄在DoC這棵BIT
     */
    for(int j=i;j<N;j++)// 枚舉左側點
      if(node[j].y>=node[i].y){
        Ucnt++;
        // 更新BIT
        for(int idx=node[j].y;idx<=maxy;idx+=lowbit(idx))
          UpC[idx]++;
        if(Ucnt>=K){
          short sumc=0;
          for(int idx=node[j].y;idx;idx-=lowbit(idx))
              sumc+=UpC[idx];
          if(sumc>=K and sumc<ans)
              ans=sumc;
        }
      }
      else{
        Dcnt++;
        // 更新BIT
        for(int idx=node[j].y;idx<=node[i].y;idx+=lowbit(idx))
          DoC[idx]++;
        if(Dcnt>=K){
          short sumc=Dcnt;
          for(int idx=node[j].y;idx;idx-=lowbit(idx))
              sumc-=UpC[idx];
          if(sumc>=K and sumc<ans)
              ans=sumc;
        }
      }
    if(ans==K) break;
  }
  printf("%hu\n",ans);
}
/*
6
4
5 1
1 2
4 3
2 4
3 5
6 6
*/