// 難在怎麼提出可行的解法，測資最大達1e6個，不可能暴力枚舉任兩個點搭配連續區間和的計算
// 做法參照：https://sites.google.com/site/silithusxoi/code/ks2014
/* 數學題。解法如下：
 * (a) 先把P/Q變成最簡分數
 * (b) 計算由第1棵棕櫚至第i棵棕櫚的累計美好度平均值，並計算出扣減整數倍P/Q後的餘數
 * 注意：這裏所指的減法不是常規的分數運算，而是分子部份和分母部份分別各自相減
 * (c) 餘數相同的棕櫚樹間的美好度平均值必然是P/Q的整數倍
 *     如上表所示，第1、4、6棵樹的餘數均為2/1，代表它們兩兩間的美好度平均值為5/1的整數倍，共有n*(n-1)/2種組合
 * (d) 把各餘數的組合數累加便是答案，注意要處理0/0的情況
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
struct fraction{
  long p; int q;
  bool operator <(const fraction &other)const{ return(q==other.q)?(p<other.p):(q<other.q); }
  bool operator!=(const fraction &other)const{ return(p!=other.p or q!=other.q); }
} rec[1000002];
int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  int N, P, Q, x; // P可能是0，題目只保證是非負數
  scanInt(N),
  scanInt(P),
  scanInt(Q);
  if(P)
    x=GCD(P,Q), P/=x, Q/=x;
  long sum=0;
  for(int i=1;i<=N;i++){
    scanInt(x),
    sum+=x;
    long mul=i/Q; mul=(P>0 and (sum/P)<mul)?(sum/P):mul;
    rec[i]={ sum-mul*P, i-(int)mul*Q };
  }
  sort(rec+1,rec+N+1);
  rec[0]={0,0};
  long cnt=0, w;
  int pre=0, idx;
  for(idx=1;idx<=N;idx++)
    if(rec[pre]!=rec[idx]){
      w=idx-pre,
      cnt+=w*(w-1)/2;
      pre=idx;
    }
  w=N+1-pre,
  cnt+=w*(w-1)/2;
  printf("%ld\n",cnt);
}