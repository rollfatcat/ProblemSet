// 求移動曼哈頓距離總和最少的 x,y 座標，改編於以下題目：
// 給定Ｎ個點(一維空間)和屬於該點的權重，求某點到Ｎ點的加總值最小化
// 將兩個維度拆開各自處理即可(計算曼哈頓距離的最小化計算方式)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2001;
int R, C;
long sumR[MAXN], sumC[MAXN];

inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
inline long absv(long x){ return(x>=0)?x:-x; }
inline int ManhattanPoint(long arr[],int len){
  return lower_bound(arr,arr+len,(arr[len-1]>>1)+(arr[len-1]&1))-arr;
}
int main(){
  int caseT, now_wght;
  int posR, posC;
  long sum_wght;
  scanInt(caseT);
  while(caseT--){
    scanInt(R),
    scanInt(C);
    memset(sumR,0,sizeof(sumR));
    memset(sumC,0,sizeof(sumC));
    for(int i=1;i<=R;i++){
      for(int j=1;j<=C;j++)
        scanInt(now_wght),
        sumR[i]+=now_wght,
        sumC[j]+=now_wght,
        sum_wght+=now_wght;
      sumR[i]+=sumR[i-1];
    }
    // 計算Ｃ軸
    for(int i=1;i<=C;i++)
      sumC[i]+=sumC[i-1];
    posC=ManhattanPoint(sumC,C+1);
    posR=ManhattanPoint(sumR,R+1);
    // 移動成本計算
    long tot=0;
    for(int i=1;i<=R;i++)
      tot+=absv( (posR-i)*(sumR[i]-sumR[i-1]) );
    for(int i=1;i<=C;i++)
      tot+=absv( (posC-i)*(sumC[i]-sumC[i-1]) );
    printf("%d %d\n%ld\n",posR,posC,tot*100);
  }
}
/*
3
1 3
1 0 1
1 6
0 1 0 1 0 1
1 7
2 0 0 0 2 0 2
2 2 3 3 5 5 6
*/