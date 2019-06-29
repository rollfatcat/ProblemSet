// 查並集的應用
/* 題目問說是否能左右相連，但是反過來則是上下邊界是否會從不相連變成相連。
 * 多設兩個虛點，我們假想所有上界點都與虛上點相連，下界點都與虛下點相連，
 * 每次一次加入一個障礙物時，檢查九宮格內是否會造成上下虛點相連，
 * 這裡必須先偷看并查集的結果，隨後在考慮是否將其相連。
 * (1) 父節點的二維位置(轉為一維座標後較方便記錄)
 * (2) use[x][y]=caseN 這個陣列標記紀錄的是這位置是第幾次case用到的
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1001;
const int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};
int parent[MAXN*MAXN];
int wght[MAXN*MAXN];
struct NODE{
  int x, y, p;
  NODE(int a=0,int b=0,int c=0):x(a),y(b),p(c){}
}now, nxt[8];
int use[MAXN][MAXN];

inline int GetP(int x){ return(parent[x]==x)? x: parent[x]=GetP(parent[x]); }
inline void unite(int x,int y){
  x=GetP(x),
  y=GetP(y);
  if(x==y) return; // 同個父節點時就不Merge
  if(wght[x]>=wght[y]) wght[x]+=wght[y], parent[y]=x;
  else                 wght[y]+=wght[x], parent[x]=y;
}

int main(){
  int R, C, Q;
  for(int caseN=1;scanf("%d",&R)!=EOF;caseN++){
    scanf("%d",&C);
    scanf("%d",&Q);
    // init
    for(int i=0;i<R*C+10;i++)
      parent[i]=i, wght[i]=1;
    int Top=R*C+1, Down=R*C+2;

    while(Q--){
      scanf("%d %d",&now.x,&now.y),
      now.p=now.x*C+now.y;
      Top=GetP(Top),
      Down=GetP(Down);

      // 偵測8個鄰居點
      int state=0;
      for(int i=0;i<8;i++){
        nxt[i]=NODE(now.x+dx[i],now.y+dy[i]);

        // 超過左右邊界時，將父節指向自己
        if(nxt[i].y<0 or nxt[i].y>=C){ nxt[i].p=now.p; continue; }
        /* 超過上下邊界時分情況討論：
         * (1)超過上界：Top
         * (2)超過下界：Down
         * (3)範圍內節點：若該節點這次的case標記的代表這格應該指向自己
         */
        if(0>nxt[i].x)      nxt[i].p=Top,  state|=1;
        else if(nxt[i].x>=R)nxt[i].p=Down, state|=2;
        else{
          if(use[nxt[i].x][nxt[i].y]!=caseN){
            nxt[i].p=now.p; continue;
          }
          nxt[i].p=nxt[i].x*C+nxt[i].y;
        }
      }

      if(state==3) puts(">_<");
      else{
        puts("<(_ _)>");
        for(int i=0;i<8;i++)
          unite(now.p,nxt[i].p);
        use[now.x][now.y]=caseN;
      }
    }
  }
}
/*
3 10 5
0 1
1 1
2 1
2 2
2 3
====
<(_ _)>
<(_ _)>
>_<
>_<
<(_ _)>
*/