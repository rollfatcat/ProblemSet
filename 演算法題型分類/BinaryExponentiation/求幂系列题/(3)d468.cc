// 這題的目的是禁止挑戰者使用 math.pow(), 會因為精確度出現問題, 要自己做快速幂次
// 特殊情況：當基底是1/0/-1時, 次方項沒有限制(但輸出符合題目落在long範圍內), 需要字串讀取
#include<iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string nss;
  for(long a; cin>>a>>nss; ){
    long n, num, i;
    for(i=0;i<nss.length() and nss[i]=='0';i++);
    for(n=0;i<nss.length();i++)
      n=10*n+nss[i]-'0';
    if(a==0 and n==0){ cout<<"All Over."; break; }
    if(a==0 or a==1){  cout<<a<<endl; continue; }
    if(a==-1){  cout<<( (n%2)?a:1 )<<endl; continue; }
    for(num=1; n>0; n/=2, a*=a)
      if(n%2)
        num*=a;
    cout<<num<<endl;
  }
}