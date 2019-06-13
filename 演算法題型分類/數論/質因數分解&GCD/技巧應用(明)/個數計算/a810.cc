// 核心解法不難，但是測資很難搞
// LCM可能會超過longlong範圍，輸入的倍數可能是0
/* (1) 1至a之間x的倍數有a/x個、y的倍數則有a/y個；
 * (2) 1至a之間x和y的共同倍數有a/LCM(x,y)個；
 * (3) 1至a之間x或y的倍數的個數NUM(a,x,y) = a/x + a/y - a/LCM(x,y)；
 * (4) a至b之間x或y的倍數的個數 = NUM(b,x,y) - NUM(a-1,x,y)；
 * (5) 如果[a,b]橫跨正負值區間，把正值區間和負值區間分開處理；若[a,b]包含0，需把0也算上。
 */
#include<iostream>
using namespace std;
#define INF 0x7fffffffffffffff

long GCD(long x,long y){ return(x%y)?GCD(y,x%y):y; }
long LCM(long x,long y){
  if(x==0ll or y==0ll) return 0ll;
  x/=GCD(x,y); return (x>INF/y)?INF:x*y;
}
long NUM(long R,long x,long y,long l){
  long cnt=0;
  cnt+=(x==0ll)?0ll:(R/x);
  cnt+=(y==0ll)?0ll:(R/y);
  cnt-=(l==0ll)?0ll:(R/l);
  return cnt;
}
int main(){
  long a, b, x, y, ans;
  cin>>a>>b>>x>>y;
  if(a>b) a^=b^=a^=b;
  if(x<0) x=-x;
  if(y<0) y=-y;
  bool zero=((a<0ll and b>0ll) || (a==0ll) || (b==0ll));
  long l=LCM(x,y);
  if(a==0ll and b>0ll) a++;
  if(b==0ll and a<0ll) b--;

  if(a<0ll and b<0ll)
    ans=NUM(-a,x,y,l)-NUM(-b-1,x,y,l)+zero;
  else if( a>0ll && b>0ll )
    ans=NUM(b,x,y,l)-NUM(a-1,x,y,l)+zero;
  else
    ans=NUM(b,x,y,l)+NUM(-a,x,y,l)+zero;
  cout<<ans<<endl;
}