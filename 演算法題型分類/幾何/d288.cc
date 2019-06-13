// 國中數學：梯形對角線相連構成的相似三角形面積關係
// 解說影片：https://www.youtube.com/watch?v=SdlZSSSLIWA
/* 因為△ACE 為平行四邊形面積的(1/2)*(a/(a+b))倍，
 * 又因為△AOE 的底、高分別是△COB 的ａ/(ａ+ｂ) 和 ａ/(2a+b) 倍。
 * △AOE 的面積 = (1/2)*(a/(a+b))*(a/(2a+b))*K
 * △EOC 的面積 = (1/2)*(a/(a+b))*((a+b)/(2a+b))*K
 * △COB 的面積 = (1/2)*( (a+b)^2 / [(a+b)*(2a+b)])*K => △AOE的面積剛好是底邊的平方比
 */
#include<iostream>
using namespace std;

long GCD(long a,long b){ return (a%b)?GCD(b,a%b):b; }
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(long K,a,b; cin>>K>>a>>b; ){
    if(K==0){ cout<<0<<endl<<0<<endl<<0<<endl; continue; }
    long numerator, denominator, gcd;
    // 理論上每做一次運算就要取GCD，但這一題可以先把ab化簡之後計算過程就不會超過long範圍
    gcd=GCD(a,b), a/=gcd, b/=gcd;
    denominator=2*(a+b)*(2*a+b);
    // area of AOE
    numerator=a*a*K;
    if(numerator%denominator==0)  cout<<(numerator/denominator)<<endl;
    else  gcd=GCD(numerator,denominator),cout<<(numerator/gcd)<<" / "<<(denominator/gcd)<<endl;
    // area of EOC
    numerator=a*(a+b)*K;
    if(numerator%denominator==0)  cout<<(numerator/denominator)<<endl;
    else  gcd=GCD(numerator,denominator),cout<<(numerator/gcd)<<" / "<<(denominator/gcd)<<endl;
    // area of COB
    numerator=(a+b)*(a+b)*K;
    if(numerator%denominator==0)  cout<<(numerator/denominator)<<endl;
    else  gcd=GCD(numerator,denominator),cout<<(numerator/gcd)<<" / "<<(denominator/gcd)<<endl;
  }
}