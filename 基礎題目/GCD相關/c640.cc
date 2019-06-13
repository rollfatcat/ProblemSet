// 餘數相同時就是輸出 落在範圍內的最小公倍數的倍數+餘數
// 當餘數不同時就需要中國餘式定理(乘法反元素)來解題
#include<bits/stdc++.h>
using namespace std;


int main(){
  string ss;
  int M, k, i, n;
  int num[5];
  while(getline(cin,ss)){
    for(i=M=0;ss[i]>='0' and ss[i]<='9';i++)
      M=(M<<3)+(M<<1)+ss[i]-'0';
    for(i++,k=0;ss[i]>='0' and ss[i]<='9';i++)
      k=(k<<3)+(k<<1)+ss[i]-'0';
    //
    getline(cin,ss);
    for(i=n=0; i<ss.length();n++,i++)
      for(num[n]=0;ss[i]>='0' and ss[i]<='9';i++)
        num[n]=(num[n]<<3)+(num[n]<<1)+ss[i]-'0';
    int gcd=__gcd(num[0],num[1]), lca=num[0];
    for(i=2;i<n;i++)
      gcd=__gcd(gcd,num[i]);
    for(i=1;i<n;i++)
      lca*=num[i]/gcd;
    for(i=lca+k;i<=M;i+=lca)
      cout<<i<<' ';
    cout<<endl;
  }
}