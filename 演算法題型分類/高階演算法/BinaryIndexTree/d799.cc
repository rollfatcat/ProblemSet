// 將線段樹處理的RMQ問題(且必須支援區間修改)轉成BIT處理方式
/* 模板詳解：http://kenby.iteye.com/blog/962159
 * sum[x]=segma(org[i])+(x+1)*segma(delta[i])-segma(delta[i]*i)，1<=i<=x
 * 維護三個前綴和：org[i]/delta[i]/delta[i]*i
 */
#include<iostream>
using namespace std;
#define MaxN 500001

long N;
// 設delta[i]表示[i,n]的共同增量
long sum[MaxN]={0};//
long c1[MaxN]; // 維護delta[i] 的前缀和
long c2[MaxN]; // 維護delta[i]*i 的前缀和
inline void scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
long query(long *arr, int st){
  long tmp=0;
  for(;st>0; st-=(st&-st) )
    tmp+=arr[st];
  return tmp;
}
void update(long *arr,int st,int add){
  for(; st<=N; st+=(st&-st))
    arr[st]+=add;
}
int main(){
  long M, v, x, y, k;

  scanLong(N);
  for(int i=1;i<=N;i++)
    scanLong(sum[i]), sum[i]+=sum[i-1];
  for(scanLong(M); M--; ){
    scanLong(v),
    scanLong(x),
    scanLong(y);
    if(v==2){
      long ans=sum[y]-sum[x-1];
      ans+=((y+1)*query(c1,y)-query(c2,y));
      ans-=(x*query(c1,x-1)-query(c2,x-1));
      cout<<ans<<endl;
    } else {
      // 把delta[i](s<=i<=t)加d，策略是先把[s,n]内的增量加d，再把[t+1,n]的增量减d
      scanLong(k);
      update(c1,  x, k);
      update(c1,y+1,-k);
      update(c2,  x,k*x);
      update(c2,y+1,-k*(y+1));
    }
  }
}