// HuffmanCode編碼模板題
// 改自 c233：RadixSort＋double vector
// 單筆數值最大是2^16，最多65535筆，總和最大是(long)68719476736
#include<bits/stdc++.h>
using namespace std;

int N, idx, front, back;
vector<int> num;
long Q[(1<<16)+1];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
long LeastNum(){
  if(front==back){  return num[idx++]; }
  if(idx==N or Q[front]<=num[idx]){ return Q[front++]; }
  return num[idx++];
}
int main(){

  scanInt(N);
  num.assign(N,0);
  for(int i=0;i<N;i++)
    scanInt(num[i]);
  sort(num.begin(),num.end());

  long sum=0;
  idx=front=back=0;
  for(int t=1;t<N;t++){
    long A=LeastNum(), 
         B=LeastNum();
    Q[back]=A+B, sum+=Q[back++], ;
  }
  printf("%ld\n",sum);
}