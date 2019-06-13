// 需要支援：單點修改＋區間查詢
// 將整除問題轉換成餘數加總 => SegmentTree決定怎麼拆成區間，紀錄每個節點的餘數狀態
#include<bits/stdc++.h>
using namespace std;

const int MAXL=100001;
int qL, qR, qK, nowv;
short cycle[51]={};
short tail[51]={};
vector<short> remaind[51];
struct NODE{ int L; short rem[49]; }node[MAXL<<2];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x; }
inline int DigitLen(int x,int l=1){ for(x/=10;x;l++,x/=10); return l;}
inline int TenPowerToRem(int L,int mod){
  if(L<tail[mod]) return remaind[mod][L];
  return remaind[mod][ (L-tail[mod])%cycle[mod]+tail[mod] ];
}
void BuildSegTree(int nL,int nR,int pt){
  if(nL==nR){ // 到達葉節點時讀取輸入，併計算除以50的所有餘數
    int num;
    scanf("%d",&num);
    node[pt].L=DigitLen(num);
    for(int i=2;i<=50;i++)
      node[pt].rem[i-2]=num%i;
    return;
  }
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  BuildSegTree(  nL,nM,Lson);
  BuildSegTree(nM+1,nR,Rson);
  // 合併左右節點的餘數：合併時左節點需要乘以10^(右節點長度) => 根據餘數循環的方式計算
  node[pt].L=node[Lson].L+node[Rson].L;
  for(int i=2;i<=50;i++)
    node[pt].rem[i-2]=( node[Lson].rem[i-2]*TenPowerToRem(node[Rson].L,i)+node[Rson].rem[i-2] )%i;
}
void Update(int nL,int nR,int pt){ //單點更新，但左右邊界需要透過遞迴求得
  if(nL==nR and nL==qL){
    node[pt].L=DigitLen(qR);
    for(int i=2;i<=50;i++)
      node[pt].rem[i-2]=qR%i;
    return;
  }
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  (qL<=nM)? Update( nL,nM,Lson): Update(nM+1,nR,Rson);
  // merge
  node[pt].L=node[Lson].L+node[Rson].L;
  for(int i=2;i<=50;i++)
    node[pt].rem[i-2]=( node[Lson].rem[i-2]*TenPowerToRem(node[Rson].L,i)+node[Rson].rem[i-2] )%i;
}
void Query(int nL,int nR,int pt){
  //因為更新時節點是由左往右，類似將字串"123"轉為數字123的方式一邊乘一邊累加
  if(qL<=nL and nR<=qR){ nowv=(nowv*TenPowerToRem(node[pt].L,qK)+node[pt].rem[qK-2])%qK; return; }
  int nM=(nL+nR)>>1;
  if(qL<=nM) Query(  nL,nM,  pt<<1);
  if(qR> nM) Query(nM+1,nR,pt<<1|1);
}
int main(){
  // 餘數循環：注意循環小數的規律和循環長度
  for(int n,i=2;i<=50;i++){
    vector<int> rem(i,-1);
    for(n=1;rem[n]==-1;cycle[i]++)
      remaind[i].push_back(n),
      rem[n]=cycle[i],
      n=10*n%i;
    cycle[i]=cycle[i]-rem[n];
    tail[i]=remaind[i].size()-cycle[i];
  }
  // 讀取測資
  int N, Q, act;
  scanf("%d",&N);
  scanf("%d",&Q);
  BuildSegTree(1,N,1);
  while(Q--){
    scanf("%d",&act),
    scanf("%d",&qL),
    scanf("%d",&qR);
    if(act==1)
      Update(1,N,1);
    else{
      scanf("%d",&qK);
      nowv=0;
      if(qK>1) Query(1,N,1);
      puts((nowv==0)?"YES":"NO");
    }
  }
}
/*
3 5
997 129 1000

5 5
2 3 0 12 5
2 1 3 5
2 3 5 4
1 5 16
2 1 5 3
2 3 3 17

10 10
3 8 1 6 5 4 7 2 9 0
2 1 1 1
2 1 2 2
2 1 3 3
2 1 4 4
2 1 5 5
2 1 6 6
2 1 7 7
2 1 8 8
2 1 9 9
2 1 10 10
*/