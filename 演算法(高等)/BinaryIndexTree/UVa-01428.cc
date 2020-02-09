/* 這一題的考點有兩個
 * (1)用 BIT 處理找到比某個數字小和大的個數總和
 * (2)要窮舉的不是起點和終點，而是中繼點
 * 利用 BIT 處理出每個位置左邊比它小的個數和右邊比他小的個數和，左邊和右邊大就也能計算出来，那麼比賽的場次是左小*右大+左大*右小。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e4;
const int NUM=1e5;
int data[MAXN];
short BIT[NUM+1];
short front[MAXN];
short back[MAXN];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lowbit(int x){ return -x&x; }
int main(){
  int caseN, N;
  for(scanInt(caseN);caseN--;){
    scanInt(N);
    long ans=0;
    memset(BIT,0,sizeof(BIT));
    // ---邊讀取輸入邊更新BIT---
    for(int i=0;i<N;i++){
      scanInt(data[i]);
      // ---區間查詢---
      // ---比現在這個數字小的總數---
      front[i]=0;
      for(int pos=data[i]-1;pos;pos-=lowbit(pos))
        front[i]+=BIT[pos];
      // ---比現在這個數字大的總數---
      back[i]=0;
      for(int pos=data[i];pos;pos-=lowbit(pos))
        back[i]+=BIT[pos];
      back[i]=i-back[i];
      // ---更新這個點和他的父節點們的數量和---
      for(int pos=data[i];pos<=NUM;pos+=lowbit(pos))
        BIT[pos]++;
    }
    /* 窮舉所有的【中繼點】
     */
    memset(BIT,0,sizeof(BIT));
    for(int pos=data[N-1];pos<=NUM;pos+=lowbit(pos))
      BIT[pos]++;
    for(int i=N-2;i;i--){
      int cnt_front=0;
      int cnt_back=0;
      // ---區間查詢---
      // ---比現在這個數字小的總數---
      for(int pos=data[i]-1;pos;pos-=lowbit(pos))
        cnt_front+=BIT[pos];
      // ---比現在這個數字大的總數---
      for(int pos=data[i];pos;pos-=lowbit(pos))
        cnt_back+=BIT[pos];
      cnt_back=N-1-i-cnt_back;
      // ---更新這個點和他的父節點們的數量和---
      for(int pos=data[i];pos<=NUM;pos+=lowbit(pos))
        BIT[pos]++;
      ans+=cnt_front*back[i]+cnt_back*front[i];
    }
    printf("%ld\n",ans);
  }
}