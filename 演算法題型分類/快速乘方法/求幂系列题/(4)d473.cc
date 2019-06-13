// 有點類似d468, 只是連底數都得是字串讀入, 而且要避開一堆特殊情況
// 以行為單位讀入,不知道為什麼最後的cnt輸出時要-1
#include<iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for(string ass,nss; cin>>ass>>nss; ){
    long a, n, num, i;
    bool asign=(ass[0]=='-')?true:false;
    bool nsign=(nss[0]=='-')?true:false;
    for(i=asign;i<ass.length() and ass[i]=='0';i++);
    for(a=0;i<ass.length();i++)
      a=10*a+ass[i]-'0';
    a=(asign)?-a:a;
    for(i=nsign;i<nss.length() and nss[i]=='0';i++);
    for(n=0;i<nss.length();i++)
      n=10*n+nss[i]-'0';
    if(a==0 and n==0 and !asign and !nsign){ cout<<"All Over."; break; }
    if(a==0 or a==1){  cout<<a<<endl; continue; }
    if(a==-1){  cout<<( (n%2)?a:1 )<<endl; continue; }
    for(num=1; n>0; n/=2, a*=a)
      if(n%2)
        num*=a;
    cout<<num<<endl;
  }
  int cnt=-1;
  for(string ss; getline(cin,ss); cnt++);
  cout<<" Exceeded "<<cnt<<" lines!"<<endl;
}